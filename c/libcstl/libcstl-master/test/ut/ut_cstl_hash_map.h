#ifndef _UT_CSTL_HASH_MAP_H_
#define _UT_CSTL_HASH_MAP_H_

UT_SUIT_DECLARATION(cstl_hash_map)
/*
 * test hash_map_init
 */
UT_CASE_DECLARATION(hash_map_init)
void test_hash_map_init__null_hash_map(void** state);
void test_hash_map_init__non_created(void** state);
void test_hash_map_init__non_created_pair(void** state);
void test_hash_map_init__null_compare(void** state);
/*
 * test hash_map_init_ex
 */
UT_CASE_DECLARATION(hash_map_init_ex)
void test_hash_map_init_ex__null_hash_map(void** state);
void test_hash_map_init_ex__non_created(void** state);
void test_hash_map_init_ex__non_created_pair(void** state);
void test_hash_map_init_ex__0_bucketcount(void** state);
void test_hash_map_init_ex__100_bucketcount(void** state);
void test_hash_map_init_ex__null_hash(void** state);
void test_hash_map_init_ex__non_null_hash(void** state);
void test_hash_map_init_ex__null_compare(void** state);
void test_hash_map_init_ex__non_null_compare(void** state);
/*
 * test hash_map_init_copy
 */
UT_CASE_DECLARATION(hash_map_init_copy)
void test_hash_map_init_copy__null_dest(void** state);
void test_hash_map_init_copy__null_src(void** state);
void test_hash_map_init_copy__non_created_dest(void** state);
void test_hash_map_init_copy__non_created_dest_pair(void** state);
void test_hash_map_init_copy__non_inited_src(void** state);
void test_hash_map_init_copy__non_inited_src_pair(void** state);
void test_hash_map_init_copy__not_same_type(void** state);
void test_hash_map_init_copy__empty(void** state);
void test_hash_map_init_copy__non_empty(void** state);
void test_hash_map_init_copy__bucketcount(void** state);
void test_hash_map_init_copy__non_null_hash(void** state);
void test_hash_map_init_copy__non_null_compare(void** state);
/*
 * test hash_map_init_copy_range
 */
UT_CASE_DECLARATION(hash_map_init_copy_range)
void test_hash_map_init_copy_range__null_hash_map(void** state);
void test_hash_map_init_copy_range__non_created_hash_map(void** state);
void test_hash_map_init_copy_range__non_created_hash_map_pair(void** state);
void test_hash_map_init_copy_range__invalid_begin(void** state);
void test_hash_map_init_copy_range__invalid_end(void** state);
void test_hash_map_init_copy_range__invalid_range(void** state);
void test_hash_map_init_copy_range__invalid_range_not_same_type(void** state);
void test_hash_map_init_copy_range__empty(void** state);
void test_hash_map_init_copy_range__non_empty(void** state);
void test_hash_map_init_copy_range__other(void** state);
void test_hash_map_init_copy_range__other_not_same(void** state);
/*
 * test hash_map_init_copy_array
 */
UT_CASE_DECLARATION(hash_map_init_copy_array)
void test_hash_map_init_copy_array__null_hash_map(void** state);
void test_hash_map_init_copy_array__non_created_hash_map(void** state);
void test_hash_map_init_copy_array__non_created_hash_map_pair(void** state);
void test_hash_map_init_copy_array__invalid_array(void** state);
void test_hash_map_init_copy_array__invalid_array_not_same_type(void** state);
void test_hash_map_init_copy_array__empty(void** state);
void test_hash_map_init_copy_array__non_empty(void** state);
void test_hash_map_init_copy_array__non_empty_dup(void** state);
/*
 * test hash_map_init_copy_range_ex
 */
UT_CASE_DECLARATION(hash_map_init_copy_range_ex)
void test_hash_map_init_copy_range_ex__null_hash_map(void** state);
void test_hash_map_init_copy_range_ex__non_created_hash_map(void** state);
void test_hash_map_init_copy_range_ex__non_created_hash_map_pair(void** state);
void test_hash_map_init_copy_range_ex__invalid_begin(void** state);
void test_hash_map_init_copy_range_ex__invalid_end(void** state);
void test_hash_map_init_copy_range_ex__invalid_range(void** state);
void test_hash_map_init_copy_range_ex__invalid_range_not_same_type(void** state);
void test_hash_map_init_copy_range_ex__empty(void** state);
void test_hash_map_init_copy_range_ex__non_empty(void** state);
void test_hash_map_init_copy_range_ex__bucketcount(void** state);
void test_hash_map_init_copy_range_ex__hash(void** state);
void test_hash_map_init_copy_range_ex__compare(void** state);
void test_hash_map_init_copy_range_ex__other(void** state);
void test_hash_map_init_copy_range_ex__other_not_same(void** state);
/*
 * test hash_map_init_copy_array_ex
 */
UT_CASE_DECLARATION(hash_map_init_copy_array_ex)
void test_hash_map_init_copy_array_ex__null_hash_map(void** state);
void test_hash_map_init_copy_array_ex__non_created_hash_map(void** state);
void test_hash_map_init_copy_array_ex__non_created_hash_map_pair(void** state);
void test_hash_map_init_copy_array_ex__invalid_array(void** state);
void test_hash_map_init_copy_array_ex__invalid_array_not_same_type(void** state);
void test_hash_map_init_copy_array_ex__empty(void** state);
void test_hash_map_init_copy_array_ex__non_empty(void** state);
void test_hash_map_init_copy_array_ex__non_empty_dup(void** state);
void test_hash_map_init_copy_array_ex__bucketcount(void** state);
void test_hash_map_init_copy_array_ex__hash(void** state);
void test_hash_map_init_copy_array_ex__compare(void** state);
/*
 * test hash_map_destroy
 */
