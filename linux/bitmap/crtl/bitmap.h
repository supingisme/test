#ifndef __BITS_BITMAP_H 
#define __BITS_BITMAP_H 1
 
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

#include "bits_find.h"


 /**
  * DOC: bitmap overview
  *
  * The available bitmap operations and their rough meaning in the
  * case that the bitmap is a single unsigned long are thus:
  *
  * The generated code is more efficient when nbits is known at
  * compile-time and at most BITS_PER_LONG.
  *
  * ::
  *
  *  bitmap_zero(dst, nbits)                     *dst = 0UL
  *  bitmap_fill(dst, nbits)                     *dst = ~0UL
  *  bitmap_copy(dst, src, nbits)                *dst = *src
  *  bitmap_and(dst, src1, src2, nbits)          *dst = *src1 & *src2
  *  bitmap_or(dst, src1, src2, nbits)           *dst = *src1 | *src2
  *  bitmap_xor(dst, src1, src2, nbits)          *dst = *src1 ^ *src2
  *  bitmap_andnot(dst, src1, src2, nbits)       *dst = *src1 & ~(*src2)
  *  bitmap_complement(dst, src, nbits)          *dst = ~(*src)
  *  bitmap_equal(src1, src2, nbits)             Are *src1 and *src2 equal?
  *  bitmap_intersects(src1, src2, nbits)        Do *src1 and *src2 overlap?
  *  bitmap_subset(src1, src2, nbits)            Is *src1 a subset of *src2?
  *  bitmap_empty(src, nbits)                    Are all bits zero in *src?
  *  bitmap_full(src, nbits)                     Are all bits set in *src?
  *  bitmap_weight(src, nbits)                   Hamming Weight: number set bits
  *  bitmap_set(dst, pos, nbits)                 Set specified bit area
  *  bitmap_clear(dst, pos, nbits)               Clear specified bit area
  *  bitmap_find_next_zero_area(buf, len, pos, n, mask)  Find bit free area
  *  bitmap_find_next_zero_area_off(buf, len, pos, n, mask)  as above
  *  bitmap_shift_right(dst, src, n, nbits)      *dst = *src >> n
  *  bitmap_shift_left(dst, src, n, nbits)       *dst = *src << n
  *  bitmap_cut(dst, src, first, n, nbits)       Cut n bits from first, copy rest
  *  bitmap_replace(dst, old, new, mask, nbits)  *dst = (*old & ~(*mask)) | (*new & *mask)
  *  bitmap_remap(dst, src, old, new, nbits)     *dst = map(old, new)(src)
  *  bitmap_bitremap(oldbit, old, new, nbits)    newbit = map(old, new)(oldbit)
  *  bitmap_onto(dst, orig, relmap, nbits)       *dst = orig relative to relmap
  *  bitmap_fold(dst, orig, sz, nbits)           dst bits = orig bits mod sz
  *  bitmap_parse(buf, buflen, dst, nbits)       Parse bitmap dst from kernel buf
  *  bitmap_parse_user(ubuf, ulen, dst, nbits)   Parse bitmap dst from user buf
  *  bitmap_parselist(buf, dst, nbits)           Parse bitmap dst from kernel buf
  *  bitmap_parselist_user(buf, dst, nbits)      Parse bitmap dst from user buf
  *  bitmap_find_free_region(bitmap, bits, order)  Find and allocate bit region
  *  bitmap_release_region(bitmap, pos, order)   Free specified bit region
  *  bitmap_allocate_region(bitmap, pos, order)  Allocate specified bit region
  *  bitmap_from_arr32(dst, buf, nbits)          Copy nbits from u32[] buf to dst
  *  bitmap_to_arr32(buf, src, nbits)            Copy nbits from buf to u32[] dst
  *  bitmap_get_value8(map, start)               Get 8bit value from map at start
  *  bitmap_set_value8(map, value, start)        Set 8bit value to map at start
  *
  * Note, bitmap_zero() and bitmap_fill() operate over the region of
  * unsigned longs, that is, bits behind bitmap till the unsigned long
  * boundary will be zeroed or filled as well. Consider to use
  * bitmap_clear() or bitmap_set() to make explicit zeroing or filling
  * respectively.
  */
 
 /**
  * DOC: declare bitmap
  * The DECLARE_BITMAP(name,bits) macro, in linux/types.h, can be used
  * to declare an array named 'name' of just enough unsigned longs to
  * contain all bit positions from 0 to 'bits' - 1.
  */
 
 /*
  * Allocation and deallocation of bitmap.
  * Provided in lib/bitmap.c to avoid circular dependency.
  */
 unsigned long *bitmap_alloc(unsigned int nbits);
 void bitmap_free(unsigned long *bitmap);
 
 
 /**
  * bitmap_cut() - remove bit region from bitmap and right shift remaining bits
  * @dst: destination bitmap, might overlap with src
  * @src: source bitmap
  * @first: start bit of region to be removed
  * @cut: number of bits to remove
  * @nbits: bitmap size, in bits
  *
  * Set the n-th bit of @dst iff the n-th bit of @src is set and
  * n is less than @first, or the m-th bit of @src is set for any
  * m such that @first <= n < nbits, and m = n + @cut.
  *
  * In pictures, example for a big-endian 32-bit architecture:
  *
  * @src:
  * 31                                   63
  * |                                    |
  * 10000000 11000001 11110010 00010101  10000000 11000001 01110010 00010101
  *                 |  |              |                                    |
  *                16  14             0                                   32
  *
  * if @cut is 3, and @first is 14, bits 14-16 in @src are cut and @dst is:
  *
  * 31                                   63
  * |                                    |
  * 10110000 00011000 00110010 00010101  00010000 00011000 00101110 01000010
  *                    |              |                                    |
  *                    14 (bit 17     0                                   32
  *                        from @src)
  *
  * Note that @dst and @src might overlap partially or entirely.
  *
  * This is implemented in the obvious way, with a shift and carry
  * step for each moved bit. Optimisation is left as an exercise
  * for the compiler.
  */
 void bitmap_cut(unsigned long *dst, const unsigned long *src, unsigned int first, unsigned int cut, unsigned int nbits);
 
 
 
 /**
  * bitmap_find_next_zero_area_off - find a contiguous aligned zero area
  * @map: The address to base the search on
  * @size: The bitmap size in bits
  * @start: The bitnumber to start searching at
  * @nr: The number of zeroed bits we're looking for
  * @align_mask: Alignment mask for zero area
  * @align_offset: Alignment offset for zero area.
  *
  * The @align_mask should be one less than a power of 2; the effect is that
  * the bit offset of all zero areas this function finds plus @align_offset
  * is multiple of that power of 2.
  */
 unsigned long bitmap_find_next_zero_area_off(unsigned long *map, unsigned long size,
                                                 unsigned long start, unsigned int nr, unsigned long align_mask,
                                                 unsigned long align_offset);
 
 /**
  * bitmap_find_next_zero_area - find a contiguous aligned zero area
  * @map: The address to base the search on
  * @size: The bitmap size in bits
  * @start: The bitnumber to start searching at
  * @nr: The number of zeroed bits we're looking for
  * @align_mask: Alignment mask for zero area
  *
  * The @align_mask should be one less than a power of 2; the effect is that
  * the bit offset of all zero areas this function finds is multiples of that
  * power of 2. A @align_mask of 0 means no alignment is required.
  */
 inline unsigned long bitmap_find_next_zero_area(unsigned long *map, unsigned long size,
                                     unsigned long start, unsigned int nr, unsigned long align_mask);
 
 /**
  * bitmap_parse - convert an ASCII hex string into a bitmap.
  * @start: pointer to buffer containing string.
  * @buflen: buffer size in bytes.  If string is smaller than this
  *    then it must be terminated with a \0 or \n. In that case,
  *    UINT_MAX may be provided instead of string length.
  * @maskp: pointer to bitmap array that will contain result.
  * @nmaskbits: size of bitmap, in bits.
  *
  * Commas group hex digits into chunks.  Each chunk defines exactly 32
  * bits of the resultant bitmask.  No chunk may specify a value larger
  * than 32 bits (%-EOVERFLOW), and if a chunk specifies a smaller value
  * then leading 0-bits are prepended.  %-EINVAL is returned for illegal
  * characters. Grouping such as "1,,5", ",44", "," or "" is allowed.
  * Leading, embedded and trailing whitespace accepted.
  */
 int bitmap_parse(const char *buf, unsigned int buflen, unsigned long *dst, int nbits);
 
 /*
  * Bitmap printing & parsing functions: first version by Nadia Yvette Chambers,
  * second version by Paul Jackson, third by Joe Korty.
  */
 
 /**
  * bitmap_parse_user - convert an ASCII hex string in a user buffer into a bitmap
  *
  * @ubuf: pointer to user buffer containing string.
  * @ulen: buffer size in bytes.  If string is smaller than this
  *    then it must be terminated with a \0.
  * @maskp: pointer to bitmap array that will contain result.
  * @nmaskbits: size of bitmap, in bits.
  */
 int bitmap_parse_user(const char *ubuf, unsigned int ulen, unsigned long *dst, int nbits);
 
 /**
  * bitmap_parselist - convert list format ASCII string to bitmap
  * @buf: read user string from this buffer; must be terminated
  *    with a \0 or \n.
  * @maskp: write resulting mask here
  * @nmaskbits: number of bits in mask to be written
  *
  * Input format is a comma-separated list of decimal numbers and
  * ranges.  Consecutively set bits are shown as two hyphen-separated
  * decimal numbers, the smallest and largest bit numbers set in
  * the range.
  * Optionally each range can be postfixed to denote that only parts of it
  * should be set. The range will divided to groups of specific size.
  * From each group will be used only defined amount of bits.
  * Syntax: range:used_size/group_size
  * Example: 0-1023:2/256 ==> 0,1,256,257,512,513,768,769
  *
  * Returns: 0 on success, -errno on invalid input strings. Error values:
  *
  *   - ``-EINVAL``: wrong region format
  *   - ``-EINVAL``: invalid character in string
  *   - ``-ERANGE``: bit number specified too large for mask
  *   - ``-EOVERFLOW``: integer overflow in the input parameters
  */ 
 int bitmap_parselist(const char *buf, unsigned long *maskp, int nmaskbits);
 
 /**
  * bitmap_parselist_user()
  *
  * @ubuf: pointer to user buffer containing string.
  * @ulen: buffer size in bytes.  If string is smaller than this
  *    then it must be terminated with a \0.
  * @maskp: pointer to bitmap array that will contain result.
  * @nmaskbits: size of bitmap, in bits.
  *
  * Wrapper for bitmap_parselist(), providing it with user buffer.
  */
 int bitmap_parselist_user(const char *ubuf, unsigned int ulen, unsigned long *dst, int nbits);
 
 /**
  * bitmap_remap - Apply map defined by a pair of bitmaps to another bitmap
  *  @dst: remapped result
  *  @src: subset to be remapped
  *  @old: defines domain of map
  *  @new: defines range of map
  *  @nbits: number of bits in each of these bitmaps
  *
  * Let @old and @new define a mapping of bit positions, such that
  * whatever position is held by the n-th set bit in @old is mapped
  * to the n-th set bit in @new.  In the more general case, allowing
  * for the possibility that the weight 'w' of @new is less than the
  * weight of @old, map the position of the n-th set bit in @old to
  * the position of the m-th set bit in @new, where m == n % w.
  *
  * If either of the @old and @new bitmaps are empty, or if @src and
  * @dst point to the same location, then this routine copies @src
  * to @dst.
  *
  * The positions of unset bits in @old are mapped to themselves
  * (the identify map).
  *
  * Apply the above specified mapping to @src, placing the result in
  * @dst, clearing any bits previously set in @dst.
  *
  * For example, lets say that @old has bits 4 through 7 set, and
  * @new has bits 12 through 15 set.  This defines the mapping of bit
  * position 4 to 12, 5 to 13, 6 to 14 and 7 to 15, and of all other
  * bit positions unchanged.  So if say @src comes into this routine
  * with bits 1, 5 and 7 set, then @dst should leave with bits 1,
  * 13 and 15 set.
  */
 void bitmap_remap(unsigned long *dst, const unsigned long *src, const unsigned long *old, 
                             const unsigned long *new, unsigned int nbits);
 
 /**
  * bitmap_bitremap - Apply map defined by a pair of bitmaps to a single bit
  *  @oldbit: bit position to be mapped
  *  @old: defines domain of map
  *  @new: defines range of map
  *  @bits: number of bits in each of these bitmaps
  *
  * Let @old and @new define a mapping of bit positions, such that
  * whatever position is held by the n-th set bit in @old is mapped
  * to the n-th set bit in @new.  In the more general case, allowing
  * for the possibility that the weight 'w' of @new is less than the
  * weight of @old, map the position of the n-th set bit in @old to
  * the position of the m-th set bit in @new, where m == n % w.
  *
  * The positions of unset bits in @old are mapped to themselves
  * (the identify map).
  *
  * Apply the above specified mapping to bit position @oldbit, returning
  * the new bit position.
  *
  * For example, lets say that @old has bits 4 through 7 set, and
  * @new has bits 12 through 15 set.  This defines the mapping of bit
  * position 4 to 12, 5 to 13, 6 to 14 and 7 to 15, and of all other
  * bit positions unchanged.  So if say @oldbit is 5, then this routine
  * returns 13.
  */
 int bitmap_bitremap(int oldbit, const unsigned long *old, const unsigned long *new, int bits);
 
 
 /**
  * bitmap_onto - translate one bitmap relative to another
  *  @dst: resulting translated bitmap
  *  @orig: original untranslated bitmap
  *  @relmap: bitmap relative to which translated
  *  @bits: number of bits in each of these bitmaps
  *
  * Set the n-th bit of @dst iff there exists some m such that the
  * n-th bit of @relmap is set, the m-th bit of @orig is set, and
  * the n-th bit of @relmap is also the m-th _set_ bit of @relmap.
  * (If you understood the previous sentence the first time your
  * read it, you're overqualified for your current job.)
  *
  * In other words, @orig is mapped onto (surjectively) @dst,
  * using the map { <n, m> | the n-th bit of @relmap is the
  * m-th set bit of @relmap }.
  *
  * Any set bits in @orig above bit number W, where W is the
  * weight of (number of set bits in) @relmap are mapped nowhere.
  * In particular, if for all bits m set in @orig, m >= W, then
  * @dst will end up empty.  In situations where the possibility
  * of such an empty result is not desired, one way to avoid it is
  * to use the bitmap_fold() operator, below, to first fold the
  * @orig bitmap over itself so that all its set bits x are in the
  * range 0 <= x < W.  The bitmap_fold() operator does this by
  * setting the bit (m % W) in @dst, for each bit (m) set in @orig.
  *
  * Example [1] for bitmap_onto():
  *  Let's say @relmap has bits 30-39 set, and @orig has bits
  *  1, 3, 5, 7, 9 and 11 set.  Then on return from this routine,
  *  @dst will have bits 31, 33, 35, 37 and 39 set.
  *
  *  When bit 0 is set in @orig, it means turn on the bit in
  *  @dst corresponding to whatever is the first bit (if any)
  *  that is turned on in @relmap.  Since bit 0 was off in the
  *  above example, we leave off that bit (bit 30) in @dst.
  *
  *  When bit 1 is set in @orig (as in the above example), it
  *  means turn on the bit in @dst corresponding to whatever
  *  is the second bit that is turned on in @relmap.  The second
  *  bit in @relmap that was turned on in the above example was
  *  bit 31, so we turned on bit 31 in @dst.
  *
  *  Similarly, we turned on bits 33, 35, 37 and 39 in @dst,
  *  because they were the 4th, 6th, 8th and 10th set bits
  *  set in @relmap, and the 4th, 6th, 8th and 10th bits of
  *  @orig (i.e. bits 3, 5, 7 and 9) were also set.
  *
  *  When bit 11 is set in @orig, it means turn on the bit in
  *  @dst corresponding to whatever is the twelfth bit that is
  *  turned on in @relmap.  In the above example, there were
  *  only ten bits turned on in @relmap (30..39), so that bit
  *  11 was set in @orig had no affect on @dst.
  *
  * Example [2] for bitmap_fold() + bitmap_onto():
  *  Let's say @relmap has these ten bits set::
  *
  *      40 41 42 43 45 48 53 61 74 95
  *
  *  (for the curious, that's 40 plus the first ten terms of the
  *  Fibonacci sequence.)
  *
  *  Further lets say we use the following code, invoking
  *  bitmap_fold() then bitmap_onto, as suggested above to
  *  avoid the possibility of an empty @dst result::
  *
  *  unsigned long *tmp; // a temporary bitmap's bits
  *
  *  bitmap_fold(tmp, orig, bitmap_weight(relmap, bits), bits);
  *  bitmap_onto(dst, tmp, relmap, bits);
  *
  *  Then this table shows what various values of @dst would be, for
  *  various @orig's.  I list the zero-based positions of each set bit.
  *  The tmp column shows the intermediate result, as computed by
  *  using bitmap_fold() to fold the @orig bitmap modulo ten
  *  (the weight of @relmap):
  *
  *      =============== ============== =================
  *      @orig           tmp            @dst
  *      0                0             40
  *      1                1             41
  *      9                9             95
  *      10               0             40 [#f1]_
  *      1 3 5 7          1 3 5 7       41 43 48 61
  *      0 1 2 3 4        0 1 2 3 4     40 41 42 43 45
  *      0 9 18 27        0 9 8 7       40 61 74 95
  *      0 10 20 30       0             40
  *      0 11 22 33       0 1 2 3       40 41 42 43
  *      0 12 24 36       0 2 4 6       40 42 45 53
  *      78 102 211       1 2 8         41 42 74 [#f1]_
  *      =============== ============== =================
  *
  * .. [#f1]
  *
  *     For these marked lines, if we hadn't first done bitmap_fold()
  *     into tmp, then the @dst result would have been empty.
  *
  * If either of @orig or @relmap is empty (no set bits), then @dst
  * will be returned empty.
  *
  * If (as explained above) the only set bits in @orig are in positions
  * m where m >= W, (where W is the weight of @relmap) then @dst will
  * once again be returned empty.
  *
  * All bits in @dst not set by the above rule are cleared.
  */
 void bitmap_onto(unsigned long *dst, const unsigned long *orig, const unsigned long *relmap, unsigned int bits);
 
 /**
  * bitmap_fold - fold larger bitmap into smaller, modulo specified size
  *  @dst: resulting smaller bitmap
  *  @orig: original larger bitmap
  *  @sz: specified size
  *  @nbits: number of bits in each of these bitmaps
  *
  * For each bit oldbit in @orig, set bit oldbit mod @sz in @dst.
  * Clear all other bits in @dst.  See further the comment and
  * Example [2] for bitmap_onto() for why and how to use this.
  */
 void bitmap_fold(unsigned long *dst, const unsigned long *orig, unsigned int sz, unsigned int nbits);
 
 /**
  * bitmap_find_free_region - find a contiguous aligned mem region
  *  @bitmap: array of unsigned longs corresponding to the bitmap
  *  @bits: number of bits in the bitmap
  *  @order: region size (log base 2 of number of bits) to find
  *
  * Find a region of free (zero) bits in a @bitmap of @bits bits and
  * allocate them (set them to one).  Only consider regions of length
  * a power (@order) of two, aligned to that power of two, which
  * makes the search algorithm much faster.
  *
  * Return the bit offset in bitmap of the allocated region,
  * or -errno on failure.
  */
 int bitmap_find_free_region(unsigned long *bitmap, unsigned int bits, int order);
 
 /**
  * bitmap_release_region - release allocated bitmap region
  *  @bitmap: array of unsigned longs corresponding to the bitmap
  *  @pos: beginning of bit region to release
  *  @order: region size (log base 2 of number of bits) to release
  *
  * This is the complement to __bitmap_find_free_region() and releases
  * the found region (by clearing it in the bitmap).
  *
  * No return value.
  */
 void bitmap_release_region(unsigned long *bitmap, unsigned int pos, int order);
 
 /**
  * bitmap_allocate_region - allocate bitmap region
  *  @bitmap: array of unsigned longs corresponding to the bitmap
  *  @pos: beginning of bit region to allocate
  *  @order: region size (log base 2 of number of bits) to allocate
  *
  * Allocate (set bits in) a specified region of a bitmap.
  *
  * Return 0 on success, or %-EBUSY if specified region wasn't
  * free (not all bits were zero).
  */
