//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_pop_0();

int test_instruction_pop(){

    i32 test_results = 0;

    test_results |= test_instruction_pop_0();

    return test_results;
}

int test_instruction_pop_0(){

    i32 test_results = 0, instruction = INSTRUCTION_HALT;
    i32 program[] = {
            INSTRUCTION_PUSH, 1,
            INSTRUCTION_PUSH, 2,
            INSTRUCTION_PUSH, 3,

            INSTRUCTION_POP, C,
            INSTRUCTION_POP, B,
            INSTRUCTION_POP, A,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));

    TEST_BEGIN();

    TEST_ASSERT(vm->instruction_index == 0, "vm.instruction_index == 000");
    TEST_ASSERT(vm->stack_index == 0, "vm.stack_index == 000");
    TEST_ASSERT(vm->registers[A] == 0, "vm.registers[A] == 000");
    TEST_ASSERT(vm->registers[B] == 0, "vm.registers[B] == 000");
    TEST_ASSERT(vm->registers[C] == 0, "vm.registers[C] == 000");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm)); // 1
    TEST_ASSERT(vm->instruction_index == 2, "vm.instruction_index == 002");
    TEST_ASSERT(vm->stack_index == 1, "vm.stack_index == 001");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm)); // 2
    TEST_ASSERT(vm->instruction_index == 4, "vm.instruction_index == 004");
    TEST_ASSERT(vm->stack_index == 2, "vm.stack_index == 002");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm)); // 3
    TEST_ASSERT(vm->instruction_index == 6, "vm.instruction_index == 006");
    TEST_ASSERT(vm->stack_index == 3, "vm.stack_index == 003");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->instruction_index == 8, "vm.instruction_index == 008");
    TEST_ASSERT(vm->stack_index == 2, "vm.stack_index == 003");
    TEST_ASSERT(vm->registers[A] == 0, "vm.registers[A] == 000");
    TEST_ASSERT(vm->registers[B] == 0, "vm.registers[B] == 000");
    TEST_ASSERT(vm->registers[C] == 3, "vm.registers[C] == 003");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->instruction_index == 10, "vm.instruction_index == 010");
    TEST_ASSERT(vm->stack_index == 1, "vm.stack_index == 001");
    TEST_ASSERT(vm->registers[A] == 0, "vm.registers[A] == 000");
    TEST_ASSERT(vm->registers[B] == 2, "vm.registers[B] == 002");
    TEST_ASSERT(vm->registers[C] == 3, "vm.registers[C] == 003");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->instruction_index == 12, "vm.instruction_index == 012");
    TEST_ASSERT(vm->stack_index == 0, "vm.stack_index == 000");
    TEST_ASSERT(vm->registers[A] == 1, "vm.registers[A] == 001");
    TEST_ASSERT(vm->registers[B] == 2, "vm.registers[B] == 002");
    TEST_ASSERT(vm->registers[C] == 3, "vm.registers[C] == 003");

    TEST_END();

    vm_free(vm);

    return test_results;
}