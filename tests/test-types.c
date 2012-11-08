/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <check.h>

#include "yardarm/c99.h"
#include "yardarm/yardarm.h"

#include "helpers.h"


/*-----------------------------------------------------------------------
 * Helpers
 */

#define test_basics(type, ename, esize) \
    do { \
        fail_unless(strcmp((type)->name, ename) == 0, \
                    "Unexpected name for " #type ": got %s, expected %s", \
                    (type)->name, ename); \
        fail_unless((type)->size == esize, \
                    "Unexpected size for " #type ": got %zu, expected %zu", \
                    (type)->size, esize); \
    } while (0)

#define test_count(type, echild_count) \
    do { \
        fail_unless((type)->child_count == echild_count, \
                    "Unexpected child count for " #type \
                    ": got %zu, expected %zu", \
                    (type)->child_count, echild_count); \
    } while (0)

#define test_scalar2(name, p_name, c_type) \
    do { \
        test_basics(&yat_##name, #c_type, sizeof(c_type)); \
        test_count(&yat_##name, 0); \
        test_basics(&yat_##p_name, #c_type " *", sizeof(c_type *)); \
        test_count(&yat_##p_name, 0); \
        fail_unless(yat_##p_name.pointer == &yat_##name, \
                    "Unexpected reference type for " #p_name); \
    } while (0)

#define test_scalar(name, c_type) \
    test_scalar2(name, name##_p, c_type)

#define test_enum_value(type, i, evalue, ename, eshort_name) \
    do { \
        fail_unless(strcmp((type)->values[i].name, ename) == 0, \
                    "Unexpected name for " #type " value %d: " \
                    "got %s, expected %s", \
                    (int) i, (type)->values[i].name, ename); \
        fail_unless(strcmp((type)->values[i].short_name, eshort_name) == 0, \
                    "Unexpected short name for " #type " value %d: " \
                    "got %s, expected %s", \
                    (int) i, (type)->values[i].short_name, eshort_name); \
        fail_unless((type)->values[i].value == evalue, \
                    "Unexpected value for " #type " value %d: " \
                    "got %ld, expected %ld", \
                    (type)->values[i].value, evalue); \
    } while (0)


/*-----------------------------------------------------------------------
 * C99 types
 */

START_TEST(test_c99)
{
    DESCRIBE_TEST;
    test_scalar2(bool_, bool_p, bool);
    test_scalar(char, char);
    test_scalar(schar, signed char);
    test_scalar(short, short);
    test_scalar(int, int);
    test_scalar(long, long);
    test_scalar(uchar, unsigned char);
    test_scalar(ushort, unsigned short);
    test_scalar(uint, unsigned int);
    test_scalar(ulong, unsigned long);
    test_scalar(int8, int8_t);
    test_scalar(int16, int16_t);
    test_scalar(int32, int32_t);
    test_scalar(int64, int64_t);
    test_scalar(intptr, intptr_t);
    test_scalar(ssize, ssize_t);
    test_scalar(uint8, uint8_t);
    test_scalar(uint16, uint16_t);
    test_scalar(uint32, uint32_t);
    test_scalar(uint64, uint64_t);
    test_scalar(uintptr, uintptr_t);
    test_scalar(size, size_t);
    test_scalar(float, float);
    test_scalar(double, double);
}
END_TEST


/*-----------------------------------------------------------------------
 * Enums
 */

START_TEST(test_yardarm)
{
    DESCRIBE_TEST;

    test_basics(&yat_ya_kind, "enum ya_kind", sizeof(enum ya_kind));
    test_count(&yat_ya_kind, 5);
    test_enum_value(&yat_ya_kind, 0, YA_KIND_ENUM, "YA_KIND_ENUM", "ENUM");
    test_enum_value(&yat_ya_kind, 1, YA_KIND_POINTER,
                    "YA_KIND_POINTER", "POINTER");
    test_enum_value(&yat_ya_kind, 2, YA_KIND_SCALAR, "YA_KIND_SCALAR", "SCALAR");
    test_enum_value(&yat_ya_kind, 3, YA_KIND_STRUCT, "YA_KIND_STRUCT", "STRUCT");
    test_enum_value(&yat_ya_kind, 4, YA_KIND_UNION, "YA_KIND_UNION", "UNION");
}
END_TEST


/*-----------------------------------------------------------------------
 * Testing harness
 */

Suite *
test_suite()
{
    Suite  *s = suite_create("types");

    TCase  *tc_types = tcase_create("types");
    tcase_add_test(tc_types, test_c99);
    tcase_add_test(tc_types, test_yardarm);
    suite_add_tcase(s, tc_types);

    return s;
}


int
main(int argc, const char **argv)
{
    int  number_failed;
    Suite  *suite = test_suite();
    SRunner  *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0)? EXIT_SUCCESS: EXIT_FAILURE;
}