int bitmap_allocate_region(unsigned long *bitmap, unsigned int pos, int order);



void bitmap_copy_le(unsigned long *dst, const unsigned long *src, unsigned int nbits);


unsigned int bitmap_ord_to_pos(const unsigned long *bitmap, unsigned int ord, unsigned int nbits);
int bitmap_print_to_pagebuf(bool list, char *buf, const unsigned long *maskp, int nmaskbits);
 
 
 
 
#define BITMAP_FIRST_WORD_MASK(start) (~0UL << ((start) & (BITS_PER_LONG - 1)))
#define BITMAP_LAST_WORD_MASK(nbits) (~0UL >> (-(nbits) & (BITS_PER_LONG - 1)))
 
 
 /*
  * The static inlines below do not handle constant nbits==0 correctly,
  * so make such users (should any ever turn up) call the out-of-line
  * versions.
  */
#define small_const_nbits(nbits) \
     (__builtin_constant_p(nbits) && (nbits) <= BITS_PER_LONG && (nbits) > 0)
 
 inline void bitmap_zero(unsigned long *dst, unsigned int nbits);
 
 inline void bitmap_fill(unsigned long *dst, unsigned int nbits);
 
 inline void bitmap_copy(unsigned long *dst, const unsigned long *src, unsigned int nbits);
 
 
 /*
 * Copy bitmap and clear tail bits in last word.
 */
 inline void bitmap_copy_clear_tail(unsigned long *dst, const unsigned long *src, unsigned int nbits);
 
 
        
