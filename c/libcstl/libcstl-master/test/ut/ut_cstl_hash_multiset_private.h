#ifndef _UT_CSTL_HASH_MULTISET_PRIVATE_H_
#define _UT_CSTL_HASH_MULTISET_PRIVATE_H_

UT_SUIT_DECLARATION(cstl_hash_multiset_private)
/*
 * test _create_hash_multiset
 */
UT_CASE_DECLARATION(_create_hash_multiset)
void test__create_hash_multiset__null_typename(void** state);
void test__create_hash_multiset__c_builtin(void** state);
void test__create_hash_multiset__cstr(void** state);
void test__create_hash_multiset__libcstl_builtin(void** state);
void test__create_hash_multiset__user_define(void** state);
void test__create_hash_multiset__unregister(void** state);
/*
 * test _create_hash_multiset_auxiliary
 */
UT_CASE_DECLARATION(_create_hash_multiset_auxiliary)
void test__create_hash_multiset_auxiliary__null_hash_multiset(void** state);
void test__create_hash_multiset_auxiliary__null_typename(void** state);
void test__create_hash_multiset_auxiliary__unregistered(void** state);
void test__create_hash_multiset_auxiliary__c_builtin(void** state);
void test__create_hash_multiset_auxiliary__cstr(void** state);
void test__create_hash_multiset_auxiliary__libcstl_builtin(void** state);
void test__create_hash_multiset_auxiliary__user_define(void** state);
/*
 * test _hash_multiset_destroy_auxiliary
 */
UT_CASE_DECLARATION(_hash_multiset_destroy_auxiliary)
void test__hash_multiset_destroy_auxiliary__null_hash_multiset(void** state);
void test__hash_multiset_destroy_auxiliary__non_created(void** state);
/*void test__hash_multiset_destroy_auxiliary__non_inited(void** state);*/
void test__hash_multiset_destroy_auxiliary__empty(void** state);
void test__hash_multiset_destroy_auxiliary__non_empty(void** state);
/*
 * test _hash_multiset_find and _hash_multiset_find_varg
 */
UT_CASE_DECLARATION(_hash_multiset_find__hash_multiset_find_varg)
void test__hash_multiset_find__hash_multiset_find_varg__null_hash_multiset(void** state);
void test__hash_multiset_find__hash_multiset_find_varg__non_inited(void** state);
void test__hash_multiset_find__hash_multiset_find_varg__c_builtin_find(void** state);
void test__hash_multiset_find__hash_multiset_find_varg__c_builtin_not_find(void** state);
void test__hash_multiset_find__hash_multiset_find_varg__cstr_find(void** state);
void test__hash_multiset_find__hash_multiset_find_varg__cstr_not_find(void** state);
void test__hash_multiset_find__hash_multiset_find_varg__libcstl_builtin_find(void** state);
void test__hash_multiset_find__hash_multiset_find_varg__libcstl_builtin_not_find(void** state);
void test__hash_multiset_find__hash_multiset_find_varg__user_define_find(void** state);
void test__hash_multiset_find__hash_multiset_find_varg__user_define_not_find(void** state);
/*
 * test _hash_multiset_count and _hash_multiset_count_varg
 */
UT_CASE_DECLARATION(_hash_multiset_count__hash_multiset_count_varg)
void test__hash_multiset_count__hash_multiset_count_varg__null_hash_multiset(void** state);
void test__hash_multiset_count__hash_multiset_count_varg__non_inited(void** state);
void test__hash_multiset_count__hash_multiset_count_varg__c_builtin_0(void** state);
void test__hash_multiset_count__hash_multiset_count_varg__c_builtin_1(void** state);
void test__hash_multiset_count__hash_multiset_count_varg__c_builtin_n(void** state);
void test__hash_multiset_count__hash_multiset_count_varg__cstr_0(void** state);
void test__hash_multiset_count__hash_multiset_count_varg__cstr_1(void** state);
void test__hash_multiset_count__hash_multiset_count_varg__cstr_n(void** state);
void test__hash_multiset_count__hash_multiset_count_varg__libcstl_builtin_0(void** state);
void test__hash_multiset_count__hash_multiset_count_varg__libcstl_builtin_1(void** state);
void test__hash_multiset_count__hash_multiset_count_varg__libcstl_builtin_n(void** state);
void test__hash_multiset_count__hash_multiset_count_varg__user_define_0(void** state);
void test__hash_multiset_count__hash_multiset_count_varg__user_define_1(void** state);
void test__hash_multiset_count__hash_multiset_count_varg__user_define_n(void** state);
/*
 * test _hash_multiset_equal_range and _hash_multiset_equal_range_varg
 */
