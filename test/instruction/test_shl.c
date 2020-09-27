//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_shl_0();

int test_instruction_shl(){

    i32 test_results = 0;

    test_results |= test_instruction_shl_0();

    return test_results;
}

int test_instruction_shl_0() {

    i32 test_results = 0, instruction = INSTRUCTION_HALT;
    i32 program[] = {
            INSTRUCTION_PUSH, 1,
            INSTRUCTION_LOAD, A,
            INSTRUCTION_SHL, A, 1,

            INSTRUCTION_PUSH, 44,
            INSTRUCTION_LOAD, A,
            INSTRUCTION_SHL, A, 2,

            INSTRUCTION_PUSH, 1,
            INSTRUCTION_LOAD, B,
            INSTRUCTION_SHL, B, 2,

            INSTRUCTION_PUSH, 36987,
            INSTRUCTION_LOAD, B,
            INSTRUCTION_SHL, B, 16,

            INSTRUCTION_PUSH, 1,
            INSTRUCTION_LOAD, C,
            INSTRUCTION_SHL, C, 4,
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
    TEST_ASSERT(vm->registers[A] == 2, "vm->registers[A] == 4");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->instruction_index == 14, "vm.instruction_index == 014");
    TEST_ASSERT(vm->registers[B] == 4, "vm->registers[B] == 004");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->instruction_index == 21, "vm.instruction_index == 021");
    TEST_ASSERT(vm->registers[C] == 16, "vm->registers[A] == 016");

    TEST_END();

    return test_results;
}