/*
 * Copyright (C) 2021 Niklaus Leuenberger
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    module_hello_module hello_module
 * @ingroup     module
 * @brief       A simple module to test the buildsystem and unittest framework.
 *
 * @{
 *
 * @file        hello_module.h
 *
 * @author      Niklaus Leuenberger <niklaus.leuenb@gmail.com>
 */

#ifndef HELLO_MODULE_H
#define HELLO_MODULE_H

/* #include "xyz.h" */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Set the message to print.
 *
 * The provided message will be printed to stdout when calling
 * \ref hello_module_print_message().
 *
 * @param new_message new message to print later
 * @return int allways 0
 */
int hello_module_set_message(const char *new_message);

/**
 * @brief Print the currently set message.
 *
 * @return int allways 0
 */
int hello_module_print_message(void);

#ifdef __cplusplus
}
#endif

#endif /* HELLO_MODULE_H */
/** @} */
