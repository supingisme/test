#include <stddef.h>
#include <stdarg.h>
#include <setjmp.h>
#include <google/cmockery.h>

#include "cstl/cstl_def.h"
#include "cstl/citerator.h"
#include "cstl/chash_map.h"
#include "cstl/cstring.h"
#include "cstl/cvector.h"
#include "cstl/clist.h"
#include "cstl_vector_aux.h"
#include "cstl_hashtable_aux.h"
#include "cstl_hash_multimap_aux.h"

#include "ut_def.h"
#include "ut_cstl_hash_multimap.h"

UT_SUIT_DEFINATION(cstl_hash_multimap, hash_multimap_init)

/*
 * test hash_multimap_init
 */
UT_CASE_DEFINATION(hash_multimap_init)
void test_hash_multimap_init__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_init(NULL));
}

void test_hash_multimap_init__non_created(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = 999;
    expect_assert_failure(hash_multimap_init(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_init__non_created_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    pt_hash_multimap->_pair_temp._pv_first = (void*)0x9999;
    expect_assert_failure(hash_multimap_init(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._pv_first = NULL;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_init__null_compare(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init(pt_hash_multimap);
    assert_true(_pair_is_inited(&pt_hash_multimap->_pair_temp));
    assert_true(_hashtable_is_inited(&pt_hash_multimap->_t_hashtable));

    hash_multimap_destroy(pt_hash_multimap);
}

/*
 * test hash_multimap_init_ex
 */
UT_CASE_DEFINATION(hash_multimap_init_ex)
void test_hash_multimap_init_ex__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_init_ex(NULL, 0, NULL, NULL));
}

void test_hash_multimap_init_ex__non_created(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = 4444;
    expect_assert_failure(hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL));
    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_init_ex__non_created_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    pt_hash_multimap->_pair_temp._pv_first = (void*)0x7777;
    expect_assert_failure(hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL));
    pt_hash_multimap->_pair_temp._pv_first = NULL;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_init_ex__0_bucketcount(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    assert_true(_hashtable_is_inited(&pt_hash_multimap->_t_hashtable));
    assert_true(_pair_is_inited(&pt_hash_multimap->_pair_temp));
    assert_true(hash_multimap_bucket_count(pt_hash_multimap) == 53);
    assert_true(hash_multimap_hash(pt_hash_multimap) == _hash_multimap_default_hash);
    assert_true(pt_hash_multimap->_bfun_keycompare == NULL);
    assert_true(pt_hash_multimap->_pair_temp._bfun_mapkeycompare == NULL);

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_init_ex__100_bucketcount(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_hash_multimap, 100, NULL, NULL);
    assert_true(_hashtable_is_inited(&pt_hash_multimap->_t_hashtable));
    assert_true(_pair_is_inited(&pt_hash_multimap->_pair_temp));
    assert_true(hash_multimap_bucket_count(pt_hash_multimap) == 193);
    assert_true(hash_multimap_hash(pt_hash_multimap) == _hash_multimap_default_hash);
    assert_true(pt_hash_multimap->_bfun_keycompare == NULL);
    assert_true(pt_hash_multimap->_pair_temp._bfun_mapkeycompare == NULL);

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_init_ex__null_hash(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    assert_true(_hashtable_is_inited(&pt_hash_multimap->_t_hashtable));
    assert_true(_pair_is_inited(&pt_hash_multimap->_pair_temp));
    assert_true(hash_multimap_bucket_count(pt_hash_multimap) == 53);
    assert_true(hash_multimap_hash(pt_hash_multimap) == _hash_multimap_default_hash);
    assert_true(pt_hash_multimap->_bfun_keycompare == NULL);
    assert_true(pt_hash_multimap->_pair_temp._bfun_mapkeycompare == NULL);

    hash_multimap_destroy(pt_hash_multimap);
}

static void _test_hash_multimap_init_ex__non_null_hash(const void* cpv_input, void* pv_output)
{
    *(size_t*)pv_output = *(int*)pair_first((pair_t*)cpv_input);
}
void test_hash_multimap_init_ex__non_null_hash(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_hash_multimap, 0, _test_hash_multimap_init_ex__non_null_hash, NULL);
    assert_true(_hashtable_is_inited(&pt_hash_multimap->_t_hashtable));
    assert_true(_pair_is_inited(&pt_hash_multimap->_pair_temp));
    assert_true(hash_multimap_bucket_count(pt_hash_multimap) == 53);
    assert_true(hash_multimap_hash(pt_hash_multimap) == _test_hash_multimap_init_ex__non_null_hash);
    assert_true(pt_hash_multimap->_bfun_keycompare == NULL);
    assert_true(pt_hash_multimap->_pair_temp._bfun_mapkeycompare == NULL);

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_init_ex__null_compare(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    assert_true(_hashtable_is_inited(&pt_hash_multimap->_t_hashtable));
    assert_true(_pair_is_inited(&pt_hash_multimap->_pair_temp));
    assert_true(hash_multimap_bucket_count(pt_hash_multimap) == 53);
    assert_true(hash_multimap_hash(pt_hash_multimap) == _hash_multimap_default_hash);
    assert_true(pt_hash_multimap->_bfun_keycompare == NULL);
    assert_true(pt_hash_multimap->_pair_temp._bfun_mapkeycompare == NULL);

    hash_multimap_destroy(pt_hash_multimap);
}

static void _test_hash_multimap_init_ex__non_null_compare(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first < *(int*)cpv_second ? true : false;
}
void test_hash_multimap_init_ex__non_null_compare(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, _test_hash_multimap_init_ex__non_null_compare);
    assert_true(_hashtable_is_inited(&pt_hash_multimap->_t_hashtable));
    assert_true(_pair_is_inited(&pt_hash_multimap->_pair_temp));
    assert_true(hash_multimap_bucket_count(pt_hash_multimap) == 53);
    assert_true(hash_multimap_hash(pt_hash_multimap) == _hash_multimap_default_hash);
    assert_true(pt_hash_multimap->_bfun_keycompare == _test_hash_multimap_init_ex__non_null_compare);
    assert_true(pt_hash_multimap->_pair_temp._bfun_mapkeycompare == _test_hash_multimap_init_ex__non_null_compare);

    hash_multimap_destroy(pt_hash_multimap);
}

/*
 * test hash_multimap_init_copy
 */
UT_CASE_DEFINATION(hash_multimap_init_copy)
void test_hash_multimap_init_copy__null_dest(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    expect_assert_failure(hash_multimap_init_copy(NULL, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_init_copy__null_src(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    expect_assert_failure(hash_multimap_init_copy(pt_hash_multimap, NULL));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_init_copy__non_created_dest(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);

    hash_multimap_init(pt_src);
    pt_dest->_pair_temp._t_typeinfofirst._t_style = 8999;
    expect_assert_failure(hash_multimap_init_copy(pt_dest, pt_src));
    pt_dest->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_init_copy__non_created_dest_pair(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);

    hash_multimap_init(pt_src);
    pt_dest->_pair_temp._pv_first = (void*)0x733;
    expect_assert_failure(hash_multimap_init_copy(pt_dest, pt_src));
    pt_dest->_pair_temp._pv_first = NULL;

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_init_copy__non_inited_src(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);

    hash_multimap_init(pt_src);
    pt_src->_pair_temp._t_typeinfosecond._t_style = 9090;
    expect_assert_failure(hash_multimap_init_copy(pt_dest, pt_src));
    pt_src->_pair_temp._t_typeinfosecond._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_init_copy__non_inited_src_pair(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init(pt_src);
    pv_tmp = pt_src->_pair_temp._pv_first;
    pt_src->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_init_copy(pt_dest, pt_src));
    pt_src->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_init_copy__not_same_type(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(double, int);

    hash_multimap_init(pt_src);
    expect_assert_failure(hash_multimap_init_copy(pt_dest, pt_src));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_init_copy__empty(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(signed int, int);

    hash_multimap_init(pt_src);
    hash_multimap_init_copy(pt_dest, pt_src);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_empty(pt_dest));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_init_copy__non_empty(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 100;

    hash_multimap_init(pt_src);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);
    hash_multimap_init_copy(pt_dest, pt_src);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 1);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_init_copy__bucketcount(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 100;

    hash_multimap_init_ex(pt_src, 100, NULL, NULL);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);
    hash_multimap_init_copy(pt_dest, pt_src);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 1);
    assert_true(hash_multimap_bucket_count(pt_dest) == 193);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_init_copy__non_null_hash(const void* cpv_input, void* pv_output)
{
    *(size_t*)pv_output = *(int*)pair_first((pair_t*)cpv_input);
}
void test_hash_multimap_init_copy__non_null_hash(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 100;

    hash_multimap_init_ex(pt_src, 0, _test_hash_multimap_init_copy__non_null_hash, NULL);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);
    hash_multimap_init_copy(pt_dest, pt_src);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 1);
    assert_true(hash_multimap_bucket_count(pt_dest) == 53);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_init_copy__non_null_compare(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first < *(int*)cpv_second ? true : false;
}
void test_hash_multimap_init_copy__non_null_compare(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i = 0;

    hash_multimap_init_ex(pt_src, 0, NULL, _test_hash_multimap_init_copy__non_null_compare);
    pair_init(pt_pair);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_src, pt_pair);
    }
    hash_multimap_init_copy(pt_dest, pt_src);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 10);
    assert_true(pt_dest->_bfun_keycompare == _test_hash_multimap_init_copy__non_null_compare);
    assert_true(pt_dest->_pair_temp._bfun_mapkeycompare == _test_hash_multimap_init_copy__non_null_compare);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_init_copy_range
 */
UT_CASE_DEFINATION(hash_multimap_init_copy_range)
void test_hash_multimap_init_copy_range__null_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    expect_assert_failure(hash_multimap_init_copy_range(NULL, hash_multimap_begin(pt_hash_multimap), hash_multimap_end(pt_hash_multimap)));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_init_copy_range__non_created_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    pt_dest->_pair_temp._t_typeinfofirst._t_style = 9999;
    expect_assert_failure(hash_multimap_init_copy_range(pt_dest, hash_multimap_begin(pt_hash_multimap), hash_multimap_end(pt_hash_multimap)));
    pt_dest->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_init_copy_range__non_created_hash_multimap_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    pt_dest->_pair_temp._pv_first = (void*)0x8989;
    expect_assert_failure(hash_multimap_init_copy_range(pt_dest, hash_multimap_begin(pt_hash_multimap), hash_multimap_end(pt_hash_multimap)));
    pt_dest->_pair_temp._pv_first = NULL;

    hash_multimap_destroy(pt_hash_multimap);
    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_init_copy_range__invalid_begin(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init(pt_src);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    it_begin._t_containertype = 99999;
    expect_assert_failure(hash_multimap_init_copy_range(pt_dest, it_begin, it_end));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_init_copy_range__invalid_end(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init(pt_src);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    it_end._t_iteratortype = 44444;
    expect_assert_failure(hash_multimap_init_copy_range(pt_dest, it_begin, it_end));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_init_copy_range__invalid_range(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int elem = 9;

    hash_multimap_init(pt_src);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    expect_assert_failure(hash_multimap_init_copy_range(pt_dest, it_end, it_begin));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_init_copy_range__invalid_range_not_same_type(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(double, int);
    pair_t* ppair = create_pair(double, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    pair_init_elem(ppair, 1.0, 2);
    hash_multimap_init(pt_src);
    hash_multimap_insert(pt_src, ppair);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    expect_assert_failure(hash_multimap_init_copy_range(pt_dest, it_begin, it_end));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(ppair);
}

void test_hash_multimap_init_copy_range__empty(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init(pt_src);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    hash_multimap_init_copy_range(pt_dest, it_begin, it_end);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_empty(pt_dest));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_init_copy_range__non_empty(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int elem = 9;

    hash_multimap_init(pt_src);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    hash_multimap_init_copy_range(pt_dest, it_begin, it_end);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 1);
    assert_true(hash_multimap_equal(pt_dest, pt_src));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_init_copy_range__other(void** state)
{
    hash_multimap_t* phmmap = create_hash_multimap(int, int);
    vector_t* pvec = create_vector(pair_t<int, int>);
    pair_t* ppair = create_pair(int, int);

    pair_init_elem(ppair, 1, 1);
    vector_init_elem(pvec, 10, ppair);
    hash_multimap_init_copy_range(phmmap, vector_begin(pvec), vector_end(pvec));
    assert_true(hash_multimap_size(phmmap) == 10);

    pair_destroy(ppair);
    vector_destroy(pvec);
    hash_multimap_destroy(phmmap);
}

void test_hash_multimap_init_copy_range__other_not_same(void** state)
{
    hash_multimap_t* phmmap = create_hash_multimap(int, int);
    vector_t* pvec = create_vector(pair_t<int, double>);
    pair_t* ppair = create_pair(int, double);

    pair_init_elem(ppair, 1, 1);
    vector_init_elem(pvec, 10, ppair);
    expect_assert_failure(hash_multimap_init_copy_range(phmmap, vector_begin(pvec), vector_end(pvec)));

    pair_destroy(ppair);
    vector_destroy(pvec);
    hash_multimap_destroy(phmmap);
}

/*
 * test hash_multimap_init_copy_array
 */
UT_CASE_DEFINATION(hash_multimap_init_copy_array)
void test_hash_multimap_init_copy_array__null_hash_multimap(void** state)
{
    pair_t* apair[10] = {NULL};
    expect_assert_failure(hash_multimap_init_copy_array(NULL, apair, 10));
}

void test_hash_multimap_init_copy_array__non_created_hash_multimap(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);

    pt_dest->_pair_temp._t_typeinfofirst._t_style = 9999;
    expect_assert_failure(hash_multimap_init_copy_array(pt_dest, apair, 10));
    pt_dest->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_init_copy_array__non_created_hash_multimap_pair(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);

    pt_dest->_pair_temp._pv_first = (void*)0x8989;
    expect_assert_failure(hash_multimap_init_copy_array(pt_dest, apair, 10));
    pt_dest->_pair_temp._pv_first = NULL;

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_init_copy_array__invalid_array(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);

    expect_assert_failure(hash_multimap_init_copy_array(pt_dest, NULL, 10));

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_init_copy_array__invalid_array_not_same_type(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    int i = 0;

    for (i = 0; i < 10; ++i) {
        apair[i] = create_pair(int, double);
        pair_init_elem(apair[i], i, i);
    }
    expect_assert_failure(hash_multimap_init_copy_array(pt_dest, apair, 10));

    hash_multimap_destroy(pt_dest);
    for (i = 0; i < 10; ++i) {
        pair_destroy(apair[i]);
    }
}

void test_hash_multimap_init_copy_array__empty(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    int i = 0;

    for (i = 0; i < 10; ++i) {
        apair[i] = create_pair(int, int);
        pair_init_elem(apair[i], i, i);
    }
    hash_multimap_init_copy_array(pt_dest, apair, 0);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_empty(pt_dest));

    hash_multimap_destroy(pt_dest);
    for (i = 0; i < 10; ++i) {
        pair_destroy(apair[i]);
    }
}

void test_hash_multimap_init_copy_array__non_empty(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    int i = 0;

    for (i = 0; i < 10; ++i) {
        apair[i] = create_pair(int, int);
        pair_init_elem(apair[i], i, i);
    }
    hash_multimap_init_copy_array(pt_dest, apair, 10);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 10);

    hash_multimap_destroy(pt_dest);
    for (i = 0; i < 10; ++i) {
        pair_destroy(apair[i]);
    }
}

void test_hash_multimap_init_copy_array__non_empty_dup(void** state)
{
    pair_t* apair[20] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    int i = 0;

    for (i = 0; i < 20; i += 2) {
        apair[i] = create_pair(int, int);
        pair_init_elem(apair[i], i, i);
        apair[i + 1] = create_pair(int, int);
        pair_init_elem(apair[i + 1], i, i);
    }
    hash_multimap_init_copy_array(pt_dest, apair, 20);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 20);

    hash_multimap_destroy(pt_dest);
    for (i = 0; i < 20; ++i) {
        pair_destroy(apair[i]);
    }
}

/*
 * test hash_multimap_init_copy_range_ex
 */
UT_CASE_DEFINATION(hash_multimap_init_copy_range_ex)
void test_hash_multimap_init_copy_range_ex__null_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    expect_assert_failure(hash_multimap_init_copy_range_ex(NULL, hash_multimap_begin(pt_hash_multimap), hash_multimap_end(pt_hash_multimap), 0, NULL, NULL));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_init_copy_range_ex__non_created_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    pt_dest->_pair_temp._t_typeinfofirst._t_style = 9999;
    expect_assert_failure(hash_multimap_init_copy_range_ex(pt_dest, hash_multimap_begin(pt_hash_multimap), hash_multimap_end(pt_hash_multimap), 0, NULL, NULL));
    pt_dest->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_init_copy_range_ex__non_created_hash_multimap_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    pt_dest->_pair_temp._pv_second = (void*)0x7383;
    expect_assert_failure(hash_multimap_init_copy_range_ex(pt_dest, hash_multimap_begin(pt_hash_multimap), hash_multimap_end(pt_hash_multimap), 0, NULL, NULL));
    pt_dest->_pair_temp._pv_second = NULL;

    hash_multimap_destroy(pt_hash_multimap);
    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_init_copy_range_ex__invalid_begin(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init(pt_src);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    it_begin._t_containertype = 99999;
    expect_assert_failure(hash_multimap_init_copy_range_ex(pt_dest, it_begin, it_end, 0, NULL, NULL));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_init_copy_range_ex__invalid_end(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init(pt_src);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    it_end._t_iteratortype = 33333;
    expect_assert_failure(hash_multimap_init_copy_range_ex(pt_dest, it_begin, it_end, 0, NULL, NULL));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_init_copy_range_ex__invalid_range(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int elem = 9;

    hash_multimap_init(pt_src);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    expect_assert_failure(hash_multimap_init_copy_range_ex(pt_dest, it_end, it_begin, 0, NULL, NULL));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_init_copy_range_ex__invalid_range_not_same_type(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(double, int);
    pair_t* ppair = create_pair(double, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    pair_init_elem(ppair, 2.3, 4);
    hash_multimap_init(pt_src);
    hash_multimap_insert(pt_src, ppair);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    expect_assert_failure(hash_multimap_init_copy_range_ex(pt_dest, it_begin, it_end, 0, NULL, NULL));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(ppair);
}

void test_hash_multimap_init_copy_range_ex__empty(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init(pt_src);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    hash_multimap_init_copy_range_ex(pt_dest, it_begin, it_end, 0, NULL, NULL);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_empty(pt_dest));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_init_copy_range_ex__non_empty(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int elem = 9;

    hash_multimap_init(pt_src);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    hash_multimap_init_copy_range_ex(pt_dest, it_begin, it_end, 0, NULL, NULL);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 1);
    assert_true(hash_multimap_equal(pt_dest, pt_src));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_init_copy_range_ex__bucketcount(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int elem = 9;

    hash_multimap_init_ex(pt_src, 0, NULL, NULL);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    hash_multimap_init_copy_range_ex(pt_dest, it_begin, it_end, 100, NULL, NULL);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 1);
    assert_true(hash_multimap_bucket_count(pt_dest) == 193);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_init_copy__hash(const void* cpv_input, void* pv_output)
{
    *(size_t*)pv_output = *(int*)pair_first((pair_t*)cpv_input);
}
void test_hash_multimap_init_copy_range_ex__hash(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int elem = 9;

    hash_multimap_init_ex(pt_src, 100, NULL, NULL);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    hash_multimap_init_copy_range_ex(pt_dest, it_begin, it_end, 0, _test_hash_multimap_init_copy__hash, NULL);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 1);
    assert_true(hash_multimap_bucket_count(pt_dest) == 53);
    assert_true(hash_multimap_hash(pt_dest) == _test_hash_multimap_init_copy__hash);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

static void _test__hash_multimap_init_compare_range_ex__compare(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first < *(int*)cpv_second ? true : false;
}
void test_hash_multimap_init_copy_range_ex__compare(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int elem = 9;

    hash_multimap_init(pt_src);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    hash_multimap_init_copy_range_ex(pt_dest, it_begin, it_end, 0, NULL, _test__hash_multimap_init_compare_range_ex__compare);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 1);
    assert_true(pt_dest->_bfun_keycompare == _test__hash_multimap_init_compare_range_ex__compare);
    assert_true(pt_dest->_pair_temp._bfun_mapkeycompare == _test__hash_multimap_init_compare_range_ex__compare);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_init_copy_range_ex__other(void** state)
{
    hash_multimap_t* phmmap = create_hash_multimap(int, int);
    vector_t* pvec = create_vector(pair_t<int, int>);
    pair_t* ppair = create_pair(int, int);

    pair_init_elem(ppair, 1, 1);
    vector_init_elem(pvec, 10, ppair);
    hash_multimap_init_copy_range_ex(phmmap, vector_begin(pvec), vector_end(pvec), 0, NULL, NULL);
    assert_true(hash_multimap_size(phmmap) == 10);

    pair_destroy(ppair);
    vector_destroy(pvec);
    hash_multimap_destroy(phmmap);
}

void test_hash_multimap_init_copy_range_ex__other_not_same(void** state)
{
    hash_multimap_t* phmmap = create_hash_multimap(int, int);
    vector_t* pvec = create_vector(pair_t<int, double>);
    pair_t* ppair = create_pair(int, double);

    pair_init_elem(ppair, 1, 1);
    vector_init_elem(pvec, 10, ppair);
    expect_assert_failure(hash_multimap_init_copy_range_ex(phmmap, vector_begin(pvec), vector_end(pvec), 0, NULL, NULL));

    pair_destroy(ppair);
    vector_destroy(pvec);
    hash_multimap_destroy(phmmap);
}

/*
 * test hash_multimap_init_copy_array_ex
 */
UT_CASE_DEFINATION(hash_multimap_init_copy_array_ex)
void test_hash_multimap_init_copy_array_ex__null_hash_multimap(void** state)
{
    pair_t* apair[10] = {NULL};
    expect_assert_failure(hash_multimap_init_copy_array_ex(NULL, apair, 10, 0, NULL, NULL));
}

void test_hash_multimap_init_copy_array_ex__non_created_hash_multimap(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);

    pt_dest->_pair_temp._t_typeinfofirst._t_style = 9999;
    expect_assert_failure(hash_multimap_init_copy_array_ex(pt_dest, apair, 10, 0, NULL, NULL));
    pt_dest->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_init_copy_array_ex__non_created_hash_multimap_pair(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);

    pt_dest->_pair_temp._pv_second = (void*)0x7383;
    expect_assert_failure(hash_multimap_init_copy_array_ex(pt_dest, apair, 10, 0, NULL, NULL));
    pt_dest->_pair_temp._pv_second = NULL;

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_init_copy_array_ex__invalid_array(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);

    expect_assert_failure(hash_multimap_init_copy_array_ex(pt_dest, NULL, 10, 0, NULL, NULL));

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_init_copy_array_ex__invalid_array_not_same_type(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    int i = 0;

    for (i = 0; i < 10; ++i) {
        apair[i] = create_pair(int, double);
        pair_init_elem(apair[i], i, i);
    }
    expect_assert_failure(hash_multimap_init_copy_array_ex(pt_dest, apair, 10, 0, NULL, NULL));

    hash_multimap_destroy(pt_dest);
    for (i = 0; i < 10; ++i) {
        pair_destroy(apair[i]);
    }
}

void test_hash_multimap_init_copy_array_ex__empty(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    int i = 0;

    for (i = 0; i < 10; ++i) {
        apair[i] = create_pair(int, int);
        pair_init_elem(apair[i], i, i);
    }
    hash_multimap_init_copy_array_ex(pt_dest, apair, 0, 0, NULL, NULL);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_empty(pt_dest));

    hash_multimap_destroy(pt_dest);
    for (i = 0; i < 10; ++i) {
        pair_destroy(apair[i]);
    }
}

void test_hash_multimap_init_copy_array_ex__non_empty(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    int i = 0;

    for (i = 0; i < 10; ++i) {
        apair[i] = create_pair(int, int);
        pair_init_elem(apair[i], i, i);
    }
    hash_multimap_init_copy_array_ex(pt_dest, apair, 10, 0, NULL, NULL);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 10);

    hash_multimap_destroy(pt_dest);
    for (i = 0; i < 10; ++i) {
        pair_destroy(apair[i]);
    }
}

void test_hash_multimap_init_copy_array_ex__non_empty_dup(void** state)
{
    pair_t* apair[20] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    int i = 0;

    for (i = 0; i < 20; i += 2) {
        apair[i] = create_pair(int, int);
        pair_init_elem(apair[i], i, i);
        apair[i + 1] = create_pair(int, int);
        pair_init_elem(apair[i + 1], i, i);
    }
    hash_multimap_init_copy_array_ex(pt_dest, apair, 10, 0, NULL, NULL);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 10);

    hash_multimap_destroy(pt_dest);
    for (i = 0; i < 20; ++i) {
        pair_destroy(apair[i]);
    }
}

void test_hash_multimap_init_copy_array_ex__bucketcount(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    int i = 0;

    for (i = 0; i < 10; ++i) {
        apair[i] = create_pair(int, int);
        pair_init_elem(apair[i], i, i);
    }
    hash_multimap_init_copy_array_ex(pt_dest, apair, 10, 100, NULL, NULL);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 10);
    assert_true(hash_multimap_bucket_count(pt_dest) == 193);

    hash_multimap_destroy(pt_dest);
    for (i = 0; i < 10; ++i) {
        pair_destroy(apair[i]);
    }
}

void test_hash_multimap_init_copy_array_ex__hash(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    int i = 0;

    for (i = 0; i < 10; ++i) {
        apair[i] = create_pair(int, int);
        pair_init_elem(apair[i], i, i);
    }
    hash_multimap_init_copy_array_ex(pt_dest, apair, 10, 0, _test_hash_multimap_init_copy__hash, NULL);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 10);
    assert_true(hash_multimap_bucket_count(pt_dest) == 53);
    assert_true(hash_multimap_hash(pt_dest) == _test_hash_multimap_init_copy__hash);

    hash_multimap_destroy(pt_dest);
    for (i = 0; i < 10; ++i) {
        pair_destroy(apair[i]);
    }

}

static void _test__hash_multimap_init_compare_array_ex__compare(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first < *(int*)cpv_second ? true : false;
}
void test_hash_multimap_init_copy_array_ex__compare(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    int i = 0;
    
    for (i = 0; i < 10; ++i) {
        apair[i] = create_pair(int, int);
        pair_init_elem(apair[i], i, i);
    }
    hash_multimap_init_copy_array_ex(pt_dest, apair, 10, 0, NULL, _test__hash_multimap_init_compare_array_ex__compare);
    assert_true(_hashtable_is_inited(&pt_dest->_t_hashtable));
    assert_true(_pair_is_inited(&pt_dest->_pair_temp));
    assert_true(hash_multimap_size(pt_dest) == 10);
    assert_true(pt_dest->_bfun_keycompare == _test__hash_multimap_init_compare_array_ex__compare);
    assert_true(pt_dest->_pair_temp._bfun_mapkeycompare == _test__hash_multimap_init_compare_array_ex__compare);

    hash_multimap_destroy(pt_dest);
    for (i = 0; i < 10; ++i) {
        pair_destroy(apair[i]);
    }
}

/*
 * test hash_multimap_destroy
 */
UT_CASE_DEFINATION(hash_multimap_destroy)
void test_hash_multimap_destroy__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_destroy(NULL));
}

