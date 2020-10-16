//
// Created by sirh3e on 10/5/2020.
//

#include "../assert.h"
#include "../instructions.h"
#include "../util.h"
#include "../vm.h"

vm_instruction_result vm_instruction_jmp(Vm *vm) {

    VM_ASSERT(vm);
    VM_ASSERT_INSTRUCTION_INDEX(vm, 1);
    VM_ASSERT_INSTRUCTION(VM_INSTRUCTION_GET(vm));
    ASSERT(VM_INSTRUCTION_GET_BY_INDEX(vm, VM_INSTRUCTION_GET(vm)) == INSTRUCTION_LABEL);

    vm->instruction_index = VM_INSTRUCTION_GET(vm);

    return 0;
}