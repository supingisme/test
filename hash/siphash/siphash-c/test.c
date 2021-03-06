#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include <assert.h>

#include "siphash.h"

volatile int failures = 0;
jmp_buf failbuf;
//#define assert(expr) ((expr) || (failed(#expr, __FUNCTION__, __FILE__, __LINE__), 0))



static void
failed(const char *expr, const char *func, const char *file, int line)
{
    ++failures;
    fprintf(stderr, "Assertion failed: %s, function %s, file %s, line %d\n", expr, func, file, line);
    longjmp(failbuf, 1);
}

#define U32TO8_LE(p, v)			\
do {					\
    (p)[0] = (uint8_t)((v)      );	\
    (p)[1] = (uint8_t)((v) >>  8); 	\
    (p)[2] = (uint8_t)((v) >> 16);	\
    (p)[3] = (uint8_t)((v) >> 24);	\
} while (0)

#define U64TO8_LE(p, v) \
do {						\
    U32TO8_LE((p),     (uint32_t)((v)      )); 	\
    U32TO8_LE((p) + 4, (uint32_t)((v) >> 32));	\
} while (0)

static uint8_t SPEC_KEY[16] = {
   0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
   0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
};

static uint8_t SPEC_MSG[15] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e
};

/*
   SipHash-2-4 output with
   k = 00 01 02 ...
   and
   in = (empty string)
   in = 00 (1 byte)
   in = 00 01 (2 bytes)
   in = 00 01 02 (3 bytes)
   ...
   in = 00 01 02 ... 3e (63 bytes)
*/
static const uint8_t const SPEC_VECTORS[64][8] =
{
  { 0x31, 0x0e, 0x0e, 0xdd, 0x47, 0xdb, 0x6f, 0x72, },
  { 0xfd, 0x67, 0xdc, 0x93, 0xc5, 0x39, 0xf8, 0x74, },
  { 0x5a, 0x4f, 0xa9, 0xd9, 0x09, 0x80, 0x6c, 0x0d, },
  { 0x2d, 0x7e, 0xfb, 0xd7, 0x96, 0x66, 0x67, 0x85, },
  { 0xb7, 0x87, 0x71, 0x27, 0xe0, 0x94, 0x27, 0xcf, },
  { 0x8d, 0xa6, 0x99, 0xcd, 0x64, 0x55, 0x76, 0x18, },
  { 0xce, 0xe3, 0xfe, 0x58, 0x6e, 0x46, 0xc9, 0xcb, },
  { 0x37, 0xd1, 0x01, 0x8b, 0xf5, 0x00, 0x02, 0xab, },
  { 0x62, 0x24, 0x93, 0x9a, 0x79, 0xf5, 0xf5, 0x93, },
  { 0xb0, 0xe4, 0xa9, 0x0b, 0xdf, 0x82, 0x00, 0x9e, },
  { 0xf3, 0xb9, 0xdd, 0x94, 0xc5, 0xbb, 0x5d, 0x7a, },
  { 0xa7, 0xad, 0x6b, 0x22, 0x46, 0x2f, 0xb3, 0xf4, },
  { 0xfb, 0xe5, 0x0e, 0x86, 0xbc, 0x8f, 0x1e, 0x75, },
  { 0x90, 0x3d, 0x84, 0xc0, 0x27, 0x56, 0xea, 0x14, },
  { 0xee, 0xf2, 0x7a, 0x8e, 0x90, 0xca, 0x23, 0xf7, },
  { 0xe5, 0x45, 0xbe, 0x49, 0x61, 0xca, 0x29, 0xa1, },
  { 0xdb, 0x9b, 0xc2, 0x57, 0x7f, 0xcc, 0x2a, 0x3f, },
  { 0x94, 0x47, 0xbe, 0x2c, 0xf5, 0xe9, 0x9a, 0x69, },
  { 0x9c, 0xd3, 0x8d, 0x96, 0xf0, 0xb3, 0xc1, 0x4b, },
  { 0xbd, 0x61, 0x79, 0xa7, 0x1d, 0xc9, 0x6d, 0xbb, },
  { 0x98, 0xee, 0xa2, 0x1a, 0xf2, 0x5c, 0xd6, 0xbe, },
  { 0xc7, 0x67, 0x3b, 0x2e, 0xb0, 0xcb, 0xf2, 0xd0, },
  { 0x88, 0x3e, 0xa3, 0xe3, 0x95, 0x67, 0x53, 0x93, },
  { 0xc8, 0xce, 0x5c, 0xcd, 0x8c, 0x03, 0x0c, 0xa8, },
  { 0x94, 0xaf, 0x49, 0xf6, 0xc6, 0x50, 0xad, 0xb8, },
  { 0xea, 0xb8, 0x85, 0x8a, 0xde, 0x92, 0xe1, 0xbc, },
  { 0xf3, 0x15, 0xbb, 0x5b, 0xb8, 0x35, 0xd8, 0x17, },
  { 0xad, 0xcf, 0x6b, 0x07, 0x63, 0x61, 0x2e, 0x2f, },
  { 0xa5, 0xc9, 0x1d, 0xa7, 0xac, 0xaa, 0x4d, 0xde, },
  { 0x71, 0x65, 0x95, 0x87, 0x66, 0x50, 0xa2, 0xa6, },
  { 0x28, 0xef, 0x49, 0x5c, 0x53, 0xa3, 0x87, 0xad, },
  { 0x42, 0xc3, 0x41, 0xd8, 0xfa, 0x92, 0xd8, 0x32, },
  { 0xce, 0x7c, 0xf2, 0x72, 0x2f, 0x51, 0x27, 0x71, },
  { 0xe3, 0x78, 0x59, 0xf9, 0x46, 0x23, 0xf3, 0xa7, },
  { 0x38, 0x12, 0x05, 0xbb, 0x1a, 0xb0, 0xe0, 0x12, },
  { 0xae, 0x97, 0xa1, 0x0f, 0xd4, 0x34, 0xe0, 0x15, },
  { 0xb4, 0xa3, 0x15, 0x08, 0xbe, 0xff, 0x4d, 0x31, },
  { 0x81, 0x39, 0x62, 0x29, 0xf0, 0x90, 0x79, 0x02, },
  { 0x4d, 0x0c, 0xf4, 0x9e, 0xe5, 0xd4, 0xdc, 0xca, },
  { 0x5c, 0x73, 0x33, 0x6a, 0x76, 0xd8, 0xbf, 0x9a, },
  { 0xd0, 0xa7, 0x04, 0x53, 0x6b, 0xa9, 0x3e, 0x0e, },
  { 0x92, 0x59, 0x58, 0xfc, 0xd6, 0x42, 0x0c, 0xad, },
  { 0xa9, 0x15, 0xc2, 0x9b, 0xc8, 0x06, 0x73, 0x18, },
  { 0x95, 0x2b, 0x79, 0xf3, 0xbc, 0x0a, 0xa6, 0xd4, },
  { 0xf2, 0x1d, 0xf2, 0xe4, 0x1d, 0x45, 0x35, 0xf9, },
  { 0x87, 0x57, 0x75, 0x19, 0x04, 0x8f, 0x53, 0xa9, },
  { 0x10, 0xa5, 0x6c, 0xf5, 0xdf, 0xcd, 0x9a, 0xdb, },
  { 0xeb, 0x75, 0x09, 0x5c, 0xcd, 0x98, 0x6c, 0xd0, },
  { 0x51, 0xa9, 0xcb, 0x9e, 0xcb, 0xa3, 0x12, 0xe6, },
  { 0x96, 0xaf, 0xad, 0xfc, 0x2c, 0xe6, 0x66, 0xc7, },
  { 0x72, 0xfe, 0x52, 0x97, 0x5a, 0x43, 0x64, 0xee, },
  { 0x5a, 0x16, 0x45, 0xb2, 0x76, 0xd5, 0x92, 0xa1, },
  { 0xb2, 0x74, 0xcb, 0x8e, 0xbf, 0x87, 0x87, 0x0a, },
  { 0x6f, 0x9b, 0xb4, 0x20, 0x3d, 0xe7, 0xb3, 0x81, },
  { 0xea, 0xec, 0xb2, 0xa3, 0x0b, 0x22, 0xa8, 0x7f, },
  { 0x99, 0x24, 0xa4, 0x3c, 0xc1, 0x31, 0x57, 0x24, },
  { 0xbd, 0x83, 0x8d, 0x3a, 0xaf, 0xbf, 0x8d, 0xb7, },
  { 0x0b, 0x1a, 0x2a, 0x32, 0x65, 0xd5, 0x1a, 0xea, },
  { 0x13, 0x50, 0x79, 0xa3, 0x23, 0x1c, 0xe6, 0x60, },
  { 0x93, 0x2b, 0x28, 0x46, 0xe4, 0xd7, 0x06, 0x66, },
  { 0xe1, 0x91, 0x5f, 0x5c, 0xb1, 0xec, 0xa4, 0x6c, },
  { 0xf3, 0x25, 0x96, 0x5c, 0xa1, 0x6d, 0x62, 0x9f, },
  { 0x57, 0x5f, 0xf2, 0x8e, 0x60, 0x38, 0x1b, 0xe5, },
  { 0x72, 0x45, 0x06, 0xeb, 0x4c, 0x32, 0x8a, 0x95, }
};

