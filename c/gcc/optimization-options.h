/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:08 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:22 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:29 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:07 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
/*
 *	Optimization Options
 *	See Section 3.10 [Options that Control Optimization], page 86.
 *	-falign-arrays -falign-functions[=n] -falign-jumps[=n]
 *	-falign-labels[=n] -falign-loops[=n] -fassociative-math
 *	-fauto-inc-dec -fbranch-probabilities -fbranch-target-load-optimize
 *	-fbranch-target-load-optimize2 -fbtr-bb-exclusive -fcaller-saves
 *	-fcheck-data-deps -fconserve-stack -fcprop-registers -fcrossjumping
 *	-fcse-follow-jumps -fcse-skip-blocks -fcx-fortran-rules -fcx-limited-range
 *	-fdata-sections -fdce -fdce
 *	-fdelayed-branch -fdelete-null-pointer-checks -fdse -fdse
 *	-fearly-inlining -fipa-sra -fexpensive-optimizations -ffast-math
 *	-ffinite-math-only -ffloat-store -fexcess-precision=style
 *	-fforward-propagate -ffunction-sections
 *	-fgcse -fgcse-after-reload -fgcse-las -fgcse-lm
 *	-fgcse-sm -fif-conversion -fif-conversion2 -findirect-inlining
 *	-finline-functions -finline-functions-called-once -finline-limit=n
 *	-finline-small-functions -fipa-cp -fipa-cp-clone -fipa-matrix-reorg -fipa
 *	pta
 *	-fipa-pure-const -fipa-reference -fipa-struct-reorg
 *	-fipa-type-escape -fira-algorithm=algorithm
 *	-fira-region=region -fira-coalesce
 *	-fira-loop-pressure -fno-ira-share-save-slots
 *	-fno-ira-share-spill-slots -fira-verbose=n
 *	-fivopts -fkeep-inline-functions -fkeep-static-consts
 *	-floop-block -floop-interchange -floop-strip-mine -fgraphite-identity
 *	-floop-parallelize-all -flto -flto-compression-level -flto-report -fltrans
 *	-fltrans-output-list -fmerge-all-constants -fmerge-constants -fmodulo-sched
 *	-fmodulo-sched-allow-regmoves -fmove-loop-invariants -fmudflap
 *	-fmudflapir -fmudflapth -fno-branch-count-reg -fno-default-inline
 *	-fno-defer-pop -fno-function-cse -fno-guess-branch-probability
 *	-fno-inline -fno-math-errno -fno-peephole -fno-peephole2
 *	-fno-sched-interblock -fno-sched-spec -fno-signed-zeros
 *	-fno-toplevel-reorder -fno-trapping-math -fno-zero-initialized-in-bss
 *	-fomit-frame-pointer -foptimize-register-move -foptimize-sibling-calls
 *	-fpeel-loops -fpredictive-commoning -fprefetch-loop-arrays
 *	-fprofile-correction -fprofile-dir=path -fprofile-generate
 *	-fprofile-generate=path
 *	-fprofile-use -fprofile-use=path -fprofile-values
 *	-freciprocal-math -fregmove -frename-registers -freorder-blocks
 *	-freorder-blocks-and-partition -freorder-functions
 *	-frerun-cse-after-loop -freschedule-modulo-scheduled-loops
 *	-frounding-math -fsched2-use-superblocks -fsched-pressure
 *	-fsched-spec-load -fsched-spec-load-dangerous
 *	-fsched-stalled-insns-dep[=n] -fsched-stalled-insns[=n]
 *	-fsched-group-heuristic -fsched-critical-path-heuristic
 *	-fsched-spec-insn-heuristic -fsched-rank-heuristic
 *	-fsched-last-insn-heuristic -fsched-dep-count-heuristic
 *	-fschedule-insns -fschedule-insns2 -fsection-anchors
 *	-fselective-scheduling -fselective-scheduling2
 *	-fsel-sched-pipelining -fsel-sched-pipelining-outer-loops
 *	-fsignaling-nans -fsingle-precision-constant -fsplit-ivs-in-unroller
 *	-fsplit-wide-types -fstack-protector -fstack-protector-all
 *	-fstrict-aliasing -fstrict-overflow -fthread-jumps -ftracer
 *	-ftree-builtin-call-dce -ftree-ccp -ftree-ch -ftree-copy-prop
 *	-ftree-copyrename -ftree-dce
 *	-ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
 *	-ftree-if-to-switch-conversion -ftree-loop-im
 *	-ftree-phiprop -ftree-loop-distribution
 *	-ftree-loop-ivcanon -ftree-loop-linear -ftree-loop-optimize
 *	-ftree-parallelize-loops=n -ftree-pre -ftree-pta -ftree-reassoc
 *	-ftree-sink -ftree-sra -ftree-switch-conversion
 *	-ftree-ter -ftree-vect-loop-version -ftree-vectorize -ftree-vrp
 *	-funit-at-a-time -funroll-all-loops -funroll-loops
 *	-funsafe-loop-optimizations -funsafe-math-optimizations -funswitch-loops
 *	-fvariable-expansion-in-unroller -fvect-cost-model -fvpt -fweb
 *	-fwhole-program -fwhopr -fwpa -fuse-linker-plugin
 *	--param name=value -O -O0 -O1 -O2 -O3 -Os
 */
