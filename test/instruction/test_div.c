//
// Created by sirh3e on 9/26/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"


int test_instruction_div_0();

int test_instruction_div(){

    i32 test_results = 0;

    test_results |= test_instruction_div_0();

    return test_results;
}

int test_instruction_div_0(){

    i32 test_results = 0, instruction = INSTRUCTION_HALT;
    i32 program[] = {
            INSTRUCTION_DIV, 2, 1,
            INSTRUCTION_DIV, 2, 2,
            INSTRUCTION_DIV, 4, 2,

            INSTRUCTION_DIV, 58364, 2,
            INSTRUCTION_DIV, 15, 3,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));

    TEST_BEGIN();

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 2, "vm->registers[A] == 2");
    TEST_ASSERT(vm->registers[B] == 1, "vm->registers[B] == 1");
    TEST_ASSERT(vm->registers[C] == 2, "vm->registers[C] == 2");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 2, "vm->registers[A] == 2");
    TEST_ASSERT(vm->registers[B] == 2, "vm->registers[B] == 1");
    TEST_ASSERT(vm->registers[C] == 1, "vm->registers[C] == 2");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 4, "vm->registers[A] == 4");
    TEST_ASSERT(vm->registers[B] == 2, "vm->registers[B] == 2");
    TEST_ASSERT(vm->registers[C] == 2, "vm->registers[C] == 2");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 58364, "vm->registers[A] == 58364");
    TEST_ASSERT(vm->registers[B] == 2, "vm->registers[B] == 00002");
    TEST_ASSERT(vm->registers[C] == 29182, "vm->registers[C] == 29182");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    TEST_ASSERT(vm->registers[A] == 15, "vm->registers[A] == 15");
    TEST_ASSERT(vm->registers[B] == 3, "vm->registers[B] == 03");
    TEST_ASSERT(vm->registers[C] == 5, "vm->registers[C] == 05");

    TEST_END();
    vm_free(vm);

    return test_results;
}