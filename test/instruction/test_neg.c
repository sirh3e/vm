//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_neg_0();

int test_instruction_neg(){

    i32 test_results = 0;

    test_results |= test_instruction_neg_0();

    return test_results;
}

int test_instruction_neg_0(){

    i32 test_results = 0, instruction = INSTRUCTION_HALT;
    i32 program[] = {
            INSTRUCTION_INC, A, 255,
            INSTRUCTION_NEG, A,
            INSTRUCTION_NEG, A,

            INSTRUCTION_INC, B, -48,
            INSTRUCTION_NEG, B,
            INSTRUCTION_NEG, B,

            INSTRUCTION_INC, C, 128,
            INSTRUCTION_NEG, C,
            INSTRUCTION_NEG, C,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));

    TEST_BEGIN();

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 0255");
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == -255, "vm.registers[A] == -255");
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 0255");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[B] == -48, "vm.registers[A] == -048");
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[B] == 48, "vm.registers[A] == 0048");
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[B] == -48, "vm.registers[A] == -048");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[C] == 128, "vm.registers[A] == 0128");
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[C] == -128, "vm.registers[A] == -128");
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[C] == 128, "vm.registers[A] == 0128");

    TEST_END();
    vm_free(vm);

    return test_results;
}