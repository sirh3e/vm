//
// Created by sirh3e on 9/20/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_add_0();
int test_instruction_add_1();

int test_instruction_add(){

    i32 test_results = 0;

    test_results |= test_instruction_add_0();
    test_results |= test_instruction_add_1();

    return test_results;
}

int test_instruction_add_0(){

    i32 test_results = 0;
    i32 program[] = {
            INSTRUCTION_ADD, 64, 2,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));
    vm_program_run(vm);

    TEST_BEGIN();

    TEST_ASSERT(vm->registers[A] == 64, "vm.registers[A] == 064");
    TEST_ASSERT(vm->registers[B] == 02, "vm.registers[B] == 002");
    TEST_ASSERT(vm->registers[C] == 66, "vm.registers[C] == 066");

    TEST_END();

    vm_free(vm);

    return test_results;
}

int test_instruction_add_1(){

    i32 test_results = 0;
    i32 program[] = {
            INSTRUCTION_ADD, 64, -36,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));
    vm_program_run(vm);

    TEST_BEGIN();

    TEST_ASSERT(vm->registers[A] == 64, "vm.registers[A] == 064");
    TEST_ASSERT(vm->registers[B] == -36, "vm.registers[B] == -36");
    TEST_ASSERT(vm->registers[C] == 28, "vm.registers[C] == 028");

    TEST_END();
    vm_free(vm);

    return test_results;
}