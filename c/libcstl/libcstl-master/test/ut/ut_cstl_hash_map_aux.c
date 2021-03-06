#include <stddef.h>
#include <stdarg.h>
#include <setjmp.h>
#include <google/cmockery.h>

#include "cstl/cstl_def.h"
#include "cstl/citerator.h"
#include "cstl/chash_map.h"
#include "cstl/cstring.h"
#include "cstl/cvector.h"
#include "cstl_hash_map_aux.h"

#include "ut_def.h"
#include "ut_cstl_hash_map_aux.h"

UT_SUIT_DEFINATION(cstl_hash_map_aux, _hash_map_same_pair_type_ex)

/*
 * test _hash_map_same_pair_type_ex
 */
UT_CASE_DEFINATION(_hash_map_same_pair_type_ex)
void test__hash_map_same_pair_type_ex__first_null(void** state)
{
    pair_t* ppair = create_pair(int, int);
    pair_init(ppair);

    expect_assert_failure(_hash_map_same_pair_type_ex(NULL, ppair));

    pair_destroy(ppair);
}

void test__hash_map_same_pair_type_ex__second_null(void** state)
{
    pair_t* ppair = create_pair(int, int);
    pair_init(ppair);

    expect_assert_failure(_hash_map_same_pair_type_ex(ppair, NULL));

    pair_destroy(ppair);
}

void test__hash_map_same_pair_type_ex__first_noninited(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);

    ppair_first->_t_typeinfofirst._t_style = 99999;
    expect_assert_failure(_hash_map_same_pair_type_ex(ppair_first, ppair_second));
    ppair_first->_t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_same_pair_type_ex__second_noninited(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);

    ppair_second->_t_typeinfosecond._t_style = 9999;
    expect_assert_failure(_hash_map_same_pair_type_ex(ppair_first, ppair_second));
    ppair_second->_t_typeinfosecond._t_style = _TYPE_C_BUILTIN;

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_same_pair_type_ex__same_pair(void** state)
{
    pair_t* ppair = create_pair(int, int);
    pair_init(ppair);

    assert_true(_hash_map_same_pair_type_ex(ppair, ppair));

    pair_destroy(ppair);
}

