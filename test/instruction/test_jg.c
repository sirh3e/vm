//
// Created by sirh3e on 10/10/2020.
//

#include "../test.h"

test_vm_instruction_result test_vm_instruction_jg() {

    test_vm_instruction_result test_results = 0;
    i32 program[] = {
            INSTRUCTION_LABEL,

            INSTRUCTION_PUSH, 2,
            INSTRUCTION_PUSH, 2,
            INSTRUCTION_POP, C,
            INSTRUCTION_POP, D,
            //will not pass C = 2, D = 2
            INSTRUCTION_JG, 0,
            INSTRUCTION_NOP,

            INSTRUCTION_PUSH, 5,
            INSTRUCTION_POP, C,
            //will pass C = 5, D = 1
            INSTRUCTION_JG, 0,
            INSTRUCTION_NOP
    };

    VM_INIT(program);
    TEST_BEGIN();

    for (int i = 0; i < 5; ++i) {
        TEST_ASSERT(vm->instruction_index == 0);
        TEST_ASSERT(vm->instructions[vm->instruction_index] == INSTRUCTION_LABEL);
        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //label

        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //push 2
        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //push 2
        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //pop C
        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //pop D

        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //je C = 2, D = 2 false

        TEST_ASSERT(vm->instruction_index == 11);
        TEST_ASSERT(vm->instructions[vm->instruction_index] == INSTRUCTION_NOP);

        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //nop
        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //push 5
        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //pop C

        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //je C = 5, D = 1 true
    }

    TEST_END(vm);

    return test_results;
}