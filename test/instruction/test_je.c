//
// Created by sirh3e on 10/10/2020.
//

#include "../test.h"

test_vm_instruction_result test_vm_instruction_je(){

    test_vm_instruction_result test_results = 0;
    i32 program[] = {
            INSTRUCTION_LABEL,

            INSTRUCTION_PUSH, 1,
            INSTRUCTION_PUSH, 2,
            INSTRUCTION_POP, C,
            INSTRUCTION_POP, D,
            //will not pass C = 2, D = 1
            INSTRUCTION_JE, 0,
            INSTRUCTION_NOP,

            INSTRUCTION_PUSH, 1,
            INSTRUCTION_POP, C,
            //will pass C = 1, D = 1
            INSTRUCTION_JE, 0,
            INSTRUCTION_NOP
    };

    VM_INIT(program);
    TEST_BEGIN();

    for (int i = 0; i < 2; ++i) {
        TEST_ASSERT(vm->instruction_index == 0, "vm->instruction_index == 0");
        TEST_ASSERT(vm->instructions[vm->instruction_index] == INSTRUCTION_LABEL, "vm->instructions[vm->instruction_index] == INSTRUCTION_LABEL");
        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //label

        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //push 1
        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //push 2
        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //pop C
        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //pop D

        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //je C = 2, D = 1 true

        TEST_ASSERT(vm->instruction_index == 11, "vm->instruction_index == 11");
        TEST_ASSERT(vm->instructions[vm->instruction_index] == INSTRUCTION_NOP, "vm->instructions[vm->instruction_index] == INSTRUCTION_NOP");

        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //nop
        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //push 1
        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //pop C

        TEST_INSTRUCTION_EXECUTE_NEXT(vm); //je C = 1, D = 1 true
    }

    TEST_END(vm);

    return test_results;
}