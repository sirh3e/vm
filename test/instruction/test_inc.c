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

    printf("[debug] register-c: '%d' vm->registers[C]: '%d'\n", C, vm->registers[C]);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 2);

    printf("[debug] register-c: '%d' vm->registers[C]: '%d'\n", C, vm->registers[C]);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[A] == 4);

    printf("[debug] register-c: '%d' vm->registers[C]: '%d'\n", C, vm->registers[C]);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[B] == 128);

    printf("[debug] register-c: '%d' vm->registers[C]: '%d'\n", C, vm->registers[C]);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[B] == 256);

    printf("[debug] register-c: '%d' vm->registers[C]: '%d'\n", C, vm->registers[C]);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[C] == 0);

    printf("[debug] register-c: '%d' vm->registers[C]: '%d'\n", C, vm->registers[C]);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[C] == 369);

    printf("[debug] register-c: '%d' vm->registers[C]: '%d'\n", C, vm->registers[C]);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->registers[C] == 738);

    printf("[debug] register-c: '%d' vm->registers[C]: '%d'\n", C, vm->registers[C]);

    TEST_END(vm);

    return test_results;
}