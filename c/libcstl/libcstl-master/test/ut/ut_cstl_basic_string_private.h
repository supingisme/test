#ifndef _UT_CSTL_BASIC_STRING_PRIVATE_H_
#define _UT_CSTL_BASIC_STRING_PRIVATE_H_

UT_SUIT_DECLARATION(cstl_basic_string_private)

/*
 * test _create_basic_string
 */
UT_CASE_DECLARATION(_create_basic_string)
void test__create_basic_string__null_typename(void** state);
void test__create_basic_string__unregisted_type(void** state);
void test__create_basic_string__c_builtin_type(void** state);
void test__create_basic_string__libcstl_builtin_type(void** state);
void test__create_basic_string__registed_type(void** state);
/*
 * test _create_basic_string_auxiliary
 */
UT_CASE_DECLARATION(_create_basic_string_auxiliary)
void test__create_basic_string_auxiliary__null_basic_string_container(void** state);
void test__create_basic_string_auxiliary__null_typename(void** state);
void test__create_basic_string_auxiliary__unregisted_type(void** state);
void test__create_basic_string_auxiliary__c_builtin_type(void** state);
void test__create_basic_string_auxiliary__libcstl_builtin_type(void** state);
void test__create_basic_string_auxiliary__registed_type(void** state);
/*
 * test _basic_string_init_elem and _basic_string_init_elem_varg
 */
UT_CASE_DECLARATION(_basic_string_init_elem__basic_string_init_elem_varg)
void test__basic_string_init_elem__basic_string_init_elem_varg__null_basic_string_container(void** state);
void test__basic_string_init_elem__basic_string_init_elem_varg__non_created(void** state);
void test__basic_string_init_elem__basic_string_init_elem_varg__successfully_0_count(void** state);
void test__basic_string_init_elem__basic_string_init_elem_varg__successfully(void** state);
void test__basic_string_init_elem__basic_string_init_elem_varg__successfully_large_amounts_of_data(void** state);
void test__basic_string_init_elem__basic_string_init_elem_varg__successfully_multiple_specificed_element(void** state);
void test__basic_string_init_elem__terminator_c(void** state);
void test__basic_string_init_elem__terminator_cstr(void** state);
void test__basic_string_init_elem__terminator_libcstl(void** state);
void test__basic_string_init_elem__terminator_user_define(void** state);
/*
 * test _basic_string_destroy_auxiliary
 */
UT_CASE_DECLARATION(_basic_string_destroy_auxiliary)
void test__basic_string_destroy_auxiliary__null_basic_string_container(void** state);
void test__basic_string_destroy_auxiliary__non_created(void** state);
void test__basic_string_destroy_auxiliary__successfully_non_inited(void** state);
void test__basic_string_destroy_auxiliary__successfully_empty_container(void** state);
void test__basic_string_destroy_auxiliary__successfully(void** state);
void test__basic_string_destroy_auxiliary__shared(void** state);
/*
 * test _basic_string_find_elem and _basic_string_find_elem_varg
 */
