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
 *	Machine Dependent Options
 *	See Section 3.17 [Hardware Models and Confgurations], page 156.
 *	ARC Options
 *	-EB -EL
 *	-mmangle-cpu -mcpu=cpu -mtext=text-section
 *	-mdata=data-section -mrodata=readonly-data-section
 *	ARM Options
 *	-mapcs-frame -mno-apcs-frame
 *	-mabi=name
 *	-mapcs-stack-check -mno-apcs-stack-check
 *	-mapcs-float -mno-apcs-float
 *	-mapcs-reentrant -mno-apcs-reentrant
 *	-msched-prolog -mno-sched-prolog
 *	-mlittle-endian -mbig-endian -mwords-little-endian
 *	-mfloat-abi=name -msoft-float -mhard-float -mfpe
 *	-mfp16-format=name -mthumb-interwork -mno-thumb-interwork
 *	-mcpu=name -march=name -mfpu=name
 *	-mstructure-size-boundary=n
 *	-mabort-on-noreturn
 *	-mlong-calls -mno-long-calls
 *	-msingle-pic-base -mno-single-pic-base
 *	-mpic-register=reg
 *	-mnop-fun-dllimport
 *	-mcirrus-fix-invalid-insns -mno-cirrus-fix-invalid-insns
 *	-mpoke-function-name
 *	-mthumb -marm
 *	-mtpcs-frame -mtpcs-leaf-frame
 *	-mcaller-super-interworking -mcallee-super-interworking
 *	-mtp=name -mtls-dialect=dialect
 *
 *	-mlow-irq-latency
 *	-mword-relocations
 *	-mfix-cortex-m3-ldrd
 *	AVR Options
 *	-mmcu=mcu -mno-interrupts
 *	-mcall-prologues -mtiny-stack -mint8
 *	Blackfn Options
 *	-mcpu=cpu[-sirevision]
 *	-msim -momit-leaf-frame-pointer -mno-omit-leaf-frame-pointer
 *	-mspecld-anomaly -mno-specld-anomaly -mcsync-anomaly -mno-csync-anomaly
 *	-mlow-64k -mno-low64k -mstack-check-l1 -mid-shared-library
 *	-mno-id-shared-library -mshared-library-id=n
 *	-mleaf-id-shared-library -mno-leaf-id-shared-library
 *	-msep-data -mno-sep-data -mlong-calls -mno-long-calls
 *	-mfast-fp -minline-plt -mmulticore -mcorea -mcoreb -msdram
 *	-micplb
 *	CRIS Options
 *	-mcpu=cpu -march=cpu -mtune=cpu
 *	-mmax-stack-frame=n -melinux-stacksize=n
 *	-metrax4 -metrax100 -mpdebug -mcc-init -mno-side-effects
 *	-mstack-align -mdata-align -mconst-align
 *	-m32-bit -m16-bit -m8-bit -mno-prologue-epilogue -mno-gotplt
 *	-melf -maout -melinux -mlinux -sim -sim2
 *	-mmul-bug-workaround -mno-mul-bug-workaround
 *	CRX Options
 *	-mmac -mpush-args
 *	Darwin Options
 *	-all_load -allowable_client -arch -arch_errors_fatal
 *	-arch_only -bind_at_load -bundle -bundle_loader
 *	-client_name -compatibility_version -current_version
 *	-dead_strip
 *	-dependency-file -dylib_file -dylinker_install_name
 *	-dynamic -dynamiclib -exported_symbols_list
 *	-filelist -flat_namespace -force_cpusubtype_ALL
 *	-force_flat_namespace -headerpad_max_install_names
 *	-iframework
 *	-image_base -init -install_name -keep_private_externs
 *	-multi_module -multiply_defined -multiply_defined_unused
 *	-noall_load -no_dead_strip_inits_and_terms
 *	-nofixprebinding -nomultidefs -noprebind -noseglinkedit
