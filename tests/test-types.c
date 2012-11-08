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
#include "yardarm/types.h"

#include "helpers.h"


/*-----------------------------------------------------------------------
 * Scalar types
 */

#define test_scalar(type, expected_name, expected_size) \
    do { \
        fail_unless(strcmp((type)->name, expected_name) == 0, \
                    "Unexpected name for " #type ": got %s, expected %s", \
                    (type)->name, expected_name); \
        fail_unless((type)->size == expected_size, \
                    "Unexpected size for " #type ": got %zu, expected %zu", \
                    (type)->size, expected_size); \
    } while (0)

START_TEST(test_c99)
{
    DESCRIBE_TEST;
#define ___(name, c_type) \
    test_scalar(&yat_##name, #c_type, sizeof(c_type)); \
    test_scalar(&yat_##name##_p, #c_type " *", sizeof(c_type *));
    ya_all_c99_types(___);
#undef ___
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