UT_CASE_DECLARATION(hash_map_destroy)
void test_hash_map_destroy__null_hash_map(void** state);
void test_hash_map_destroy__non_created(void** state);
void test_hash_map_destroy__created(void** state);
void test_hash_map_destroy__inited(void** state);
void test_hash_map_destroy__non_empty(void** state);
/*
 * test hash_map_assign
 */
UT_CASE_DECLARATION(hash_map_assign)
void test_hash_map_assign__null_dest(void** state);
void test_hash_map_assign__null_src(void** state);
void test_hash_map_assign__non_created_dest(void** state);
void test_hash_map_assign__non_created_dest_pair(void** state);
void test_hash_map_assign__non_init_src(void** state);
void test_hash_map_assign__non_init_src_pair(void** state);
void test_hash_map_assign__not_same_type(void** state);
void test_hash_map_assign__empty_empty(void** state);
void test_hash_map_assign__non_empty_empty(void** state);
void test_hash_map_assign__non_empty_non_empty_less(void** state);
void test_hash_map_assign__non_empty_non_empty_size_equal(void** state);
void test_hash_map_assign__non_empty_non_empty_equal(void** state);
void test_hash_map_assign__non_empty_non_empty_greater(void** state);
void test_hash_map_assign__empty_non_empty(void** state);
/*
 * test hash_map_size
 */
UT_CASE_DECLARATION(hash_map_size)
void test_hash_map_size__null_hash_map(void** state);
void test_hash_map_size__non_inited(void** state);
void test_hash_map_size__non_inited_pair(void** state);
void test_hash_map_size__empty(void** state);
void test_hash_map_size__non_empty(void** state);
/*
 * test _hash_map_emtpy
 */
UT_CASE_DECLARATION(hash_map_empty)
void test_hash_map_empty__null_hash_map(void** state);
void test_hash_map_empty__non_inited(void** state);
void test_hash_map_empty__non_inited_pair(void** state);
void test_hash_map_empty__empty(void** state);
void test_hash_map_empty__non_empty(void** state);
/*
 * test hash_map_max_size
 */
UT_CASE_DECLARATION(hash_map_max_size)
void test_hash_map_max_size__null_hash_map(void** state);
void test_hash_map_max_size__non_inited(void** state);
void test_hash_map_max_size__non_inited_pair(void** state);
void test_hash_map_max_size__empty(void** state);
void test_hash_map_max_size__non_empty(void** state);
/*
 * test hash_map_bucket_count
 */
UT_CASE_DECLARATION(hash_map_bucket_count)
void test_hash_map_bucket_count__null_hash_map(void** state);
void test_hash_map_bucket_count__non_inited(void** state);
void test_hash_map_bucket_count__non_inited_pair(void** state);
void test_hash_map_bucket_count__0(void** state);
void test_hash_map_bucket_count__100(void** state);
/*
 * test hash_map_begin
 */
UT_CASE_DECLARATION(hash_map_begin)
void test_hash_map_begin__null_hash_map(void** state);
void test_hash_map_begin__non_inited(void** state);
void test_hash_map_begin__non_inited_pair(void** state);
void test_hash_map_begin__empty(void** state);
void test_hash_map_begin__non_empty(void** state);
/*
 * test hash_map_end
 */
UT_CASE_DECLARATION(hash_map_end)
void test_hash_map_end__null_hash_map(void** state);
void test_hash_map_end__non_inited(void** state);
void test_hash_map_end__non_inited_pair(void** state);
void test_hash_map_end__empty(void** state);
void test_hash_map_end__non_empty(void** state);
/*
 * test hash_map_hash
 */
UT_CASE_DECLARATION(hash_map_hash)
void test_hash_map_hash__null_hash_map(void** state);
void test_hash_map_hash__non_inited(void** state);
void test_hash_map_hash__default_hash(void** state);
void test_hash_map_hash__user_define_hash(void** state);
/*
 * test hash_map_key_comp
 */
UT_CASE_DECLARATION(hash_map_key_comp)
void test_hash_map_key_comp__null_hash_map(void** state);
void test_hash_map_key_comp__non_inited(void** state);
void test_hash_map_key_comp__default_key_comp(void** state);
void test_hash_map_key_comp__user_define_key_comp(void** state);
/*
 * test hash_map_value_comp
 */
UT_CASE_DECLARATION(hash_map_value_comp)
void test_hash_map_value_comp__null_hash_map(void** state);
void test_hash_map_value_comp__non_inited(void** state);
void test_hash_map_value_comp__default_value_comp(void** state);
void test_hash_map_value_comp__user_define_value_comp(void** state);
/*
 * test hash_map_clear
 */
UT_CASE_DECLARATION(hash_map_clear)
void test_hash_map_clear__null_hash_map(void** state);
void test_hash_map_clear__non_inited(void** state);
void test_hash_map_clear__non_inited_pair(void** state);
void test_hash_map_clear__empty(void** state);
void test_hash_map_clear__non_empty(void** state);
/*
 * test hash_map_equal
 */
UT_CASE_DECLARATION(hash_map_equal)
void test_hash_map_equal__null_first(void** state);
void test_hash_map_equal__null_second(void** state);
void test_hash_map_equal__non_inited_first(void** state);
void test_hash_map_equal__non_inited_first_pair(void** state);
void test_hash_map_equal__non_inited_second(void** state);
void test_hash_map_equal__non_inited_second_pair(void** state);
void test_hash_map_equal__not_same_type(void** state);
void test_hash_map_equal__same_hash_map(void** state);
void test_hash_map_equal__size_first_less_than_second(void** state);
void test_hash_map_equal__size_first_greater_than_second(void** state);
void test_hash_map_equal__size_equal_0(void** state);
void test_hash_map_equal__size_equal_elem_first_less_than_second(void** state);
void test_hash_map_equal__size_equal_elem_first_greater_than_second(void** state);
void test_hash_map_equal__bucketcount_not_equal(void** state);
void test_hash_map_equal__hash_not_equal(void** state);
void test_hash_map_equal__compare_not_equal(void** state);
void test_hash_map_equal__equal(void** state);
/*
 * test hash_map_not_equal
 */
