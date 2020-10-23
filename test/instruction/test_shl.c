//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

test_vm_result test_vm_instruction_shl() {

    test_vm_result TEST_RESULTS_INIT(test_results);
    i32 program[] = {
            INSTRUCTION_PUSH, 1,
            INSTRUCTION_LOAD, A,
            INSTRUCTION_SHL, A, 1,

            INSTRUCTION_PUSH, 44,
            INSTRUCTION_LOAD, A,
            INSTRUCTION_SHL, A, 2,

            INSTRUCTION_PUSH, 1,
            INSTRUCTION_LOAD, B,
            INSTRUCTION_SHL, B, 2,

            INSTRUCTION_PUSH, 36987,
            INSTRUCTION_LOAD, B,
            INSTRUCTION_SHL, B, 14,

            INSTRUCTION_PUSH, 1,
            INSTRUCTION_LOAD, C,
            INSTRUCTION_SHL, C, 4,
    };

    VM_INIT(program);
    TEST_BEGIN();

    TEST_ASSERT(vm->instruction_index == 0);
    TEST_ASSERT(vm->stack_index == 0);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 7);
    TEST_ASSERT(vm->registers[A] == 2);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 14);
    TEST_ASSERT(vm->registers[A] == 176);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 21);
    TEST_ASSERT(vm->registers[B] == 4);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 28);
    TEST_ASSERT(vm->registers[B] == 605995008);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 35);
    TEST_ASSERT(vm->registers[C] == 16);

    TEST_END(vm, test_results);

    return test_results;
}