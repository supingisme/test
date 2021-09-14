# Assembly

## MacOS

### Environments

Assume to be x86-64:


```bash
% uname -a
Darwin Kenta-Nakajima-no-MacBook-Pro.local 15.6.0 Darwin Kernel Version 15.6.0: Sun Jun  4 21:43:07 PDT 2017; root:xnu-3248.70.3~1/RELEASE_X86_64 x86_64
% sysctl -a machdep.cpu
machdep.cpu.max_basic: 20
machdep.cpu.max_ext: 2147483656
machdep.cpu.vendor: GenuineIntel
machdep.cpu.brand_string: Intel(R) Core(TM) i5-5257U CPU @ 2.70GHz
machdep.cpu.family: 6
machdep.cpu.model: 61
machdep.cpu.extmodel: 3
machdep.cpu.extfamily: 0
machdep.cpu.stepping: 4
machdep.cpu.feature_bits: 9221959987971750911
machdep.cpu.leaf7_feature_bits: 35399595
machdep.cpu.extfeature_bits: 1241984796928
machdep.cpu.signature: 198356
machdep.cpu.brand: 0
machdep.cpu.features: FPU VME DE PSE TSC MSR PAE MCE CX8 APIC SEP MTRR PGE MCA CMOV PAT PSE36 CLFSH DS ACPI MMX FXSR SSE SSE2 SS HTT TM PBE SSE3 PCLMULQDQ DTES64 MON DSCPL VMX EST TM2 SSSE3 FMA CX16 TPR PDCM SSE4.1 SSE4.2 x2APIC MOVBE POPCNT AES PCID XSAVE OSXSAVE SEGLIM64 TSCTMR AVX1.0 RDRAND F16C
machdep.cpu.leaf7_features: SMEP ERMS RDWRFSGS TSC_THREAD_OFFSET BMI1 AVX2 BMI2 INVPCID SMAP RDSEED ADX IPT FPU_CSDS
machdep.cpu.extfeatures: SYSCALL XD 1GBPAGE EM64T LAHF LZCNT PREFETCHW RDTSCP TSCI
machdep.cpu.logical_per_package: 16
machdep.cpu.cores_per_package: 8
machdep.cpu.microcode_version: 33
machdep.cpu.processor_flag: 6
machdep.cpu.mwait.linesize_min: 64
machdep.cpu.mwait.linesize_max: 64
machdep.cpu.mwait.extensions: 3
machdep.cpu.mwait.sub_Cstates: 286531872
machdep.cpu.thermal.sensor: 1
machdep.cpu.thermal.dynamic_acceleration: 1
machdep.cpu.thermal.invariant_APIC_timer: 1
machdep.cpu.thermal.thresholds: 2
machdep.cpu.thermal.ACNT_MCNT: 1
machdep.cpu.thermal.core_power_limits: 1
machdep.cpu.thermal.fine_grain_clock_mod: 1
machdep.cpu.thermal.package_thermal_intr: 1
machdep.cpu.thermal.hardware_feedback: 0
machdep.cpu.thermal.energy_policy: 1
machdep.cpu.xsave.extended_state: 7 832 832 0
machdep.cpu.xsave.extended_state1: 1 0 0 0
machdep.cpu.arch_perf.version: 3
machdep.cpu.arch_perf.number: 4
machdep.cpu.arch_perf.width: 48
machdep.cpu.arch_perf.events_number: 7
machdep.cpu.arch_perf.events: 0
machdep.cpu.arch_perf.fixed_number: 3
machdep.cpu.arch_perf.fixed_width: 48
machdep.cpu.cache.linesize: 64
machdep.cpu.cache.L2_associativity: 8
machdep.cpu.cache.size: 256
machdep.cpu.tlb.inst.large: 8
machdep.cpu.tlb.data.small: 64
machdep.cpu.tlb.data.small_level1: 64
machdep.cpu.address_bits.physical: 39
machdep.cpu.address_bits.virtual: 48
machdep.cpu.core_count: 2
machdep.cpu.thread_count: 4
machdep.cpu.tsc_ccc.numerator: 0
machdep.cpu.tsc_ccc.denominator: 0
% nasm -v
NASM version 2.13.03 compiled on Feb  8 2018
% nasm -hf
// skip

valid output formats for -f are (`*' denotes default):
  * bin       flat-form binary files (e.g. DOS .COM, .SYS)
    ith       Intel hex
    srec      Motorola S-records
    aout      Linux a.out object files
    aoutb     NetBSD/FreeBSD a.out object files
    coff      COFF (i386) object files (e.g. DJGPP for DOS)
    elf32     ELF32 (i386) object files (e.g. Linux)
    elf64     ELF64 (x86_64) object files (e.g. Linux)
    elfx32    ELFX32 (x86_64) object files (e.g. Linux)
    as86      Linux as86 (bin86 version 0.3) object files
    obj       MS-DOS 16-bit/32-bit OMF object files
    win32     Microsoft Win32 (i386) object files
    win64     Microsoft Win64 (x86-64) object files
    rdf       Relocatable Dynamic Object File Format v2.0
    ieee      IEEE-695 (LADsoft variant) object file format
    macho32   NeXTstep/OpenStep/Rhapsody/Darwin/MacOS X (i386) object files
    macho64   NeXTstep/OpenStep/Rhapsody/Darwin/MacOS X (x86_64) object files
    dbg       Trace of all info passed to output stage
    elf       ELF (short name for ELF32)
    macho     MACHO (short name for MACHO32)
    win       WIN (short name for WIN32)
