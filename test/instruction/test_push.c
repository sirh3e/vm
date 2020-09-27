//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_push_0();

int test_instruction_push(){

    i32 test_results = 0;

    test_results |= test_instruction_push_0();

    return test_results;
}

int test_instruction_push_0(){

    i32 test_results = 0, instruction = INSTRUCTION_HALT;
    i32 program[] = {
            INSTRUCTION_PUSH, 1,
            INSTRUCTION_PUSH, 2,
            INSTRUCTION_PUSH, 3,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));

    TEST_BEGIN();

    TEST_ASSERT(vm->instruction_index == 0, "vm.instruction_index == 000");
    TEST_ASSERT(vm->stack_index == 0, "vm.stack_index == 000");

    //ToDo create test for loop

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm)); // 1
    TEST_ASSERT(vm->instruction_index == 2, "vm.instruction_index == 002");
    TEST_ASSERT(vm->stack_index == 1, "vm.stack_index == 001");
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 1, "vm->stack[vm->stack_index - 1] == 001");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm)); // 2
    TEST_ASSERT(vm->instruction_index == 4, "vm.instruction_index == 004");
    TEST_ASSERT(vm->stack_index == 2, "vm.stack_index == 002");
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 2, "vm->stack[vm->stack_index - 1] == 002");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm)); // 3
    TEST_ASSERT(vm->instruction_index == 6, "vm.instruction_index == 006");
    TEST_ASSERT(vm->stack_index == 3, "vm.stack_index == 003");
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 3, "vm->stack[vm->stack_index - 1] == 003");

    TEST_END();
    vm_free(vm);

    return test_results;
}