/*
 * On 32-bit systems bitmaps are represented as u32 arrays internally, and
 * therefore conversion is not needed when copying data from/to arrays of u32.
 */
void bitmap_from_arr32(unsigned long *bitmap, const uint32_t *buf, unsigned int nbits);
void bitmap_to_arr32(uint32_t *buf, const unsigned long *bitmap, unsigned int nbits);


inline int bitmap_and(unsigned long *dst, const unsigned long *src1, const unsigned long *src2, unsigned int nbits);

inline void bitmap_or(unsigned long *dst, const unsigned long *src1, const unsigned long *src2, unsigned int nbits);

inline void bitmap_xor(unsigned long *dst, const unsigned long *src1, const unsigned long *src2, unsigned int nbits);

inline int bitmap_andnot(unsigned long *dst, const unsigned long *src1, const unsigned long *src2, unsigned int nbits);

inline void bitmap_complement(unsigned long *dst, const unsigned long *src, unsigned int nbits);

inline int bitmap_equal(const unsigned long *src1, const unsigned long *src2, unsigned int nbits);
 
 /**
  * bitmap_or_equal - Check whether the or of two bitmaps is equal to a third
  * @src1:   Pointer to bitmap 1
  * @src2:   Pointer to bitmap 2 will be or'ed with bitmap 1
  * @src3:   Pointer to bitmap 3. Compare to the result of *@src1 | *@src2
  * @nbits:  number of bits in each of these bitmaps
  *
  * Returns: True if (*@src1 | *@src2) == *@src3, false otherwise
  */