void test_hash_multimap_destroy__non_created(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = 999;
    expect_assert_failure(hash_multimap_destroy(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_destroy__created(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_destroy__inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_destroy__non_empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);

    hash_multimap_init(pt_hash_multimap);
    pair_init_elem(pt_pair, 2, 4);
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_assign
 */
UT_CASE_DEFINATION(hash_multimap_assign)
void test_hash_multimap_assign__null_dest(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init(pt_hash_multimap);
    expect_assert_failure(hash_multimap_assign(NULL, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_assign__null_src(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init(pt_hash_multimap);
    expect_assert_failure(hash_multimap_assign(pt_hash_multimap, NULL));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_assign__non_created_dest(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);

    hash_multimap_init(pt_dest);
    hash_multimap_init(pt_src);
    pt_dest->_pair_temp._t_typeinfofirst._t_style = 999;
    expect_assert_failure(hash_multimap_assign(pt_dest, pt_src));
    pt_dest->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_assign__non_created_dest_pair(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init(pt_dest);
    hash_multimap_init(pt_src);
    pv_tmp = pt_dest->_pair_temp._pv_first;
    pt_dest->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_assign(pt_dest, pt_src));
    pt_dest->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_assign__non_init_src(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);

    hash_multimap_init(pt_src);
    hash_multimap_init(pt_dest);
    pt_src->_pair_temp._t_typeinfofirst._t_style = 3444;
    expect_assert_failure(hash_multimap_assign(pt_dest, pt_src));
    pt_src->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_assign__non_init_src_pair(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init(pt_src);
    hash_multimap_init(pt_dest);
    pv_tmp = pt_src->_pair_temp._pv_second;
    pt_src->_pair_temp._pv_second = NULL;
    expect_assert_failure(hash_multimap_assign(pt_dest, pt_src));
    pt_src->_pair_temp._pv_second = pv_tmp;

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_assign__not_same_type(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(double, int);

    hash_multimap_init(pt_src);
    hash_multimap_init(pt_dest);
    expect_assert_failure(hash_multimap_assign(pt_dest, pt_src));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_assign__empty_empty(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);

    hash_multimap_init(pt_src);
    hash_multimap_init(pt_dest);
    hash_multimap_assign(pt_dest, pt_src);
    assert_true(hash_multimap_empty(pt_dest));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_assign__non_empty_empty(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 9;

    hash_multimap_init(pt_src);
    hash_multimap_init(pt_dest);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_dest, pt_pair);
    hash_multimap_assign(pt_dest, pt_src);
    assert_true(hash_multimap_empty(pt_dest));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_assign__non_empty_non_empty_less(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 999;

    hash_multimap_init(pt_src);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);
    elem = 222;
    pair_make(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);

    hash_multimap_init(pt_dest);
    elem = 897;
    pair_make(pt_pair, elem, elem);
    hash_multimap_insert(pt_dest, pt_pair);

    hash_multimap_assign(pt_dest, pt_src);
    assert_true(hash_multimap_size(pt_dest) == 2);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_assign__non_empty_non_empty_size_equal(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 9;

    pair_init(pt_pair);
    hash_multimap_init(pt_src);

    pair_make(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);

    hash_multimap_init(pt_dest);
    elem = 334;
    pair_make(pt_pair, elem, elem);
    hash_multimap_insert(pt_dest, pt_pair);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(hash_multimap_begin(pt_dest))) == 334);
    hash_multimap_assign(pt_dest, pt_src);
    assert_true(hash_multimap_size(pt_dest) == 1);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(hash_multimap_begin(pt_dest))) == 9);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_assign__non_empty_non_empty_equal(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 9;

    pair_init(pt_pair);
    hash_multimap_init(pt_src);

    pair_make(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);

    hash_multimap_init(pt_dest);
    pair_make(pt_pair, elem, elem);
    hash_multimap_insert(pt_dest, pt_pair);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(hash_multimap_begin(pt_dest))) == 9);
    hash_multimap_assign(pt_dest, pt_src);
    assert_true(hash_multimap_size(pt_dest) == 1);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(hash_multimap_begin(pt_dest))) == 9);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_assign__non_empty_non_empty_greater(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 9;

    pair_init(pt_pair);
    hash_multimap_init(pt_src);

    pair_make(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);

    hash_multimap_init(pt_dest);
    elem = 876;
    pair_make(pt_pair, elem, elem);
    hash_multimap_insert(pt_dest, pt_pair);
    elem = 333;
    pair_make(pt_pair, elem, elem);
    hash_multimap_insert(pt_dest, pt_pair);
    hash_multimap_assign(pt_dest, pt_src);
    assert_true(hash_multimap_size(pt_dest) == 1);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(hash_multimap_begin(pt_dest))) == 9);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_assign__empty_non_empty(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 9;

    pair_init(pt_pair);
    hash_multimap_init(pt_src);
    pair_make(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);
    hash_multimap_init(pt_dest);
    hash_multimap_assign(pt_dest, pt_src);
    assert_true(hash_multimap_size(pt_dest) == 1);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(hash_multimap_begin(pt_dest))) == 9);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_size
 */
UT_CASE_DEFINATION(hash_multimap_size)
void test_hash_multimap_size__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_size(NULL));
}

