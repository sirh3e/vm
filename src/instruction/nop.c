//
// Created by sirh3e on 10/5/2020.
//

#include "../assert.h"
#include "../statuscode.h"
#include "../vm.h"

vm_instruction_result vm_instruction_nop(Vm *vm) {

    VM_ASSERT(vm);
    VM_ASSERT_INSTRUCTION_INDEX(vm, 1);

    return STATUS_CODE_SUCCESSFUL;
}