//
// Created by sirh3e on 30.09.20.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_xor_0();

int test_instruction_xor(){
 
 i32 test_results = 0;
 
 test_results |= test_instruction_xor_0();
 
 return test_results;
}

int test_instruction_xor_0(){
 
 i32 test_results = 0;
 i32 program[] = {
         INSTRUCTION_XOR, 1, 1,
         INSTRUCTION_XOR, 1, 2,
         INSTRUCTION_XOR, 4, 9,
 };
 
 Vm* vm = vm_new();
 
 vm_init(vm);
 vm_program_set(vm, program, ARRAY_LENGTH(program));
 
 TEST_BEGIN();

 vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
 TEST_ASSERT(vm->instruction_index == 3, "vm.instruction_index == 3");
 TEST_ASSERT(vm->registers[A] == 1, "vm.register[A] == 1");
 TEST_ASSERT(vm->registers[B] == 1, "vm.register[B] == 1");
 TEST_ASSERT(vm->registers[C] == 0, "vm.register[C] == 0");
 
 vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
 TEST_ASSERT(vm->instruction_index == 6, "vm.instruction_index == 6");
 TEST_ASSERT(vm->registers[A] == 1, "vm.register[A] == 1");
 TEST_ASSERT(vm->registers[B] == 2, "vm.register[B] == 2");
 TEST_ASSERT(vm->registers[C] == 3, "vm.register[C] == 3");
 
 vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
 TEST_ASSERT(vm->instruction_index == 9, "vm.instruction_index == 9");
 TEST_ASSERT(vm->registers[A] == 4, "vm.register[A] == 04");
 TEST_ASSERT(vm->registers[B] == 9, "vm.register[B] == 09");
 TEST_ASSERT(vm->registers[C] == 13, "vm.register[C] == 13");
 
 TEST_END();
 vm_free(vm);
 
 return test_results;
}