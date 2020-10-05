//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"

test_result_t test_instruction_or() {

    i32 test_results = 0, instruction = INSTRUCTION_HALT;
    i32 program[] = {
            INSTRUCTION_OR, 255, 2,
            INSTRUCTION_OR, 255, 4,
            INSTRUCTION_OR, 255, 8,
            INSTRUCTION_OR, 255, 16,
            INSTRUCTION_OR, 255, 32,
            INSTRUCTION_OR, 255, 64,
            INSTRUCTION_OR, 255, 128,
            INSTRUCTION_OR, 255, 256,
    };

    VM_INIT(program);
    TEST_BEGIN();

    TEST_ASSERT(vm->registers[A] == 0, "vm.registers[A] == 000");
    TEST_ASSERT(vm->registers[B] == 0, "vm.registers[B] == 000");
    TEST_ASSERT(vm->registers[C] == 0, "vm.registers[C] == 000");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 2, "vm.registers[B] == 002");
    TEST_ASSERT(vm->registers[C] == 255, "vm.registers[C] == 255");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 4, "vm.registers[B] == 004");
    TEST_ASSERT(vm->registers[C] == 255, "vm.registers[C] == 255");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 8, "vm.registers[B] == 008");
    TEST_ASSERT(vm->registers[C] == 255, "vm.registers[C] == 255");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 16, "vm.registers[B] == 016");
    TEST_ASSERT(vm->registers[C] == 255, "vm.registers[C] == 016");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 32, "vm.registers[B] == 032");
    TEST_ASSERT(vm->registers[C] == 255, "vm.registers[C] == 255");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 64, "vm.registers[B] == 064");
    TEST_ASSERT(vm->registers[C] == 255, "vm.registers[C] == 255");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 128, "vm.registers[B] == 128");
    TEST_ASSERT(vm->registers[C] == 255, "vm.registers[C] == 128");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 255");
    TEST_ASSERT(vm->registers[B] == 256, "vm.registers[B] == 256");
    TEST_ASSERT(vm->registers[C] == 511, "vm.registers[C] == 511");

    TEST_END(vm);

    return test_results;
}