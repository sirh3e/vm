//
// Created by sirh3e on 07.10.20.
//

#include <assert.h>

#include "../instructions.h"
#include "../macros.h"

int instruction_jl(Vm* vm){
 
 assert(vm != NULL);
 VM_ASSERT_INSTRUCTION_INDEX(vm, 1);
 
 if (vm->registers[C] >= vm->registers[D])
  return 0;
 
 return instruction_jmp(vm);
}