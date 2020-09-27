//
// Created by sirh3e on 9/21/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_and_0();
int test_instruction_and_1();

int test_instruction_and(){

    i32 test_results = 0;

    test_results |= test_instruction_and_0();
    test_results |= test_instruction_and_1();

    return test_results;
}

int test_instruction_and_0(){

    i32 test_results = 0;
    i32 program[] = {
            INSTRUCTION_AND, 2, 2,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));
    vm_program_run(vm);

    TEST_BEGIN();

    TEST_ASSERT(vm->registers[A] == 2, "vm.registers[A] == 2");
    TEST_ASSERT(vm->registers[B] == 2, "vm.registers[B] == 2");
    TEST_ASSERT(vm->registers[C] == 2, "vm.registers[C] == 2");

    TEST_END();

    vm_free(vm);

    return 0;
}

int test_instruction_and_1(){

    i32 test_results = 0;
    i32 program[] = {
            INSTRUCTION_AND, 255, 2,
            INSTRUCTION_AND, 255, 4,
            INSTRUCTION_AND, 255, 8,
            INSTRUCTION_AND, 255, 16,
            INSTRUCTION_AND, 255, 32,
            INSTRUCTION_AND, 255, 64,
            INSTRUCTION_AND, 255, 128,
            INSTRUCTION_AND, 255, 256,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));

    TEST_BEGIN();

    TEST_ASSERT(vm->registers[A] == 0, "vm.registers[A] == 000");
    TEST_ASSERT(vm->registers[B] == 0, "vm.registers[B] == 000");
    TEST_ASSERT(vm->registers[C] == 0, "vm.registers[C] == 000");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 2, "vm.registers[B] == 002");
    TEST_ASSERT(vm->registers[C] == 2, "vm.registers[C] == 002");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 4, "vm.registers[B] == 004");
    TEST_ASSERT(vm->registers[C] == 4, "vm.registers[C] == 004");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 8, "vm.registers[B] == 008");
    TEST_ASSERT(vm->registers[C] == 8, "vm.registers[C] == 008");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 16, "vm.registers[B] == 016");
    TEST_ASSERT(vm->registers[C] == 16, "vm.registers[C] == 016");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 32, "vm.registers[B] == 032");
    TEST_ASSERT(vm->registers[C] == 32, "vm.registers[C] == 032");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 64, "vm.registers[B] == 064");
    TEST_ASSERT(vm->registers[C] == 64, "vm.registers[C] == 064");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 128, "vm.registers[B] == 128");
    TEST_ASSERT(vm->registers[C] == 128, "vm.registers[C] == 128");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 256, "vm.registers[B] == 256");
    TEST_ASSERT(vm->registers[C] == 0, "vm.registers[C] == 0");

    TEST_END();
    vm_free(vm);

    return test_results;
}