//
// Created by sirh3e on 9/27/2020.
//

#include "../test_instructions.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"

test_result_t test_instruction_shr() {

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

    VM_INIT(program);
    TEST_BEGIN();

    TEST_ASSERT(vm->instruction_index == 0, "vm.instruction_index == 000");
    TEST_ASSERT(vm->stack_index == 0, "vm.stack_index == 000");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 7, "vm.instruction_index == 007");
    TEST_ASSERT(vm->registers[A] == 50, "vm->registers[A] == 050");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 14, "vm.instruction_index == 014");
    TEST_ASSERT(vm->registers[A] == 11, "vm->registers[B] == 011");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 21, "vm.instruction_index == 021");
    TEST_ASSERT(vm->registers[B] == 1, "vm->registers[A] == 001");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 28, "vm.instruction_index == 028");
    TEST_ASSERT(vm->registers[B] == 144, "vm->registers[A] == 144");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 35, "vm.instruction_index == 035");
    TEST_ASSERT(vm->registers[C] == 2, "vm->registers[A] == 002");

    TEST_END(vm);

    return test_results;
}