UT_CASE_DECLARATION(hash_map_not_equal)
void test_hash_map_not_equal__null_first(void** state);
void test_hash_map_not_equal__null_second(void** state);
void test_hash_map_not_equal__non_inited_first(void** state);
void test_hash_map_not_equal__non_inited_first_pair(void** state);
void test_hash_map_not_equal__non_inited_second(void** state);
void test_hash_map_not_equal__non_inited_second_pair(void** state);
void test_hash_map_not_equal__not_same_type(void** state);
void test_hash_map_not_equal__same_hash_map(void** state);
void test_hash_map_not_equal__size_first_less_than_second(void** state);
void test_hash_map_not_equal__size_first_greater_than_second(void** state);
void test_hash_map_not_equal__size_equal_0(void** state);
void test_hash_map_not_equal__size_equal_elem_first_less_than_second(void** state);
void test_hash_map_not_equal__size_equal_elem_first_greater_than_second(void** state);
void test_hash_map_not_equal__bucketcount_not_equal(void** state);
void test_hash_map_not_equal__hash_not_equal(void** state);
void test_hash_map_not_equal__compare_not_equal(void** state);
void test_hash_map_not_equal__equal(void** state);
/*
 * test hash_map_less
 */
UT_CASE_DECLARATION(hash_map_less)
void test_hash_map_less__null_first(void** state);
void test_hash_map_less__null_second(void** state);
void test_hash_map_less__non_inited_first(void** state);
void test_hash_map_less__non_inited_first_pair(void** state);
void test_hash_map_less__non_inited_second(void** state);
void test_hash_map_less__non_inited_second_pair(void** state);
void test_hash_map_less__not_same_type(void** state);
void test_hash_map_less__same_hash_map(void** state);
void test_hash_map_less__size_first_less_than_second(void** state);
void test_hash_map_less__size_first_greater_than_second(void** state);
void test_hash_map_less__size_equal_0(void** state);
void test_hash_map_less__size_equal_elem_first_less_than_second(void** state);
void test_hash_map_less__size_equal_elem_first_greater_than_second(void** state);
void test_hash_map_less__bucketcount_not_equal(void** state);
void test_hash_map_less__hash_not_equal(void** state);
void test_hash_map_less__compare_less(void** state);
void test_hash_map_less__equal(void** state);
/*
 * test hash_map_less_equal
 */
UT_CASE_DECLARATION(hash_map_less_equal)
void test_hash_map_less_equal__null_first(void** state);
void test_hash_map_less_equal__null_second(void** state);
void test_hash_map_less_equal__non_inited_first(void** state);
void test_hash_map_less_equal__non_inited_first_pair(void** state);
void test_hash_map_less_equal__non_inited_second(void** state);
void test_hash_map_less_equal__non_inited_second_pair(void** state);
void test_hash_map_less_equal__not_same_type(void** state);
void test_hash_map_less_equal__same_hash_map(void** state);
void test_hash_map_less_equal__size_first_less_than_second(void** state);
void test_hash_map_less_equal__size_first_greater_than_second(void** state);
void test_hash_map_less_equal__size_equal_0(void** state);
void test_hash_map_less_equal__size_equal_elem_first_less_than_second(void** state);
void test_hash_map_less_equal__size_equal_elem_first_greater_than_second(void** state);
void test_hash_map_less_equal__bucketcount_not_equal(void** state);
void test_hash_map_less_equal__hash_not_equal(void** state);
void test_hash_map_less_equal__compare_less(void** state);
void test_hash_map_less_equal__equal(void** state);
/*
 * test hash_map_greater
 */
UT_CASE_DECLARATION(hash_map_greater)
void test_hash_map_greater__null_first(void** state);
void test_hash_map_greater__null_second(void** state);
void test_hash_map_greater__non_inited_first(void** state);
void test_hash_map_greater__non_inited_first_pair(void** state);
void test_hash_map_greater__non_inited_second(void** state);
void test_hash_map_greater__non_inited_second_pair(void** state);
void test_hash_map_greater__not_same_type(void** state);
void test_hash_map_greater__same_hash_map(void** state);
void test_hash_map_greater__size_first_less_than_second(void** state);
void test_hash_map_greater__size_first_greater_than_second(void** state);
void test_hash_map_greater__size_equal_0(void** state);
void test_hash_map_greater__size_equal_elem_first_less_than_second(void** state);
void test_hash_map_greater__size_equal_elem_first_greater_than_second(void** state);
void test_hash_map_greater__bucketcount_not_equal(void** state);
void test_hash_map_greater__hash_not_equal(void** state);
void test_hash_map_greater__compare_less(void** state);
void test_hash_map_greater__equal(void** state);
/*
 * test hash_map_greater_equal
 */
UT_CASE_DECLARATION(hash_map_greater_equal)
void test_hash_map_greater_equal__null_first(void** state);
void test_hash_map_greater_equal__null_second(void** state);
void test_hash_map_greater_equal__non_inited_first(void** state);
void test_hash_map_greater_equal__non_inited_first_pair(void** state);
void test_hash_map_greater_equal__non_inited_second(void** state);
void test_hash_map_greater_equal__non_inited_second_pair(void** state);
void test_hash_map_greater_equal__not_same_type(void** state);
void test_hash_map_greater_equal__same_hash_map(void** state);
void test_hash_map_greater_equal__size_first_less_than_second(void** state);
void test_hash_map_greater_equal__size_first_greater_than_second(void** state);
void test_hash_map_greater_equal__size_equal_0(void** state);
void test_hash_map_greater_equal__size_equal_elem_first_less_than_second(void** state);
void test_hash_map_greater_equal__size_equal_elem_first_greater_than_second(void** state);
void test_hash_map_greater_equal__bucketcount_not_equal(void** state);
void test_hash_map_greater_equal__hash_not_equal(void** state);
void test_hash_map_greater_equal__compare_less(void** state);
void test_hash_map_greater_equal__equal(void** state);
/*
 * test hash_map_swap
 */
