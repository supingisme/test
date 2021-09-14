void main() {
    unsigned long sum = 0, a = 0, b = 0, c = 0, d = 0;
    register unsigned long i = 0;
    for (i = 0; i < 0x10000000; i += 4) {
        a += i; b += i + 1; c += i + 2; d += i + 3;
    }
    sum = a + b + c + d;
}
