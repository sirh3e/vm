//
// Created by sirh3e on 10/10/2020.
//

#ifndef VM_TEST_UTIL_H
#define VM_TEST_UTIL_H

#include "../src/vm.h"
#include "../src/util.h"

#include "test_color.h"

#define TEST_RESULTS_INIT(test_result) \
        test_result = {                \
            .failed = 0,               \
            .passed = 0,               \
        }

#define VM_INIT(program) \
    Vm* vm = vm_new();   \
    vm_init(vm);         \
    vm_program_set(vm, program, ARRAY_LENGTH(program))

#define TEST_BEGIN() \
    printf("[ BEGIN  ] %s\n", __func__)

#define TEST_END(vm, test_results)                                      \
    printf(                                                             \
        "[ END    ] %s tests: %s%u%s passed: %s%u%s failed: %s%u%s\n",  \
        __func__,                                                       \
        test_results.failed ? VM_TEST_COLOR_RED : VM_TEST_COLOR_GREEN,  \
        test_results.failed + test_results.passed,                      \
        VM_TEST_COLOR_REST,                                             \
        test_results.failed ? VM_TEST_COLOR_RED : VM_TEST_COLOR_GREEN,  \
        test_results.passed,                                            \
        VM_TEST_COLOR_REST,                                             \
        test_results.failed ? VM_TEST_COLOR_RED : VM_TEST_COLOR_GREEN,  \
        test_results.failed,                                            \
        VM_TEST_COLOR_REST                                              \
    );                                                                  \
    vm_free(vm)

#define TEST_INSTRUCTION_EXECUTE_NEXT(vm) \
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm))

#endif //VM_TEST_UTIL_H