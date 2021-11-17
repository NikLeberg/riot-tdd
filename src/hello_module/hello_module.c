/*
 * Copyright (C) 2021 Niklaus Leuenberger
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     module_hello_module
 * @{
 *
 * @file        hello_module.c
 * @brief       hello_module implementation
 *
 * @author      Niklaus Leuenberger <niklaus.leuenb@gmail.com>
 *
 * @}
 */

#include <stdio.h>

#include "hello_module.h"


#define MESSAGE_LENGTH (26)                 //< Maximum length for new messages

static char hello_message[MESSAGE_LENGTH];  //< Message to get printed


int hello_module_set_message(const char *new_message)
{
    for (int i = 0; i < MESSAGE_LENGTH; ++i) {
        if (new_message[i] == '\0') {
            break;
        }
        else {
            hello_message[i] = new_message[i];
        }
    }
    hello_message[MESSAGE_LENGTH - 1] = '\0'; /* for sanity */
    return 0;
}

int hello_module_print_message(void)
{
    puts(hello_message);
    return 0;
}
