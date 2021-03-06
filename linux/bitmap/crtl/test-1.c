#include <stdio.h>

#include "bitmap.h"
#include "bits_common.h"

_api int memshow(const void*in, int len)
{
    if(unlikely(!in))
        return -1;
    char _unused const *c = in;
    int i;
    for(i=0;i<len;i++, c++)
        printf("%02x ", (unsigned char)*c);
    printf("\n");
    return len;
}

static void demo_bitmap_test1()
{
    int nbits= 256;
    int byte=8;
    unsigned long * bm = bitmap_alloc(nbits);
    unsigned long * bm2 = bitmap_alloc(nbits);
    unsigned long * bm3 = bitmap_alloc(nbits);
    unsigned long * bm4 = bitmap_alloc(nbits);
    
    bitmap_zero(bm, nbits);
    memshow(bm, nbits/byte);

    bitmap_fill(bm, 128);

    bitmap_set(bm, 2, 200);
    bitmap_set(bm2, 150, 30);

    
    memshow(bm, nbits/byte);
    memshow(bm2, nbits/byte);

    bitmap_xor(bm3, bm2, bm, nbits);
    memshow(bm3, nbits/byte);

    bitmap_or(bm4, bm2, bm, nbits);
    memshow(bm4, nbits/byte);

    bitmap_complement(bm2, bm, nbits);
    memshow(bm2, nbits/byte);

    bitmap_clear(bm2, 200, 30);
    memshow(bm2, nbits/byte);

    
    print_warning("bitmap_and\n");
    unsigned long * bm5 = bitmap_alloc(nbits);
    bitmap_and(bm5, bm2, bm, nbits);
    memshow(bm2, nbits/byte);
    memshow(bm, nbits/byte);
    memshow(bm5, nbits/byte);

    print_warning("bitmap_or\n");
    unsigned long * bm6 = bitmap_alloc(nbits);
    bitmap_or(bm6, bm2, bm, nbits);
    memshow(bm2, nbits/byte);
    memshow(bm, nbits/byte);
    memshow(bm6, nbits/byte);
    
    print_warning("bitmap_xor\n");
    bitmap_xor(bm6, bm3, bm, nbits);
    memshow(bm3, nbits/byte);
    memshow(bm, nbits/byte);
    memshow(bm6, nbits/byte);

    
    print_warning("bitmap_andnot\n");
    bitmap_andnot(bm6, bm2, bm, nbits);
    memshow(bm2, nbits/byte);
    memshow(bm, nbits/byte);
    memshow(bm6, nbits/byte);

    
    
    bitmap_free(bm);
}


static void demo_bitmap_test2_equal()
{
    int nbits= 256;
    unsigned long * bm1 = bitmap_alloc(nbits);
    unsigned long * bm2 = bitmap_alloc(nbits);

    bitmap_set(bm1, 0, 200);
    bitmap_set(bm2, 0, 200);

    if(bitmap_equal(bm1, bm2, 200)) {
        print_info("bitmap_equal equal.\n");
    } else {
        print_info("bitmap_equal not equal.\n");
    
}


        

    
    unsigned long * bm3 = bitmap_alloc(nbits);
    unsigned long * bm4 = bitmap_alloc(nbits);
    unsigned long * bm5 = bitmap_alloc(nbits);
    
    bitmap_set(bm3, 0, 100);
    bitmap_set(bm4, 100, 200);
    bitmap_set(bm5, 0, 200);

    if(bitmap_or_equal(bm1, bm2,bm5, 200)) {
        print_info("bitmap_or_equal equal.\n");
    } else {
        print_info("bitmap_or_equal not equal.\n");
    
}


    
    unsigned long * bm6 = bitmap_alloc(nbits);
    unsigned long * bm7 = bitmap_alloc(nbits);

    bitmap_set(bm6, 0, 100);
    bitmap_set(bm7, 99, 200);
    if(bitmap_intersects(bm6, bm7, 200)) {
        print_info("bitmap_intersects ok.\n");
    } else {
        print_info("bitmap_intersects not ok.\n");
    
}

    memshow(bm6, nbits/8);
    memshow(bm7, nbits/8);

    
    print_warning("bitmap_subset\n");
    unsigned long * bm9 = bitmap_alloc(nbits);
    unsigned long * bm10 = bitmap_alloc(nbits);
    bitmap_set(bm9, 3, 200);
    bitmap_set(bm10, 3, 100);
    memshow(bm9, nbits/8);
    memshow(bm10, nbits/8);
    if(bitmap_subset(bm10, bm9, nbits)) {
        print_info("bitmap_subset ok.\n");
    } else {
        print_info("bitmap_subset not ok.\n");
    
}

    
    int w = bitmap_weight(bm9, nbits);
    print_info("__bitmap_weight %d.\n", w);
    memshow(bm9, nbits/8);


    
}

