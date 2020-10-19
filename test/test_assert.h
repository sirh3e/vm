//
// Created by sirh3e on 10/10/2020.
//

#ifndef VM_TEST_ASSERT_H
#define VM_TEST_ASSERT_H

#include <stdio.h>

#include "test_color.h"
#include "test_types.h"

#define TEST_ASSERT_MESSAGE(expression, message) \
            printf("[ %s%s%s ] %-32s file: [%s] function: [%s] line: [%d] \n", expression ? VM_TEST_COLOR_GREEN : VM_TEST_COLOR_RED, expression ? "PASSED" : "FAILED", VM_TEST_COLOR_REST, message, __FILE__, __func__, __LINE__); \
            test_results |= expression ? (test_vm_instruction_result)0 : (test_vm_instruction_result)1

#define TEST_ASSERT(expression) \
           TEST_ASSERT_MESSAGE(expression, #expression)

#endif //VM_TEST_ASSERT_H