//
// Created by sirh3e on 9/20/2020.
//

#include "../assert.h"
#include "../registers.h"
#include "../util.h"
#include "../vm.h"

vm_instruction_result vm_instruction_add(Vm *vm) {

    VM_ASSERT(vm);
    VM_ASSERT_INSTRUCTION_INDEX(vm, 2);

    vm->registers[A] = VM_INSTRUCTION_GET(vm);
    vm->instruction_index++;

    vm->registers[B] = VM_INSTRUCTION_GET(vm);
    vm->instruction_index++;

    vm->registers[C] = vm->registers[A] + vm->registers[B];

    return 0;
}
