//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

test_vm_result test_vm_instruction_pop() {

    test_vm_result TEST_RESULTS_INIT(test_results);
    i32 program[] = {
            INSTRUCTION_PUSH, 1,
            INSTRUCTION_PUSH, 2,
            INSTRUCTION_PUSH, 3,

            INSTRUCTION_POP, C,
            INSTRUCTION_POP, B,
            INSTRUCTION_POP, A,
    };

    VM_INIT(program);
    TEST_BEGIN();

    TEST_ASSERT(vm->instruction_index == 0);
    TEST_ASSERT(vm->stack_index == 0);
    TEST_ASSERT(vm->registers[A] == 0);
    TEST_ASSERT(vm->registers[B] == 0);
    TEST_ASSERT(vm->registers[C] == 0);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm); // 1
    TEST_ASSERT(vm->instruction_index == 2);
    TEST_ASSERT(vm->stack_index == 1);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm); // 2
    TEST_ASSERT(vm->instruction_index == 4);
    TEST_ASSERT(vm->stack_index == 2);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm); // 3
    TEST_ASSERT(vm->instruction_index == 6);
    TEST_ASSERT(vm->stack_index == 3);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 8);
    TEST_ASSERT(vm->stack_index == 2);
    TEST_ASSERT(vm->registers[A] == 0);
    TEST_ASSERT(vm->registers[B] == 0);
    TEST_ASSERT(vm->registers[C] == 3);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 10);
    TEST_ASSERT(vm->stack_index == 1);
    TEST_ASSERT(vm->registers[A] == 0);
    TEST_ASSERT(vm->registers[B] == 2);
    TEST_ASSERT(vm->registers[C] == 3);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 12);
    TEST_ASSERT(vm->stack_index == 0);
    TEST_ASSERT(vm->registers[A] == 1);
    TEST_ASSERT(vm->registers[B] == 2);
    TEST_ASSERT(vm->registers[C] == 3);

    TEST_END(vm, test_results);

    return test_results;
}