UT_CASE_DECLARATION(_hash_multiset_equal_range__hash_multiset_equal_range_varg)
void test__hash_multiset_equal_range__hash_multiset_equal_range_varg__null_hash_multiset(void** state);
void test__hash_multiset_equal_range__hash_multiset_equal_range_varg__non_inited(void** state);
void test__hash_multiset_equal_range__hash_multiset_equal_range_varg__c_builtin_equal(void** state);
void test__hash_multiset_equal_range__hash_multiset_equal_range_varg__c_builtin_greater(void** state);
void test__hash_multiset_equal_range__hash_multiset_equal_range_varg__cstr_upper_equal(void** state);
void test__hash_multiset_equal_range__hash_multiset_equal_range_varg__cstr_greater(void** state);
void test__hash_multiset_equal_range__hash_multiset_equal_range_varg__libcstl_builtin_equal(void** state);
void test__hash_multiset_equal_range__hash_multiset_equal_range_varg__libcstl_builtin_greater(void** state);
void test__hash_multiset_equal_range__hash_multiset_equal_range_varg__user_define_equal(void** state);
void test__hash_multiset_equal_range__hash_multiset_equal_range_varg__user_define_greater(void** state);
/*
 * test _hash_multiset_erase and _hash_multiset_erase_varg
 */
UT_CASE_DECLARATION(_hash_multiset_erase__hash_multiset_erase_varg)
void test__hash_multiset_erase__hash_multiset_erase_varg__null_hash_multiset(void** state);
void test__hash_multiset_erase__hash_multiset_erase_varg__non_inited(void** state);
void test__hash_multiset_erase__hash_multiset_erase_varg__c_builtin_0(void** state);
void test__hash_multiset_erase__hash_multiset_erase_varg__c_builtin_1(void** state);
void test__hash_multiset_erase__hash_multiset_erase_varg__c_builtin_n(void** state);
void test__hash_multiset_erase__hash_multiset_erase_varg__cstr_0(void** state);
void test__hash_multiset_erase__hash_multiset_erase_varg__cstr_1(void** state);
void test__hash_multiset_erase__hash_multiset_erase_varg__cstr_n(void** state);
void test__hash_multiset_erase__hash_multiset_erase_varg__libcstl_builtin_0(void** state);
void test__hash_multiset_erase__hash_multiset_erase_varg__libcstl_builtin_1(void** state);
void test__hash_multiset_erase__hash_multiset_erase_varg__libcstl_builtin_n(void** state);
void test__hash_multiset_erase__hash_multiset_erase_varg__user_define_0(void** state);
void test__hash_multiset_erase__hash_multiset_erase_varg__user_define_1(void** state);
void test__hash_multiset_erase__hash_multiset_erase_varg__user_define_n(void** state);
/*
 * test _hash_multiset_insert and _hash_multiset_insert_varg
 */
UT_CASE_DECLARATION(_hash_multiset_insert__hash_multiset_insert_varg)
void test__hash_multiset_insert_varg__null_hash_multiset(void** state);
void test__hash_multiset_insert_varg__non_inited(void** state);
void test__hash_multiset_insert_varg__c_builtin_equal(void** state);
void test__hash_multiset_insert_varg__c_builtin_not_equal(void** state);
void test__hash_multiset_insert_varg__cstr_equal(void** state);
void test__hash_multiset_insert_varg__cstr_not_equal(void** state);
void test__hash_multiset_insert_varg__libcstl_builtin_equal(void** state);
void test__hash_multiset_insert_varg__libcstl_builtin_not_equal(void** state);
void test__hash_multiset_insert_varg__user_define_equal(void** state);
void test__hash_multiset_insert_varg__user_define_not_equal(void** state);
/*
 * test _hash_multiset_init_elem_auxiliary
 */
UT_CASE_DECLARATION(_hash_multiset_init_elem_auxiliary)
void test__hash_multiset_init_elem_auxiliary__null_hash_multiset_container(void** state);
void test__hash_multiset_init_elem_auxiliary__null_elem(void** state);
void test__hash_multiset_init_elem_auxiliary__successfully_int(void** state);
void test__hash_multiset_init_elem_auxiliary__successfully_cstr(void** state);
void test__hash_multiset_init_elem_auxiliary__successfully_iterator(void** state);
void test__hash_multiset_init_elem_auxiliary__successfully_container(void** state);
void test__hash_multiset_init_elem_auxiliary__successfully_user_defined(void** state);