UT_CASE_DECLARATION(hash_map_swap)
void test_hash_map_swap__null_first(void** state);
void test_hash_map_swap__null_second(void** state);
void test_hash_map_swap__non_inited_first(void** state);
void test_hash_map_swap__non_inited_first_pair(void** state);
void test_hash_map_swap__non_inited_second(void** state);
void test_hash_map_swap__non_inited_second_pair(void** state);
void test_hash_map_swap__not_same_type(void** state);
void test_hash_map_swap__same_hash_map(void** state);
void test_hash_map_swap__0_swap_n(void** state);
void test_hash_map_swap__n_swap_0(void** state);
void test_hash_map_swap__n_swap_n(void** state);
void test_hash_map_swap__m_swap_n(void** state);
/*
 * test hash_map_insert
 */
UT_CASE_DECLARATION(hash_map_insert)
void test_hash_map_insert__null_hash_map(void** state);
void test_hash_map_insert__null_pair(void** state);
void test_hash_map_insert__non_inited(void** state);
void test_hash_map_insert__non_inited_pair(void** state);
void test_hash_map_insert__pair_non_inited(void** state);
void test_hash_map_insert__not_smae_type(void** state);
void test_hash_map_insert__c_builtin_equal(void** state);
void test_hash_map_insert__c_builtin_not_equal(void** state);
void test_hash_map_insert__cstr_equal(void** state);
void test_hash_map_insert__cstr_not_equal(void** state);
void test_hash_map_insert__libcstl_builtin_equal(void** state);
void test_hash_map_insert__libcstl_builtin_not_equal(void** state);
void test_hash_map_insert__user_define_equal(void** state);
void test_hash_map_insert__user_define_not_equal(void** state);
/*
 * test hash_map_insert_range
 */
UT_CASE_DECLARATION(hash_map_insert_range)
void test_hash_map_insert_range__null_hash_map(void** state);
void test_hash_map_insert_range__non_inited(void** state);
void test_hash_map_insert_range__non_inited_pair(void** state);
void test_hash_map_insert_range__invalid_begin(void** state);
void test_hash_map_insert_range__invalid_end(void** state);
void test_hash_map_insert_range__invalid_range(void** state);
void test_hash_map_insert_range__not_same_type(void** state);
void test_hash_map_insert_range__empty(void** state);
void test_hash_map_insert_range__non_empty_equal(void** state);
void test_hash_map_insert_range__non_empty_dest_src_dup(void** state);
void test_hash_map_insert_range__non_empty_src_dup(void** state);
void test_hash_map_insert_range__compare(void** state);
void test_hash_map_insert_range__other(void** state);
void test_hash_map_insert_range__other_not_same(void** state);
/*
 * test hash_map_insert_array
 */
UT_CASE_DECLARATION(hash_map_insert_array)
void test_hash_map_insert_array__null_hash_map(void** state);
void test_hash_map_insert_array__non_inited(void** state);
void test_hash_map_insert_array__non_inited_pair(void** state);
void test_hash_map_insert_array__invalid_array(void** state);
void test_hash_map_insert_array__not_same_type(void** state);
void test_hash_map_insert_array__empty(void** state);
void test_hash_map_insert_array__non_empty_equal(void** state);
void test_hash_map_insert_array__non_empty_dest_src_dup(void** state);
void test_hash_map_insert_array__non_empty_src_dup(void** state);
/*
 * test hash_map_erase_pos
 */
UT_CASE_DECLARATION(hash_map_erase_pos)
void test_hash_map_erase_pos__null_hash_map(void** state);
void test_hash_map_erase_pos__non_inited(void** state);
void test_hash_map_erase_pos__non_inited_pair(void** state);
void test_hash_map_erase_pos__invalid_pos(void** state);
void test_hash_map_erase_pos__end(void** state);
void test_hash_map_erase_pos__begin(void** state);
void test_hash_map_erase_pos__middle(void** state);
void test_hash_map_erase_pos__last(void** state);
void test_hash_map_erase_pos__erase_empty(void** state);
/*
 * test hash_map_erase_range
 */
UT_CASE_DECLARATION(hash_map_erase_range)
void test_hash_map_erase_range__null_hash_map(void** state);
void test_hash_map_erase_range__non_inited(void** state);
void test_hash_map_erase_range__non_inited_pair(void** state);
void test_hash_map_erase_range__invalid_begin(void** state);
void test_hash_map_erase_range__invalid_end(void** state);
void test_hash_map_erase_range__invalid_range(void** state);
void test_hash_map_erase_range__empty(void** state);
void test_hash_map_erase_range__begin(void** state);
void test_hash_map_erase_range__middle(void** state);
void test_hash_map_erase_range__end(void** state);
void test_hash_map_erase_range__all(void** state);
/*
 * test hash_map_resize
 */
UT_CASE_DECLARATION(hash_map_resize)
void test_hash_map_resize__null_hash_map(void** state);
void test_hash_map_resize__non_inited(void** state);
void test_hash_map_resize__non_inited_pair(void** state);
void test_hash_map_resize__resize(void** state);