inline bool bitmap_or_equal(const unsigned long *src1, const unsigned long *src2,
                             const unsigned long *src3, unsigned int nbits);

inline int bitmap_intersects(const unsigned long *src1, const unsigned long *src2, unsigned int nbits);

inline int bitmap_subset(const unsigned long *src1, const unsigned long *src2, unsigned int nbits);

inline int bitmap_empty(const unsigned long *src, unsigned nbits);

inline int bitmap_full(const unsigned long *src, unsigned int nbits);

inline int bitmap_weight(const unsigned long *src, unsigned int nbits);

inline void bitmap_set(unsigned long *map, unsigned int start, unsigned int nbits);

inline void bitmap_clear(unsigned long *map, unsigned int start, unsigned int nbits);
 
 /**
  * bitmap_shift_right - logical right shift of the bits in a bitmap
  *   @dst : destination bitmap
  *   @src : source bitmap
  *   @shift : shift by this many bits
  *   @nbits : bitmap size, in bits
  *
  * Shifting right (dividing) means moving bits in the MS -> LS bit
  * direction.  Zeros are fed into the vacated MS positions and the
  * LS bits shifted off the bottom are lost.
  */
inline void bitmap_shift_right(unsigned long *dst, const unsigned long *src,
                                     unsigned int shift, unsigned int nbits);
 
 /**
  * __bitmap_shift_left - logical left shift of the bits in a bitmap
  *   @dst : destination bitmap
  *   @src : source bitmap
  *   @shift : shift by this many bits
  *   @nbits : bitmap size, in bits
  *
  * Shifting left (multiplying) means moving bits in the LS -> MS
  * direction.  Zeros are fed into the vacated LS bit positions
  * and those MS bits shifted off the top are lost.
  */
