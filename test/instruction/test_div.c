//
// Created by sirh3e on 9/26/2020.
//

#include "../test.h"

test_vm_instruction_result test_vm_instruction_div() {

    i32 test_results = 0;
    i32 program[] = {
            INSTRUCTION_DIV, 2, 1,
            INSTRUCTION_DIV, 2, 2,
            INSTRUCTION_DIV, 4, 2,

            INSTRUCTION_DIV, 58364, 2,
            INSTRUCTION_DIV, 15, 3,
    };

    VM_INIT(program);
    TEST_BEGIN();

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 2);
    TEST_ASSERT(vm->registers[B] == 1);
    TEST_ASSERT(vm->registers[C] == 2);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 2);
    TEST_ASSERT(vm->registers[B] == 2);
    TEST_ASSERT(vm->registers[C] == 1);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 4);
    TEST_ASSERT(vm->registers[B] == 2);
    TEST_ASSERT(vm->registers[C] == 2);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 58364);
    TEST_ASSERT(vm->registers[B] == 2);
    TEST_ASSERT(vm->registers[C] == 29182);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 15);
    TEST_ASSERT(vm->registers[B] == 3);
    TEST_ASSERT(vm->registers[C] == 5);

    TEST_END(vm);

    return test_results;
}