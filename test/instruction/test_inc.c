//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_inc_0();

int test_instruction_inc(){

    i32 test_results = 0;

    test_results |= test_instruction_inc_0();

    return test_results;
}

int test_instruction_inc_0(){

    i32 test_results = 0, instruction = INSTRUCTION_HALT;
    i32 program[] = {
            INSTRUCTION_INC, A, 2,
            INSTRUCTION_INC, A, 2,
            INSTRUCTION_INC, B, 128,
            INSTRUCTION_INC, B, 128,
            INSTRUCTION_INC, C, 0,
            INSTRUCTION_INC, C, 369,
            INSTRUCTION_INC, C, 369,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));

    TEST_BEGIN();

    instruction = vm_instruction_fetch(vm);
    vm_instruction_evaluate(vm, instruction);
    TEST_ASSERT(vm->registers[A] == 2, "vm.registers[A] == 2");

    instruction = vm_instruction_fetch(vm);
    vm_instruction_evaluate(vm, instruction);
    TEST_ASSERT(vm->registers[A] == 4, "vm.registers[A] == 4");

    instruction = vm_instruction_fetch(vm);
    vm_instruction_evaluate(vm, instruction);
    TEST_ASSERT(vm->registers[B] == 128, "vm.registers[B] == 128");

    instruction = vm_instruction_fetch(vm);
    vm_instruction_evaluate(vm, instruction);
    TEST_ASSERT(vm->registers[C] == 0, "vm.registers[C] == 0");

    TEST_END(vm);

    return test_results;
}