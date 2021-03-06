//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

test_vm_instruction_result test_vm_instruction_push() {

    i32 test_results = 0;
    i32 program[] = {
            INSTRUCTION_PUSH, 1,
            INSTRUCTION_PUSH, 2,
            INSTRUCTION_PUSH, 3,
    };

    VM_INIT(program);
    TEST_BEGIN();

    TEST_ASSERT(vm->instruction_index == 0);
    TEST_ASSERT(vm->stack_index == 0);

    //ToDo create test for loop

    TEST_INSTRUCTION_EXECUTE_NEXT(vm); // 1
    TEST_ASSERT(vm->instruction_index == 2);
    TEST_ASSERT(vm->stack_index == 1);
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 1);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm); // 2
    TEST_ASSERT(vm->instruction_index == 4);
    TEST_ASSERT(vm->stack_index == 2);
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 2);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm); // 3
    TEST_ASSERT(vm->instruction_index == 6);
    TEST_ASSERT(vm->stack_index == 3);
    TEST_ASSERT(vm->stack[vm->stack_index - 1] == 3);

    TEST_END(vm);

    return test_results;
}