//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_load_0();

int test_instruction_load(){

    i32 test_results = 0;

    test_results |= test_instruction_load_0();

    return test_results;
}

int test_instruction_load_0() {

    i32 test_results = 0;
    i32 program[] = {
            INSTRUCTION_PUSH, 16,
            INSTRUCTION_LOAD, A,

            INSTRUCTION_PUSH, 64,
            INSTRUCTION_LOAD, A,

            INSTRUCTION_PUSH, 128,
            INSTRUCTION_LOAD, B,

            INSTRUCTION_PUSH, 256,
            INSTRUCTION_LOAD, B,

            INSTRUCTION_PUSH, 512,
            INSTRUCTION_LOAD, C,

            INSTRUCTION_PUSH, 1024,
            INSTRUCTION_LOAD, C,
    };

    Vm *vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));

    TEST_BEGIN();

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 16, "vm->stack[vm->stack_index - 1] == 16");
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 16, "vm.registers[A] == 0016");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 64, "vm->stack[vm->stack_index - 1] == 64");
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 64, "vm.registers[A] == 0064");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 128, "vm->stack[vm->stack_index - 1] == 0128");
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[B] == 128, "vm.registers[B] == 0128");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 256, "vm->stack[vm->stack_index - 1] == 0256");
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[B] == 256, "vm.registers[B] == 0256");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 512, "vm->stack[vm->stack_index - 1] == 0512");
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[C] == 512, "vm.registers[C] == 0512");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 1024, "vm->stack[vm->stack_index - 1] == 1024");
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[C] == 1024, "vm.registers[C] == 1024");

    TEST_END();
    vm_free(vm);

    return test_results;
}