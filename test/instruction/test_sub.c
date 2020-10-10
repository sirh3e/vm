//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

test_vm_instruction_result test_vm_instruction_sub() {

    i32 test_results = 0;
    i32 program[] = {
            INSTRUCTION_SUB, 64, 2,
            INSTRUCTION_SUB, 64, -36,
            INSTRUCTION_SUB, 167474, 252503,
            INSTRUCTION_SUB, 311546, -350241,
            INSTRUCTION_SUB, 150201, 826156,
    };

    VM_INIT(program);
    TEST_BEGIN();

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 3, "vm.instruction_index == 003");
    TEST_ASSERT(vm->registers[A] == 64, "vm.registers[A] == 064");
    TEST_ASSERT(vm->registers[B] == 02, "vm.registers[B] == 002");
    TEST_ASSERT(vm->registers[C] == 62, "vm.registers[C] == 062");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 6, "vm.instruction_index == 006");
    TEST_ASSERT(vm->registers[A] == 64, "vm.registers[A] == 064");
    TEST_ASSERT(vm->registers[B] == -36, "vm.registers[B] == -36");
    TEST_ASSERT(vm->registers[C] == 100, "vm.registers[C] == 100");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 9, "vm.instruction_index == 009");
    TEST_ASSERT(vm->registers[A] == 167474, "vm.registers[A] == 167474");
    TEST_ASSERT(vm->registers[B] == 252503, "vm.registers[B] == 252503");
    TEST_ASSERT(vm->registers[C] == -85029, "vm.registers[C] == -85029");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 12, "vm.instruction_index == 012");
    TEST_ASSERT(vm->registers[A] == 311546, "vm.registers[A] == 311546");
    TEST_ASSERT(vm->registers[B] == -350241, "vm.registers[B] == -350241");
    TEST_ASSERT(vm->registers[C] == 661787, "vm.registers[C] == 661787");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_ASSERT(vm->instruction_index == 15, "vm.instruction_index == 015");
    TEST_ASSERT(vm->registers[A] == 150201, "vm.registers[A] == 150201");
    TEST_ASSERT(vm->registers[B] == 826156, "vm.registers[B] == 826156");
    TEST_ASSERT(vm->registers[C] == -675955, "vm.registers[C] == -675955");

    TEST_END(vm);

    return test_results;
}