static void demo_bitmap_test3_complement()
{
    int nbits= 1024;
    unsigned long * bm1 = bitmap_alloc(nbits);
    unsigned long * bm2 = bitmap_alloc(nbits);

    
    bitmap_set(bm1, 0, 200);
    
    bitmap_complement(bm2, bm1, nbits);
    
    memshow(bm1, nbits/32);
    memshow(bm2, nbits/32);
    
    if(bitmap_equal(bm1, bm2, 200)) {
        print_info("bitmap_equal equal.\n");
    } else {
        print_info("bitmap_equal not equal.\n");
    
}
    
}

    
static void demo_bitmap_test_shift()
{
    int nbits= 256;
    unsigned long * bm1 = bitmap_alloc(nbits);
    unsigned long * bm2 = bitmap_alloc(nbits);

    
    bitmap_set(bm1, 0, 200);
    memshow(bm1, nbits/8);
    
    bitmap_shift_right(bm2, bm1, 50, nbits);
    memshow(bm2, nbits/8);
    
    bitmap_shift_left(bm2, bm1, 50, nbits);
    memshow(bm2, nbits/8);
    
}
static void demo_bitmap_test_cut()
{
    int nbits= 256;
    unsigned long * bm1 = bitmap_alloc(nbits);
    unsigned long * bm2 = bitmap_alloc(nbits);
    
    bitmap_set(bm1, 0, 200);
    bitmap_cut(bm2, bm1, 10, 40, nbits);
    
    memshow(bm1, nbits/8);
    memshow(bm2, nbits/8);
    
}

static void demo_bitmap_test_replace()
{
    int nbits= 256;
    unsigned long * bm1 = bitmap_alloc(nbits);
    unsigned long * bm2 = bitmap_alloc(nbits);
    unsigned long * bm3 = bitmap_alloc(nbits);
    unsigned long * bm4 = bitmap_alloc(nbits);
    
    bitmap_set(bm1, 0, 100);
    bitmap_set(bm2, 90, 100);
    bitmap_set(bm3, 10, 200);

    bitmap_replace(bm4, bm1, bm2, bm3, nbits);

    //old   ff ff ff ff ff ff ff ff ff ff ff ff 0f 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
    //new   00 00 00 00 00 00 00 00 00 00 00 fc ff ff ff ff ff ff ff ff ff ff ff 3f 00 00 00 00 00 00 00 00 
    //mask  00 fc ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff 03 00 00 00 00 00 
    //dst   ff 03 00 00 00 00 00 00 00 00 00 fc ff ff ff ff ff ff ff ff ff ff ff 3f 00 00 00 00 00 00 00 00

    memshow(bm1, nbits/8);
    memshow(bm2, nbits/8);
    memshow(bm3, nbits/8);
    memshow(bm4, nbits/8);
    
}

static void demo_bitmap_test_parse()
{
    int nbits= 256;
    unsigned long * bm1 = bitmap_alloc(nbits);
    bitmap_set(bm1, 0, 100);

    //01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 ff ff ff ff 01 00 00 00 
    //demo_bitmap.c:240 demo_bitmap_test_parse: Info: 1,ffffffff,1,1,1,1,1,1,
    char buf[1024] = {"1,ffffffff,1,1,1,1,1,1,"};
    bitmap_parse(buf, strlen(buf), bm1, nbits);
    memshow(bm1, nbits/8);
    print_info("%s\n", buf);

    unsigned long * bm2 = bitmap_alloc(nbits);
    memshow(bm2, nbits/8);
    char buf2[256] = {"0-128:2/12"};
    int ret;
    if((ret = bitmap_parselist(buf2, bm2, nbits))==0) {
        print_info("bitmap_parselist ok, %s, %d\n", buf2, ret);
    } else {
        print_info("bitmap_parselist not ok, %s\n", buf2);
    }
    memshow(bm2, nbits/8);

    
}


static void demo_bitmap_test_map()
{
    int nbits= 32;
    unsigned long * src1 = bitmap_alloc(nbits);
    unsigned long * dst1 = bitmap_alloc(nbits);
    unsigned long * old1 = bitmap_alloc(nbits);
    unsigned long * new1 = bitmap_alloc(nbits);
    
    bitmap_set(src1, 1, 1);
    bitmap_set(src1, 5, 1);
    bitmap_set(src1, 7, 1);
    bitmap_set(old1, 4, 3);
    bitmap_set(new1, 12, 3);

    print_info("bitmap_remap\n");
    bitmap_remap(dst1, src1, old1, new1, nbits);    
    memshow(dst1, nbits/8);
    memshow(src1, nbits/8);
    memshow(old1, nbits/8);
    memshow(new1, nbits/8);

    print_info("bitmap_bitremap\n");
    bitmap_bitremap(8, old1, new1, 200);
    memshow(old1, nbits/8);
    memshow(new1, nbits/8);
    
}


static void demo_bitmap_test_onto()
{
    int nbits= 32;
    unsigned long * src1 = bitmap_alloc(nbits);
    unsigned long * dst1 = bitmap_alloc(nbits);

}

static void demo_bitmap_test_from_arr32()
{
    int nbits= 64;
    unsigned long * bitmap = bitmap_alloc(nbits);

    uint32_t buf[2] = {0x12345678, 0xabcdef};
    
    bitmap_from_arr32(bitmap, buf, nbits);
    
    memshow(bitmap, nbits/8);
}


int main()
{
    demo_bitmap_test1();
    demo_bitmap_test2_equal();
    demo_bitmap_test3_complement();
    demo_bitmap_test_shift();
    demo_bitmap_test_cut();
    demo_bitmap_test_replace();
    demo_bitmap_test_parse();
    demo_bitmap_test_map();
    demo_bitmap_test_from_arr32();

    return 0;
}


