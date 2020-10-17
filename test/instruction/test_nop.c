//
// Created by sirh3e on 10/17/2020.
//

#include "../test.h"

test_vm_instruction_result test_vm_instruction_nop() {

    i32 test_results = 0;
    i32 program[] = {
           INSTRUCTION_NOP,
           INSTRUCTION_NOP,
           INSTRUCTION_NOP,
    };

    VM_INIT(program);
    TEST_BEGIN();

    TEST_ASSERT(vm->instruction_index == 0);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm); //nop
    TEST_ASSERT(vm->instruction_index == 1);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm); //nop
    TEST_ASSERT(vm->instruction_index == 2);

    TEST_INSTRUCTION_EXECUTE_NEXT(vm); //nop
    TEST_ASSERT(vm->instruction_index == 3);

    TEST_END(vm);

    return test_results;
}