#define UT_CSTL_HASH_MAP_CASE\
    UT_SUIT_BEGIN(cstl_hash_map, test_hash_map_init__null_hash_map),\
    UT_CASE(test_hash_map_init__non_created),\
    UT_CASE(test_hash_map_init__non_created),\
    UT_CASE(test_hash_map_init__null_compare),\
    UT_CASE_BEGIN(hash_map_init_ex,  test_hash_map_init_ex__null_hash_map),\
    UT_CASE(test_hash_map_init_ex__non_created),\
    UT_CASE(test_hash_map_init_ex__non_created_pair),\
    UT_CASE(test_hash_map_init_ex__0_bucketcount),\
    UT_CASE(test_hash_map_init_ex__100_bucketcount),\
    UT_CASE(test_hash_map_init_ex__null_hash),\
    UT_CASE(test_hash_map_init_ex__non_null_hash),\
    UT_CASE(test_hash_map_init_ex__null_compare),\
    UT_CASE(test_hash_map_init_ex__non_null_compare),\
    UT_CASE_BEGIN(hash_map_init_copy, test_hash_map_init_copy__null_dest),\
    UT_CASE(test_hash_map_init_copy__null_src),\
    UT_CASE(test_hash_map_init_copy__non_created_dest),\
    UT_CASE(test_hash_map_init_copy__non_created_dest_pair),\
    UT_CASE(test_hash_map_init_copy__non_inited_src),\
    UT_CASE(test_hash_map_init_copy__non_inited_src_pair),\
    UT_CASE(test_hash_map_init_copy__not_same_type),\
    UT_CASE(test_hash_map_init_copy__empty),\
    UT_CASE(test_hash_map_init_copy__non_empty),\
    UT_CASE(test_hash_map_init_copy__bucketcount),\
    UT_CASE(test_hash_map_init_copy__non_null_hash),\
    UT_CASE(test_hash_map_init_copy__non_null_compare),\
    UT_CASE_BEGIN(hash_map_init_copy_range, test_hash_map_init_copy_range__null_hash_map),\
    UT_CASE(test_hash_map_init_copy_range__non_created_hash_map),\
    UT_CASE(test_hash_map_init_copy_range__non_created_hash_map_pair),\
    UT_CASE(test_hash_map_init_copy_range__invalid_begin),\
    UT_CASE(test_hash_map_init_copy_range__invalid_end),\
    UT_CASE(test_hash_map_init_copy_range__invalid_range),\
    UT_CASE(test_hash_map_init_copy_range__invalid_range_not_same_type),\
    UT_CASE(test_hash_map_init_copy_range__empty),\
    UT_CASE(test_hash_map_init_copy_range__non_empty),\
    UT_CASE(test_hash_map_init_copy_range__other),\
    UT_CASE(test_hash_map_init_copy_range__other_not_same),\
    UT_CASE_BEGIN(hash_map_init_copy_array, test_hash_map_init_copy_array__null_hash_map),\
    UT_CASE(test_hash_map_init_copy_array__non_created_hash_map),\
    UT_CASE(test_hash_map_init_copy_array__non_created_hash_map_pair),\
    UT_CASE(test_hash_map_init_copy_array__invalid_array),\
    UT_CASE(test_hash_map_init_copy_array__invalid_array_not_same_type),\
    UT_CASE(test_hash_map_init_copy_array__empty),\
    UT_CASE(test_hash_map_init_copy_array__non_empty),\
    UT_CASE(test_hash_map_init_copy_array__non_empty_dup),\
    UT_CASE_BEGIN(hash_map_init_copy_range_ex, test_hash_map_init_copy_range_ex__null_hash_map),\
    UT_CASE(test_hash_map_init_copy_range_ex__non_created_hash_map),\
    UT_CASE(test_hash_map_init_copy_range_ex__non_created_hash_map_pair),\
    UT_CASE(test_hash_map_init_copy_range_ex__invalid_begin),\
    UT_CASE(test_hash_map_init_copy_range_ex__invalid_end),\
    UT_CASE(test_hash_map_init_copy_range_ex__invalid_range),\
    UT_CASE(test_hash_map_init_copy_range_ex__invalid_range_not_same_type),\
    UT_CASE(test_hash_map_init_copy_range_ex__empty),\
    UT_CASE(test_hash_map_init_copy_range_ex__non_empty),\
    UT_CASE(test_hash_map_init_copy_range_ex__bucketcount),\
    UT_CASE(test_hash_map_init_copy_range_ex__hash),\
    UT_CASE(test_hash_map_init_copy_range_ex__compare),\
    UT_CASE(test_hash_map_init_copy_range_ex__other),\
    UT_CASE(test_hash_map_init_copy_range_ex__other_not_same),\
    UT_CASE_BEGIN(hash_map_init_copy_array_ex, test_hash_map_init_copy_array_ex__null_hash_map),\
    UT_CASE(test_hash_map_init_copy_array_ex__non_created_hash_map),\
    UT_CASE(test_hash_map_init_copy_array_ex__non_created_hash_map_pair),\
    UT_CASE(test_hash_map_init_copy_array_ex__invalid_array),\
    UT_CASE(test_hash_map_init_copy_array_ex__invalid_array_not_same_type),\
    UT_CASE(test_hash_map_init_copy_array_ex__empty),\
    UT_CASE(test_hash_map_init_copy_array_ex__non_empty),\
    UT_CASE(test_hash_map_init_copy_array_ex__non_empty_dup),\
    UT_CASE(test_hash_map_init_copy_array_ex__bucketcount),\
    UT_CASE(test_hash_map_init_copy_array_ex__hash),\
    UT_CASE(test_hash_map_init_copy_array_ex__compare),\
    UT_CASE_BEGIN(hash_map_destroy, test_hash_map_destroy__null_hash_map),\
    UT_CASE(test_hash_map_destroy__non_created),\
    UT_CASE(test_hash_map_destroy__created),\
    UT_CASE(test_hash_map_destroy__inited),\
    UT_CASE(test_hash_map_destroy__non_empty),\
    UT_CASE_BEGIN(hash_map_assign, test_hash_map_assign__null_dest),\
    UT_CASE(test_hash_map_assign__null_src),\
    UT_CASE(test_hash_map_assign__non_created_dest),\
    UT_CASE(test_hash_map_assign__non_created_dest_pair),\
    UT_CASE(test_hash_map_assign__non_init_src),\
    UT_CASE(test_hash_map_assign__non_init_src_pair),\
    UT_CASE(test_hash_map_assign__not_same_type),\
    UT_CASE(test_hash_map_assign__empty_empty),\
    UT_CASE(test_hash_map_assign__non_empty_empty),\
    UT_CASE(test_hash_map_assign__non_empty_non_empty_less),\
    UT_CASE(test_hash_map_assign__non_empty_non_empty_size_equal),\
    UT_CASE(test_hash_map_assign__non_empty_non_empty_equal),\
    UT_CASE(test_hash_map_assign__non_empty_non_empty_greater),\
    UT_CASE(test_hash_map_assign__empty_non_empty),\
    UT_CASE_BEGIN(hash_map_size, test_hash_map_size__null_hash_map),\
    UT_CASE(test_hash_map_size__non_inited),\
    UT_CASE(test_hash_map_size__non_inited_pair),\
    UT_CASE(test_hash_map_size__empty),\
    UT_CASE(test_hash_map_size__non_empty),\
    UT_CASE_BEGIN(hash_map_empty, test_hash_map_empty__null_hash_map),\
    UT_CASE(test_hash_map_empty__non_inited),\
    UT_CASE(test_hash_map_empty__non_inited_pair),\
    UT_CASE(test_hash_map_empty__empty),\
    UT_CASE(test_hash_map_empty__non_empty),\
    UT_CASE_BEGIN(hash_map_max_size, test_hash_map_max_size__null_hash_map),\
    UT_CASE(test_hash_map_max_size__non_inited),\
    UT_CASE(test_hash_map_max_size__non_inited_pair),\
    UT_CASE(test_hash_map_max_size__empty),\
    UT_CASE(test_hash_map_max_size__non_empty),\
    UT_CASE_BEGIN(hash_map_bucket_count, test_hash_map_bucket_count__null_hash_map),\
    UT_CASE(test_hash_map_bucket_count__non_inited),\
    UT_CASE(test_hash_map_bucket_count__non_inited_pair),\
    UT_CASE(test_hash_map_bucket_count__0),\
    UT_CASE(test_hash_map_bucket_count__100),\
    UT_CASE_BEGIN(hash_map_begin, test_hash_map_begin__null_hash_map),\
    UT_CASE(test_hash_map_begin__non_inited),\
    UT_CASE(test_hash_map_begin__non_inited_pair),\
    UT_CASE(test_hash_map_begin__empty),\
    UT_CASE(test_hash_map_begin__non_empty),\
    UT_CASE_BEGIN(hash_map_end, test_hash_map_end__null_hash_map),\
    UT_CASE(test_hash_map_end__non_inited),\
    UT_CASE(test_hash_map_end__non_inited_pair),\
    UT_CASE(test_hash_map_end__empty),\
    UT_CASE(test_hash_map_end__non_empty),\
    UT_CASE_BEGIN(hash_map_hash, test_hash_map_hash__null_hash_map),\
    UT_CASE(test_hash_map_hash__non_inited),\
    UT_CASE(test_hash_map_hash__default_hash),\
    UT_CASE(test_hash_map_hash__user_define_hash),\
    UT_CASE(test_hash_map_hash__null_hash_map),\
    UT_CASE_BEGIN(hash_map_key_comp, test_hash_map_key_comp__null_hash_map),\
    UT_CASE(test_hash_map_key_comp__non_inited),\
    UT_CASE(test_hash_map_key_comp__default_key_comp),\
    UT_CASE(test_hash_map_key_comp__user_define_key_comp),\
    UT_CASE_BEGIN(hash_map_value_comp, test_hash_map_value_comp__null_hash_map),\
    UT_CASE(test_hash_map_value_comp__non_inited),\
    UT_CASE(test_hash_map_value_comp__default_value_comp),\
    UT_CASE(test_hash_map_value_comp__user_define_value_comp),\
    UT_CASE_BEGIN(hash_map_clear, test_hash_map_clear__null_hash_map),\
    UT_CASE(test_hash_map_clear__non_inited),\
    UT_CASE(test_hash_map_clear__non_inited_pair),\
    UT_CASE(test_hash_map_clear__empty),\
    UT_CASE(test_hash_map_clear__non_empty),\
    UT_CASE_BEGIN(hash_map_equal, test_hash_map_equal__null_first),\
    UT_CASE(test_hash_map_equal__null_second),\
    UT_CASE(test_hash_map_equal__non_inited_first),\
    UT_CASE(test_hash_map_equal__non_inited_first_pair),\
    UT_CASE(test_hash_map_equal__non_inited_second),\
    UT_CASE(test_hash_map_equal__non_inited_second_pair),\
    UT_CASE(test_hash_map_equal__not_same_type),\
    UT_CASE(test_hash_map_equal__same_hash_map),\
    UT_CASE(test_hash_map_equal__size_first_less_than_second),\
    UT_CASE(test_hash_map_equal__size_first_greater_than_second),\
    UT_CASE(test_hash_map_equal__size_equal_0),\
    UT_CASE(test_hash_map_equal__size_equal_elem_first_less_than_second),\
    UT_CASE(test_hash_map_equal__size_equal_elem_first_greater_than_second),\
    UT_CASE(test_hash_map_equal__bucketcount_not_equal),\
    UT_CASE(test_hash_map_equal__hash_not_equal),\
    UT_CASE(test_hash_map_equal__compare_not_equal),\
    UT_CASE(test_hash_map_equal__equal),\
    UT_CASE_BEGIN(hash_map_not_equal, test_hash_map_not_equal__null_first),\
    UT_CASE(test_hash_map_not_equal__null_second),\
    UT_CASE(test_hash_map_not_equal__non_inited_first),\
    UT_CASE(test_hash_map_not_equal__non_inited_first_pair),\
    UT_CASE(test_hash_map_not_equal__non_inited_second),\
    UT_CASE(test_hash_map_not_equal__non_inited_second_pair),\
    UT_CASE(test_hash_map_not_equal__not_same_type),\
    UT_CASE(test_hash_map_not_equal__same_hash_map),\
    UT_CASE(test_hash_map_not_equal__size_first_less_than_second),\
    UT_CASE(test_hash_map_not_equal__size_first_greater_than_second),\
    UT_CASE(test_hash_map_not_equal__size_equal_0),\
    UT_CASE(test_hash_map_not_equal__size_equal_elem_first_less_than_second),\
    UT_CASE(test_hash_map_not_equal__size_equal_elem_first_greater_than_second),\
    UT_CASE(test_hash_map_not_equal__bucketcount_not_equal),\
    UT_CASE(test_hash_map_not_equal__hash_not_equal),\
    UT_CASE(test_hash_map_not_equal__compare_not_equal),\
    UT_CASE(test_hash_map_not_equal__equal),\
    UT_CASE_BEGIN(hash_map_less, test_hash_map_less__null_first),\
    UT_CASE(test_hash_map_less__null_second),\
    UT_CASE(test_hash_map_less__non_inited_first),\
    UT_CASE(test_hash_map_less__non_inited_first_pair),\
    UT_CASE(test_hash_map_less__non_inited_second),\
    UT_CASE(test_hash_map_less__non_inited_second_pair),\
    UT_CASE(test_hash_map_less__not_same_type),\
    UT_CASE(test_hash_map_less__same_hash_map),\
    UT_CASE(test_hash_map_less__size_first_less_than_second),\
    UT_CASE(test_hash_map_less__size_first_greater_than_second),\
    UT_CASE(test_hash_map_less__size_equal_0),\
    UT_CASE(test_hash_map_less__size_equal_elem_first_less_than_second),\
    UT_CASE(test_hash_map_less__size_equal_elem_first_greater_than_second),\
    UT_CASE(test_hash_map_less__bucketcount_not_equal),\
    UT_CASE(test_hash_map_less__hash_not_equal),\
    UT_CASE(test_hash_map_less__compare_less),\
    UT_CASE(test_hash_map_less__equal),\
    UT_CASE_BEGIN(hash_map_less_equal, test_hash_map_less_equal__null_first),\
    UT_CASE(test_hash_map_less_equal__null_second),\
    UT_CASE(test_hash_map_less_equal__non_inited_first),\
    UT_CASE(test_hash_map_less_equal__non_inited_first_pair),\
    UT_CASE(test_hash_map_less_equal__non_inited_second),\
    UT_CASE(test_hash_map_less_equal__non_inited_second_pair),\
    UT_CASE(test_hash_map_less_equal__not_same_type),\
    UT_CASE(test_hash_map_less_equal__same_hash_map),\
    UT_CASE(test_hash_map_less_equal__size_first_less_than_second),\
    UT_CASE(test_hash_map_less_equal__size_first_greater_than_second),\
    UT_CASE(test_hash_map_less_equal__size_equal_0),\
    UT_CASE(test_hash_map_less_equal__size_equal_elem_first_less_than_second),\
    UT_CASE(test_hash_map_less_equal__size_equal_elem_first_greater_than_second),\
    UT_CASE(test_hash_map_less_equal__bucketcount_not_equal),\
    UT_CASE(test_hash_map_less_equal__hash_not_equal),\
    UT_CASE(test_hash_map_less_equal__compare_less),\
    UT_CASE(test_hash_map_less_equal__equal),\
    UT_CASE_BEGIN(hash_map_greater, test_hash_map_greater__null_first),\
    UT_CASE(test_hash_map_greater__null_second),\
    UT_CASE(test_hash_map_greater__non_inited_first),\
    UT_CASE(test_hash_map_greater__non_inited_first_pair),\
    UT_CASE(test_hash_map_greater__non_inited_second),\
    UT_CASE(test_hash_map_greater__non_inited_second_pair),\
    UT_CASE(test_hash_map_greater__not_same_type),\
    UT_CASE(test_hash_map_greater__same_hash_map),\
    UT_CASE(test_hash_map_greater__size_first_less_than_second),\
    UT_CASE(test_hash_map_greater__size_first_greater_than_second),\
    UT_CASE(test_hash_map_greater__size_equal_0),\
    UT_CASE(test_hash_map_greater__size_equal_elem_first_less_than_second),\
    UT_CASE(test_hash_map_greater__size_equal_elem_first_greater_than_second),\
    UT_CASE(test_hash_map_greater__bucketcount_not_equal),\
    UT_CASE(test_hash_map_greater__hash_not_equal),\
    UT_CASE(test_hash_map_greater__compare_less),\
    UT_CASE(test_hash_map_greater__equal),\
    UT_CASE_BEGIN(hash_map_greater_equal, test_hash_map_greater_equal__null_first),\
    UT_CASE(test_hash_map_greater_equal__null_second),\
    UT_CASE(test_hash_map_greater_equal__non_inited_first),\
    UT_CASE(test_hash_map_greater_equal__non_inited_first_pair),\
    UT_CASE(test_hash_map_greater_equal__non_inited_second),\
    UT_CASE(test_hash_map_greater_equal__non_inited_second_pair),\
    UT_CASE(test_hash_map_greater_equal__not_same_type),\
    UT_CASE(test_hash_map_greater_equal__same_hash_map),\
    UT_CASE(test_hash_map_greater_equal__size_first_less_than_second),\
    UT_CASE(test_hash_map_greater_equal__size_first_greater_than_second),\
    UT_CASE(test_hash_map_greater_equal__size_equal_0),\
    UT_CASE(test_hash_map_greater_equal__size_equal_elem_first_less_than_second),\
    UT_CASE(test_hash_map_greater_equal__size_equal_elem_first_greater_than_second),\
    UT_CASE(test_hash_map_greater_equal__bucketcount_not_equal),\
    UT_CASE(test_hash_map_greater_equal__hash_not_equal),\
    UT_CASE(test_hash_map_greater_equal__compare_less),\
    UT_CASE(test_hash_map_greater_equal__equal),\
    UT_CASE_BEGIN(hash_map_swap, test_hash_map_swap__null_first),\
    UT_CASE(test_hash_map_swap__null_second),\
    UT_CASE(test_hash_map_swap__non_inited_first),\
    UT_CASE(test_hash_map_swap__non_inited_first_pair),\
    UT_CASE(test_hash_map_swap__non_inited_second),\
    UT_CASE(test_hash_map_swap__non_inited_second_pair),\
    UT_CASE(test_hash_map_swap__not_same_type),\
    UT_CASE(test_hash_map_swap__same_hash_map),\
    UT_CASE(test_hash_map_swap__0_swap_n),\
    UT_CASE(test_hash_map_swap__n_swap_0),\
    UT_CASE(test_hash_map_swap__n_swap_n),\
    UT_CASE(test_hash_map_swap__m_swap_n),\
    UT_CASE_BEGIN(hash_map_insert, test_hash_map_insert__null_hash_map),\
    UT_CASE(test_hash_map_insert__null_pair),\
    UT_CASE(test_hash_map_insert__non_inited),\
    UT_CASE(test_hash_map_insert__non_inited_pair),\
    UT_CASE(test_hash_map_insert__pair_non_inited),\
    UT_CASE(test_hash_map_insert__not_smae_type),\
    UT_CASE(test_hash_map_insert__c_builtin_equal),\
    UT_CASE(test_hash_map_insert__c_builtin_not_equal),\
    UT_CASE(test_hash_map_insert__cstr_equal),\
    UT_CASE(test_hash_map_insert__cstr_not_equal),\
    UT_CASE(test_hash_map_insert__libcstl_builtin_equal),\
    UT_CASE(test_hash_map_insert__libcstl_builtin_not_equal),\
    UT_CASE(test_hash_map_insert__user_define_equal),\
    UT_CASE(test_hash_map_insert__user_define_not_equal),\
    UT_CASE_BEGIN(hash_map_insert_range, test_hash_map_insert_range__null_hash_map),\
    UT_CASE(test_hash_map_insert_range__non_inited),\
    UT_CASE(test_hash_map_insert_range__non_inited_pair),\
    UT_CASE(test_hash_map_insert_range__invalid_begin),\
    UT_CASE(test_hash_map_insert_range__invalid_end),\
    UT_CASE(test_hash_map_insert_range__invalid_range),\
    UT_CASE(test_hash_map_insert_range__not_same_type),\
    UT_CASE(test_hash_map_insert_range__empty),\
    UT_CASE(test_hash_map_insert_range__non_empty_equal),\
    UT_CASE(test_hash_map_insert_range__non_empty_dest_src_dup),\
    UT_CASE(test_hash_map_insert_range__non_empty_src_dup),\
    UT_CASE(test_hash_map_insert_range__compare),\
    UT_CASE(test_hash_map_insert_range__other),\
    UT_CASE(test_hash_map_insert_range__other_not_same),\
    UT_CASE_BEGIN(hash_map_insert_array, test_hash_map_insert_array__null_hash_map),\
    UT_CASE(test_hash_map_insert_array__non_inited),\
    UT_CASE(test_hash_map_insert_array__non_inited_pair),\
    UT_CASE(test_hash_map_insert_array__invalid_array),\
    UT_CASE(test_hash_map_insert_array__not_same_type),\
    UT_CASE(test_hash_map_insert_array__empty),\
    UT_CASE(test_hash_map_insert_array__non_empty_equal),\
    UT_CASE(test_hash_map_insert_array__non_empty_dest_src_dup),\
    UT_CASE(test_hash_map_insert_array__non_empty_src_dup),\
    UT_CASE_BEGIN(hash_map_erase_pos, test_hash_map_erase_pos__null_hash_map),\
    UT_CASE(test_hash_map_erase_pos__non_inited),\
    UT_CASE(test_hash_map_erase_pos__non_inited_pair),\
    UT_CASE(test_hash_map_erase_pos__invalid_pos),\
    UT_CASE(test_hash_map_erase_pos__end),\
    UT_CASE(test_hash_map_erase_pos__begin),\
    UT_CASE(test_hash_map_erase_pos__middle),\
    UT_CASE(test_hash_map_erase_pos__last),\
    UT_CASE(test_hash_map_erase_pos__erase_empty),\
    UT_CASE_BEGIN(hash_map_erase_range, test_hash_map_erase_range__null_hash_map),\
    UT_CASE(test_hash_map_erase_range__non_inited),\
    UT_CASE(test_hash_map_erase_range__non_inited_pair),\
    UT_CASE(test_hash_map_erase_range__invalid_begin),\
    UT_CASE(test_hash_map_erase_range__invalid_end),\
    UT_CASE(test_hash_map_erase_range__invalid_range),\
    UT_CASE(test_hash_map_erase_range__empty),\
    UT_CASE(test_hash_map_erase_range__begin),\
    UT_CASE(test_hash_map_erase_range__middle),\
    UT_CASE(test_hash_map_erase_range__end),\
    UT_CASE(test_hash_map_erase_range__all),\
    UT_CASE_BEGIN(hash_map_resize, test_hash_map_resize__null_hash_map),\
    UT_CASE(test_hash_map_resize__non_inited),\
    UT_CASE(test_hash_map_resize__non_inited_pair),\
    UT_CASE(test_hash_map_resize__resize)

#endif /* _UT_CSTL_HASH_MAP_H_ */