```

We can compile with `nasm`, which can be installed via Homebrew. Here is the way to compile `.asm` file:

```bash
nasm -f macho64 hello.asm && ld -o res hello.o && ./res
```

### Registers

+ General purpose Registers(GPR) is as follows:

|alias|Registers name|Description|Kernel interface Arguments|User-level application Arguments|stack cleanup by|
|---|---|---|---|---|---|
|rax--eax--ax--al|r0|Kind of an 'accumulator'. Returning `syscall`, it's `-errno`|ID||caller|
|rbx--ebx--bx--bl|r3|Base register|||callee|
|rcx--ecx--cx--cl|r1|Used for cycles(e.g. loop), It was changed by `syscall` instruction||**4**|caller|
|rdx--edx--dx--dl|r2|Store data during input/output operations|3|3|caller|
|rsi--esi--si--sil|r6|Source index in string manipulatinon commands (e.g `movsd`)|2|2|caller|
|rdi--edi--di--dil|r7|Destination index in string manipulation commands|1|1|caller|
|rbp--ebp--bp--bpl|r5|Stack frame's base|||callee|
|rsp--esp--sp--spl|r4|Stores the address of the topmost element in the hardware stack|||callee|
||r8--r8d--r8w--r8b||5|5|caller|
||r9||6|6|caller|
||r10|sometimes save the CPU flag when syscall instruction is executed|4||caller|
||r11|changed by `syscall` instruction|||caller|
||r12||||callee|
||r13||||callee|
||r14||||callee|
||r15||||callee|

Note1) Command line arguments are on the stack, which is argc in the head.
Note2) For the terminology, Calling conventions, see [mpx-linux64-abi.pdf](https://software.intel.com/sites/default/files/article/402129/mpx-linux64-abi.pdf)

Note3) Caller-saved-registers should be saved before invoking a function and restored after. Here is an example:

```asm
section .text
  global _start
_start:
  ; snip
  push rdi
  push rsi
  add rsi, 8
  call func
  pop rsi
  pop rdi
  ; snip
func:
  ; snip
