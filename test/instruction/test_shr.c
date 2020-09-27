//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_shr_0();

int test_instruction_shr(){

    i32 test_results = 0;

    test_results |= test_instruction_shr_0();

    return test_results;
}

int test_instruction_shr_0(){

    i32 test_results = 0, instruction = INSTRUCTION_HALT;
    i32 program[] = {
            INSTRUCTION_PUSH, 100,
            INSTRUCTION_LOAD, A,
            INSTRUCTION_SHR, A, 1,

            INSTRUCTION_PUSH, 44,
            INSTRUCTION_LOAD, A,
            INSTRUCTION_SHR, A, 2,

            INSTRUCTION_PUSH, 2,
            INSTRUCTION_LOAD, B,
            INSTRUCTION_SHR, B, 1,

            INSTRUCTION_PUSH, 36987,
            INSTRUCTION_LOAD, B,
            INSTRUCTION_SHR, B, 8,

            INSTRUCTION_PUSH, 4,
            INSTRUCTION_LOAD, C,
            INSTRUCTION_SHR, C, 1,
    };

    Vm *vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));

    TEST_BEGIN();

    TEST_ASSERT(vm->instruction_index == 0, "vm.instruction_index == 000");
    TEST_ASSERT(vm->stack_index == 0, "vm.stack_index == 000");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->instruction_index == 7, "vm.instruction_index == 007");
    TEST_ASSERT(vm->registers[A] == 50, "vm->registers[A] == 050");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->instruction_index == 14, "vm.instruction_index == 014");
    TEST_ASSERT(vm->registers[A] == 11, "vm->registers[B] == 011");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->instruction_index == 21, "vm.instruction_index == 021");
    TEST_ASSERT(vm->registers[B] == 1, "vm->registers[A] == 001");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->instruction_index == 28, "vm.instruction_index == 028");
    TEST_ASSERT(vm->registers[B] == 144, "vm->registers[A] == 144");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->instruction_index == 35, "vm.instruction_index == 035");
    TEST_ASSERT(vm->registers[C] == 2, "vm->registers[A] == 002");

    TEST_END();

    return test_results;
}