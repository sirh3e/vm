//
// Created by sirh3e on 9/21/2020.
//

#include "../test.h"

test_vm_instruction_result test_vm_instruction_dec() {

    i32 test_results = 0, instruction = INSTRUCTION_HALT;
    i32 program[] = {
            INSTRUCTION_DEC, A, 2,
            INSTRUCTION_DEC, A, 2,
            INSTRUCTION_DEC, B, 128,
            INSTRUCTION_DEC, C, 0,
    };

    VM_INIT(program);
    TEST_BEGIN();

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == -2);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == -4);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[B] == -128);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[C] == 0);

    TEST_END(vm);

    return test_results;
}