void test__hash_map_same_pair_type_ex__not_same_first_type(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(double, int);
    pair_init(ppair_first);
    pair_init(ppair_second);

    assert_false(_hash_map_same_pair_type_ex(ppair_first, ppair_second));

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_same_pair_type_ex__not_same_second_type(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, double);
    pair_init(ppair_first);
    pair_init(ppair_second);

    assert_false(_hash_map_same_pair_type_ex(ppair_first, ppair_second));

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_same_pair_type_ex__not_mapkeycompare(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);
    pair_init(ppair_first);
    pair_init(ppair_second);

    ppair_first->_bfun_mapkeycompare = (binary_function_t)0x3333;
    assert_false(_hash_map_same_pair_type_ex(ppair_first, ppair_second));

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_same_pair_type_ex__not_mapvaluecompare(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);
    pair_init(ppair_first);
    pair_init(ppair_second);

    ppair_first->_bfun_mapvaluecompare = (binary_function_t)0x8888;
    assert_false(_hash_map_same_pair_type_ex(ppair_first, ppair_second));

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_same_pair_type_ex__same_type(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);
    pair_init(ppair_first);
    pair_init(ppair_second);

    assert_true(_hash_map_same_pair_type_ex(ppair_first, ppair_second));

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

/*
 * test _hash_map_same_pair_type
 */
UT_CASE_DEFINATION(_hash_map_same_pair_type)
void test__hash_map_same_pair_type__first_null(void** state)
{
    pair_t* ppair = create_pair(int, int);
    pair_init(ppair);

    expect_assert_failure(_hash_map_same_pair_type(NULL, ppair));

    pair_destroy(ppair);
}

void test__hash_map_same_pair_type__second_null(void** state)
{
    pair_t* ppair = create_pair(int, int);
    pair_init(ppair);

    expect_assert_failure(_hash_map_same_pair_type(ppair, NULL));

    pair_destroy(ppair);
}

void test__hash_map_same_pair_type__first_noninited(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);

    ppair_first->_t_typeinfofirst._t_style = 99999;
    expect_assert_failure(_hash_map_same_pair_type(ppair_first, ppair_second));
    ppair_first->_t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_same_pair_type__second_noninited(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);

    ppair_second->_t_typeinfosecond._t_style = 9999;
    expect_assert_failure(_hash_map_same_pair_type(ppair_first, ppair_second));
    ppair_second->_t_typeinfosecond._t_style = _TYPE_C_BUILTIN;

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_same_pair_type__same_pair(void** state)
{
    pair_t* ppair = create_pair(int, int);
    pair_init(ppair);

    assert_true(_hash_map_same_pair_type(ppair, ppair));

    pair_destroy(ppair);
}

void test__hash_map_same_pair_type__not_same_first_type(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(double, int);
    pair_init(ppair_first);
    pair_init(ppair_second);

    assert_false(_hash_map_same_pair_type(ppair_first, ppair_second));

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_same_pair_type__not_same_second_type(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, double);
    pair_init(ppair_first);
    pair_init(ppair_second);

    assert_false(_hash_map_same_pair_type(ppair_first, ppair_second));

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_same_pair_type__not_mapkeycompare(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);
    pair_init(ppair_first);
    pair_init(ppair_second);

    ppair_first->_bfun_mapkeycompare = (binary_function_t)0x3333;
    assert_true(_hash_map_same_pair_type(ppair_first, ppair_second));

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_same_pair_type__not_mapvaluecompare(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);
    pair_init(ppair_first);
    pair_init(ppair_second);

    ppair_first->_bfun_mapvaluecompare = (binary_function_t)0x8888;
    assert_true(_hash_map_same_pair_type(ppair_first, ppair_second));

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_same_pair_type__same_type(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);
    pair_init(ppair_first);
    pair_init(ppair_second);

    assert_true(_hash_map_same_pair_type(ppair_first, ppair_second));

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

/*
 * test _hash_map_value_compare
 */
UT_CASE_DEFINATION(_hash_map_value_compare)
void test__hash_map_value_compare__null_first(void** state)
{
    int n_second;
    bool_t b_output;

    expect_assert_failure(_hash_map_value_compare(NULL, &n_second, &b_output));
}

void test__hash_map_value_compare__null_second(void** state)
{
    int n_first;
    bool_t b_output;

    expect_assert_failure(_hash_map_value_compare(&n_first, NULL, &b_output));
}

void test__hash_map_value_compare__null_output(void** state)
{
    int n_first;
    int n_second;

    expect_assert_failure(_hash_map_value_compare(&n_first, &n_second, NULL));
}

void test__hash_map_value_compare__noninited_first(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);
    bool_t b_output;

    ppair_first->_t_typeinfofirst._t_style = 9999;
    expect_assert_failure(_hash_map_value_compare(ppair_first, ppair_second, &b_output));
    ppair_first->_t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_value_compare__noninited_second(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);
    bool_t b_output;

    ppair_second->_t_typeinfofirst._t_style = 9999;
    expect_assert_failure(_hash_map_value_compare(ppair_first, ppair_second, &b_output));
    ppair_second->_t_typeinfofirst._t_style = _TYPE_C_BUILTIN;

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_value_compare__not_same(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, double);
    bool_t b_output;

    expect_assert_failure(_hash_map_value_compare(ppair_first, ppair_second, &b_output));

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_value_compare__no_mapkeycompare_result_true(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);
    bool_t b_output = false;

    pair_init_elem(ppair_first, 2, 9);
    pair_init_elem(ppair_second, 3, 30);

    _hash_map_value_compare(ppair_first, ppair_second, &b_output);
    assert_true(b_output);

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_value_compare__no_mapkeycompare_result_false(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);
    bool_t b_output = false;

    pair_init_elem(ppair_first, 53, 9);
    pair_init_elem(ppair_second, 3, 30);

    _hash_map_value_compare(ppair_first, ppair_second, &b_output);
    assert_false(b_output);

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void _test__hash_map_value_compare(const void* cpv_first, const void* cpv_second, void* pv_output)
{
    *(bool_t*)pv_output = *(int*)cpv_first == *(int*)cpv_second ? true : false;
}

void test__hash_map_value_compare__user_mapkeycompare_result_true(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);
    bool_t b_output = false;

    pair_init_elem(ppair_first, 53, 30);
    ppair_first->_bfun_mapkeycompare = _test__hash_map_value_compare;
    pair_init_elem(ppair_second, 53, 30);
    ppair_second->_bfun_mapkeycompare = _test__hash_map_value_compare;

    _hash_map_value_compare(ppair_first, ppair_second, &b_output);
    assert_true(b_output);

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

void test__hash_map_value_compare__user_mapkeycompare_result_false(void** state)
{
    pair_t* ppair_first = create_pair(int, int);
    pair_t* ppair_second = create_pair(int, int);
    bool_t b_output = false;

    pair_init_elem(ppair_first, 33, 3);
    ppair_first->_bfun_mapkeycompare = _test__hash_map_value_compare;
    pair_init_elem(ppair_second, 53, 30);
    ppair_second->_bfun_mapkeycompare = _test__hash_map_value_compare;

    _hash_map_value_compare(ppair_first, ppair_second, &b_output);
    assert_false(b_output);

    pair_destroy(ppair_first);
    pair_destroy(ppair_second);
}

/*
 * test _hash_map_default_hash
 */
UT_CASE_DEFINATION(_hash_map_default_hash)
void test__hash_map_default_hash__null_input(void** state)
{
    size_t t_result;
    expect_assert_failure(_hash_map_default_hash(NULL, &t_result));
}

void test__hash_map_default_hash__null_output(void** state)
{
    pair_t* ppair_pair = create_pair(int, int);

    pair_init(ppair_pair);
    expect_assert_failure(_hash_map_default_hash(ppair_pair, NULL));

    pair_destroy(ppair_pair);
}

void test__hash_map_default_hash__int(void** state)
{
    pair_t* ppair_pair = create_pair(int, int);
    size_t t_result = 0;
    pair_init_elem(ppair_pair, 0x01020304, 100);

    _hash_map_default_hash(ppair_pair, &t_result);
    assert_true(t_result == 10);

    pair_destroy(ppair_pair);
}

void test__hash_map_default_hash__cstr(void** state)
{
    pair_t* ppair_pair = create_pair(char*, int);
    size_t t_result = 0;
    pair_init_elem(ppair_pair, "abc", 100);

    _hash_map_default_hash(ppair_pair, &t_result);
    assert_true(t_result == 294);

    pair_destroy(ppair_pair);
}