static void
test_spec_streaming(void)
{
    sip_uint64_t digest64;
    sip_hash *h;

    assert(h = sip_hash_new(SPEC_KEY, 2, 4));
    assert(sip_hash_update(h, SPEC_MSG, 15));
    assert(sip_hash_final_integer(h, &digest64));

    sip_hash_free(h);
    uint64_t *p = &digest64;
    
    assert(*p == 0xa129ca6149be45e5ULL);
}

static void
test_spec_one_pass(void)
{
    sip_uint64_t digest64;
    sip_hash *h;

    assert(h = sip_hash_new(SPEC_KEY, 2, 4));
    assert(sip_hash_digest_integer(h, SPEC_MSG, 15, &digest64));
    sip_hash_free(h);
    printf("Spec: %" PRIx64 "\n", digest64);
    uint64_t *p = &digest64;
    assert(*p == 0xa129ca6149be45e5ULL);
}

static void
test_empty_string(void)
{
    sip_uint64_t digest64;
    sip_hash *h;

    assert(h = sip_hash_new(SPEC_KEY, 2, 4));
    assert(sip_hash_digest_integer(h, (uint8_t *) "", 0, &digest64));
    sip_hash_free(h);
    printf("Empty string: %" PRIx64 "\n", digest64);
    
    uint64_t *p = &digest64;
    assert(*p == 0x726fdb47dd0e0e31ULL);
}

