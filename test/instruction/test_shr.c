//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

test_vm_instruction_result test_vm_instruction_shr() {

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

    TEST_ASSERT(vm->instruction_index == 0);
    TEST_ASSERT(vm->stack_index == 0);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 7);
    TEST_ASSERT(vm->registers[A] == 50);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 14);
    TEST_ASSERT(vm->registers[A] == 11);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 21);
    TEST_ASSERT(vm->registers[B] == 1);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 28);
    TEST_ASSERT(vm->registers[B] == 144);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 35);
    TEST_ASSERT(vm->registers[C] == 2);

    TEST_END(vm);

    return test_results;
}