void test_hash_multimap_size__non_inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = 43444;
    expect_assert_failure(hash_multimap_size(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_size__non_inited_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    void* pv_tmp = NULL;
    hash_multimap_init(pt_hash_multimap);

    pv_tmp = pt_hash_multimap->_pair_temp._pv_first;
    pt_hash_multimap->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_size(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_size__empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    assert_true(hash_multimap_size(pt_hash_multimap) == 0);

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_size__non_empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 9;

    hash_multimap_init(pt_hash_multimap);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_hash_multimap, pt_pair);

    assert_true(hash_multimap_size(pt_hash_multimap) == 1);

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_empty
 */
UT_CASE_DEFINATION(hash_multimap_empty)
void test_hash_multimap_empty__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_empty(NULL));
}

void test_hash_multimap_empty__non_inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = 9999;
    expect_assert_failure(hash_multimap_empty(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_empty__non_inited_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    void* pv_tmp = NULL;
    hash_multimap_init(pt_hash_multimap);

    pv_tmp = pt_hash_multimap->_pair_temp._pv_first;
    pt_hash_multimap->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_empty(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_empty__empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    assert_true(hash_multimap_empty(pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_empty__non_empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 9;

    hash_multimap_init(pt_hash_multimap);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_hash_multimap, pt_pair);

    assert_false(hash_multimap_empty(pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_max_size
 */
UT_CASE_DEFINATION(hash_multimap_max_size)
void test_hash_multimap_max_size__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_max_size(NULL));
}

void test_hash_multimap_max_size__non_inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = 999;
    expect_assert_failure(hash_multimap_max_size(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_max_size__non_inited_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    void* pv_tmp = NULL;
    hash_multimap_init(pt_hash_multimap);

    pv_tmp = pt_hash_multimap->_pair_temp._pv_first;
    pt_hash_multimap->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_max_size(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_max_size__empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    assert_true(hash_multimap_max_size(pt_hash_multimap) > 0);

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_max_size__non_empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 9;

    hash_multimap_init(pt_hash_multimap);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_hash_multimap, pt_pair);

    assert_true(hash_multimap_max_size(pt_hash_multimap) > 0);

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_bucket_count
 */
UT_CASE_DEFINATION(hash_multimap_bucket_count)
void test_hash_multimap_bucket_count__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_bucket_count(NULL));
}

void test_hash_multimap_bucket_count__non_inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = 33333;
    expect_assert_failure(hash_multimap_bucket_count(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_bucket_count__non_inited_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    void* pv_tmp = NULL;
    hash_multimap_init(pt_hash_multimap);

    pv_tmp = pt_hash_multimap->_pair_temp._pv_first;
    pt_hash_multimap->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_bucket_count(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_bucket_count__0(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    assert_true(hash_multimap_bucket_count(pt_hash_multimap) == 53);

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_bucket_count__100(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 100, NULL, NULL);

    assert_true(hash_multimap_bucket_count(pt_hash_multimap) == 193);

    hash_multimap_destroy(pt_hash_multimap);
}

/*
 * test hash_multimap_begin
 */
UT_CASE_DEFINATION(hash_multimap_begin)
void test_hash_multimap_begin__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_begin(NULL));
}

void test_hash_multimap_begin__non_inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = 33333;
    expect_assert_failure(hash_multimap_begin(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_begin__non_inited_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    void* pv_tmp = NULL;
    hash_multimap_init(pt_hash_multimap);

    pv_tmp = pt_hash_multimap->_pair_temp._pv_first;
    pt_hash_multimap->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_begin(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_begin__empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    assert_true(_hash_multimap_iterator_equal(hash_multimap_begin(pt_hash_multimap), hash_multimap_end(pt_hash_multimap)));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_begin__non_empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 9;

    hash_multimap_init(pt_hash_multimap);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_hash_multimap, pt_pair);

    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(hash_multimap_begin(pt_hash_multimap))) == 9);

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_end
 */
UT_CASE_DEFINATION(hash_multimap_end)
void test_hash_multimap_end__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_end(NULL));
}

void test_hash_multimap_end__non_inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = 999;
    expect_assert_failure(hash_multimap_end(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_end__non_inited_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    void* pv_tmp = NULL;
    hash_multimap_init(pt_hash_multimap);

    pv_tmp = pt_hash_multimap->_pair_temp._pv_first;
    pt_hash_multimap->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_end(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_end__empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    assert_true(iterator_equal(hash_multimap_begin(pt_hash_multimap), hash_multimap_end(pt_hash_multimap)));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_end__non_empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_iter;
    int elem = 9;

    hash_multimap_init(pt_hash_multimap);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_hash_multimap, pt_pair);

    it_iter = hash_multimap_end(pt_hash_multimap);
    it_iter = iterator_prev(it_iter);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(it_iter)) == 9);

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_hash
 */
UT_CASE_DEFINATION(hash_multimap_hash)
void test_hash_multimap_hash__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_hash(NULL));
}

void test_hash_multimap_hash__non_inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    void* pv_tmp = NULL;
    hash_multimap_init(pt_hash_multimap);

    pv_tmp = pt_hash_multimap->_pair_temp._pv_first;
    pt_hash_multimap->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_hash(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_hash__default_hash(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    assert_true(hash_multimap_hash(pt_hash_multimap) == _hash_multimap_default_hash);

    hash_multimap_destroy(pt_hash_multimap);
}

static void _test_hash_multimap_hash__user_define_hash(const void* cpv_input, void* pv_output)
{
    *(size_t*)pv_output = *(int*)pair_first((pair_t*)cpv_input);
}
void test_hash_multimap_hash__user_define_hash(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, _test_hash_multimap_hash__user_define_hash, NULL);

    assert_true(hash_multimap_hash(pt_hash_multimap) == _test_hash_multimap_hash__user_define_hash);

    hash_multimap_destroy(pt_hash_multimap);
}

/*
 * test hash_multimap_key_comp
 */
UT_CASE_DEFINATION(hash_multimap_key_comp)
void test_hash_multimap_key_comp__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_key_comp(NULL));
}

