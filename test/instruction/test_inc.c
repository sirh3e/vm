//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

test_vm_instruction_result test_vm_instruction_inc() {

    i32 test_results = 0;
    i32 program[] = {
            INSTRUCTION_INC, A, 2,
            INSTRUCTION_INC, A, 2,
            INSTRUCTION_INC, B, 128,
            INSTRUCTION_INC, B, 128,
            INSTRUCTION_INC, C, 0,
            INSTRUCTION_INC, C, 369,
            INSTRUCTION_INC, C, 369,
    };

    VM_INIT(program);
    TEST_BEGIN();

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 2);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 4);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[B] == 128);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[B] == 256);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[C] == 0);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[C] == 369);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[C] == 738);

    TEST_END(vm);

    return test_results;
}