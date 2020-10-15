//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

test_vm_instruction_result test_vm_instruction_or() {

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

    TEST_ASSERT(vm->registers[A] == 0);
    TEST_ASSERT(vm->registers[B] == 0);
    TEST_ASSERT(vm->registers[C] == 0);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255);
    TEST_ASSERT(vm->registers[B] == 2);
    TEST_ASSERT(vm->registers[C] == 255);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255);
    TEST_ASSERT(vm->registers[B] == 4);
    TEST_ASSERT(vm->registers[C] == 255);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255);
    TEST_ASSERT(vm->registers[B] == 8);
    TEST_ASSERT(vm->registers[C] == 255);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255);
    TEST_ASSERT(vm->registers[B] == 16);
    TEST_ASSERT(vm->registers[C] == 255);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255);
    TEST_ASSERT(vm->registers[B] == 32);
    TEST_ASSERT(vm->registers[C] == 255);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255);
    TEST_ASSERT(vm->registers[B] == 64);
    TEST_ASSERT(vm->registers[C] == 255);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255);
    TEST_ASSERT(vm->registers[B] == 128);
    TEST_ASSERT(vm->registers[C] == 255);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 255);
    TEST_ASSERT(vm->registers[B] == 256);
    TEST_ASSERT(vm->registers[C] == 511);

    TEST_END(vm);

    return test_results;
}