//
// Created by sirh3e on 9/20/2020.
//

#include "../test.h"
#include "../test_instructions.h"
#include "../types.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"

test_vm_instruction_result test_vm_instruction_add() {

    test_vm_instruction_result test_results = 0;
    i32 program[] = {
            INSTRUCTION_ADD, 64, 2,
            INSTRUCTION_ADD, 64, -36,
    };

    Vm *vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));

    TEST_BEGIN();

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 64, "vm.registers[A] == 064");
    TEST_ASSERT(vm->registers[B] == 02, "vm.registers[B] == 002");
    TEST_ASSERT(vm->registers[C] == 66, "vm.registers[C] == 066");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 64, "vm.registers[A] == 064");
    TEST_ASSERT(vm->registers[B] == -36, "vm.registers[B] == -36");
    TEST_ASSERT(vm->registers[C] == 28, "vm.registers[C] == 028");

    TEST_END(vm);

    return test_results;
}