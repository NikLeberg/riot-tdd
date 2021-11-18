/*
 * Copyright (C) 2021 Niklaus Leuenberger
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     tests
 * @{
 *
 * @file        main.c
 * @brief       Test the hello_module module with the embunit unittest framework.
 *
 * @author      Niklaus Leuenberger <niklaus.leuenb@gmail.com>
 *
 * @}
 */

#include <stdio.h>

#include "embUnit.h"
#include "fff.h"
#include "periph/pm.h"

#include "hello_module.h"

static void test_hello_module_set_message_can_set_message(void)
{
    static const char test_message[] = "Test message.";

    TEST_ASSERT_EQUAL_INT(0, hello_module_set_message(test_message));
    return;
}

static void test_hello_module_hello_module_print_message_can_be_called(void)
{
    TEST_ASSERT_EQUAL_INT(0, hello_module_print_message());
    TEST_ASSERT_EQUAL_INT(0, 1); // intentional fail
    return;
}

Test *tests_hello_module_tests(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture(test_hello_module_set_message_can_set_message),
        new_TestFixture(test_hello_module_hello_module_print_message_can_be_called),
    };

    EMB_UNIT_TESTCALLER(hello_module_tests, NULL, NULL, fixtures);
    return (Test *)&hello_module_tests;
}

int main(void)
{
    puts("Running unittest for module 'hello_module'");

    TextUIRunner_start();
    TESTS_RUN(tests_hello_module_tests());
    TextUIRunner_end();

    pm_off();
    return 0;
}
