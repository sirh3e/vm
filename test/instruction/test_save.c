//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_save_0();

int test_instruction_save(){

    i32 test_results = 0;

    test_results |= test_instruction_save_0();

    return test_results;
}

int test_instruction_save_0(){

    i32 test_results = 0, instruction = INSTRUCTION_HALT;
    i32 program[] = {
            INSTRUCTION_ADD, -963, 4589,
            INSTRUCTION_SAVE, A,

            INSTRUCTION_ADD, 369825, 63512,
            INSTRUCTION_SAVE, B,

            INSTRUCTION_ADD, 1, 2,
            INSTRUCTION_SAVE, C,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));

    TEST_BEGIN();

    TEST_ASSERT(vm->instruction_index == 0, "vm.instruction_index == 000");
    TEST_ASSERT(vm->stack_index == 0, "vm.stack_index == 000");

    //ToDo create test for loop

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->instruction_index == 5, "vm.instruction_index == 0005");
    TEST_ASSERT(vm->stack_index == 1, "vm.stack_index == 0001");
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == -963, "vm->stack[vm->stack_index - 1] == -963");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->instruction_index == 10, "vm.instruction_index == 0010");
    TEST_ASSERT(vm->stack_index == 2, "vm.stack_index == 0002");
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 63512, "vm->stack[vm->stack_index - 1] == 63512");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->instruction_index == 15, "vm.instruction_index == 0015");
    TEST_ASSERT(vm->stack_index == 3, "vm.stack_index == 0003");
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 3, "vm->stack[vm->stack_index - 1] == 3");

    TEST_END();
    vm_free(vm);

    return test_results;
}