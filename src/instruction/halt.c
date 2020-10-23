//
// Created by sirh3e on 9/20/2020.
//

#include "../assert.h"
#include "../instructions.h"
#include "../statuscode.h"
#include "../util.h"
#include "../vm.h"

vm_instruction_result vm_instruction_halt(Vm *vm) {

    VM_ASSERT(vm);

    VM_INSTRUCTION_SET_BY_INDEX(vm, --vm->instruction_index, INSTRUCTION_HALT);

    return STATUS_CODE_SUCCESSFUL;
}