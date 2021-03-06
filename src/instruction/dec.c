//
// Created by sirh3e on 9/20/2020.
//

#include "../assert.h"
#include "../vm.h"
#include "../statuscode.h"

vm_instruction_result vm_instruction_dec(Vm *vm) {

    VM_ASSERT(vm);
    VM_ASSERT_INSTRUCTION_INDEX(vm, 2);
    VM_ASSERT_REGISTER(vm->instructions[vm->instruction_index]);

    vm->registers[vm->instructions[vm->instruction_index]] -= vm->instructions[vm->instruction_index + 1];
    vm->instruction_index += 2;

    return STATUS_CODE_SUCCESSFUL;
}