static void
test_one_byte(void)
{
    sip_uint64_t digest64;
    sip_hash *h;

    assert(h = sip_hash_new(SPEC_KEY, 2, 4));
    assert(sip_hash_digest_integer(h, (uint8_t *) "a", 1, &digest64));
    sip_hash_free(h);
    printf("One byte (a): %" PRIx64 "\n", digest64);
    uint64_t *p = &digest64;
    assert(*p == 0x2ba3e8e9a71148caULL);
}

static void
test_six_bytes(void)
{
    sip_uint64_t digest64;
    sip_hash *h;

    assert(h = sip_hash_new(SPEC_KEY, 2, 4));
    assert(sip_hash_digest_integer(h, (uint8_t *) "abcdef", 6, &digest64));
    sip_hash_free(h);
    printf("Six bytes (abcdef): %" PRIx64 "\n", digest64);
    uint64_t *p = &digest64;
    assert(*p == 0x2a6e77e733c7c05dULL);
}

static void
test_seven_bytes(void)
{
    sip_uint64_t digest64;
    sip_hash *h;

    assert(h = sip_hash_new(SPEC_KEY, 2, 4));
    assert(sip_hash_digest_integer(h, (uint8_t *) "SipHash", 7, &digest64));
    sip_hash_free(h);
    printf("Seven bytes (SipHash): %" PRIx64 "\n", digest64);
    uint64_t *p = &digest64;
    assert(*p == 0x8325093242a96f60ULL);
}

static void
test_eight_bytes(void)
{
    sip_uint64_t digest64;
    sip_hash *h;

    assert(h = sip_hash_new(SPEC_KEY, 2, 4));
    assert(sip_hash_digest_integer(h, (uint8_t *) "12345678", 8, &digest64));
    sip_hash_free(h);
    printf("Eight bytes (12345678): %" PRIx64 "\n", digest64);
    uint64_t *p = &digest64;
    assert(*p == 0x2130609caea37ebULL);
}

static void
test_one_mio_zero_bytes(void)
{
    sip_uint64_t digest64;
    uint8_t msg[1000000];
    sip_hash *h;

    memset(msg, 0, 1000000);
    assert(h = sip_hash_new(SPEC_KEY, 2, 4));
    assert(sip_hash_digest_integer(h, msg, 1000000, &digest64));
    sip_hash_free(h);
    printf("One million zero bytes: %" PRIx64 "\n", digest64);
    uint64_t *p = &digest64;
    assert(*p == 0x28205108397aa742ULL);
}