inline void bitmap_shift_left(unsigned long *dst, const unsigned long *src, unsigned int shift, unsigned int nbits);

inline void bitmap_replace(unsigned long *dst, const unsigned long *old,
                           const unsigned long *new, const unsigned long *mask,
                           unsigned int nbits);

inline void bitmap_next_clear_region(unsigned long *bitmap,
                                     unsigned int *rs, unsigned int *re,
                                     unsigned int end);

inline void bitmap_next_set_region(unsigned long *bitmap,
                                   unsigned int *rs, unsigned int *re,
                                   unsigned int end);
 
 /*
  * Bitmap region iterators.  Iterates over the bitmap between [@start, @end).
  * @rs and @re should be integer variables and will be set to start and end
  * index of the current clear or set region.
  */
#define bitmap_for_each_clear_region(bitmap, rs, re, start, end)	     \
     for ((rs) = (start),                             \
          bitmap_next_clear_region((bitmap), &(rs), &(re), (end));        \
          (rs) < (re);                            \
          (rs) = (re) + 1,                            \
          bitmap_next_clear_region((bitmap), &(rs), &(re), (end)))
 
#define bitmap_for_each_set_region(bitmap, rs, re, start, end)		     \
     for ((rs) = (start),                             \
          bitmap_next_set_region((bitmap), &(rs), &(re), (end));      \
          (rs) < (re);                            \
          (rs) = (re) + 1,                            \
          bitmap_next_set_region((bitmap), &(rs), &(re), (end)))
 
 
     
 
 /**
  * bitmap_from_u64 - Check and swap words within uint64_t.
  *  @mask: source bitmap
  *  @dst:  destination bitmap
  *
  * In 32-bit Big Endian kernel, when using ``(u32 *)(&val)[*]``
  * to read uint64_t mask, we will get the wrong word.
  * That is ``(u32 *)(&val)[0]`` gets the upper 32 bits,
  * but we expect the lower 32-bits of uint64_t.
  */
inline void bitmap_from_u64(unsigned long *dst, uint64_t mask);
 
 
 /**
  * bitmap_get_value8 - get an 8-bit value within a memory region
  * @map: address to the bitmap memory region
  * @start: bit offset of the 8-bit value; must be a multiple of 8
  *
  * Returns the 8-bit value located at the @start bit offset within the @src
  * memory region.
  */
 inline unsigned long bitmap_get_value8(const unsigned long *map, unsigned long start);
 
 /**
 * bitmap_set_value8 - set an 8-bit value within a memory region
 * @map: address to the bitmap memory region
 * @value: the 8-bit value; values wider than 8 bits may clobber bitmap
 * @start: bit offset of the 8-bit value; must be a multiple of 8
 */
 inline void bitmap_set_value8(unsigned long *map, unsigned long value, unsigned long start);
 
 
#endif /*__BITS_BITMAP_H */


