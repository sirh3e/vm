//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

test_vm_instruction_result test_vm_instruction_shl() {

    i32 test_results = 0, instruction = INSTRUCTION_HALT;
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

    TEST_ASSERT(vm->instruction_index == 0, "vm.instruction_index == 000");
    TEST_ASSERT(vm->stack_index == 0, "vm.stack_index == 000");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 7, "vm.instruction_index == 007");
    TEST_ASSERT(vm->registers[A] == 2, "vm->registers[A] == 4");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 14, "vm.instruction_index == 014");
    TEST_ASSERT(vm->registers[A] == 176, "vm->registers[B] == 176");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 21, "vm.instruction_index == 021");
    TEST_ASSERT(vm->registers[B] == 4, "vm->registers[A] == 004");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 28, "vm.instruction_index == 000000028");
    TEST_ASSERT(vm->registers[B] == 605995008, "vm->registers[A] == 605995008");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 35, "vm.instruction_index == 035");
    TEST_ASSERT(vm->registers[C] == 16, "vm->registers[A] == 016");

    TEST_END(vm);

    return test_results;
}