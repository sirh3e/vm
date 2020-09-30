//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_mul_0();

int test_instruction_mul(){

    i32 test_results = 0;

    test_results |= test_instruction_mul_0();

    return test_results;
}

int test_instruction_mul_0(){

    i32 test_results = 0, instruction = INSTRUCTION_HALT;
    i32 program[] = {
            INSTRUCTION_MUL, -2, 2,
            INSTRUCTION_MUL, 2, -2,
            INSTRUCTION_MUL, -2, -2,
            INSTRUCTION_MUL, 2, 2,

            INSTRUCTION_MUL, 0, 2,
            INSTRUCTION_MUL, 2, 0,
            INSTRUCTION_MUL, 0, 0,

            INSTRUCTION_MUL, 1, 1,
            INSTRUCTION_MUL, 1000, 1000,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));

    TEST_BEGIN();

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == -2, "vm.registers[A] == -002");
    TEST_ASSERT(vm->registers[B] == 2, "vm.registers[B] == 0002");
    TEST_ASSERT(vm->registers[C] == -4, "vm.registers[C] == -004");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 2, "vm.registers[A] == 0002");
    TEST_ASSERT(vm->registers[B] == -2, "vm.registers[B] == -002");
    TEST_ASSERT(vm->registers[C] == -4, "vm.registers[C] == -004");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == -2, "vm.registers[A] == -002");
    TEST_ASSERT(vm->registers[B] == -2, "vm.registers[B] == -002");
    TEST_ASSERT(vm->registers[C] == 4, "vm.registers[C] == 0004");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 2, "vm.registers[A] == 0002");
    TEST_ASSERT(vm->registers[B] == 2, "vm.registers[B] == 0002");
    TEST_ASSERT(vm->registers[C] == 4, "vm.registers[C] == 0004");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 0, "vm.registers[A] == 0000");
    TEST_ASSERT(vm->registers[B] == 2, "vm.registers[B] == 0002");
    TEST_ASSERT(vm->registers[C] == 0, "vm.registers[C] == 0000");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 2, "vm.registers[A] == 0002");
    TEST_ASSERT(vm->registers[B] == 0, "vm.registers[B] == 0000");
    TEST_ASSERT(vm->registers[C] == 0, "vm.registers[C] == 0000");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 0, "vm.registers[A] == 0000");
    TEST_ASSERT(vm->registers[B] == 0, "vm.registers[B] == 0000");
    TEST_ASSERT(vm->registers[C] == 0, "vm.registers[C] == 0000");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 1, "vm.registers[A] == 0001");
    TEST_ASSERT(vm->registers[B] == 1, "vm.registers[B] == 0001");
    TEST_ASSERT(vm->registers[C] == 1, "vm.registers[C] == 0001");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 1000, "vm.registers[A] == 1000");
    TEST_ASSERT(vm->registers[B] == 1000, "vm.registers[B] == 1000");
    TEST_ASSERT(vm->registers[C] == 1000000, "vm.registers[C] == 10000000");

    TEST_END(vm);

    return test_results;
}