UT_CASE_DECLARATION(_basic_string_find_elem__basic_string_find_elem_varg)
void test__basic_string_find_elem__basic_string_find_elem_varg__null_basic_string_container(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__non_init_basic_string_container(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__invalid_position(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__invalid_position_end(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__invalid_position_NPOS(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__find_failure(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__find_failure_middle_pos(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__find_successful(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__find_successful_middle(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__find_successful_back(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__find_successful_middle_pos(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__cstr_find_failure(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__cstr_find_failure_middle_pos(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__cstr_find_successful(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__cstr_find_successful_middle(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__cstr_find_successful_back(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__cstr_find_successful_middle_pos(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__shared(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__terminator_c(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__terminator_cstr(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__terminator_cstl(void** state);
void test__basic_string_find_elem__basic_string_find_elem_varg__terminator_user_define(void** state);
/*
 * test _basic_string_rfind_elem and _basic_string_rfind_elem_varg
 */
UT_CASE_DECLARATION(_basic_string_rfind_elem__basic_string_rfind_elem_varg)
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__null_basic_string_container(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__non_init_basic_string_container(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__invalid_position(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__invalid_position_begin(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__invalid_position_NPOS(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__find_failure(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__find_failure_middle_pos(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__find_successful(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__find_successful_middle(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__find_successful_back(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__find_successful_middle_pos(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__pos_eq_size(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__cstr_find_failure(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__cstr_find_failure_middle_pos(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__cstr_find_successful(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__cstr_find_successful_middle(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__cstr_find_successful_back(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__cstr_find_successful_middle_pos(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__shared(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__terminator_c(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__terminator_cstr(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__terminator_cstl(void** state);
void test__basic_string_rfind_elem__basic_string_rfind_elem_varg__terminator_user_define(void** state);
/*
 * test _basic_string_find_first_not_of_elem and _basic_string_find_first_not_of_elem_varg
 */
UT_CASE_DECLARATION(_basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg)
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__null_basic_string_container(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__non_init_basic_string_container(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__invalid_position(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__invalid_position_end(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__invalid_position_NPOS(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__find_first_not_of_failure(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__find_first_not_of_failure_middle_pos(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__find_first_not_of_successful(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__find_first_not_of_successful_middle(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__find_first_not_of_successful_back(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__find_first_not_of_successful_middle_pos(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__cstr_find_first_not_of_failure(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__cstr_find_first_not_of_failure_middle_pos(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__cstr_find_first_not_of_successful(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__cstr_find_first_not_of_successful_middle(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__cstr_find_first_not_of_successful_back(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__cstr_find_first_not_of_successful_middle_pos(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__terminator_c(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__terminator_cstr(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__terminator_cstl(void** state);
void test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__terminator_user_define(void** state);
/*
 * test _basic_string_find_last_not_of_elem and _basic_string_find_last_not_of_elem_varg
 */
UT_CASE_DECLARATION(_basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg)
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__null_basic_string_container(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__non_init_basic_string_container(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__invalid_position(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__invalid_position_begin(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__invalid_position_NPOS(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__find_failure(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__find_failure_middle_pos(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__find_successful(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__find_successful_middle(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__find_successful_back(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__find_successful_middle_pos(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__cstr_find_failure(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__cstr_find_failure_middle_pos(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__cstr_find_successful(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__cstr_find_successful_middle(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__cstr_find_successful_back(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__cstr_find_successful_middle_pos(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__pos_gt_size(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__pos_eq_size(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__pos_lt_size(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__pos_eq_0(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__empty(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__terminator_c(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__terminator_cstr(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__terminator_cstl(void** state);
void test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__terminator_user_define(void** state);
/*
 * test _basic_string_connect_elem and _basic_string_connect_elem_varg
 */
UT_CASE_DECLARATION(_basic_string_connect_elem__basic_string_connect_elem_varg)
void test__basic_string_connect_elem__basic_string_connect_elem_varg__null_basic_string_container(void** state);
void test__basic_string_connect_elem__basic_string_connect_elem_varg__non_inited_basic_string_container(void** state);
void test__basic_string_connect_elem__basic_string_connect_elem_varg__empty_container(void** state);
void test__basic_string_connect_elem__basic_string_connect_elem_varg__non_empty_container(void** state);
void test__basic_string_connect_elem__basic_string_connect_elem_varg__cstr_empty_container(void** state);
void test__basic_string_connect_elem__basic_string_connect_elem_varg__cstr_non_empty_container(void** state);
/*
 * test _basic_string_assign_elem and _basic_string_assign_elem_varg
 */
UT_CASE_DECLARATION(_basic_string_assign_elem__basic_string_assign_elem_varg)
void test__basic_string_assign_elem__basic_string_assign_elem_varg__null_container(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__non_inited_container(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__empty_container_assign_empty(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__empty_container_assign_non_empty(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__non_empty_container_assign_empty(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__non_empty_container_assign_less(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__non_empty_container_assign_equal(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__non_empty_container_assign_greater(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__cstr_empty_container_assign_empty(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__cstr_empty_container_assign_non_empty(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__cstr_non_empty_container_assign_empty(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__cstr_non_empty_container_assign_less(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__cstr_non_empty_container_assign_equal(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__cstr_non_empty_container_assign_greater(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__libcstl(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__user_define(void** state);
void test__basic_string_assign_elem__basic_string_assign_elem_varg__shared(void** state);
/*
 * test _basic_string_push_back and _basic_string_push_back_varg
 */
UT_CASE_DECLARATION(_basic_string_push_back__basic_string_push_back_varg)
void test__basic_string_push_back__basic_string_push_back_varg__null_container(void** state);
void test__basic_string_push_back__basic_string_push_back_varg__non_inited_container(void** state);
void test__basic_string_push_back__basic_string_push_back_varg__empty(void** state);
void test__basic_string_push_back__basic_string_push_back_varg__non_empty(void** state);
void test__basic_string_push_back__basic_string_push_back_varg__cstr_empty(void** state);
void test__basic_string_push_back__basic_string_push_back_varg__cstr_non_empty(void** state);
void test__basic_string_push_back__basic_string_push_back_varg__shared_empty(void** state);
void test__basic_string_push_back__basic_string_push_back_varg__shared_non_empty(void** state);
void test__basic_string_push_back__basic_string_push_back_varg__cstl_builtin_empty(void** state);
void test__basic_string_push_back__basic_string_push_back_varg__cstl_builtin_non_empty(void** state);
void test__basic_string_push_back__basic_string_push_back_varg__user_define_empty(void** state);
void test__basic_string_push_back__basic_string_push_back_varg__user_define_non_empty(void** state);
/*
 * test _basic_string_resize_elem and _basic_string_resize_elem_varg
 */
UT_CASE_DECLARATION(_basic_string_resize_elem__basic_string_resize_elem_varg)
void test__basic_string_resize_elem__basic_string_resize_elem_varg__null_basic_string_container(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__non_inited(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_0_resize_0(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_0_resize_10(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_0_resize_1000(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_10_resize_0(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_10_resize_10(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_10_resize_1000(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_1000_resize_0(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_1000_resize_10(void** setate);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_1000_resize_1000(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_1000_resize_1200(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_1000_resize_2000(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_1000_resize_2000_multiple(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__shared_append(void** state);
void test__basic_string_resize_elem__basic_string_resize_elem_varg__shared_erase(void** state);
/*
 * test _basic_string_append_elem and _basic_string_append_elem_varg
 */
UT_CASE_DECLARATION(_basic_string_append_elem__basic_string_append_elem_varg)
void test__basic_string_append_elem__basic_string_append_elem_varg__null_container(void** state);
void test__basic_string_append_elem__basic_string_append_elem_varg__non_inited_container(void** state);
void test__basic_string_append_elem__basic_string_append_elem_varg__invalid_count(void** state);
void test__basic_string_append_elem__basic_string_append_elem_varg__empty_append_empty(void** state);
void test__basic_string_append_elem__basic_string_append_elem_varg__empty_append_non_empty(void** state);
void test__basic_string_append_elem__basic_string_append_elem_varg__non_empty_append_empty(void** state);
void test__basic_string_append_elem__basic_string_append_elem_varg__non_empty_append_non_empty(void** state);
void test__basic_string_append_elem__basic_string_append_elem_varg__cstr_empty_append_empty(void** state);
void test__basic_string_append_elem__basic_string_append_elem_varg__cstr_empty_append_non_empty(void** state);
void test__basic_string_append_elem__basic_string_append_elem_varg__cstr_non_empty_append_empty(void** state);
void test__basic_string_append_elem__basic_string_append_elem_varg__cstr_non_empty_append_non_empty(void** state);
void test__basic_string_append_elem__basic_string_append_elem_varg__libcstl(void** state);
void test__basic_string_append_elem__basic_string_append_elem_varg__user_define(void** state);
void test__basic_string_append_elem__basic_string_append_elem_varg__shared(void** state);
/*
 * test _basic_string_insert_n and _basic_string_insert_n_varg
 */
UT_CASE_DECLARATION(_basic_string_insert_n__basic_string_insert_n_varg)
void test__basic_string_insert_n__basic_string_insert_n_varg__null_basic_string_container(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__non_inited(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__invalid_position(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__empty_insert_0(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__empty_insert_10(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__empty_insert_1000(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__begin_insert_0(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__begin_insert_10(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__begin_insert_1000(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__middle_insert_0(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__middle_insert_10(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__middle_insert_1000(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__end_insert_0(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__end_insert_10(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__end_insert_1000(void** state);
void test__basic_string_insert_n__basic_string_insert_n_varg__end_insert_1000_multiple(void** state);
/*
 * test _basic_string_insert_elem and _basic_string_insert_elem_varg
 */
UT_CASE_DECLARATION(_basic_string_insert_elem__basic_string_insert_elem_varg)
void test__basic_string_insert_elem__basic_string_insert_elem_varg__null_basic_string_container(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__non_inited(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__invalid_position(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__empty_insert_0(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__empty_insert_10(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__empty_insert_1000(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__begin_insert_0(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__begin_insert_10(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__begin_insert_1000(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__middle_insert_0(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__middle_insert_10(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__middle_insert_1000(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__end_insert_0(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__end_insert_10(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__end_insert_1000(void** state);
void test__basic_string_insert_elem__basic_string_insert_elem_varg__end_insert_1000_multiple(void** state);
/*
 * test _basic_string_range_replace_elem and _basic_string_range_replace_elem_varg
 */
UT_CASE_DECLARATION(_basic_string_range_replace_elem__basic_string_range_replace_elem_varg)
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__null_container(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__non_inited_container(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__invalid_range(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__empty_replace_empty(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__empty_replace_non_empty(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__begin_replace_empty(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__begin_replace_less(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__begin_replace_equal(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__begin_replace_greater(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__middle_replace_empty(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__middle_replace_less(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__middle_replace_equal(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__middle_replace_greater(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__end_replace_empty(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__end_replace_less(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__end_replace_equal(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__end_replace_greater(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__replace_all(void** state);
void test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__shared(void** state);
/*
 * test _basic_string_replace_elem and _basic_string_replace_elem_varg
 */
UT_CASE_DECLARATION(_basic_string_replace_elem__basic_string_replace_elem_varg)
void test__basic_string_replace_elem__basic_string_replace_elem_varg__null_container(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__non_inited_container(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__empty_replace_empty(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__empty_replace_non_empty(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__begin_replace_empty(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__begin_replace_less(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__begin_replace_equal(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__begin_replace_greater(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__middle_replace_empty(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__middle_replace_less(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__middle_replace_equal(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__middle_replace_greater(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__end_replace_empty(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__end_replace_less(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__end_replace_equal(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__end_replace_greater(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__replace_all(void** state);
void test__basic_string_replace_elem__basic_string_replace_elem_varg__shared(void** state);
/*
 * test _basic_string_init_elem_auxiliary
 */
UT_CASE_DECLARATION(_basic_string_init_elem_auxiliary)
void test__basic_string_init_elem_auxiliary__null_basic_string_container(void** state);
void test__basic_string_init_elem_auxiliary__null_elem(void** state);
void test__basic_string_init_elem_auxiliary__non_created_basic_string(void** state);
void test__basic_string_init_elem_auxiliary__successfully_int(void** state);
void test__basic_string_init_elem_auxiliary__successfully_cstr(void** state);
void test__basic_string_init_elem_auxiliary__successfully_iterator(void** state);
void test__basic_string_init_elem_auxiliary__successfully_container(void** state);
/*
 * test _create_basic_string_representation
 */
UT_CASE_DECLARATION(_create_basic_string_representation)
void test__create_basic_string_representation__invalid_elemsize(void** state);
void test__create_basic_string_representation__capacity_0(void** state);
void test__create_basic_string_representation__new_capacity_0(void** state);
void test__create_basic_string_representation__old_capacity_0(void** state);
void test__create_basic_string_representation__capacity_new_le_old(void** state);
void test__create_basic_string_representation__capacity_new_gt_old(void** state);
void test__create_basic_string_representation__capacity_new_gt_old_twice(void** state);
/*
 * test _basic_string_rep_get_data
 */
UT_CASE_DECLARATION(_basic_string_rep_get_data)
void test__basic_string_rep_get_data__rep_null(void** state);
void test__basic_string_rep_get_data__successfully(void** state);
/*
 * test _basic_string_rep_get_representation
 */
UT_CASE_DECLARATION(_basic_string_rep_get_representation)
void test__basic_string_rep_get_representation__data_null(void** state);
void test__basic_string_rep_get_representation__successfully(void** state);
/*
 * test _basic_string_rep_get_length
 */
UT_CASE_DECLARATION(_basic_string_rep_get_length)
void test__basic_string_rep_get_length__null(void** state);
void test__basic_string_rep_get_length__0(void** state);
void test__basic_string_rep_get_length__n(void** state);
/*
 * test _basic_string_rep_set_length
 */
UT_CASE_DECLARATION(_basic_string_rep_set_length)
void test__basic_string_rep_set_lenght__null(void** state);
void test__basic_string_rep_set_lenght__len_ge_capacity(void** state);
void test__basic_string_rep_set_lenght__0(void** state);
void test__basic_string_rep_set_lenght__n(void** state);
/*
 * test _basic_string_rep_is_shared
 */
UT_CASE_DECLARATION(_basic_string_rep_is_shared)
void test__basic_string_rep_is_shared__null(void** state);
void test__basic_string_rep_is_shared__true(void** state);
void test__basic_string_rep_is_shared__false(void** state);
/*
 * test _basic_string_rep_set_sharable
 */
UT_CASE_DECLARATION(_basic_string_rep_set_sharable)
void test__basic_string_rep_set_sharable__null(void** state);
void test__basic_string_rep_set_sharable__successfully(void** state);
/*
 * test _basic_string_rep_is_leaked
 */
UT_CASE_DECLARATION(_basic_string_rep_is_leaked)
void test__basic_string_rep_is_leaked__null(void** state);
void test__basic_string_rep_is_leaked__true(void** state);
void test__basic_string_rep_is_leaked__false(void** state);
/*
 * test _basic_string_rep_set_leaked
 */
UT_CASE_DECLARATION(_basic_string_rep_set_leaked)
void test__basic_string_rep_set_leaked__null(void** state);
void test__basic_string_rep_set_leaked__successfully(void** state);
/*
 * test _basic_string_rep_reduce_shared
 */
UT_CASE_DECLARATION(_basic_string_rep_reduce_shared)
void test__basic_string_rep_reduce_shared__rep_null(void** state);
void test__basic_string_rep_reduce_shared__fun_null(void** state);
void test__basic_string_rep_reduce_shared__not_shared(void** state);
void test__basic_string_rep_reduce_shared__shared(void** state);
/*
 * test _basic_string_rep_increase_shared
 */
UT_CASE_DECLARATION(_basic_string_rep_increase_shared)
void test__basic_string_rep_increase_shared__null(void** state);
void test__basic_string_rep_increase_shared__shared(void** state);
void test__basic_string_rep_increase_shared__not_shared(void** state);

#define UT_CSTL_BASIC_STRING_PRIVATE_CASE\
    UT_SUIT_BEGIN(cstl_basic_string_private, test__create_basic_string_representation__invalid_elemsize),\
    UT_CASE(test__create_basic_string_representation__capacity_0),\
    UT_CASE(test__create_basic_string_representation__new_capacity_0),\
    UT_CASE(test__create_basic_string_representation__old_capacity_0),\
    UT_CASE(test__create_basic_string_representation__capacity_new_le_old),\
    UT_CASE(test__create_basic_string_representation__capacity_new_gt_old),\
    UT_CASE(test__create_basic_string_representation__capacity_new_gt_old_twice),\
    UT_CASE_BEGIN(_basic_string_rep_increase_shared, test__basic_string_rep_increase_shared__null),\
    UT_CASE(test__basic_string_rep_increase_shared__shared),\
    UT_CASE(test__basic_string_rep_increase_shared__not_shared),\
    UT_CASE_BEGIN(_basic_string_rep_reduce_shared, test__basic_string_rep_reduce_shared__rep_null),\
    UT_CASE(test__basic_string_rep_reduce_shared__fun_null),\
    UT_CASE(test__basic_string_rep_reduce_shared__not_shared),\
    UT_CASE(test__basic_string_rep_reduce_shared__shared),\
    UT_CASE_BEGIN(_basic_string_rep_get_data, test__basic_string_rep_get_data__rep_null),\
    UT_CASE(test__basic_string_rep_get_data__successfully),\
    UT_CASE_BEGIN(_basic_string_rep_get_representation, test__basic_string_rep_get_representation__data_null),\
    UT_CASE(test__basic_string_rep_get_representation__successfully),\
    UT_CASE_BEGIN(_basic_string_rep_get_length, test__basic_string_rep_get_length__null),\
    UT_CASE(test__basic_string_rep_get_length__0),\
    UT_CASE(test__basic_string_rep_get_length__n),\
    UT_CASE_BEGIN(_basic_string_rep_set_length, test__basic_string_rep_set_lenght__null),\
    UT_CASE(test__basic_string_rep_set_lenght__len_ge_capacity),\
    UT_CASE(test__basic_string_rep_set_lenght__0),\
    UT_CASE(test__basic_string_rep_set_lenght__n),\
    UT_CASE_BEGIN(_basic_string_rep_is_shared, test__basic_string_rep_is_shared__null),\
    UT_CASE(test__basic_string_rep_is_shared__true),\
    UT_CASE(test__basic_string_rep_is_shared__false),\
    UT_CASE_BEGIN(_basic_string_rep_set_sharable, test__basic_string_rep_set_sharable__null),\
    UT_CASE(test__basic_string_rep_set_sharable__successfully),\
    UT_CASE_BEGIN(_basic_string_rep_is_leaked, test__basic_string_rep_is_leaked__null),\
    UT_CASE(test__basic_string_rep_is_leaked__true),\
    UT_CASE(test__basic_string_rep_is_leaked__false),\
    UT_CASE_BEGIN(_basic_string_rep_set_leaked, test__basic_string_rep_set_leaked__null),\
    UT_CASE(test__basic_string_rep_set_leaked__successfully),\
    UT_CASE_BEGIN(_create_basic_string, test__create_basic_string__null_typename),\
    UT_CASE(test__create_basic_string__unregisted_type),\
    UT_CASE(test__create_basic_string__c_builtin_type),\
    UT_CASE(test__create_basic_string__libcstl_builtin_type),\
    UT_CASE(test__create_basic_string__registed_type),\
    UT_CASE_BEGIN(_create_basic_string_auxiliary, test__create_basic_string_auxiliary__null_basic_string_container),\
    UT_CASE(test__create_basic_string_auxiliary__null_typename),\
    UT_CASE(test__create_basic_string_auxiliary__unregisted_type),\
    UT_CASE(test__create_basic_string_auxiliary__c_builtin_type),\
    UT_CASE(test__create_basic_string_auxiliary__libcstl_builtin_type),\
    UT_CASE(test__create_basic_string_auxiliary__registed_type),\
    UT_CASE_BEGIN(_basic_string_init_elem__basic_string_init_elem_varg,\
            test__basic_string_init_elem__basic_string_init_elem_varg__null_basic_string_container),\
    UT_CASE(test__basic_string_init_elem__basic_string_init_elem_varg__non_created),\
    UT_CASE(test__basic_string_init_elem__basic_string_init_elem_varg__successfully_0_count),\
    UT_CASE(test__basic_string_init_elem__basic_string_init_elem_varg__successfully),\
    UT_CASE(test__basic_string_init_elem__basic_string_init_elem_varg__successfully_large_amounts_of_data),\
    UT_CASE(test__basic_string_init_elem__basic_string_init_elem_varg__successfully_multiple_specificed_element),\
    UT_CASE(test__basic_string_init_elem__terminator_c),\
    UT_CASE(test__basic_string_init_elem__terminator_cstr),\
    UT_CASE(test__basic_string_init_elem__terminator_libcstl),\
    UT_CASE(test__basic_string_init_elem__terminator_user_define),\
    UT_CASE_BEGIN(_basic_string_init_elem_auxiliary, test__basic_string_init_elem_auxiliary__null_basic_string_container),\
    UT_CASE(test__basic_string_init_elem_auxiliary__null_elem),\
    UT_CASE(test__basic_string_init_elem_auxiliary__non_created_basic_string),\
    UT_CASE(test__basic_string_init_elem_auxiliary__successfully_int),\
    UT_CASE(test__basic_string_init_elem_auxiliary__successfully_cstr),\
    UT_CASE(test__basic_string_init_elem_auxiliary__successfully_iterator),\
    UT_CASE(test__basic_string_init_elem_auxiliary__successfully_container),\
    UT_CASE_BEGIN(_basic_string_push_back__basic_string_push_back_varg,\
        test__basic_string_push_back__basic_string_push_back_varg__null_container),\
    UT_CASE(test__basic_string_push_back__basic_string_push_back_varg__non_inited_container),\
    UT_CASE(test__basic_string_push_back__basic_string_push_back_varg__empty),\
    UT_CASE(test__basic_string_push_back__basic_string_push_back_varg__non_empty),\
    UT_CASE(test__basic_string_push_back__basic_string_push_back_varg__cstr_empty),\
    UT_CASE(test__basic_string_push_back__basic_string_push_back_varg__cstr_non_empty),\
    UT_CASE(test__basic_string_push_back__basic_string_push_back_varg__shared_empty),\
    UT_CASE(test__basic_string_push_back__basic_string_push_back_varg__shared_non_empty),\
    UT_CASE(test__basic_string_push_back__basic_string_push_back_varg__cstl_builtin_empty),\
    UT_CASE(test__basic_string_push_back__basic_string_push_back_varg__cstl_builtin_non_empty),\
    UT_CASE(test__basic_string_push_back__basic_string_push_back_varg__user_define_empty),\
    UT_CASE(test__basic_string_push_back__basic_string_push_back_varg__user_define_non_empty),\
    UT_CASE_BEGIN(_basic_string_destroy_auxiliary, test__basic_string_destroy_auxiliary__null_basic_string_container),\
    UT_CASE(test__basic_string_destroy_auxiliary__non_created),\
    UT_CASE(test__basic_string_destroy_auxiliary__successfully_non_inited),\
    UT_CASE(test__basic_string_destroy_auxiliary__successfully_empty_container),\
    UT_CASE(test__basic_string_destroy_auxiliary__successfully),\
    UT_CASE(test__basic_string_destroy_auxiliary__shared),\
    UT_CASE_BEGIN(_basic_string_assign_elem__basic_string_assign_elem_varg,\
        test__basic_string_assign_elem__basic_string_assign_elem_varg__null_container),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__non_inited_container),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__empty_container_assign_empty),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__empty_container_assign_non_empty),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__non_empty_container_assign_empty),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__non_empty_container_assign_less),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__non_empty_container_assign_equal),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__non_empty_container_assign_greater),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__cstr_empty_container_assign_empty),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__cstr_empty_container_assign_non_empty),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__cstr_non_empty_container_assign_empty),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__cstr_non_empty_container_assign_less),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__cstr_non_empty_container_assign_equal),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__cstr_non_empty_container_assign_greater),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__libcstl),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__user_define),\
    UT_CASE(test__basic_string_assign_elem__basic_string_assign_elem_varg__shared),\
    UT_CASE_BEGIN(_basic_string_append_elem__basic_string_append_elem_varg,\
        test__basic_string_append_elem__basic_string_append_elem_varg__null_container),\
    UT_CASE(test__basic_string_append_elem__basic_string_append_elem_varg__non_inited_container),\
    UT_CASE(test__basic_string_append_elem__basic_string_append_elem_varg__invalid_count),\
    UT_CASE(test__basic_string_append_elem__basic_string_append_elem_varg__empty_append_empty),\
    UT_CASE(test__basic_string_append_elem__basic_string_append_elem_varg__empty_append_non_empty),\
    UT_CASE(test__basic_string_append_elem__basic_string_append_elem_varg__non_empty_append_empty),\
    UT_CASE(test__basic_string_append_elem__basic_string_append_elem_varg__non_empty_append_non_empty),\
    UT_CASE(test__basic_string_append_elem__basic_string_append_elem_varg__cstr_empty_append_empty),\
    UT_CASE(test__basic_string_append_elem__basic_string_append_elem_varg__cstr_empty_append_non_empty),\
    UT_CASE(test__basic_string_append_elem__basic_string_append_elem_varg__cstr_non_empty_append_empty),\
    UT_CASE(test__basic_string_append_elem__basic_string_append_elem_varg__cstr_non_empty_append_non_empty),\
    UT_CASE(test__basic_string_append_elem__basic_string_append_elem_varg__libcstl),\
    UT_CASE(test__basic_string_append_elem__basic_string_append_elem_varg__user_define),\
    UT_CASE(test__basic_string_append_elem__basic_string_append_elem_varg__shared),\
    UT_CASE_BEGIN(_basic_string_connect_elem__basic_string_connect_elem_varg,\
        test__basic_string_connect_elem__basic_string_connect_elem_varg__null_basic_string_container),\
    UT_CASE(test__basic_string_connect_elem__basic_string_connect_elem_varg__non_inited_basic_string_container),\
    UT_CASE(test__basic_string_connect_elem__basic_string_connect_elem_varg__empty_container),\
    UT_CASE(test__basic_string_connect_elem__basic_string_connect_elem_varg__non_empty_container),\
    UT_CASE(test__basic_string_connect_elem__basic_string_connect_elem_varg__cstr_empty_container),\
    UT_CASE(test__basic_string_connect_elem__basic_string_connect_elem_varg__cstr_non_empty_container),\
    UT_CASE_BEGIN(_basic_string_resize_elem__basic_string_resize_elem_varg,\
        test__basic_string_resize_elem__basic_string_resize_elem_varg__null_basic_string_container),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__non_inited),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_0_resize_0),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_0_resize_10),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_0_resize_1000),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_10_resize_0),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_10_resize_10),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_10_resize_1000),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_1000_resize_0),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_1000_resize_10),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_1000_resize_1000),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_1000_resize_1200),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_1000_resize_2000),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__successfully_1000_resize_2000_multiple),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__shared_append),\
    UT_CASE(test__basic_string_resize_elem__basic_string_resize_elem_varg__shared_erase),\
    UT_CASE_BEGIN(_basic_string_replace_elem__basic_string_replace_elem_varg,\
        test__basic_string_replace_elem__basic_string_replace_elem_varg__null_container),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__non_inited_container),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__empty_replace_empty),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__empty_replace_non_empty),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__begin_replace_empty),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__begin_replace_less),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__begin_replace_equal),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__begin_replace_greater),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__middle_replace_empty),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__middle_replace_less),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__middle_replace_equal),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__middle_replace_greater),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__end_replace_empty),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__end_replace_less),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__end_replace_equal),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__end_replace_greater),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__replace_all),\
    UT_CASE(test__basic_string_replace_elem__basic_string_replace_elem_varg__shared),\
    UT_CASE_BEGIN(_basic_string_range_replace_elem__basic_string_range_replace_elem_varg,\
        test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__null_container),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__non_inited_container),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__invalid_range),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__empty_replace_empty),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__empty_replace_non_empty),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__begin_replace_empty),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__begin_replace_less),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__begin_replace_equal),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__begin_replace_greater),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__middle_replace_empty),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__middle_replace_less),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__middle_replace_equal),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__middle_replace_greater),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__end_replace_empty),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__end_replace_less),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__end_replace_equal),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__end_replace_greater),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__replace_all),\
    UT_CASE(test__basic_string_range_replace_elem__basic_string_range_replace_elem_varg__shared),\
    UT_CASE_BEGIN(_basic_string_insert_elem__basic_string_insert_elem_varg,\
        test__basic_string_insert_elem__basic_string_insert_elem_varg__null_basic_string_container),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__non_inited),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__invalid_position),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__empty_insert_0),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__empty_insert_10),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__empty_insert_1000),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__begin_insert_0),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__begin_insert_10),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__begin_insert_1000),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__middle_insert_0),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__middle_insert_10),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__middle_insert_1000),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__end_insert_0),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__end_insert_10),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__end_insert_1000),\
    UT_CASE(test__basic_string_insert_elem__basic_string_insert_elem_varg__end_insert_1000_multiple),\
    UT_CASE_BEGIN(_basic_string_insert_n__basic_string_insert_n_varg,\
        test__basic_string_insert_n__basic_string_insert_n_varg__null_basic_string_container),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__non_inited),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__invalid_position),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__empty_insert_0),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__empty_insert_10),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__empty_insert_1000),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__begin_insert_0),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__begin_insert_10),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__begin_insert_1000),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__middle_insert_0),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__middle_insert_10),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__middle_insert_1000),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__end_insert_0),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__end_insert_10),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__end_insert_1000),\
    UT_CASE(test__basic_string_insert_n__basic_string_insert_n_varg__end_insert_1000_multiple),\
    UT_CASE_BEGIN(_basic_string_find_elem__basic_string_find_elem_varg,\
        test__basic_string_find_elem__basic_string_find_elem_varg__null_basic_string_container),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__non_init_basic_string_container),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__invalid_position),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__invalid_position_end),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__invalid_position_NPOS),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__find_failure),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__find_failure_middle_pos),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__find_successful),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__find_successful_middle),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__find_successful_back),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__find_successful_middle_pos),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__cstr_find_failure),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__cstr_find_failure_middle_pos),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__cstr_find_successful),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__cstr_find_successful_middle),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__cstr_find_successful_back),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__cstr_find_successful_middle_pos),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__shared),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__terminator_c),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__terminator_cstr),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__terminator_cstl),\
    UT_CASE(test__basic_string_find_elem__basic_string_find_elem_varg__terminator_user_define),\
    UT_CASE_BEGIN(_basic_string_rfind_elem__basic_string_rfind_elem_varg,\
        test__basic_string_rfind_elem__basic_string_rfind_elem_varg__null_basic_string_container),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__non_init_basic_string_container),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__invalid_position),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__invalid_position_begin),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__invalid_position_NPOS),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__find_failure),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__find_failure_middle_pos),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__find_successful),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__find_successful_middle),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__find_successful_back),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__find_successful_middle_pos),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__pos_eq_size),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__cstr_find_failure),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__cstr_find_failure_middle_pos),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__cstr_find_successful),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__cstr_find_successful_middle),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__cstr_find_successful_back),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__cstr_find_successful_middle_pos),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__shared),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__terminator_c),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__terminator_cstr),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__terminator_cstl),\
    UT_CASE(test__basic_string_rfind_elem__basic_string_rfind_elem_varg__terminator_user_define),\
    UT_CASE_BEGIN(_basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg,\
        test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__null_basic_string_container),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__non_init_basic_string_container),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__invalid_position),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__invalid_position_end),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__invalid_position_NPOS),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__find_first_not_of_failure),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__find_first_not_of_failure_middle_pos),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__find_first_not_of_successful),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__find_first_not_of_successful_middle),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__find_first_not_of_successful_back),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__find_first_not_of_successful_middle_pos),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__cstr_find_first_not_of_failure),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__cstr_find_first_not_of_failure_middle_pos),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__cstr_find_first_not_of_successful),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__cstr_find_first_not_of_successful_middle),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__cstr_find_first_not_of_successful_back),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__cstr_find_first_not_of_successful_middle_pos),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__terminator_c),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__terminator_cstr),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__terminator_cstl),\
    UT_CASE(test__basic_string_find_first_not_of_elem__basic_string_find_first_not_of_elem_varg__terminator_user_define),\
    UT_CASE_BEGIN(_basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg,\
        test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__null_basic_string_container),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__non_init_basic_string_container),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__invalid_position),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__invalid_position_begin),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__invalid_position_NPOS),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__find_failure),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__find_failure_middle_pos),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__find_successful),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__find_successful_middle),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__find_successful_back),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__find_successful_middle_pos),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__cstr_find_failure),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__cstr_find_failure_middle_pos),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__cstr_find_successful),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__cstr_find_successful_middle),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__cstr_find_successful_back),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__cstr_find_successful_middle_pos),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__pos_gt_size),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__pos_eq_size),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__pos_lt_size),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__pos_eq_0),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__empty),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__terminator_c),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__terminator_cstr),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__terminator_cstl),\
    UT_CASE(test__basic_string_find_last_not_of_elem__basic_string_find_last_not_of_elem_varg__terminator_user_define)

#endif /* _UT_CSTL_BASIC_STRING_PRIVATE_H_ */