```

+ other registers is as follows:

|alias|Description|
|---|---|
|rsp|(ext)Instruction Pointer. It stores address of the next instruction to be executed|
|rflags|(ext)Program Status and Control Register|
|CS, DS, ES, SS, FS, and GS| segment registers|

For more information, see chapter3 in `Intel® 64 and IA-32 Architectures Software Developer’s Manual`

### references

+ The gist page, https://gist.github.com/FiloSottile/7125822, describes the brief code and some references for MacOS.

+ https://opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master ( Note: MacOS (xnu) BSD syscall numbers are pretty different from Linux based x64 syscall, https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl. )

+ The table-formatted version of the above link is https://sigsegv.pl/osx-bsd-syscalls/.

## ubuntu

### Setup docker

```bash
# When using docker itself
$ docker build -t nasm_study . # t .. tagged
# `--privileged` option avoids `Operation not permitted` error
$ docker run -it --privileged --rm -v $(pwd):/usr/src nasm_study # --rm : remote automatically when exit container.
root@77a18ca7c730:/# cd /usr/src/ubuntu
root@77a18ca7c730:/# nasm -f elf64 hello_world.asm
root@77a18ca7c730:/# ld -o res hello_world.o
root@77a18ca7c730:/# ./res
hello world # Also, you can use readelf, hexdump to analyze ELF file!
```

### Environments

```bash
# uname -a
Linux bcd9df7291e8 4.9.87-linuxkit-aufs #1 SMP Wed Mar 14 15:12:16 UTC 2018 x86_64 x86_64 x86_64 GNU/Linux
# cat /proc/cpuinfo
processor	: 0
vendor_id	: GenuineIntel
cpu family	: 6
model		: 61
model name	: Intel(R) Core(TM) i5-5257U CPU @ 2.70GHz
stepping	: 4
cpu MHz		: 2697.899
cache size	: 3072 KB
physical id	: 0
siblings	: 1
core id		: 0
cpu cores	: 1
apicid		: 0
initial apicid	: 0
fpu		: yes
fpu_exception	: yes
cpuid level	: 20
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ss ht pbe syscall nx pdpe1gb lm constant_tsc rep_good nopl xtopology nonstop_tsc eagerfpu pni pclmulqdq dtes64 ds_cpl ssse3 sdbg fma cx16 xtpr pcid sse4_1 sse4_2 movbe popcnt aes xsave avx f16c rdrand hypervisor lahf_lm abm 3dnowprefetch kaiser fsgsbase bmi1 avx2 bmi2 erms xsaveopt arat
bugs		: cpu_meltdown spectre_v1 spectre_v2
bogomips	: 5395.79
clflush size	: 64
cache_alignment	: 64
address sizes	: 39 bits physical, 48 bits virtual
power management:

