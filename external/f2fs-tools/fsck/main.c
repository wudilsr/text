/**
 * main.c
 *
 * Copyright (c) 2013 Samsung Electronics Co., Ltd.
 *             http://www.samsung.com/
 * Copyright (c) 2015 Jaegeuk Kim <jaegeuk@kernel.org>
 *  : implement defrag.f2fs
 * Copyright (C) 2015 Huawei Ltd.
 *   Hou Pengyang <houpengyang@huawei.com>
 *   Liu Shuoran <liushuoran@huawei.com>
 *   Jaegeuk Kim <jaegeuk@kernel.org>
 *  : add sload.f2fs
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include "fsck.h"
#include <libgen.h>
#include <ctype.h>

#include <sys/time.h>
#include <time.h>

struct f2fs_fsck gfsck;

void fsck_usage()
{
	MSG(0, "\nUsage: fsck.f2fs [options] device\n");
	MSG(0, "[options]:\n");
	MSG(0, "  -a check/fix potential corruption, reported by f2fs\n");
	MSG(0, "  -d debug level [default:0]\n");
	MSG(0, "  -f check/fix entire partition\n");
	MSG(0, "  -p preen mode [default:0 the same as -a [0|1]]\n");
	MSG(0, "  -t show directory tree\n");
	exit(1);
}

void dump_usage()
{
	MSG(0, "\nUsage: dump.f2fs [options] device\n");
	MSG(0, "[options]:\n");
	MSG(0, "  -d debug level [default:0]\n");
	MSG(0, "  -i inode no (hex)\n");
	MSG(0, "  -n [NAT dump segno from #1~#2 (decimal), for all 0~-1]\n");
	MSG(0, "  -s [SIT dump segno from #1~#2 (decimal), for all 0~-1]\n");
	MSG(0, "  -a [SSA dump segno from #1~#2 (decimal), for all 0~-1]\n");
	MSG(0, "  -b blk_addr (in 4KB)\n");

	exit(1);
}

void defrag_usage()
{
	MSG(0, "\nUsage: defrag.f2fs [options] device\n");
	MSG(0, "[options]:\n");
	MSG(0, "  -d debug level [default:0]\n");
	MSG(0, "  -s start block address [default: main_blkaddr]\n");
	MSG(0, "  -l length [default:512 (2MB)]\n");
	MSG(0, "  -t target block address [default: main_blkaddr + 2MB]\n");
	MSG(0, "  -i set direction as shrink [default: expand]\n");
	exit(1);
}

void resize_usage()
{
	MSG(0, "\nUsage: resize.f2fs [options] device\n");
	MSG(0, "[options]:\n");
	MSG(0, "  -d debug level [default:0]\n");
	MSG(0, "  -t target sectors [default: device size]\n");
	exit(1);
}

void sload_usage()
{
	MSG(0, "\nUsage: sload.f2fs [options] device\n");
	MSG(0, "[options]:\n");
	MSG(0, "  -f source directory [path of the source directory]\n");
	MSG(0, "  -t mount point [prefix of target fs path, default:/]\n");
	MSG(0, "  -d debug level [default:0]\n");
	exit(1);
}

static int is_digits(char *optarg)
{
	unsigned int i;

	for (i = 0; i < strlen(optarg); i++)
		if (!isdigit(optarg[i]))
			break;
	return i == strlen(optarg);
}

static void error_out(char *prog)
{
	if (!strcmp("fsck.f2fs", prog))
		fsck_usage();
	else if (!strcmp("dump.f2fs", prog))
		dump_usage();
	else if (!strcmp("defrag.f2fs", prog))
		defrag_usage();
	else if (!strcmp("resize.f2fs", prog))
		resize_usage();
	else if (!strcmp("sload.f2fs", prog))
		sload_usage();
	else
		MSG(0, "\nWrong progam.\n");
}

void f2fs_parse_options(int argc, char *argv[])
{
	int option = 0;
	char *prog = basename(argv[0]);
	int err = NOERROR;

	if (argc < 2) {
		MSG(0, "\tError: Device not specified\n");
		error_out(prog);
	}

	if (!strcmp("fsck.f2fs", prog) || !strcmp("fsck.f2fs_s", prog)) {
		const char *option_string = "ad:fp:tq";

		c.func = FSCK;
		while ((option = getopt(argc, argv, option_string)) != EOF) {
			switch (option) {
			case 'a':
				c.auto_fix = 1;
				MSG(0, "Info: Fix the reported corruption.\n");
				break;
			case 'p':
				/* preen mode has different levels:
				 *  0: default level, the same as -a
				 *  1: check meta
				 */
				if (optarg[0] == '-') {
					c.preen_mode = PREEN_MODE_0;
					optind--;
					break;
				} else if (!is_digits(optarg)) {
					err = EWRONG_OPT;
					break;
				}
				c.preen_mode = atoi(optarg);
				if (c.preen_mode < 0)
					c.preen_mode = PREEN_MODE_0;
				else if (c.preen_mode >= PREEN_MODE_MAX)
					c.preen_mode = PREEN_MODE_MAX - 1;
				if (c.preen_mode == PREEN_MODE_0)
					c.auto_fix = 1;
				MSG(0, "Info: Fix the reported corruption in "
					"preen mode %d\n", c.preen_mode);
				break;
			case 'd':
				if (optarg[0] == '-') {
					err = ENEED_ARG;
					break;
				} else if (!is_digits(optarg)) {
					err = EWRONG_OPT;
					break;
				}
				c.dbg_lv = atoi(optarg);
				MSG(0, "Info: Debug level = %d\n", c.dbg_lv);
				break;
			case 'f':
				c.fix_on = 1;
				MSG(0, "Info: Force to fix corruption\n");
				break;
			case 't':
				c.show_dentry = 1;
				break;
			case 'q':
				c.preen_mode = PREEN_MODE_1;
				set_bg_fsck_mode();
				MSG(0, "Info: Begin background fsck! \n");
				break;

			case ':':
				if (optopt == 'p') {
					MSG(0, "Info: Use default preen mode\n");
					c.preen_mode = PREEN_MODE_0;
					c.auto_fix = 1;
				} else {
					option = optopt;
					err = ENEED_ARG;
					break;
				}
				break;
			case '?':
				option = optopt;
			default:
				err = EUNKNOWN_OPT;
				break;
			}
			if (err != NOERROR)
				break;
		}
	} else if (!strcmp("dump.f2fs", prog)) {
		const char *option_string = "d:i:n:s:a:b:";
		static struct dump_option dump_opt = {
			.nid = 0,	/* default root ino */
			.start_nat = -1,
			.end_nat = -1,
			.start_sit = -1,
			.end_sit = -1,
			.start_ssa = -1,
			.end_ssa = -1,
			.blk_addr = -1,
		};

		c.func = DUMP;
		while ((option = getopt(argc, argv, option_string)) != EOF) {
			int ret = 0;

			switch (option) {
			case 'd':
				if (!is_digits(optarg)) {
					err = EWRONG_OPT;
					break;
				}
				c.dbg_lv = atoi(optarg);
				MSG(0, "Info: Debug level = %d\n",
							c.dbg_lv);
				break;
			case 'i':
				if (strncmp(optarg, "0x", 2))
					ret = sscanf(optarg, "%d",
							&dump_opt.nid);
				else
					ret = sscanf(optarg, "%x",
							&dump_opt.nid);
				break;
			case 'n':
				ret = sscanf(optarg, "%d~%d",
							&dump_opt.start_nat,
							&dump_opt.end_nat);
				break;
			case 's':
				ret = sscanf(optarg, "%d~%d",
							&dump_opt.start_sit,
							&dump_opt.end_sit);
				break;
			case 'a':
				ret = sscanf(optarg, "%d~%d",
							&dump_opt.start_ssa,
							&dump_opt.end_ssa);
				break;
			case 'b':
				if (strncmp(optarg, "0x", 2))
					ret = sscanf(optarg, "%d",
							&dump_opt.blk_addr);
				else
					ret = sscanf(optarg, "%x",
							&dump_opt.blk_addr);
				break;
			default:
				err = EUNKNOWN_OPT;
				break;
			}
			ASSERT(ret >= 0);
			if (err != NOERROR)
				break;
		}

		c.private = &dump_opt;
	} else if (!strcmp("defrag.f2fs", prog)) {
		const char *option_string = "d:s:l:t:i";

		c.func = DEFRAG;
		while ((option = getopt(argc, argv, option_string)) != EOF) {
			int ret = 0;

			switch (option) {
			case 'd':
				if (!is_digits(optarg)) {
					err = EWRONG_OPT;
					break;
				}
				c.dbg_lv = atoi(optarg);
				MSG(0, "Info: Debug level = %d\n",
							c.dbg_lv);
				break;
			case 's':
				if (strncmp(optarg, "0x", 2))
					ret = sscanf(optarg, "%"PRIu64"",
							&c.defrag_start);
				else
					ret = sscanf(optarg, "%"PRIx64"",
							&c.defrag_start);
				break;
			case 'l':
				if (strncmp(optarg, "0x", 2))
					ret = sscanf(optarg, "%"PRIu64"",
							&c.defrag_len);
				else
					ret = sscanf(optarg, "%"PRIx64"",
							&c.defrag_len);
				break;
			case 't':
				if (strncmp(optarg, "0x", 2))
					ret = sscanf(optarg, "%"PRIu64"",
							&c.defrag_target);
				else
					ret = sscanf(optarg, "%"PRIx64"",
							&c.defrag_target);
				break;
			case 'i':
				c.defrag_shrink = 1;
				break;
			default:
				err = EUNKNOWN_OPT;
				break;
			}
			ASSERT(ret >= 0);
			if (err != NOERROR)
				break;
		}
	} else if (!strcmp("resize.f2fs", prog) || !strcmp("resize.f2fs_s", prog) ) {
		const char *option_string = "d:l:";

		c.func = RESIZE;
		while ((option = getopt(argc, argv, option_string)) != EOF) {
			int ret = 0;

			switch (option) {
			case 'd':
				if (!is_digits(optarg)) {
					err = EWRONG_OPT;
					break;
				}
				c.dbg_lv = atoi(optarg);
				MSG(0, "Info: Debug level = %d\n",
							c.dbg_lv);
				break;
			case 'l':
				if (strncmp(optarg, "0x", 2))
					ret = sscanf(optarg, "%"PRIu64"",
							&c.target_sectors);
				else
					ret = sscanf(optarg, "%"PRIx64"",
							&c.target_sectors);
				break;
			default:
				MSG(0, "\tError: Unknown option %c\n", option);
				err = EUNKNOWN_OPT;
				break;
			}
			ASSERT(ret >= 0);
			if (err != NOERROR)
				break;
		}
	} else if (!strcmp("sload.f2fs", prog)) {
		const char *option_string = "d:f:t:";

		c.func = SLOAD;
		while ((option = getopt(argc, argv, option_string)) != EOF) {
			switch (option) {
			case 'd':
				if (!is_digits(optarg)) {
					err = EWRONG_OPT;
					break;
				}
				c.dbg_lv = atoi(optarg);
				MSG(0, "Info: Debug level = %d\n",
						c.dbg_lv);
				break;
			case 'f':
				c.from_dir = (char *)optarg;
				break;
			case 't':
				c.mount_point = (char *)optarg;
				break;
			default:
				err = EUNKNOWN_OPT;
				break;
			}
			if (err != NOERROR)
				break;
		}
	}

	if (optind >= argc) {
		MSG(0, "\tError: Device not specified\n");
		error_out(prog);
	}

	c.devices[0].path = strdup(argv[optind]);
	if (argc > (optind + 1)) {
		c.dbg_lv = 0;
		err = EUNKNOWN_ARG;
	}
	if (err == NOERROR)
		return;

	/* print out error */
	switch (err) {
	case EWRONG_OPT:
		MSG(0, "\tError: Wrong option -%c %s\n", option, optarg);
		break;
	case ENEED_ARG:
		MSG(0, "\tError: Need argument for -%c\n", option);
		break;
	case EUNKNOWN_OPT:
		MSG(0, "\tError: Unknown option %c\n", option);
		break;
	case EUNKNOWN_ARG:
		MSG(0, "\tError: Unknown argument %s\n", argv[optind]);
		break;
	}
	error_out(prog);
}

