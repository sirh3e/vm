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
            INSTRUCTION_AND, 64, 2,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));
    vm_program_run(vm);

    TEST_BEGIN();

    TEST_ASSERT(vm->registers[A] == 64, "vm.registers[A] == 64");
    TEST_ASSERT(vm->registers[B] == 02, "vm.registers[B] == 02");
    TEST_ASSERT(vm->registers[C] == 00, "vm.registers[C] == 00");

    TEST_END();

    vm_free(vm);

    return 0;
}