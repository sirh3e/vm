//
// Created by sirh3e on 30.09.20.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

test_result_t test_instruction_xor(){
 
 i32 test_results = 0;
 i32 program[] = {
         INSTRUCTION_XOR, 1, 1,
         INSTRUCTION_XOR, 1, 2,
         INSTRUCTION_XOR, 4, 9,
 };
 
 VM_INIT(program);
 TEST_BEGIN();

 TEST_INSTRUCTION_EXECUTE_NEXT(vm);
 TEST_ASSERT(vm->instruction_index == 3, "vm.instruction_index == 3");
 TEST_ASSERT(vm->registers[A] == 1, "vm.register[A] == 1");
 TEST_ASSERT(vm->registers[B] == 1, "vm.register[B] == 1");
 TEST_ASSERT(vm->registers[C] == 0, "vm.register[C] == 0");
 
 TEST_INSTRUCTION_EXECUTE_NEXT(vm);
 TEST_ASSERT(vm->instruction_index == 6, "vm.instruction_index == 6");
 TEST_ASSERT(vm->registers[A] == 1, "vm.register[A] == 1");
 TEST_ASSERT(vm->registers[B] == 2, "vm.register[B] == 2");
 TEST_ASSERT(vm->registers[C] == 3, "vm.register[C] == 3");
 
 TEST_INSTRUCTION_EXECUTE_NEXT(vm);
 TEST_ASSERT(vm->instruction_index == 9, "vm.instruction_index == 9");
 TEST_ASSERT(vm->registers[A] == 4, "vm.register[A] == 04");
 TEST_ASSERT(vm->registers[B] == 9, "vm.register[B] == 09");
 TEST_ASSERT(vm->registers[C] == 13, "vm.register[C] == 13");
 
 TEST_END(vm);
 
 return test_results;
}