//
// Created by sirh3e on 10/10/2020.
//

#ifndef VM_TEST_UTIL_H
#define VM_TEST_UTIL_H

#include "../src/vm.h"
#include "../src/util.h"

#define TEST_BEGIN() \
    printf("[ BEGIN  ] %s\n", __func__)

#define TEST_END(vm) \
    printf("[ END    ] %s\n", __func__); \
    vm_free(vm)

#define VM_INIT(program) \
    Vm* vm = vm_new();      \
    vm_init(vm);            \
    vm_program_set(vm, program, ARRAY_LENGTH(program))

#define TEST_INSTRUCTION_EXECUTE_NEXT(vm) \
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm))

#endif //VM_TEST_UTIL_H