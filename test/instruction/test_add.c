//
// Created by sirh3e on 9/20/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_add(){

    i32 program[] = {
            INSTRUCTION_ADD, 64, 2,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));

    test_assert(vm->registers[A] == 64, "vm.registers[A] == 64");
    test_assert(vm->registers[B] == 02, "vm.registers[B] == 02");
    test_assert(vm->registers[C] == 66, "vm.registers[C] == 66");

    vm_free(vm);

    return 0;
}