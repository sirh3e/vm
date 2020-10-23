//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

test_vm_result test_vm_instruction_mul() {

    test_vm_result TEST_RESULTS_INIT(test_results);
    i32 program[] = {
            INSTRUCTION_MUL, -2, 2,
            INSTRUCTION_MUL, 2, -2,
            INSTRUCTION_MUL, -2, -2,
            INSTRUCTION_MUL, 2, 2,

            INSTRUCTION_MUL, 0, 2,
            INSTRUCTION_MUL, 2, 0,
            INSTRUCTION_MUL, 0, 0,

            INSTRUCTION_MUL, 1, 1,
            INSTRUCTION_MUL, 1000, 1000,
    };

    VM_INIT(program);
    TEST_BEGIN();

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == -2);
    TEST_ASSERT(vm->registers[B] == 2);
    TEST_ASSERT(vm->registers[C] == -4);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 2);
    TEST_ASSERT(vm->registers[B] == -2);
    TEST_ASSERT(vm->registers[C] == -4);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == -2);
    TEST_ASSERT(vm->registers[B] == -2);
    TEST_ASSERT(vm->registers[C] == 4);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 2);
    TEST_ASSERT(vm->registers[B] == 2);
    TEST_ASSERT(vm->registers[C] == 4);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 0);
    TEST_ASSERT(vm->registers[B] == 2);
    TEST_ASSERT(vm->registers[C] == 0);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 2);
    TEST_ASSERT(vm->registers[B] == 0);
    TEST_ASSERT(vm->registers[C] == 0);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 0);
    TEST_ASSERT(vm->registers[B] == 0);
    TEST_ASSERT(vm->registers[C] == 0);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 1);
    TEST_ASSERT(vm->registers[B] == 1);
    TEST_ASSERT(vm->registers[C] == 1);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 1000);
    TEST_ASSERT(vm->registers[B] == 1000);
    TEST_ASSERT(vm->registers[C] == 1000000);

    TEST_END(vm, test_results);

    return test_results;
}