*	-pagezero_size -prebind -prebind_all_twolevel_modules
*	-private_bundle -read_only_relocs -sectalign
*	-sectobjectsymbols -whyload -seg1addr
*	-sectcreate -sectobjectsymbols -sectorder
*	-segaddr -segs_read_only_addr -segs_read_write_addr
*	-seg_addr_table -seg_addr_table_filename -seglinkedit
*	-segprot -segs_read_only_addr -segs_read_write_addr
*	-single_module -static -sub_library -sub_umbrella
*	-twolevel_namespace -umbrella -undefined
*	-unexported_symbols_list -weak_reference_mismatches
*	-whatsloaded -F -gused -gfull -mmacosx-version-min=version
*	-mkernel -mone-byte-bool
*	DEC Alpha Options
*
*	-mno-fp-regs -msoft-float -malpha-as -mgas
*	-mieee -mieee-with-inexact -mieee-conformant
*	-mfp-trap-mode=mode -mfp-rounding-mode=mode
*	-mtrap-precision=mode -mbuild-constants
*	-mcpu=cpu-type -mtune=cpu-type
*	-mbwx -mmax -mfix -mcix
*	-mfloat-vax -mfloat-ieee
*	-mexplicit-relocs -msmall-data -mlarge-data
*	-msmall-text -mlarge-text
*	-mmemory-latency=time
*	DEC Alpha/VMS Options
*	-mvms-return-codes -mdebug-main=prefix -mmalloc64
*	FR30 Options
*	-msmall-model -mno-lsim
*	FRV Options
*	-mgpr-32 -mgpr-64 -mfpr-32 -mfpr-64
*	-mhard-float -msoft-float
*	-malloc-cc -mfixed-cc -mdword -mno-dword
*	-mdouble -mno-double
*	-mmedia -mno-media -mmuladd -mno-muladd
*	-mfdpic -minline-plt -mgprel-ro -multilib-library-pic
*	-mlinked-fp -mlong-calls -malign-labels
*	-mlibrary-pic -macc-4 -macc-8
*	-mpack -mno-pack -mno-eflags -mcond-move -mno-cond-move
*	-moptimize-membar -mno-optimize-membar
*	-mscc -mno-scc -mcond-exec -mno-cond-exec
*	-mvliw-branch -mno-vliw-branch
*	-mmulti-cond-exec -mno-multi-cond-exec -mnested-cond-exec
*	-mno-nested-cond-exec -mtomcat-stats
*	-mTLS -mtls
*	-mcpu=cpu
*	GNU/Linux Options
*	-muclibc
*	H8/300 Options
*	-mrelax -mh -ms -mn -mint32 -malign-300
*	HPPA Options
*	-march=architecture-type
*	-mbig-switch -mdisable-fpregs -mdisable-indexing
*	-mfast-indirect-calls -mgas -mgnu-ld -mhp-ld
*	-mfixed-range=register-range
*	-mjump-in-delay -mlinker-opt -mlong-calls
*	-mlong-load-store -mno-big-switch -mno-disable-fpregs
*	-mno-disable-indexing -mno-fast-indirect-calls -mno-gas
*	-mno-jump-in-delay -mno-long-load-store
*	-mno-portable-runtime -mno-soft-float
*	-mno-space-regs -msoft-float -mpa-risc-1-0
*	-mpa-risc-1-1 -mpa-risc-2-0 -mportable-runtime
*	-mschedule=cpu-type -mspace-regs -msio -mwsio
*	-munix=unix-std -nolibdld -static -threads
*	i386 and x86-64 Options
*	-mtune=cpu-type -march=cpu-type
*	-mfpmath=unit
*	-masm=dialect -mno-fancy-math-387
*	-mno-fp-ret-in-387 -msoft-float
*	-mno-wide-multiply -mrtd -malign-double
*	-mpreferred-stack-boundary=num -mincoming-stack-boundary=num -mcld -mcx16 -
*	msahf -mmovbe -mcrc32 -mrecip
*	-mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -msse4 -mavx
*	-maes -mpclmul -mfused-madd
*	-msse4a -m3dnow -mpopcnt -mabm -mfma4 -mxop -mlwp
*	-mthreads -mno-align-stringops -minline-all-stringops
*	-minline-stringops-dynamically -mstringop-strategy=alg
*	-mpush-args -maccumulate-outgoing-args -m128bit-long-double
*	-m96bit-long-double -mregparm=num -msseregparm
*	-mveclibabi=type -mpc32 -mpc64 -mpc80 -mstackrealign
*	-momit-leaf-frame-pointer -mno-red-zone -mno-tls-direct-seg-refs
*	-mcmodel=code-model -mabi=name
*	-m32 -m64 -mlarge-data-threshold=num
*	-msse2avx
*	IA-64 Options
*	-mbig-endian -mlittle-endian -mgnu-as -mgnu-ld -mno-pic
*	-mvolatile-asm-stop -mregister-names -msdata -mno-sdata
*	-mconstant-gp -mauto-pic -mfused-madd
*	-minline-float-divide-min-latency
*	-minline-float-divide-max-throughput
*	-mno-inline-float-divide
*	-minline-int-divide-min-latency
*	-minline-int-divide-max-throughput
*	-mno-inline-int-divide
*	-minline-sqrt-min-latency -minline-sqrt-max-throughput
*	-mno-inline-sqrt
*	-mdwarf2-asm -mearly-stop-bits
*	-mfixed-range=register-range -mtls-size=tls-size
*	-mtune=cpu-type -milp32 -mlp64
*	-msched-br-data-spec -msched-ar-data-spec -msched-control-spec
*	-msched-br-in-data-spec -msched-ar-in-data-spec -msched-in-control-spec
*	-msched-spec-ldc -msched-spec-control-ldc
*	-msched-prefer-non-data-spec-insns -msched-prefer-non-control-spec-insns
*	-msched-stop-bits-after-every-cycle -msched-count-spec-in-critical-path
*	-msel-sched-dont-check-control-spec -msched-fp-mem-deps-zero-cost
*	-msched-max-memory-insns-hard-limit -msched-max-memory-insns=max-insns
*	IA-64/VMS Options
*	-mvms-return-codes -mdebug-main=prefix -mmalloc64
*	LM32 Options
*	-mbarrel-shift-enabled -mdivide-enabled -mmultiply-enabled
*	-msign-extend-enabled -muser-enabled
*	M32R/D Options
*	-m32r2 -m32rx -m32r
*	-mdebug
*	-malign-loops -mno-align-loops
*	-missue-rate=number
*	-mbranch-cost=number
*	-mmodel=code-size-model-type
*	-msdata=sdata-type
*	-mno-flush-func -mflush-func=name
*	-mno-flush-trap -mflush-trap=number
*	-G num
*	M32C Options
*	-mcpu=cpu -msim -memregs=number
*	M680x0 Options
*	-march=arch -mcpu=cpu -mtune=tune -m68000 -m68020 -m68020-40 -m68020-60 -
*	m68030 -m68040
*	-m68060 -mcpu32 -m5200 -m5206e -m528x -m5307 -m5407
*	-mcfv4e -mbitfield -mno-bitfield -mc68000 -mc68020
*	-mnobitfield -mrtd -mno-rtd -mdiv -mno-div -mshort
*	-mno-short -mhard-float -m68881 -msoft-float -mpcrel
*	-malign-int -mstrict-align -msep-data -mno-sep-data
*	-mshared-library-id=n -mid-shared-library -mno-id-shared-library
*	-mxgot -mno-xgot
*	M68hc1x Options
*	-m6811 -m6812 -m68hc11 -m68hc12 -m68hcs12
*	-mauto-incdec -minmax -mlong-calls -mshort
*	-msoft-reg-count=count
*	MCore Options
*	-mhardlit -mno-hardlit -mdiv -mno-div -mrelax-immediates
*	-mno-relax-immediates -mwide-bitfields -mno-wide-bitfields
*	-m4byte-functions -mno-4byte-functions -mcallgraph-data
*	-mno-callgraph-data -mslow-bytes -mno-slow-bytes -mno-lsim
*	-mlittle-endian -mbig-endian -m210 -m340 -mstack-increment
*	MeP Options
*	-mabsdiff -mall-opts -maverage -mbased=n -mbitops
*	-mc=n -mclip -mconfig=name -mcop -mcop32 -mcop64 -mivc2
*	-mdc -mdiv -meb -mel -mio-volatile -ml -mleadz -mm -mminmax
*	-mmult -mno-opts -mrepeat -ms -msatur -msdram -msim -msimnovec -mtf
*	-mtiny=n
*	MIPS Options
*	-EL -EB -march=arch -mtune=arch
*	-mips1 -mips2 -mips3 -mips4 -mips32 -mips32r2
*	-mips64 -mips64r2
*	-mips16 -mips16e -mno-mips16 -mflip-mips16
*	-minterlink-mips16 -mno-interlink-mips16
*	-mabi=abi -mabicalls -mno-abicalls
*	-mshared -mno-shared -mplt -mno-plt -mxgot -mno-xgot
*	-mgp32 -mgp64 -mfp32 -mfp64 -mhard-float -msoft-float
*	-msingle-float -mdouble-float -mdsp -mno-dsp -mdspr2 -mno-dspr2
*	-mmicromips -mno-micromips -mmcu -mmno-mcu
*	-mfpu=fpu-type
*	-msmartmips -mno-smartmips
*	-mpaired-single -mno-paired-single -mdmx -mno-mdmx
*	-mips3d -mno-mips3d -mmt -mno-mt -mllsc -mno-llsc
*	-mlong64 -mlong32 -msym32 -mno-sym32
*	-Gnum -mlocal-sdata -mno-local-sdata
*	-mextern-sdata -mno-extern-sdata -mgpopt -mno-gopt
*	-membedded-data -mno-embedded-data
*	-muninit-const-in-rodata -mno-uninit-const-in-rodata
*	-mcode-readable=setting
*	-msplit-addresses -mno-split-addresses
*	-mexplicit-relocs -mno-explicit-relocs
*	-mcheck-zero-division -mno-check-zero-division
*	-mdivide-traps -mdivide-breaks
*	-mmemcpy -mno-memcpy -mlong-calls -mno-long-calls
*	-mjals -mno-jals
*	-mmad -mno-mad -mfused-madd -mno-fused-madd -nocpp
*	-mfix-r4000 -mno-fix-r4000 -mfix-r4400 -mno-fix-r4400
*	-mfix-r10000 -mno-fix-r10000 -mfix-vr4120 -mno-fix-vr4120
*	-mfix-vr4130 -mno-fix-vr4130 -mfix-sb1 -mno-fix-sb1
*	-mflush-func=func -mno-flush-func
*	-mbranch-cost=num -mbranch-likely -mno-branch-likely
*	-mfp-exceptions -mno-fp-exceptions
*	-mvr4130-align -mno-vr4130-align -msynci -mno-synci
*	-mrelax-pic-calls -mno-relax-pic-calls -mmcount-ra-address
*	MMIX Options
*	-mlibfuncs -mno-libfuncs -mepsilon -mno-epsilon -mabi=gnu
*	-mabi=mmixware -mzero-extend -mknuthdiv -mtoplevel-symbols
*	-melf -mbranch-predict -mno-branch-predict -mbase-addresses
*	-mno-base-addresses -msingle-exit -mno-single-exit
*	MN10300 Options
*	-mmult-bug -mno-mult-bug
*	-mam33 -mno-am33
*	-mam33-2 -mno-am33-2
*	-mreturn-pointer-on-d0
*	-mno-crt0 -mrelax
*	PDP-11 Options
*	-mfpu -msoft-float -mac0 -mno-ac0 -m40 -m45 -m10
*	-mbcopy -mbcopy-builtin -mint32 -mno-int16
*	-mint16 -mno-int32 -mfloat32 -mno-float64
*	-mfloat64 -mno-float32 -mabshi -mno-abshi
*	-mbranch-expensive -mbranch-cheap
*	-msplit -mno-split -munix-asm -mdec-asm
*	picoChip Options
*	-mae=ae_type -mvliw-lookahead=N -msymbol-as-address -mno-inefficient-warnings
*	PowerPC Options See RS/6000 and PowerPC Options.
*	RS/6000 and PowerPC Options
*	-mcpu=cpu-type
*	-mtune=cpu-type
*	-mpower -mno-power -mpower2 -mno-power2
*	-mpowerpc -mpowerpc64 -mno-powerpc
*	-maltivec -mno-altivec
*	-mpowerpc-gpopt -mno-powerpc-gpopt
*	-mpowerpc-gfxopt -mno-powerpc-gfxopt
*	-mmfcrf -mno-mfcrf -mpopcntb -mno-popcntb -mpopcntd -mno-popcntd
*	-mfprnd -mno-fprnd
*	-mcmpb -mno-cmpb -mmfpgpr -mno-mfpgpr -mhard-dfp -mno-hard-dfp
*	-mnew-mnemonics -mold-mnemonics
*	-mfull-toc -mminimal-toc -mno-fp-in-toc -mno-sum-in-toc
*	-m64 -m32 -mxl-compat -mno-xl-compat -mpe
*	-malign-power -malign-natural
*	-msoft-float -mhard-float -mmultiple -mno-multiple
*	-msingle-float -mdouble-float -msimple-fpu
*	-mstring -mno-string -mupdate -mno-update
*	-mavoid-indexed-addresses -mno-avoid-indexed-addresses
*	-mfused-madd -mno-fused-madd -mbit-align -mno-bit-align
*	-mstrict-align -mno-strict-align -mrelocatable
*	-mno-relocatable -mrelocatable-lib -mno-relocatable-lib
*	-mtoc -mno-toc -mlittle -mlittle-endian -mbig -mbig-endian
*	-mdynamic-no-pic -maltivec -mswdiv
*	-mprioritize-restricted-insns=priority
*
*	-msched-costly-dep=dependence_type
*	-minsert-sched-nops=scheme
*	-mcall-sysv -mcall-netbsd
*	-maix-struct-return -msvr4-struct-return
*	-mabi=abi-type -msecure-plt -mbss-plt
*	-mblock-move-inline-limit=num
*	-misel -mno-isel
*	-misel=yes -misel=no
*	-mspe -mno-spe
*	-mspe=yes -mspe=no
*	-mpaired
*	-mgen-cell-microcode -mwarn-cell-microcode
*	-mvrsave -mno-vrsave
*	-mmulhw -mno-mulhw
*	-mdlmzb -mno-dlmzb
*	-mfloat-gprs=yes -mfloat-gprs=no -mfloat-gprs=single -mfloat-gprs=double
*	-mprototype -mno-prototype
*	-msim -mmvme -mads -myellowknife -memb -msdata
*	-msdata=opt -mvxworks -G num -pthread
*	RX Options
*	-m64bit-doubles -m32bit-doubles -fpu -nofpu
*	-mcpu= -patch=
*	-mbig-endian-data -mlittle-endian-data
*	-msmall-data
*	-msim -mno-sim
*	-mas100-syntax -mno-as100-syntax
*	-mrelax
*	-mmax-constant-size=
*	-mint-register=
*	-msave-acc-in-interrupts
*	S/390 and zSeries Options
*	-mtune=cpu-type -march=cpu-type
*	-mhard-float -msoft-float -mhard-dfp -mno-hard-dfp
*	-mlong-double-64 -mlong-double-128
*	-mbackchain -mno-backchain -mpacked-stack -mno-packed-stack
*	-msmall-exec -mno-small-exec -mmvcle -mno-mvcle
*	-m64 -m31 -mdebug -mno-debug -mesa -mzarch
*	-mtpf-trace -mno-tpf-trace -mfused-madd -mno-fused-madd
*	-mwarn-framesize -mwarn-dynamicstack -mstack-size -mstack-guard
*	Score Options
*	-meb -mel
*	-mnhwloop
*	-muls
*	-mmac
*	-mscore5 -mscore5u -mscore7 -mscore7d
*	SH Options
*	-m1 -m2 -m2e
*	-m2a-nofpu -m2a-single-only -m2a-single -m2a
*	-m3 -m3e
*	-m4-nofpu -m4-single-only -m4-single -m4
*	-m4a-nofpu -m4a-single-only -m4a-single -m4a -m4al
*	-m5-64media -m5-64media-nofpu
*	-m5-32media -m5-32media-nofpu
*	-m5-compact -m5-compact-nofpu
*	-mb -ml -mdalign -mrelax
*	-mbigtable -mfmovd -mhitachi -mrenesas -mno-renesas -mnomacsave
*	-mieee -mbitops -misize -minline-ic_invalidate -mpadstruct -mspace
*	-mprefergot -musermode -multcost=number -mdiv=strategy
*	-mdivsi3_libfunc=name -mfixed-range=register-range
*	-madjust-unroll -mindexed-addressing -mgettrcost=number -mpt-fixed
*	-minvalid-symbols
*	SPARC Options
*	-mcpu=cpu-type
*	-mtune=cpu-type
*	-mcmodel=code-model
*	-m32 -m64 -mapp-regs -mno-app-regs
*	-mfaster-structs -mno-faster-structs
*	-mfpu -mno-fpu -mhard-float -msoft-float
*	-mhard-quad-float -msoft-quad-float
*	-mimpure-text -mno-impure-text -mlittle-endian
*	-mstack-bias -mno-stack-bias
*	-munaligned-doubles -mno-unaligned-doubles
*	-mv8plus -mno-v8plus -mvis -mno-vis -threads -pthreads -pthread
*	SPU Options
*	-mwarn-reloc -merror-reloc
*	-msafe-dma -munsafe-dma
*	-mbranch-hints
*	-msmall-mem -mlarge-mem -mstdmain
*	-mfixed-range=register-range
*	-mea32 -mea64
*	-maddress-space-conversion -mno-address-space-conversion
*	-mcache-size=cache-size
*	-matomic-updates -mno-atomic-updates
*	System V Options
*	-Qy -Qn -YP,paths -Ym,dir
*	V850 Options
*	-mlong-calls -mno-long-calls -mep -mno-ep
*	-mprolog-function -mno-prolog-function -mspace
*	-mtda=n -msda=n -mzda=n
*	-mapp-regs -mno-app-regs
*	-mdisable-callt -mno-disable-callt
*	-mv850e1
*	-mv850e
*	-mv850 -mbig-switch
*	VAX Options
*	-mg -mgnu -munix
*	VxWorks Options
*	-mrtp -non-static -Bstatic -Bdynamic
*	-Xbind-lazy -Xbind-now
*	x86-64 Options See i386 and x86-64 Options.
*	i386 and x86-64 Windows Options
*	-mconsole -mcygwin -mno-cygwin -mdll -mnop-fun-dllimport -mthread -municode -
*	mwin32 -mwindows -fno-set-stack-executable
*	Xstormy16 Options
*	-msim
*	Xtensa Options
*	-mconst16 -mno-const16
*	-mfused-madd -mno-fused-madd
*	-mserialize-volatile -mno-serialize-volatile
*	-mtext-section-literals -mno-text-section-literals
*	-mtarget-align -mno-target-align
*	-mlongcalls -mno-longcalls
*	zSeries Options See S/390 and zSeries Options.
 */