static void do_fsck(struct f2fs_sb_info *sbi)
{
	struct f2fs_checkpoint *ckpt = F2FS_CKPT(sbi);
	u32 flag = le32_to_cpu(ckpt->ckpt_flags);
	u32 blk_cnt;

	fsck_init(sbi);

	print_cp_state(flag);

	if (!c.fix_on && !c.bug_on) {
		switch (c.preen_mode) {
		case PREEN_MODE_1:
			if (fsck_chk_meta(sbi)) {
				DMD_ADD_ERROR(LOG_TYP_FSCK, PR_FSCK_META_MISMATCH);
				MSG(0, "[FSCK] F2FS metadata   [Fail]");
				MSG(0, "\tError: meta does not match, "
					"force check all\n");
			} else {
				MSG(0, "[FSCK] F2FS metadata   [Ok..]");
				fsck_free(sbi);
				return;
			}

			if (!c.ro)
				c.fix_on = 1;
			break;
		}
	} else {
		/*
		 * we can hit this in 3 situations:
		 *  1. fsck -f, fix_on has already been set to 1 when
		 *     parsing options;
		 *  2. fsck -a && CP_FSCK_FLAG is set, fix_on has already
		 *     been set to 1 when checking CP_FSCK_FLAG;
		 *  3. fsck -p 1 && error is detected, then bug_on is set,
		 *     we set fix_on = 1 here, so that fsck can fix errors
		 *     automatically
		*/
		c.fix_on = 1;
	}

	if(is_in_bg_fsck()){
		return;
	}

	fsck_chk_orphan_node(sbi);

	/* Traverse all block recursively from root inode */
	blk_cnt = 1;
	fsck_chk_node_blk(sbi, NULL, sbi->root_ino_num,
			F2FS_FT_DIR, TYPE_INODE, &blk_cnt, NULL);
	fsck_verify(sbi);
	fsck_free(sbi);
}

