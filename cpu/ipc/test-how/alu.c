void main() {
    while(1) {
        __asm__ (
            "movq $0x0,%rax\n\t"
            "movq $0xa,%rbx\n\t"
            "andq $0x12345678,%rbx\n\t"
            "orq  $0x12345678,%rbx\n\t"
            "shlq $0x2,%rbx\n\t"
            "addq %rbx,%rax\n\t"
            "subq $0x14,%rax\n\t"
            "movq %rax,%rcx");
    }
}
