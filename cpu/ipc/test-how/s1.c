void main() {
    unsigned long sum = 0, i = 0;
    for (i = 0; i < 0x10000000; i += 1) {
        sum += i;
    }
}