static void
test_reference_vectors(void) {
    uint8_t *digest;
    size_t digest_len;
    uint8_t msg[64];
    sip_hash *h;
    int i;

    for(i = 0; i < 64; ++i) {
        msg[i] = i;
        assert(h = sip_hash_new(SPEC_KEY, 2, 4));
    	sip_hash_digest(h, msg, i, &digest, &digest_len);
        assert(digest_len == sizeof(sip_uint64_t));
        assert(!memcmp(SPEC_VECTORS[i], digest, 8));
        sip_hash_free(h);
        free(digest);
    }
}

static void
test_24_spec(void)
{
    sip_uint64_t digest64;

    digest64 = sip_hash24(SPEC_KEY, SPEC_MSG, 15);
    printf("sip_hash24 spec: %" PRIx64 "\n", digest64);
    uint64_t *p = &digest64;
    assert(*p == 0xa129ca6149be45e5ULL);
}

static void
test_24_empty_string(void)
{
    sip_uint64_t digest64;

    digest64 = sip_hash24(SPEC_KEY, (uint8_t *) "", 0);
    printf("sip_hash24 empty string: %" PRIx64 "\n", digest64);
    uint64_t *p = &digest64;
    assert(*p == 0x726fdb47dd0e0e31ULL);
}

static void
test_24_one_byte(void)
{
    sip_uint64_t digest64;

    digest64 = sip_hash24(SPEC_KEY, (uint8_t *) "a", 1);
    printf("sip_hash24 one byte (a): %" PRIx64 "\n", digest64);
    uint64_t *p = &digest64;
    assert(*p == 0x2ba3e8e9a71148caULL);
}

static void
test_24_six_bytes(void)
{
    sip_uint64_t digest64;

    digest64 = sip_hash24(SPEC_KEY, (uint8_t *) "abcdef", 6);
    printf("sip_hash24 six bytes (a): %" PRIx64 "\n", digest64);
    uint64_t *p = &digest64;
    assert(*p == 0x2a6e77e733c7c05dULL);
}

static void
test_24_seven_bytes(void)
{
    sip_uint64_t digest64;

    digest64 = sip_hash24(SPEC_KEY, (uint8_t *) "SipHash", 7);
    printf("sip_hash24 seven bytes (SipHash): %" PRIx64 "\n", digest64);
    uint64_t *p = &digest64;
    assert(*p == 0x8325093242a96f60ULL);
}

static void
test_24_eight_bytes(void)
{
    sip_uint64_t digest64;

    digest64 = sip_hash24(SPEC_KEY, (uint8_t *) "12345678", 8);
    printf("sip_hash24 eight bytes (12345678): %" PRIx64 "\n", digest64);
    uint64_t *p = &digest64;
    assert(*p == 0x2130609caea37ebULL);
}

static void
test_24_one_mio_zero_bytes(void)
{
    sip_uint64_t digest64;
    uint8_t msg[1000000];

    memset(msg, 0, 1000000);
    digest64 = sip_hash24(SPEC_KEY, msg, 1000000);
    printf("sip_hash24 one million zero bytes: %" PRIx64 "\n", digest64);
    uint64_t *p = &digest64;
    assert(*p  == 0x28205108397aa742ULL);
}

static void
test_24_reference_vectors(void)
{
    sip_uint64_t digest64;
    uint8_t msg[64];
    uint8_t digest[sizeof(sip_uint64_t)];
    int i;

    for(i = 0; i < 64; ++i) {
        msg[i] = i;
        digest64 = sip_hash24(SPEC_KEY, msg, i);
        uint64_t *p = &digest64;
        U64TO8_LE(digest, *p);
        assert(!memcmp(SPEC_VECTORS[i], digest, 8));
    }
}

int main(int argc, char **argv) {
    static void (*const funcs[])(void) = {
	test_spec_streaming,
	test_spec_one_pass,

	test_empty_string,
	test_one_byte,
	test_six_bytes,
	test_seven_bytes,
	test_eight_bytes,
	//test_fifteen_bytes, tested by the spec
	test_one_mio_zero_bytes,
	test_reference_vectors,

	test_24_spec,

	test_24_empty_string,
	test_24_one_byte,
	test_24_six_bytes,
	test_24_seven_bytes,
	test_24_eight_bytes,
	//test_24_fifteen_bytes, tested by the spec
	test_24_one_mio_zero_bytes,
	test_24_reference_vectors,
    };
    volatile int done = 0;

    setjmp(failbuf);
    while (done < (int)(sizeof(funcs) / sizeof(funcs[0]))) {
	int i = done++;
	(*funcs[i])();
    }
    if (failures) {
	fprintf(stderr, "%d failures\n", failures);
	return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