static void do_dump(struct f2fs_sb_info *sbi)
{
	struct dump_option *opt = (struct dump_option *)c.private;
	struct f2fs_checkpoint *ckpt = F2FS_CKPT(sbi);
	u32 flag = le32_to_cpu(ckpt->ckpt_flags);

	if (opt->end_nat == -1)
		opt->end_nat = NM_I(sbi)->max_nid;
	if (opt->end_sit == -1)
		opt->end_sit = SM_I(sbi)->main_segments;
	if (opt->end_ssa == -1)
		opt->end_ssa = SM_I(sbi)->main_segments;
	if (opt->start_nat != -1)
		nat_dump(sbi);
	if (opt->start_sit != -1)
		sit_dump(sbi, opt->start_sit, opt->end_sit);
	if (opt->start_ssa != -1)
		ssa_dump(sbi, opt->start_ssa, opt->end_ssa);
	if (opt->blk_addr != -1)
		dump_info_from_blkaddr(sbi, opt->blk_addr);
	if (opt->nid)
		dump_node(sbi, opt->nid, 0);

	print_cp_state(flag);

}

static int do_defrag(struct f2fs_sb_info *sbi)
{
	struct f2fs_super_block *sb = F2FS_RAW_SUPER(sbi);

	if (c.defrag_start > get_sb(block_count))
		goto out_range;
	if (c.defrag_start < SM_I(sbi)->main_blkaddr)
		c.defrag_start = SM_I(sbi)->main_blkaddr;

	if (c.defrag_len == 0)
		c.defrag_len = sbi->blocks_per_seg;

	if (c.defrag_start + c.defrag_len > get_sb(block_count))
		c.defrag_len = get_sb(block_count) - c.defrag_start;

	if (c.defrag_target == 0) {
		c.defrag_target = c.defrag_start - 1;
		if (!c.defrag_shrink)
			c.defrag_target += c.defrag_len + 1;
	}

	if (c.defrag_target < SM_I(sbi)->main_blkaddr ||
			c.defrag_target > get_sb(block_count))
		goto out_range;
	if (c.defrag_target >= c.defrag_start &&
		c.defrag_target < c.defrag_start + c.defrag_len)
		goto out_range;

	if (c.defrag_start > c.defrag_target)
		MSG(0, "Info: Move 0x%"PRIx64" <- [0x%"PRIx64"-0x%"PRIx64"]\n",
				c.defrag_target,
				c.defrag_start,
				c.defrag_start + c.defrag_len - 1);
	else
		MSG(0, "Info: Move [0x%"PRIx64"-0x%"PRIx64"] -> 0x%"PRIx64"\n",
				c.defrag_start,
				c.defrag_start + c.defrag_len - 1,
				c.defrag_target);

	return f2fs_defragment(sbi, c.defrag_start, c.defrag_len,
			c.defrag_target, c.defrag_shrink);
out_range:
	ASSERT_MSG("Out-of-range [0x%"PRIx64" ~ 0x%"PRIx64"] to 0x%"PRIx64"",
				c.defrag_start,
				c.defrag_start + c.defrag_len - 1,
				c.defrag_target);
	return -1;
}

