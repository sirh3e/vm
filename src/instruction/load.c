//
// Created by sirh3e on 9/20/2020.
//

#include "../assert.h"
#include "../vm.h"
#include "../instructions.h"
#include "../util.h"

vm_instruction_result vm_instruction_load(Vm* vm){

    VM_ASSERT(vm);
    VM_ASSERT_INSTRUCTION_INDEX(vm, 1);
    VM_ASSERT_REGISTER(vm->instructions[vm->instruction_index]);
    VM_ASSERT_STACK_INDEX(vm, -1);

    vm->stack_index -= 1;
    vm->registers[vm->instructions[vm->instruction_index]] = vm->stack[vm->stack_index];
    vm->instruction_index += 1;

    return 0;
}