void test_hash_multimap_key_comp__non_inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    void* pv_tmp = NULL;
    hash_multimap_init(pt_hash_multimap);

    pv_tmp = pt_hash_multimap->_pair_temp._pv_first;
    pt_hash_multimap->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_key_comp(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_key_comp__default_key_comp(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    assert_true(hash_multimap_key_comp(pt_hash_multimap) == _GET_HASH_MULTIMAP_FIRST_TYPE_LESS_FUNCTION(pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void _test_hash_multimap_key_comp__user_define_key_comp(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first < *(int*)cpv_second ? true : false;
}

void test_hash_multimap_key_comp__user_define_key_comp(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, _test_hash_multimap_key_comp__user_define_key_comp);

    assert_true(hash_multimap_key_comp(pt_hash_multimap) == _test_hash_multimap_key_comp__user_define_key_comp);

    hash_multimap_destroy(pt_hash_multimap);
}

/*
 * test hash_multimap_value_comp
 */
UT_CASE_DEFINATION(hash_multimap_value_comp)
void test_hash_multimap_value_comp__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_value_comp(NULL));
}

void test_hash_multimap_value_comp__non_inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    void* pv_tmp = NULL;
    hash_multimap_init(pt_hash_multimap);

    pv_tmp = pt_hash_multimap->_pair_temp._pv_first;
    pt_hash_multimap->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_value_comp(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_value_comp__default_value_comp(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    assert_true(hash_multimap_value_comp(pt_hash_multimap) == _hash_multimap_value_compare);

    hash_multimap_destroy(pt_hash_multimap);
}

void _test_hash_multimap_value_comp__user_define_value_comp(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first < *(int*)cpv_second ? true : false;
}

void test_hash_multimap_value_comp__user_define_value_comp(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, _test_hash_multimap_value_comp__user_define_value_comp);

    assert_true(hash_multimap_value_comp(pt_hash_multimap) == _hash_multimap_value_compare);

    hash_multimap_destroy(pt_hash_multimap);
}

/*
 * test hash_multimap_clear
 */
UT_CASE_DEFINATION(hash_multimap_clear)
void test_hash_multimap_clear__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_clear(NULL));
}