#define UT_CSTL_HASH_MULTISET_PRIVATE_CASE\
    UT_SUIT_BEGIN(cstl_hash_multiset_private, test__create_hash_multiset__null_typename),\
    UT_CASE(test__create_hash_multiset__c_builtin),\
    UT_CASE(test__create_hash_multiset__cstr),\
    UT_CASE(test__create_hash_multiset__libcstl_builtin),\
    UT_CASE(test__create_hash_multiset__user_define),\
    UT_CASE(test__create_hash_multiset__unregister),\
    UT_CASE_BEGIN(_create_hash_multiset_auxiliary, test__create_hash_multiset_auxiliary__null_hash_multiset),\
    UT_CASE(test__create_hash_multiset_auxiliary__null_typename),\
    UT_CASE(test__create_hash_multiset_auxiliary__unregistered),\
    UT_CASE(test__create_hash_multiset_auxiliary__c_builtin),\
    UT_CASE(test__create_hash_multiset_auxiliary__cstr),\
    UT_CASE(test__create_hash_multiset_auxiliary__libcstl_builtin),\
    UT_CASE(test__create_hash_multiset_auxiliary__user_define),\
    UT_CASE_BEGIN(_hash_multiset_destroy_auxiliary, test__hash_multiset_destroy_auxiliary__null_hash_multiset),\
    UT_CASE(test__hash_multiset_destroy_auxiliary__non_created),\
    UT_CASE(test__hash_multiset_destroy_auxiliary__empty),\
    UT_CASE(test__hash_multiset_destroy_auxiliary__non_empty),\
    UT_CASE_BEGIN(_hash_multiset_find__hash_multiset_find_varg, test__hash_multiset_find__hash_multiset_find_varg__null_hash_multiset),\
    UT_CASE(test__hash_multiset_find__hash_multiset_find_varg__non_inited),\
    UT_CASE(test__hash_multiset_find__hash_multiset_find_varg__c_builtin_find),\
    UT_CASE(test__hash_multiset_find__hash_multiset_find_varg__c_builtin_not_find),\
    UT_CASE(test__hash_multiset_find__hash_multiset_find_varg__cstr_find),\
    UT_CASE(test__hash_multiset_find__hash_multiset_find_varg__cstr_not_find),\
    UT_CASE(test__hash_multiset_find__hash_multiset_find_varg__libcstl_builtin_find),\
    UT_CASE(test__hash_multiset_find__hash_multiset_find_varg__libcstl_builtin_not_find),\
    UT_CASE(test__hash_multiset_find__hash_multiset_find_varg__user_define_find),\
    UT_CASE(test__hash_multiset_find__hash_multiset_find_varg__user_define_not_find),\
    UT_CASE_BEGIN(_hash_multiset_count__hash_multiset_count_varg, test__hash_multiset_count__hash_multiset_count_varg__null_hash_multiset),\
    UT_CASE(test__hash_multiset_count__hash_multiset_count_varg__non_inited),\
    UT_CASE(test__hash_multiset_count__hash_multiset_count_varg__c_builtin_0),\
    UT_CASE(test__hash_multiset_count__hash_multiset_count_varg__c_builtin_1),\
    UT_CASE(test__hash_multiset_count__hash_multiset_count_varg__c_builtin_n),\
    UT_CASE(test__hash_multiset_count__hash_multiset_count_varg__cstr_0),\
    UT_CASE(test__hash_multiset_count__hash_multiset_count_varg__cstr_1),\
    UT_CASE(test__hash_multiset_count__hash_multiset_count_varg__cstr_n),\
    UT_CASE(test__hash_multiset_count__hash_multiset_count_varg__libcstl_builtin_0),\
    UT_CASE(test__hash_multiset_count__hash_multiset_count_varg__libcstl_builtin_1),\
    UT_CASE(test__hash_multiset_count__hash_multiset_count_varg__libcstl_builtin_n),\
    UT_CASE(test__hash_multiset_count__hash_multiset_count_varg__user_define_0),\
    UT_CASE(test__hash_multiset_count__hash_multiset_count_varg__user_define_1),\
    UT_CASE(test__hash_multiset_count__hash_multiset_count_varg__user_define_n),\
    UT_CASE_BEGIN(_hash_multiset_equal_range__hash_multiset_equal_range_varg, test__hash_multiset_equal_range__hash_multiset_equal_range_varg__null_hash_multiset),\
    UT_CASE(test__hash_multiset_equal_range__hash_multiset_equal_range_varg__non_inited),\
    UT_CASE(test__hash_multiset_equal_range__hash_multiset_equal_range_varg__c_builtin_equal),\
    UT_CASE(test__hash_multiset_equal_range__hash_multiset_equal_range_varg__c_builtin_greater),\
    UT_CASE(test__hash_multiset_equal_range__hash_multiset_equal_range_varg__cstr_upper_equal),\
    UT_CASE(test__hash_multiset_equal_range__hash_multiset_equal_range_varg__cstr_greater),\
    UT_CASE(test__hash_multiset_equal_range__hash_multiset_equal_range_varg__libcstl_builtin_equal),\
    UT_CASE(test__hash_multiset_equal_range__hash_multiset_equal_range_varg__libcstl_builtin_greater),\
    UT_CASE(test__hash_multiset_equal_range__hash_multiset_equal_range_varg__user_define_equal),\
    UT_CASE(test__hash_multiset_equal_range__hash_multiset_equal_range_varg__user_define_greater),\
    UT_CASE_BEGIN(_hash_multiset_erase__hash_multiset_erase_varg, test__hash_multiset_erase__hash_multiset_erase_varg__null_hash_multiset),\
    UT_CASE(test__hash_multiset_erase__hash_multiset_erase_varg__non_inited),\
    UT_CASE(test__hash_multiset_erase__hash_multiset_erase_varg__c_builtin_0),\
    UT_CASE(test__hash_multiset_erase__hash_multiset_erase_varg__c_builtin_1),\
    UT_CASE(test__hash_multiset_erase__hash_multiset_erase_varg__c_builtin_n),\
    UT_CASE(test__hash_multiset_erase__hash_multiset_erase_varg__cstr_0),\
    UT_CASE(test__hash_multiset_erase__hash_multiset_erase_varg__cstr_1),\
    UT_CASE(test__hash_multiset_erase__hash_multiset_erase_varg__cstr_n),\
    UT_CASE(test__hash_multiset_erase__hash_multiset_erase_varg__libcstl_builtin_0),\
    UT_CASE(test__hash_multiset_erase__hash_multiset_erase_varg__libcstl_builtin_1),\
    UT_CASE(test__hash_multiset_erase__hash_multiset_erase_varg__libcstl_builtin_n),\
    UT_CASE(test__hash_multiset_erase__hash_multiset_erase_varg__user_define_0),\
    UT_CASE(test__hash_multiset_erase__hash_multiset_erase_varg__user_define_1),\
    UT_CASE(test__hash_multiset_erase__hash_multiset_erase_varg__user_define_n),\
    UT_CASE_BEGIN(_hash_multiset_insert__hash_multiset_insert_varg, test__hash_multiset_insert_varg__null_hash_multiset),\
    UT_CASE(test__hash_multiset_insert_varg__non_inited),\
    UT_CASE(test__hash_multiset_insert_varg__c_builtin_equal),\
    UT_CASE(test__hash_multiset_insert_varg__c_builtin_not_equal),\
    UT_CASE(test__hash_multiset_insert_varg__cstr_equal),\
    UT_CASE(test__hash_multiset_insert_varg__cstr_not_equal),\
    UT_CASE(test__hash_multiset_insert_varg__libcstl_builtin_equal),\
    UT_CASE(test__hash_multiset_insert_varg__libcstl_builtin_not_equal),\
    UT_CASE(test__hash_multiset_insert_varg__user_define_equal),\
    UT_CASE(test__hash_multiset_insert_varg__user_define_not_equal),\
    UT_CASE_BEGIN(_hash_multiset_init_elem_auxiliary, test__hash_multiset_init_elem_auxiliary__null_hash_multiset_container),\
    UT_CASE(test__hash_multiset_init_elem_auxiliary__null_elem),\
    UT_CASE(test__hash_multiset_init_elem_auxiliary__successfully_int),\
    UT_CASE(test__hash_multiset_init_elem_auxiliary__successfully_cstr),\
    UT_CASE(test__hash_multiset_init_elem_auxiliary__successfully_iterator),\
    UT_CASE(test__hash_multiset_init_elem_auxiliary__successfully_container),\
    UT_CASE(test__hash_multiset_init_elem_auxiliary__successfully_user_defined)

#endif /* _UT_CSTL_HASH_MULTISET_PRIVATE_H_ */