processor	: 1
vendor_id	: GenuineIntel
cpu family	: 6
model		: 61
model name	: Intel(R) Core(TM) i5-5257U CPU @ 2.70GHz
stepping	: 4
cpu MHz		: 2697.899
cache size	: 3072 KB
physical id	: 1
siblings	: 1
core id		: 0
cpu cores	: 1
apicid		: 1
initial apicid	: 1
fpu		: yes
fpu_exception	: yes
cpuid level	: 20
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ss ht pbe syscall nx pdpe1gb lm constant_tsc rep_good nopl xtopology nonstop_tsc eagerfpu pni pclmulqdq dtes64 ds_cpl ssse3 sdbg fma cx16 xtpr pcid sse4_1 sse4_2 movbe popcnt aes xsave avx f16c rdrand hypervisor lahf_lm abm 3dnowprefetch kaiser fsgsbase bmi1 avx2 bmi2 erms xsaveopt arat
bugs		: cpu_meltdown spectre_v1 spectre_v2
bogomips	: 5200.21
clflush size	: 64
cache_alignment	: 64
address sizes	: 39 bits physical, 48 bits virtual
power management:
# cat /proc/meminfo
MemTotal:        2046940 kB
MemFree:          253272 kB
MemAvailable:    1656672 kB
Buffers:           65904 kB
Cached:          1438016 kB
SwapCached:            0 kB
Active:           341100 kB
Inactive:        1348348 kB
Active(anon):     172048 kB
Inactive(anon):    14736 kB
Active(file):     169052 kB
Inactive(file):  1333612 kB
Unevictable:           0 kB
Mlocked:               0 kB
SwapTotal:       1048572 kB
SwapFree:        1048572 kB
Dirty:                 0 kB
Writeback:             0 kB
AnonPages:        181492 kB
Mapped:            88412 kB
Shmem:              1260 kB
Slab:              83084 kB
SReclaimable:      65060 kB
SUnreclaim:        18024 kB
KernelStack:        4688 kB
PageTables:         1796 kB
NFS_Unstable:          0 kB
Bounce:                0 kB
WritebackTmp:          0 kB
CommitLimit:     2072040 kB
Committed_AS:     495492 kB
VmallocTotal:   34359738367 kB
VmallocUsed:           0 kB
VmallocChunk:          0 kB
AnonHugePages:         0 kB
ShmemHugePages:        0 kB
ShmemPmdMapped:        0 kB
HugePages_Total:       0
HugePages_Free:        0
HugePages_Rsvd:        0
HugePages_Surp:        0
Hugepagesize:       2048 kB
DirectMap4k:       52652 kB
DirectMap2M:     2043904 kB
DirectMap1G:           0 kB
# nasm -v
NASM version 2.13.02
```


Like MacOS, `.asm` file compiled via `nasm` except replacing `-o macho64` with `-o elf64`:

```bash
nasm -f elf64 hello.asm && ld -o res hello.o && ./res
# options
; -E file.asm .. preprocess file.asm
; -d flag .. support `%ifdef flag` variable
```

### References

+ https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl

+ http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/

+ http://refspecs.linux-foundation.org/ .. Linux Standard Base (LSB), Single UNIX Specification(SUS), Debug With Attributed Record Format (DWARF), Executable and Linking Format (ELF), Application Binary Interface (ABI) standards reference

+ Intel® 64 and IA-32 Architectures Software Developer’s Manual, https://software.intel.com/en-us/download/intel-64-and-ia-32-architectures-sdm-combined-volumes-1-2a-2b-2c-2d-3a-3b-3c-3d-and-4

+ Linux Cross Reference (lxr) online, https://elixir.bootlin.com/linux/latest/source

+ x86, x86_64 opcode and Instruction Reference .. http://ref.x86asm.net/

## Brief introduction to gdb

The debugger, gdb is to allow you to see what's going on inside step by step.

### Install

```bash
$ sudo apt-get upgrade
$ sudo apt-get install gdb
```

### Usage

```bash
# Assume that `./res` is executable file
$ gdb ./res
# To display assembly as intel syntax, put `set disassembly-flavor intel` in the `~/.gdbinit` file
(gdb) break _start
(gdb) start # type n to make breakpoint
# I recommend to enter TUI-mode.
# Type `Ctrl-X + 2` twice and you can see the register information(same as `layout regs`) and the assembly information (`layout asm`)
(gdb) si # have fun!
```

### command

+ si(stepi) .. step unit instruction
+ x [address] .. display address information
  + x &text ; display text global variables

### examples

+ The `print` command displays content, whereas `x` command displays address itself.

```asm
section .data
  text db "hello world", 10

section .text
  global _start
_start:
  mov rax, 1
  mov rdi, 1
  mov rsi, text
  mov rdx, 13
  syscall

  mov rax, 60
  mov rdi, 0
  syscall
```

Note) Note: 64-bit x86 uses syscall instead of interrupt 0x80(`int 0x80`).

```bash
# move the exec before `mov rdx, 13`.
(gdb) print $rsi
$1 = 6291672
(gdb) x $rsi
0x6000d8:       0x6c6c6568
(gdb) x /s $rsi
0x6000d8:       "hello world\n"
(gdb) print text
$2 = 1819043176
(gdb) x text
0x6c6c6568:     <error: Cannot access memory at address 0x6c6c6568>
(gdb) x /s text
0x6c6c6568:     <error: Cannot access memory at address 0x6c6c6568>
(gdb) x &text
0x6000d8:       "hello world\n"
```

## GNU Assembler (GAS)

+ GAS supports AT&T syntax, which is quite differnt from Intel syntax. See https://www.ibm.com/developerworks/library/l-gas-nasm/index.html. For Japanese only, this page, http://caspar.hazymoon.jp/OpenBSD/annex/gas.html is also useful.

+ Quick reference .. https://en.wikibooks.org/wiki/X86_Assembly/GAS_Syntax#Quick_reference

+ complete reference .. https://sourceware.org/binutils/docs/as/

### assemble and link

```bash
# as command contains in binutils
# without o command, a.out file is output.
as -o hello.o hello.s
ld -o hello hello.o
./hello
```