static int do_resize(struct f2fs_sb_info *sbi)
{
	struct f2fs_super_block *sb = F2FS_RAW_SUPER(sbi);

	if (!c.target_sectors)
		c.target_sectors = c.total_sectors - (16 * 1024 / c.sector_size);

	if (c.target_sectors > (c.total_sectors - (16 * 1024 / c.sector_size))) {
		ASSERT_MSG("Out-of-range Target=0x%"PRIx64" / 0x%"PRIx64"",
				c.target_sectors, c.total_sectors);
		return -1;
	}

	/* may different sector size */
	if ((c.target_sectors * c.sector_size >>
			get_sb(log_blocksize)) <= get_sb(block_count)) {
		ASSERT_MSG("Nothing to resize, now only support resize to expand\n");
		return -1;
	}

	MSG(0, "\t Begin to resize from block: %ld to block: %lld!\n",
		get_sb(block_count), (c.target_sectors * c.sector_size) >> get_sb(log_blocksize));

	return f2fs_resize(sbi);
}

#ifdef BG_FSCK
static void do_resize_check(struct f2fs_sb_info *sbi)
{
	if(!sbi) return;
	unsigned long long len = (unsigned long long)(sbi->total_sections) * sbi->segs_per_sec * sbi->blocks_per_seg * sbi->blocksize;
	KLOGI("total_sections : %d, segs_per_sec : %d, blocks_per_seg : %d, blocksize : %d \n", sbi->total_sections , sbi->segs_per_sec , sbi->blocks_per_seg , sbi->blocksize);
	if(len > (unsigned long long)USERDATA_RESIZE) {
		KLOGI("%s : no need to do resize!", __func__);
		int fd = open(BG_FSCK_NO_NEED_RESIZE_FLAG, O_WRONLY|O_CREAT, 0000);
		if ( fd < 0 ){
			KLOGE("%s :open %s failed, error is %s !", __func__, BG_FSCK_NO_NEED_RESIZE_FLAG, strerror(errno));
			return;
		}
		close(fd);
	} else {
		KLOGI("%s : need to do resize!", __func__);
	}
}
#else
static inline void do_resize_check(struct f2fs_sb_info *sbi)
{
	if(!sbi)
		return;
	KLOGI("total_sections : %d, segs_per_sec : %d, blocks_per_seg : %d, blocksize : %d \n", sbi->total_sections , sbi->segs_per_sec , sbi->blocks_per_seg , sbi->blocksize);
	return;
}
#endif

