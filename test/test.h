//
// Created by sirh3e on 9/20/2020.
//

#ifndef VM_TEST_H
#define VM_TEST_H

#include "../src/types.h"
typedef u32 test_result_t;

#define COLOR_REST "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"

#define TEST_INIT(program) \
   Vm* vm = vm_new();      \
   vm_init(vm);            \
   vm_program_set(vm, program, ARRAY_SIZE)

#define TEST_BEGIN() \
            printf("[ BEGIN  ] %s\n", __func__)

#define TEST_END(vm) \
    printf("[ END    ] %s\n", __func__); \
    vm_free(vm)
    
#define TEST_ASSERT(expression, message) \
            printf("[ %s%s%s ] %s file: [%s] function: [%s] line: [%d] \n", expression ? COLOR_GREEN : COLOR_RED, expression ? "PASSED" : "FAILED", COLOR_REST, message, __FILE__, __func__, __LINE__); \
            test_results |= expression ? (test_result_t)0 : (test_result_t)1

#define TEST_INSTRUCTION_EXECUTE_NEXT(vm) \
        vm_instruction_evaluate(vm, vm_instruction_fetch(vm))

#endif //VM_TEST_H