void test_hash_multimap_clear__non_inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    pt_hash_multimap->_pair_temp._t_typeinfosecond._t_style = 444;
    expect_assert_failure(hash_multimap_clear(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._t_typeinfosecond._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_clear__non_inited_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    void* pv_tmp = NULL;
    hash_multimap_init(pt_hash_multimap);

    pv_tmp = pt_hash_multimap->_pair_temp._pv_first;
    pt_hash_multimap->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_clear(pt_hash_multimap));
    pt_hash_multimap->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_clear__empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);

    assert_true(hash_multimap_empty(pt_hash_multimap));
    hash_multimap_clear(pt_hash_multimap);
    assert_true(hash_multimap_empty(pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_clear__non_empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 8;
    hash_multimap_init(pt_hash_multimap);

    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    assert_false(hash_multimap_empty(pt_hash_multimap));
    hash_multimap_clear(pt_hash_multimap);
    assert_true(hash_multimap_empty(pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_equal
 */
UT_CASE_DEFINATION(hash_multimap_equal)
void test_hash_multimap_equal__null_first(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_equal(NULL, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_equal__null_second(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_equal(pt_hash_multimap, NULL));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_equal__non_inited_first(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_first->_pair_temp._t_typeinfofirst._t_style = 4444;
    expect_assert_failure(hash_multimap_equal(pt_first, pt_second));
    pt_first->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_equal__non_inited_first_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_first->_pair_temp._pv_first;
    pt_first->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_equal(pt_first, pt_second));
    pt_first->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_equal__non_inited_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_second->_pair_temp._t_typeinfofirst._t_style = 4344;
    expect_assert_failure(hash_multimap_equal(pt_first, pt_second));
    pt_second->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_equal__non_inited_second_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_second->_pair_temp._pv_first;
    pt_second->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_equal(pt_first, pt_second));
    pt_second->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_equal__not_same_type(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(list_t<int>,int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_equal__same_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    assert_true(hash_multimap_equal(pt_hash_multimap, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_equal__size_first_less_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 0; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_equal__size_first_greater_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 0; i < 2; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_equal__size_equal_0(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    assert_true(hash_multimap_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_equal__size_equal_elem_first_less_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_equal__size_equal_elem_first_greater_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 30; i < 40; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_equal__bucketcount_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 100, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_equal__hash_not_equal(const void* cpv_input, void* pv_output)
{
    *(size_t*)pv_output = *(int*)pair_first((pair_t*)cpv_input);
}
void test_hash_multimap_equal__hash_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, _test_hash_multimap_equal__hash_not_equal, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_equal__compare_not_equal(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first < *(int*)cpv_second ? true : false;
}
void test_hash_multimap_equal__compare_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, _test_hash_multimap_equal__compare_not_equal);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_equal__equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_not_equal
 */
UT_CASE_DEFINATION(hash_multimap_not_equal)
void test_hash_multimap_not_equal__null_first(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_not_equal(NULL, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_not_equal__null_second(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_not_equal(pt_hash_multimap, NULL));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_not_equal__non_inited_first(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_first->_pair_temp._t_typeinfofirst._t_style = 4444;
    expect_assert_failure(hash_multimap_not_equal(pt_first, pt_second));
    pt_first->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_not_equal__non_inited_first_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_first->_pair_temp._pv_first;
    pt_first->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_not_equal(pt_first, pt_second));
    pt_first->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_not_equal__non_inited_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_second->_pair_temp._t_typeinfofirst._t_style = 9999;
    expect_assert_failure(hash_multimap_not_equal(pt_first, pt_second));
    pt_second->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_not_equal__non_inited_second_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_second->_pair_temp._pv_first;
    pt_second->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_not_equal(pt_first, pt_second));
    pt_second->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_not_equal__not_same_type(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(list_t<int>, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_not_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_not_equal__same_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    assert_false(hash_multimap_not_equal(pt_hash_multimap, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_not_equal__size_first_less_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 0; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_not_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_not_equal__size_first_greater_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 0; i < 2; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_not_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_not_equal__size_equal_0(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    assert_false(hash_multimap_not_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_not_equal__size_equal_elem_first_less_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_not_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_not_equal__size_equal_elem_first_greater_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 30; i < 40; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_not_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_not_equal__bucketcount_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 100, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_not_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_not_equal__hash_not_equal(const void* cpv_input, void* pv_output)
{
    *(size_t*)pv_output = *(int*)pair_first((pair_t*)cpv_input);
}
void test_hash_multimap_not_equal__hash_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, _test_hash_multimap_not_equal__hash_not_equal, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_not_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_not_equal__compare_not_equal(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first < *(int*)cpv_second ? true : false;
}
void test_hash_multimap_not_equal__compare_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, _test_hash_multimap_not_equal__compare_not_equal);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_not_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_not_equal__equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_not_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_less
 */
UT_CASE_DEFINATION(hash_multimap_less)
void test_hash_multimap_less__null_first(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_less(NULL, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_less__null_second(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_less(pt_hash_multimap, NULL));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_less__non_inited_first(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_first->_pair_temp._t_typeinfofirst._t_style = 4444;
    expect_assert_failure(hash_multimap_less(pt_first, pt_second));
    pt_first->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_less__non_inited_first_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_first->_pair_temp._pv_first;
    pt_first->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_less(pt_first, pt_second));
    pt_first->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_less__non_inited_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_second->_pair_temp._t_typeinfofirst._t_style = 999;
    expect_assert_failure(hash_multimap_less(pt_first, pt_second));
    pt_second->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_less__non_inited_second_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_second->_pair_temp._pv_first;
    pt_second->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_less(pt_first, pt_second));
    pt_second->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_less__not_same_type(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(list_t<int>, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_less(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_less__same_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    assert_false(hash_multimap_less(pt_hash_multimap, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_less__size_first_less_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 0; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_less(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_less__size_first_greater_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 0; i < 2; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_less(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_less__size_equal_0(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    assert_false(hash_multimap_less(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_less__size_equal_elem_first_less_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_less(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_less__size_equal_elem_first_greater_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 30; i < 40; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_less(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_less__bucketcount_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 100, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_less(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_less__hash_not_equal(const void* cpv_input, void* pv_output)
{
    *(size_t*)pv_output = *(int*)pair_first((pair_t*)cpv_input);
}
void test_hash_multimap_less__hash_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, _test_hash_multimap_less__hash_not_equal, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_less(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_less__compare_less(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first < *(int*)cpv_second ? true : false;
}
void test_hash_multimap_less__compare_less(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, _test_hash_multimap_less__compare_less);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_less(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_less__equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_less(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_less_equal
 */
UT_CASE_DEFINATION(hash_multimap_less_equal)
void test_hash_multimap_less_equal__null_first(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_less_equal(NULL, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_less_equal__null_second(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_less_equal(pt_hash_multimap, NULL));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_less_equal__non_inited_first(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_first->_pair_temp._t_typeinfofirst._t_style = 4444;
    expect_assert_failure(hash_multimap_less_equal(pt_first, pt_second));
    pt_first->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_less_equal__non_inited_first_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_first->_pair_temp._pv_first;
    pt_first->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_less_equal(pt_first, pt_second));
    pt_first->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_less_equal__non_inited_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_second->_pair_temp._t_typeinfofirst._t_style = 9999;
    expect_assert_failure(hash_multimap_less_equal(pt_first, pt_second));
    pt_second->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_less_equal__non_inited_second_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_second->_pair_temp._pv_first;
    pt_second->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_less_equal(pt_first, pt_second));
    pt_second->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_less_equal__not_same_type(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(list_t<int>, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_less_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_less_equal__same_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    assert_true(hash_multimap_less_equal(pt_hash_multimap, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_less_equal__size_first_less_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 0; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_less_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_less_equal__size_first_greater_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 0; i < 2; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_less_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_less_equal__size_equal_0(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    assert_true(hash_multimap_less_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_less_equal__size_equal_elem_first_less_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_less_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_less_equal__size_equal_elem_first_greater_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 30; i < 40; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_less_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_less_equal__bucketcount_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 100, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_less_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_less_equal__hash_not_equal(const void* cpv_input, void* pv_output)
{
    *(size_t*)pv_output = *(int*)pair_first((pair_t*)cpv_input);
}
void test_hash_multimap_less_equal__hash_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, _test_hash_multimap_less_equal__hash_not_equal, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_less_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_less_equal__compare_less(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first < *(int*)cpv_second ? true : false;
}
void test_hash_multimap_less_equal__compare_less(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, _test_hash_multimap_less_equal__compare_less);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_less_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_less_equal__equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_less_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_greater
 */
UT_CASE_DEFINATION(hash_multimap_greater)
void test_hash_multimap_greater__null_first(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_greater(NULL, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_greater__null_second(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_greater(pt_hash_multimap, NULL));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_greater__non_inited_first(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_first->_pair_temp._t_typeinfofirst._t_style = 8888;
    expect_assert_failure(hash_multimap_greater(pt_first, pt_second));
    pt_first->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_greater__non_inited_first_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_first->_pair_temp._pv_first;
    pt_first->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_greater(pt_first, pt_second));
    pt_first->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_greater__non_inited_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_second->_pair_temp._t_typeinfofirst._t_style = 4444;
    expect_assert_failure(hash_multimap_greater(pt_first, pt_second));
    pt_second->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_greater__non_inited_second_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_second->_pair_temp._pv_first;
    pt_second->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_greater(pt_first, pt_second));
    pt_second->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_greater__not_same_type(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(list_t<int>, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_greater(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_greater__same_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    assert_false(hash_multimap_greater(pt_hash_multimap, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_greater__size_first_less_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 0; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_greater(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_greater__size_first_greater_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 0; i < 2; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_greater(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_greater__size_equal_0(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    assert_false(hash_multimap_greater(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_greater__size_equal_elem_first_less_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_greater(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_greater__size_equal_elem_first_greater_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 30; i < 40; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_greater(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_greater__bucketcount_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 100, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_greater(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_greater__hash_not_equal(const void* cpv_input, void* pv_output)
{
    *(size_t*)pv_output = *(int*)pair_first((pair_t*)cpv_input);
}
void test_hash_multimap_greater__hash_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, _test_hash_multimap_greater__hash_not_equal, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_greater(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_greater__compare_less(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first < *(int*)cpv_second ? true : false;
}
void test_hash_multimap_greater__compare_less(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, _test_hash_multimap_greater__compare_less);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_greater(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_greater__equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_greater(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_greater_equal
 */
UT_CASE_DEFINATION(hash_multimap_greater_equal)
void test_hash_multimap_greater_equal__null_first(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_greater_equal(NULL, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_greater_equal__null_second(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_greater_equal(pt_hash_multimap, NULL));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_greater_equal__non_inited_first(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_first->_pair_temp._t_typeinfofirst._t_style = 8888;
    expect_assert_failure(hash_multimap_greater_equal(pt_first, pt_second));
    pt_first->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_greater_equal__non_inited_first_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_first->_pair_temp._pv_first;
    pt_first->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_greater_equal(pt_first, pt_second));
    pt_first->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_greater_equal__non_inited_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_second->_pair_temp._t_typeinfofirst._t_style = 9999;
    expect_assert_failure(hash_multimap_greater_equal(pt_first, pt_second));
    pt_second->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_greater_equal__non_inited_second_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_second->_pair_temp._pv_second;
    pt_second->_pair_temp._pv_second = NULL;
    expect_assert_failure(hash_multimap_greater_equal(pt_first, pt_second));
    pt_second->_pair_temp._pv_second = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_greater_equal__not_same_type(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(list_t<int>, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_greater_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_greater_equal__same_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    assert_true(hash_multimap_greater_equal(pt_hash_multimap, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_greater_equal__size_first_less_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 0; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_greater_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_greater_equal__size_first_greater_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 0; i < 2; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_greater_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_greater_equal__size_equal_0(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    assert_true(hash_multimap_greater_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_greater_equal__size_equal_elem_first_less_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_false(hash_multimap_greater_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_greater_equal__size_equal_elem_first_greater_than_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 30; i < 40; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_greater_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_greater_equal__bucketcount_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 100, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_greater_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_greater_equal__hash_not_equal(const void* cpv_input, void* pv_output)
{
    *(size_t*)pv_output = *(int*)pair_first((pair_t*)cpv_input);
}
void test_hash_multimap_greater_equal__hash_not_equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int,int);
    hash_multimap_t* pt_second = create_hash_multimap(signed int,int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, _test_hash_multimap_greater_equal__hash_not_equal, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_greater_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_greater_equal__compare_less(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first < *(int*)cpv_second ? true : false;
}
void test_hash_multimap_greater_equal__compare_less(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, _test_hash_multimap_greater_equal__compare_less);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    expect_assert_failure(hash_multimap_greater_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_greater_equal__equal(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_greater_equal(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_swap
 */
UT_CASE_DEFINATION(hash_multimap_swap)
void test_hash_multimap_swap__null_first(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_swap(NULL, pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_swap__null_second(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_swap(pt_hash_multimap, NULL));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_swap__non_inited_first(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_first->_pair_temp._t_typeinfofirst._t_style = 33333;
    expect_assert_failure(hash_multimap_swap(pt_first, pt_second));
    pt_first->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_swap__non_inited_first_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_first->_pair_temp._pv_first;
    pt_first->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_swap(pt_first, pt_second));
    pt_first->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_swap__non_inited_second(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pt_second->_pair_temp._t_typeinfofirst._t_style = 2222;
    expect_assert_failure(hash_multimap_swap(pt_first, pt_second));
    pt_second->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_swap__non_inited_second_pair(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    pv_tmp = pt_second->_pair_temp._pv_first;
    pt_second->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_swap(pt_first, pt_second));
    pt_second->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_swap__not_same_type(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(list_t<int>, int);

    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_swap(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
}

void test_hash_multimap_swap__same_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    hash_multimap_swap(pt_hash_multimap, pt_hash_multimap);
    assert_true(hash_multimap_empty(pt_hash_multimap));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_swap__0_swap_n(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i = 0;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_size(pt_first) == 0);
    assert_true(hash_multimap_size(pt_second) == 10);
    hash_multimap_swap(pt_first, pt_second);
    assert_true(hash_multimap_size(pt_first) == 10);
    assert_true(hash_multimap_size(pt_second) == 0);

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_swap__n_swap_0(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i = 0;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }

    assert_true(hash_multimap_size(pt_first) == 10);
    assert_true(hash_multimap_size(pt_second) == 0);
    hash_multimap_swap(pt_first, pt_second);
    assert_true(hash_multimap_size(pt_first) == 0);
    assert_true(hash_multimap_size(pt_second) == 10);

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_swap__n_swap_n(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i = 0;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 100; i < 110; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_size(pt_first) == 10);
    assert_true(hash_multimap_size(pt_second) == 10);
    assert_true(hash_multimap_less(pt_first, pt_second));
    hash_multimap_swap(pt_first, pt_second);
    assert_true(hash_multimap_size(pt_first) == 10);
    assert_true(hash_multimap_size(pt_second) == 10);
    assert_true(hash_multimap_greater(pt_first, pt_second));

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

void test_hash_multimap_swap__m_swap_n(void** state)
{
    hash_multimap_t* pt_first = create_hash_multimap(int, int);
    hash_multimap_t* pt_second = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i = 0;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_first, 0, NULL, NULL);
    hash_multimap_init_ex(pt_second, 0, NULL, NULL);
    for(i = 0; i < 30; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_first, pt_pair);
    }
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_second, pt_pair);
    }

    assert_true(hash_multimap_size(pt_first) == 30);
    assert_true(hash_multimap_size(pt_second) == 10);
    hash_multimap_swap(pt_first, pt_second);
    assert_true(hash_multimap_size(pt_first) == 10);
    assert_true(hash_multimap_size(pt_second) == 30);

    hash_multimap_destroy(pt_first);
    hash_multimap_destroy(pt_second);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_insert
 */
UT_CASE_DEFINATION(hash_multimap_insert)
void test_hash_multimap_insert__null_hash_multimap(void** state)
{
    pair_t* pt_pair = create_pair(int, int);
    pair_init(pt_pair);
    expect_assert_failure(hash_multimap_insert(NULL, pt_pair));
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert__null_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init(pt_hash_multimap);
    expect_assert_failure(hash_multimap_insert(pt_hash_multimap, NULL));
    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_insert__non_inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    pair_init(pt_pair);

    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = 9999;
    expect_assert_failure(hash_multimap_insert(pt_hash_multimap, pt_pair));
    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert__non_inited_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    void* pv_tmp = NULL;
    pair_init(pt_pair);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    pv_tmp = pt_hash_multimap->_pair_temp._pv_first;
    pt_hash_multimap->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_insert(pt_hash_multimap, pt_pair));
    pt_hash_multimap->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert__pair_non_inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_insert(pt_hash_multimap, pt_pair));

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert__not_smae_type(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, double);

    hash_multimap_init(pt_hash_multimap);
    pair_init(pt_pair);
    expect_assert_failure(hash_multimap_insert(pt_hash_multimap, pt_pair));

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert__c_builtin_equal(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_iter;
    int i;

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    pair_init(pt_pair);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_hash_multimap, pt_pair);
    }

    pair_make(pt_pair, 3, 444);
    it_iter = hash_multimap_insert(pt_hash_multimap, pt_pair);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(it_iter))== 3);
    assert_true(hash_multimap_size(pt_hash_multimap) == 11);

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert__c_builtin_not_equal(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_iter;
    int i;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_hash_multimap, pt_pair);
    }

    pair_make(pt_pair, -8, 3);
    it_iter = hash_multimap_insert(pt_hash_multimap, pt_pair);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(it_iter))== -8);
    assert_true(hash_multimap_size(pt_hash_multimap) == 11);

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert__cstr_equal(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(char*, char*);
    pair_t* pt_pair = create_pair(char*, char*);
    hash_multimap_iterator_t it_iter;
    pair_init(pt_pair);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    pair_make(pt_pair, "aaa", "aaa");
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    pair_make(pt_pair, "ggg", "ggg");
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    pair_make(pt_pair, "nghl", "lhgn");
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    pair_make(pt_pair, "asery", "yresa");
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    pair_make(pt_pair, "linux", "window");
    hash_multimap_insert(pt_hash_multimap, pt_pair);

    pair_make(pt_pair, "ggg", "llll");
    it_iter = hash_multimap_insert(pt_hash_multimap, pt_pair);
    assert_true(strcmp((char*)pair_first((pair_t*)iterator_get_pointer(it_iter)), "ggg") == 0);
    assert_true(hash_multimap_size(pt_hash_multimap) == 6);

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert__cstr_not_equal(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(char*, char*);
    pair_t* pt_pair = create_pair(char*, char*);
    hash_multimap_iterator_t it_iter;
    pair_init(pt_pair);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    pair_make(pt_pair, "aaa", "aaa");
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    pair_make(pt_pair, "ggg", "ggg");
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    pair_make(pt_pair, "nghl", "lhgn");
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    pair_make(pt_pair, "asery", "yresa");
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    pair_make(pt_pair, "linux", "window");
    hash_multimap_insert(pt_hash_multimap, pt_pair);

    pair_make(pt_pair, "vvvv", "llll");
    it_iter = hash_multimap_insert(pt_hash_multimap, pt_pair);
    assert_true(strcmp((char*)pair_first((pair_t*)iterator_get_pointer(it_iter)), "vvvv") == 0);
    assert_true(hash_multimap_size(pt_hash_multimap) == 6);

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_insert__hash(const void* cpv_input, void* pv_output)
{
    *(size_t*)pv_output = *(int*)pair_first((pair_t*)cpv_input);
}
void test_hash_multimap_insert__libcstl_builtin_equal(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(list_t<int>, vector_t<int>);
    pair_t* pt_pair = create_pair(list_t<int>, vector_t<int>);
    hash_multimap_iterator_t it_iter;
    vector_t* pvec = create_vector(int);
    list_t* plist = create_list(int);
    int i = 0;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_hash_multimap, 0, _test_hash_multimap_insert__hash, NULL);
    list_init(plist);
    vector_init(pvec);

    for(i = 0; i < 10; i++)
    {
        list_clear(plist);
        vector_clear(pvec);
        vector_push_back(pvec, i);
        list_push_back(plist, i);
        pair_make(pt_pair, plist, pvec);
        hash_multimap_insert(pt_hash_multimap, pt_pair);
    }

    list_clear(plist);
    list_push_back(plist, 6);
    vector_clear(pvec);
    vector_push_back(pvec, 3);
    pair_make(pt_pair, plist, pvec);
    it_iter = hash_multimap_insert(pt_hash_multimap, pt_pair);
    assert_true(*(int*)list_front((list_t*)pair_first((pair_t*)iterator_get_pointer(it_iter))) == 6);
    assert_true(hash_multimap_size(pt_hash_multimap) == 11);

    hash_multimap_destroy(pt_hash_multimap);
    list_destroy(plist);
    pair_destroy(pt_pair);
    vector_destroy(pvec);
}

void test_hash_multimap_insert__libcstl_builtin_not_equal(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(list_t<int>, vector_t<int>);
    pair_t* pt_pair = create_pair(list_t<int>, vector_t<int>);
    hash_multimap_iterator_t it_iter;
    vector_t* pvec = create_vector(int);
    list_t* plist = create_list(int);
    int i = 0;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_hash_multimap, 0, _test_hash_multimap_insert__hash, NULL);
    list_init(plist);
    vector_init(pvec);

    for(i = 0; i < 10; i++)
    {
        list_clear(plist);
        vector_clear(pvec);
        vector_push_back(pvec, i);
        list_push_back(plist, i);
        pair_make(pt_pair, plist, pvec);
        hash_multimap_insert(pt_hash_multimap, pt_pair);
    }

    list_clear(plist);
    list_push_back(plist, 44);
    vector_clear(pvec);
    vector_push_back(pvec, 3);
    pair_make(pt_pair, plist, pvec);
    it_iter = hash_multimap_insert(pt_hash_multimap, pt_pair);
    assert_true(*(int*)list_front((list_t*)pair_first((pair_t*)iterator_get_pointer(it_iter))) == 44);
    assert_true(hash_multimap_size(pt_hash_multimap) == 11);

    hash_multimap_destroy(pt_hash_multimap);
    list_destroy(plist);
    pair_destroy(pt_pair);
    vector_destroy(pvec);
}

typedef struct _tag_test_hash_multimap_insert__user_define
{
    int n_elem;
}_test_hash_multimap_insert__user_define_t;
void test_hash_multimap_insert__user_define_equal(void** state)
{
    hash_multimap_t* pt_hash_multimap = NULL;
    pair_t* pt_pair = NULL;
    hash_multimap_iterator_t it_iter;
    _test_hash_multimap_insert__user_define_t elem;
    int i = 0;

    type_register(_test_hash_multimap_insert__user_define_t, NULL, NULL, NULL, NULL);

    pt_hash_multimap = create_hash_multimap(_test_hash_multimap_insert__user_define_t, _test_hash_multimap_insert__user_define_t);
    pt_pair = create_pair(_test_hash_multimap_insert__user_define_t, _test_hash_multimap_insert__user_define_t);

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        elem.n_elem = i;
        pair_make(pt_pair, &elem, &elem);
        hash_multimap_insert(pt_hash_multimap, pt_pair);
    }

    elem.n_elem = 8;
    pair_make(pt_pair, &elem, &elem);
    it_iter = hash_multimap_insert(pt_hash_multimap, pt_pair);
    assert_true(((_test_hash_multimap_insert__user_define_t*)pair_first((pair_t*)iterator_get_pointer(it_iter)))->n_elem == 8);
    assert_true(hash_multimap_size(pt_hash_multimap) == 11);

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert__user_define_not_equal(void** state)
{
    hash_multimap_t* pt_hash_multimap =  create_hash_multimap(_test_hash_multimap_insert__user_define_t, _test_hash_multimap_insert__user_define_t);
    pair_t* pt_pair = create_pair(_test_hash_multimap_insert__user_define_t, _test_hash_multimap_insert__user_define_t);
    hash_multimap_iterator_t it_iter;
    _test_hash_multimap_insert__user_define_t elem;
    int i = 0;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    for(i = 0; i < 10; ++i)
    {
        elem.n_elem = i * 2;
        pair_make(pt_pair, &elem, &elem);
        hash_multimap_insert(pt_hash_multimap, pt_pair);
    }

    elem.n_elem = 7;
    pair_make(pt_pair, &elem, &elem);
    it_iter = hash_multimap_insert(pt_hash_multimap, pt_pair);
    assert_true(((_test_hash_multimap_insert__user_define_t*)pair_first((pair_t*)iterator_get_pointer(it_iter)))->n_elem == 7);
    assert_true(hash_multimap_size(pt_hash_multimap) == 11);

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_insert_range
 */
UT_CASE_DEFINATION(hash_multimap_insert_range)
void test_hash_multimap_insert_range__null_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_insert_range(NULL, hash_multimap_begin(pt_hash_multimap), hash_multimap_end(pt_hash_multimap)));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_insert_range__non_inited(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    hash_multimap_init_ex(pt_src, 0, NULL, NULL);
    pair_init_elem(pt_pair, 3, 3);
    hash_multimap_insert(pt_src, pt_pair);

    pt_dest->_pair_temp._t_typeinfofirst._t_style = 8888;
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    expect_assert_failure(hash_multimap_insert_range(pt_dest, it_begin, it_end));
    pt_dest->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert_range__non_inited_pair(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    void* pv_tmp = NULL;
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    hash_multimap_init_ex(pt_src, 0, NULL, NULL);

    pv_tmp = pt_dest->_pair_temp._pv_first;
    pt_dest->_pair_temp._pv_first = NULL;
    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    expect_assert_failure(hash_multimap_insert_range(pt_dest, it_begin, it_end));
    pt_dest->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_insert_range__invalid_begin(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    hash_multimap_init_ex(pt_src, 0, NULL, NULL);

    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    it_begin._t_containertype = 33333;
    expect_assert_failure(hash_multimap_insert_range(pt_dest, it_begin, it_end));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_insert_range__invalid_end(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    hash_multimap_init_ex(pt_src, 0, NULL, NULL);

    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    it_end._t_iteratortype = 3333;
    expect_assert_failure(hash_multimap_insert_range(pt_dest, it_begin, it_end));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_insert_range__invalid_range(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int elem = 0;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    hash_multimap_init_ex(pt_src, 0, NULL, NULL);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_src, pt_pair);

    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    expect_assert_failure(hash_multimap_insert_range(pt_dest, it_end, it_begin));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert_range__not_same_type(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(double, int);
    pair_t* ppair = create_pair(double, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    hash_multimap_init_ex(pt_src, 0, NULL, NULL);
    pair_init_elem(ppair, 10.2, 3);
    hash_multimap_insert(pt_src, ppair);

    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    expect_assert_failure(hash_multimap_insert_range(pt_dest, it_begin, it_end));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(ppair);
}

void test_hash_multimap_insert_range__empty(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    hash_multimap_init_ex(pt_src, 0, NULL, NULL);

    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    hash_multimap_insert_range(pt_dest, it_begin, it_end);
    assert_true(hash_multimap_empty(pt_dest));

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
}

void test_hash_multimap_insert_range__non_empty_equal(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int i = 0;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    hash_multimap_init_ex(pt_src, 0, NULL, NULL);
    pair_init(pt_pair);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_dest, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_src, pt_pair);
    }

    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    hash_multimap_insert_range(pt_dest, it_begin, it_end);
    assert_true(hash_multimap_size(pt_dest) == 20);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert_range__non_empty_dest_src_dup(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int i = 0;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    hash_multimap_init_ex(pt_src, 0, NULL, NULL);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_dest, pt_pair);
    }
    for(i = 5; i < 15; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_src, pt_pair);
    }

    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    hash_multimap_insert_range(pt_dest, it_begin, it_end);
    assert_true(hash_multimap_size(pt_dest) == 20);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert_range__non_empty_src_dup(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int i = 0;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    hash_multimap_init_ex(pt_src, 0, NULL, NULL);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_dest, pt_pair);
    }
    for(i = 15; i < 25; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_src, pt_pair);
        hash_multimap_insert(pt_src, pt_pair);
    }

    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    hash_multimap_insert_range(pt_dest, it_begin, it_end);
    assert_true(hash_multimap_size(pt_dest) == 30);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

static void _test_hash_multimap_insert_range__compare(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first < *(int*)cpv_second ? true : false;
}
void test_hash_multimap_insert_range__compare(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_t* pt_src = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    hash_multimap_init_ex(pt_src, 0, NULL, _test_hash_multimap_insert_range__compare);

    it_begin = hash_multimap_begin(pt_src);
    it_end = hash_multimap_end(pt_src);
    hash_multimap_insert_range(pt_dest, it_begin, it_end);

    hash_multimap_destroy(pt_dest);
    hash_multimap_destroy(pt_src);
    pair_destroy(pt_pair);
}

void test_hash_multimap_insert_range__other(void** state)
{
    hash_multimap_t* phmmap = create_hash_multimap(int, int);
    list_t* plist = create_list(pair_t<int, int>);
    pair_t* ppair = create_pair(int, int);

    pair_init_elem(ppair, 1, 10);
    list_init_elem(plist, 10, ppair);
    hash_multimap_init(phmmap);
    hash_multimap_insert_range(phmmap, list_begin(plist), list_end(plist));
    assert_true(hash_multimap_size(phmmap) == 10);

    hash_multimap_destroy(phmmap);
    list_destroy(plist);
    pair_destroy(ppair);
}

void test_hash_multimap_insert_range__other_not_same(void** state)
{
    hash_multimap_t* phmmap = create_hash_multimap(int, double);
    list_t* plist = create_list(pair_t<int, int>);
    pair_t* ppair = create_pair(int, int);

    pair_init_elem(ppair, 1, 10);
    list_init_elem(plist, 10, ppair);
    hash_multimap_init(phmmap);
    expect_assert_failure(hash_multimap_insert_range(phmmap, list_begin(plist), list_end(plist)));

    hash_multimap_destroy(phmmap);
    list_destroy(plist);
    pair_destroy(ppair);
}

/*
 * test hash_multimap_insert_array
 */
UT_CASE_DEFINATION(hash_multimap_insert_array)
void test_hash_multimap_insert_array__null_hash_multimap(void** state)
{
    pair_t* apair[10] = {NULL};
    expect_assert_failure(hash_multimap_insert_array(NULL, apair, 10));
}

void test_hash_multimap_insert_array__non_inited(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);

    pt_dest->_pair_temp._t_typeinfofirst._t_style = 8888;
    expect_assert_failure(hash_multimap_insert_array(pt_dest, apair, 10));
    pt_dest->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_insert_array__non_inited_pair(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    void* pv_tmp = NULL;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);

    pv_tmp = pt_dest->_pair_temp._pv_first;
    pt_dest->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_insert_array(pt_dest, apair, 10));
    pt_dest->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_insert_array__invalid_array(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_insert_array(pt_dest, NULL, 10));

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_insert_array__not_same_type(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    int i = 0;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    for (i = 0; i < 10; ++i) {
        apair[i] = create_pair(int, double);
        pair_init(apair[i]);
    }

    expect_assert_failure(hash_multimap_insert_array(pt_dest, apair, 10));

    hash_multimap_destroy(pt_dest);
    for (i = 0; i < 10; ++i) {
        pair_destroy(apair[i]);
    }
}

void test_hash_multimap_insert_array__empty(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    int i = 0;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    for (i = 0; i < 10; ++i) {
        apair[i] = create_pair(int, int);
        pair_init(apair[i]);
    }

    hash_multimap_insert_array(pt_dest, apair, 0);
    assert_true(hash_multimap_empty(pt_dest));

    hash_multimap_destroy(pt_dest);
    for (i = 0; i < 10; ++i) {
        pair_destroy(apair[i]);
    }
}

void test_hash_multimap_insert_array__non_empty_equal(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i = 0;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    pair_init(pt_pair);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_dest, pt_pair);
    }
    for(i = 10; i < 20; ++i)
    {
        apair[i - 10] = create_pair(int, int);
        pair_init_elem(apair[i - 10], i, i);
    }

    hash_multimap_insert_array(pt_dest, apair, 10);
    assert_true(hash_multimap_size(pt_dest) == 20);

    hash_multimap_destroy(pt_dest);
    pair_destroy(pt_pair);
    for (i = 0; i < 10; ++i) {
        pair_destroy(apair[i]);
    }
}

void test_hash_multimap_insert_array__non_empty_dest_src_dup(void** state)
{
    pair_t* apair[10] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i = 0;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_dest, pt_pair);
    }
    for(i = 5; i < 15; ++i)
    {
        apair[i - 5] = create_pair(int, int);
        pair_init_elem(apair[i - 5], i, i);
    }

    hash_multimap_insert_array(pt_dest, apair, 10);
    assert_true(hash_multimap_size(pt_dest) == 20);

    hash_multimap_destroy(pt_dest);
    pair_destroy(pt_pair);
    for (i = 0; i < 10; ++i) {
        pair_destroy(apair[i]);
    }
}

void test_hash_multimap_insert_array__non_empty_src_dup(void** state)
{
    pair_t* apair[20] = {NULL};
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int i = 0;

    pair_init(pt_pair);
    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_dest, pt_pair);
    }
    for (i = 0; i < 20; i += 2)
    {
        apair[i] = create_pair(int, int);
        pair_init_elem(apair[i], i + 15, i + 15);
        apair[i + 1] = create_pair(int, int);
        pair_init_elem(apair[i + 1], i + 15, i + 15);
    }

    hash_multimap_insert_array(pt_dest, apair, 20);
    assert_true(hash_multimap_size(pt_dest) == 30);

    hash_multimap_destroy(pt_dest);
    pair_destroy(pt_pair);
    for (i = 0; i < 20; ++i) {
        pair_destroy(apair[i]);
    }
}

/*
 * test hash_multimap_erase_pos
 */
UT_CASE_DEFINATION(hash_multimap_erase_pos)
void test_hash_multimap_erase_pos__null_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    int elem = 9;

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    expect_assert_failure(hash_multimap_erase_pos(NULL, hash_multimap_begin(pt_hash_multimap)));

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_erase_pos__non_inited(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_pos;
    int elem = 9;

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    it_pos = hash_multimap_begin(pt_hash_multimap);
    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = 9999;
    expect_assert_failure(hash_multimap_erase_pos(pt_hash_multimap, it_pos));
    pt_hash_multimap->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_erase_pos__non_inited_pair(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    void* pv_tmp = NULL;
    hash_multimap_iterator_t it_pos;
    int elem = 9;

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    it_pos = hash_multimap_begin(pt_hash_multimap);
    pv_tmp = pt_hash_multimap->_pair_temp._pv_first;
    pt_hash_multimap->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_erase_pos(pt_hash_multimap, it_pos));
    pt_hash_multimap->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_erase_pos__invalid_pos(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_pos;
    int elem = 9;

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    it_pos = hash_multimap_begin(pt_hash_multimap);
    it_pos._t_iteratortype = 99494;
    expect_assert_failure(hash_multimap_erase_pos(pt_hash_multimap, it_pos));

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_erase_pos__end(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_pos;
    int elem = 9;

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    it_pos = hash_multimap_end(pt_hash_multimap);
    expect_assert_failure(hash_multimap_erase_pos(pt_hash_multimap, it_pos));

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_erase_pos__begin(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_pos;
    int i = 0;

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    pair_init(pt_pair);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_hash_multimap, pt_pair);
    }
    it_pos = hash_multimap_begin(pt_hash_multimap);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(it_pos)) == 0);
    hash_multimap_erase_pos(pt_hash_multimap, it_pos);
    assert_true(hash_multimap_size(pt_hash_multimap) == 9);
    it_pos = hash_multimap_begin(pt_hash_multimap);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(it_pos)) == 1);

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_erase_pos__middle(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_pos;
    int i = 0;

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    pair_init(pt_pair);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_hash_multimap, pt_pair);
    }
    i = 4;
    it_pos = hash_multimap_find(pt_hash_multimap, i);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(it_pos)) == 4);
    hash_multimap_erase_pos(pt_hash_multimap, it_pos);
    assert_true(hash_multimap_size(pt_hash_multimap) == 9);
    it_pos = hash_multimap_find(pt_hash_multimap, i);
    assert_true(iterator_equal(it_pos, hash_multimap_end(pt_hash_multimap)));

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_erase_pos__last(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_pos;
    int i = 0;

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    pair_init(pt_pair);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_hash_multimap, pt_pair);
    }
    it_pos = iterator_prev(hash_multimap_end(pt_hash_multimap));
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(it_pos)) == 9);
    hash_multimap_erase_pos(pt_hash_multimap, it_pos);
    assert_true(hash_multimap_size(pt_hash_multimap) == 9);
    it_pos = iterator_prev(hash_multimap_end(pt_hash_multimap));
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(it_pos)) == 8);

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

void test_hash_multimap_erase_pos__erase_empty(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_pos;
    int i = 0;

    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);
    pair_init_elem(pt_pair, i, i);
    hash_multimap_insert(pt_hash_multimap, pt_pair);
    assert_true(hash_multimap_size(pt_hash_multimap) == 1);
    it_pos = hash_multimap_begin(pt_hash_multimap);
    hash_multimap_erase_pos(pt_hash_multimap, it_pos);
    assert_true(hash_multimap_size(pt_hash_multimap) == 0);

    hash_multimap_destroy(pt_hash_multimap);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_erase_range
 */
UT_CASE_DEFINATION(hash_multimap_erase_range)
void test_hash_multimap_erase_range__null_hash_multimap(void** state)
{
    hash_multimap_t* pt_hash_multimap = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_hash_multimap, 0, NULL, NULL);

    expect_assert_failure(hash_multimap_erase_range(NULL, hash_multimap_begin(pt_hash_multimap), hash_multimap_end(pt_hash_multimap)));

    hash_multimap_destroy(pt_hash_multimap);
}

void test_hash_multimap_erase_range__non_inited(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);

    it_begin = hash_multimap_begin(pt_dest);
    it_end = hash_multimap_end(pt_dest);
    pt_dest->_pair_temp._t_typeinfofirst._t_style = 999;
    expect_assert_failure(hash_multimap_erase_range(pt_dest, it_begin, it_end));
    pt_dest->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_erase_range__non_inited_pair(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    void* pv_tmp = NULL;
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);

    it_begin = hash_multimap_begin(pt_dest);
    it_end = hash_multimap_end(pt_dest);
    pv_tmp = pt_dest->_pair_temp._pv_first;
    pt_dest->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_erase_range(pt_dest, it_begin, it_end));
    pt_dest->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_erase_range__invalid_begin(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);

    it_begin = hash_multimap_begin(pt_dest);
    it_end = hash_multimap_end(pt_dest);
    it_begin._t_containertype = 555;
    expect_assert_failure(hash_multimap_erase_range(pt_dest, it_begin, it_end));

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_erase_range__invalid_end(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);

    it_begin = hash_multimap_begin(pt_dest);
    it_end = hash_multimap_end(pt_dest);
    it_end._t_iteratortype = 5555;
    expect_assert_failure(hash_multimap_erase_range(pt_dest, it_begin, it_end));

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_erase_range__invalid_range(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int elem = 0;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    pair_init_elem(pt_pair, elem, elem);
    hash_multimap_insert(pt_dest, pt_pair);

    it_begin = hash_multimap_begin(pt_dest);
    it_end = hash_multimap_end(pt_dest);
    expect_assert_failure(hash_multimap_erase_range(pt_dest, it_end, it_begin));

    hash_multimap_destroy(pt_dest);
    pair_destroy(pt_pair);
}

void test_hash_multimap_erase_range__empty(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int,int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);

    it_begin = hash_multimap_begin(pt_dest);
    it_end = hash_multimap_end(pt_dest);
    hash_multimap_erase_range(pt_dest, it_begin, it_end);
    assert_true(hash_multimap_empty(pt_dest));

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_erase_range__begin(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int,int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int i = 0;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    pair_init(pt_pair);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_dest, pt_pair);
    }

    it_begin = hash_multimap_begin(pt_dest);
    it_end = iterator_next(it_begin);
    hash_multimap_erase_range(pt_dest, it_begin, it_end);
    assert_true(hash_multimap_size(pt_dest) == 9);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(hash_multimap_begin(pt_dest))) == 1);

    hash_multimap_destroy(pt_dest);
    pair_destroy(pt_pair);
}

void test_hash_multimap_erase_range__middle(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int i = 0;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    pair_init(pt_pair);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_dest, pt_pair);
    }

    it_begin = iterator_next(hash_multimap_begin(pt_dest));
    it_end = iterator_next(it_begin);
    hash_multimap_erase_range(pt_dest, it_begin, it_end);
    assert_true(hash_multimap_size(pt_dest) == 9);
    it_begin = hash_multimap_begin(pt_dest);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(it_begin)) == 0);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(iterator_next(it_begin))) == 2);

    hash_multimap_destroy(pt_dest);
    pair_destroy(pt_pair);
}

void test_hash_multimap_erase_range__end(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int i = 0;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    pair_init(pt_pair);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_dest, pt_pair);
    }

    it_end = hash_multimap_end(pt_dest);
    it_begin = iterator_prev(it_end);
    hash_multimap_erase_range(pt_dest, it_begin, it_end);
    assert_true(hash_multimap_size(pt_dest) == 9);
    it_end = hash_multimap_end(pt_dest);
    assert_true(*(int*)pair_first((pair_t*)iterator_get_pointer(iterator_prev(it_end))) == 8);

    hash_multimap_destroy(pt_dest);
    pair_destroy(pt_pair);
}

void test_hash_multimap_erase_range__all(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    pair_t* pt_pair = create_pair(int, int);
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;
    int i = 0;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    pair_init(pt_pair);
    for(i = 0; i < 10; ++i)
    {
        pair_make(pt_pair, i, i);
        hash_multimap_insert(pt_dest, pt_pair);
    }

    it_begin = hash_multimap_begin(pt_dest);
    it_end = hash_multimap_end(pt_dest);
    hash_multimap_erase_range(pt_dest, it_begin, it_end);
    assert_true(hash_multimap_size(pt_dest) == 0);

    hash_multimap_destroy(pt_dest);
    pair_destroy(pt_pair);
}

/*
 * test hash_multimap_resize
 */
UT_CASE_DEFINATION(hash_multimap_resize)
void test_hash_multimap_resize__null_hash_multimap(void** state)
{
    expect_assert_failure(hash_multimap_resize(NULL, 100));
}

void test_hash_multimap_resize__non_inited(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);

    pt_dest->_pair_temp._t_typeinfofirst._t_style = 999;
    expect_assert_failure(hash_multimap_resize(pt_dest, 100));
    pt_dest->_pair_temp._t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_resize__non_inited_pair(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);
    void* pv_tmp = NULL;
    hash_multimap_iterator_t it_begin;
    hash_multimap_iterator_t it_end;

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);

    it_begin = hash_multimap_begin(pt_dest);
    it_end = hash_multimap_end(pt_dest);
    pv_tmp = pt_dest->_pair_temp._pv_first;
    pt_dest->_pair_temp._pv_first = NULL;
    expect_assert_failure(hash_multimap_resize(pt_dest, 100));
    pt_dest->_pair_temp._pv_first = pv_tmp;

    hash_multimap_destroy(pt_dest);
}

void test_hash_multimap_resize__resize(void** state)
{
    hash_multimap_t* pt_dest = create_hash_multimap(int, int);

    hash_multimap_init_ex(pt_dest, 0, NULL, NULL);
    assert_true(hash_multimap_bucket_count(pt_dest) == 53);
    hash_multimap_resize(pt_dest, 100);
    assert_true(hash_multimap_bucket_count(pt_dest) == 193);

    hash_multimap_destroy(pt_dest);
}

