//
// Created by sirh3e on 9/27/2020.
//

#include "../test_instructions.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"

test_result_t test_instruction_neg() {

    i32 test_results = 0, instruction = INSTRUCTION_HALT;
    i32 program[] = {
            INSTRUCTION_INC, A, 255,
            INSTRUCTION_NEG, A,
            INSTRUCTION_NEG, A,

            INSTRUCTION_INC, B, -48,
            INSTRUCTION_NEG, B,
            INSTRUCTION_NEG, B,

            INSTRUCTION_INC, C, 128,
            INSTRUCTION_NEG, C,
            INSTRUCTION_NEG, C,
    };

    VM_INIT(program);
    TEST_BEGIN();

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 0255");
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == -255, "vm.registers[A] == -255");
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255, "vm.registers[A] == 0255");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[B] == -48, "vm.registers[A] == -048");
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[B] == 48, "vm.registers[A] == 0048");
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[B] == -48, "vm.registers[A] == -048");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[C] == 128, "vm.registers[A] == 0128");
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[C] == -128, "vm.registers[A] == -128");
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[C] == 128, "vm.registers[A] == 0128");

    TEST_END(vm);

    return test_results;
}