static int do_sload(struct f2fs_sb_info *sbi)
{
	if (!c.from_dir) {
		MSG(0, "\tError: Need source directory\n");
		sload_usage();
		return -1;
	}
	if (!c.mount_point)
		c.mount_point = "/";

	return f2fs_sload(sbi, c.from_dir, c.mount_point, NULL, NULL);
}

int main(int argc, char **argv)
{
	struct f2fs_sb_info *sbi;
	int ret = 0;

	struct timeval t_start;
	struct timeval t_end;
	long start_ms = 0;
	long end_ms = 0;
	long cost_ms = 0;
	const char *client = "dsm_f2fsck";
	int is_first_fsck = 0;

	/* get start time */
	gettimeofday(&t_start, NULL);
	start_ms = ((long)t_start.tv_sec)*1000 + (long)t_start.tv_usec/1000;
	printf("\nStart time: %ld ms\n", start_ms);

	f2fs_init_configuration();

	f2fs_parse_options(argc, argv);

	switch (c.func) {
	case FSCK:
		ret = slog_init(LOG_TYP_FSCK);
		break;
	case DUMP:
		ret = slog_init(LOG_TYP_DUMP);
		break;
	case DEFRAG:
		ret = slog_init(LOG_TYP_DEFRAG);
		break;
	default:
		ret = -1;
		break;
	}

	if(!is_in_bg_fsck() && !need_fg_fsck()) {
		KLOGI("%s : no need to do fg_fsck!", __func__);
		cp_bg_fsck_result();
		rm_bg_fsck_result();
		slog_exit();
		return 0;
	}

	if (ret < 0)
		/* do not exit. For the very first booting, fsck doesn't
		 * have the permission to access /splash2
		 */
		printf("Failed to init slog\n");

	if (f2fs_devs_are_umounted() < 0) {
		if (errno == EBUSY)
			return -1;
		if (!c.ro || c.func == DEFRAG) {
			MSG(0, "\tError: Not available on mounted device!\n");
			return -1;
		}

		/* allow ro-mounted partition */
		MSG(0, "Info: Check FS only due to RO\n");
		c.fix_on = 0;
		c.auto_fix = 0;
	}

	/* Get device */
	if (f2fs_get_device_info() < 0) {
		slog_exit();
		return -1;
	}
fsck_again:
	memset(&gfsck, 0, sizeof(gfsck));
	gfsck.sbi.fsck = &gfsck;
	sbi = &gfsck.sbi;

	ret = f2fs_do_mount(sbi);

	do_resize_check(sbi);

	is_first_fsck = F2FS_FSCK(sbi)->is_first_fsck;
	if (ret != 0) {
		if (ret == 1) {
			MSG(0, "Info: No error was reported\n");
			if (sbi->ckpt)
				free(sbi->ckpt);
			if (sbi->raw_super)
				free(sbi->raw_super);
			ret = 0;
			goto out;
		}
		goto out_err;
	}

	switch (c.func) {
	case FSCK:
		do_fsck(sbi);
		break;
	case DUMP:
		do_dump(sbi);
		break;
	case RESIZE:
		if (do_resize(sbi))
			goto out_err;
		break;
#ifndef WITH_ANDROID
	case DEFRAG:
		ret = do_defrag(sbi);
		if (ret)
			goto out_err;
		break;
	case SLOAD:
		do_sload(sbi);
		break;
#endif
	}

	f2fs_do_umount(sbi);

	if (c.func == FSCK && c.bug_on) {
		if (!c.ro && c.fix_on == 0 && c.auto_fix == 0) {
			char ans[255] = {0};
retry:
			printf("Do you want to fix this partition? [Y/N] ");
			ret = scanf("%s", ans);
			ASSERT(ret >= 0);
			if (!strcasecmp(ans, "y"))
				c.fix_on = 1;
			else if (!strcasecmp(ans, "n"))
				c.fix_on = 0;
			else
				goto retry;

			if (c.fix_on)
				goto fsck_again;
		}
	}
	f2fs_finalize_device();

out:
	/* get end time */
	gettimeofday(&t_end, NULL);
	end_ms = ((long)t_end.tv_sec)*1000 + (long)t_end.tv_usec/1000;
	MSG(0, "\nEnd time: %ld ms\n", end_ms);

	/* calculate time */
	cost_ms = end_ms - start_ms;
	MSG(0, "Cost time: %ld ms\n", cost_ms);

	MSG(0, "\nDone.\n");
	slog_exit();

	/* The reason we choose '2' here is that the first fsck will always
	 * fail because FS encryption encrypts the SB. So validate_super_block
	 * cannot get correct magic number and other basic FS attributes.
	 * Only if both two SBs have 'bad' magic number, we may say this
	 * is the first fsck. The probability of two corrupted SBs is very
	 * low. If is_first_fsck is 2, then the fsck should be the first
	 * fsck. While it is less than 2, it is not the first fsck and we
	 * should do DMD-report.
	 */
	if (is_first_fsck >= 0 && is_first_fsck < 2)
		dmd_report(client, DMD_F2FSCK_ERR);

	if(is_in_bg_fsck() && c.fix_on) {
		KLOGI("%s : need to do fg_fsck!", __func__);
		rm_bg_fsck_result();
	}

	return 0;

out_err:
	if (sbi->ckpt)
		free(sbi->ckpt);
	if (sbi->raw_super)
		free(sbi->raw_super);

	if (is_first_fsck >= 0 && is_first_fsck < 2)
		dmd_report(client, DMD_F2FSCK_ERR);
	return -1;
}
