//
// Created by sirh3e on 9/21/2020.
//

#include "../test.h"

test_vm_result test_vm_instruction_and()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	i32 program[] = {
		INSTRUCTION_AND, 2,   2,   INSTRUCTION_AND, 255, 2,
		INSTRUCTION_AND, 255, 4,   INSTRUCTION_AND, 255, 8,
		INSTRUCTION_AND, 255, 16,  INSTRUCTION_AND, 255, 32,
		INSTRUCTION_AND, 255, 64,  INSTRUCTION_AND, 255, 128,
		INSTRUCTION_AND, 255, 256,
	};

	VM_INIT(program);
	TEST_BEGIN();

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == 2);
	TEST_ASSERT(vm->registers[B] == 2);
	TEST_ASSERT(vm->registers[C] == 2);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == 255);
	TEST_ASSERT(vm->registers[B] == 2);
	TEST_ASSERT(vm->registers[C] == 2);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == 255);
	TEST_ASSERT(vm->registers[B] == 4);
	TEST_ASSERT(vm->registers[C] == 4);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == 255);
	TEST_ASSERT(vm->registers[B] == 8);
	TEST_ASSERT(vm->registers[C] == 8);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == 255);
	TEST_ASSERT(vm->registers[B] == 16);
	TEST_ASSERT(vm->registers[C] == 16);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == 255);
	TEST_ASSERT(vm->registers[B] == 32);
	TEST_ASSERT(vm->registers[C] == 32);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == 255);
	TEST_ASSERT(vm->registers[B] == 64);
	TEST_ASSERT(vm->registers[C] == 64);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == 255);
	TEST_ASSERT(vm->registers[B] == 128);
	TEST_ASSERT(vm->registers[C] == 128);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == 255);
	TEST_ASSERT(vm->registers[B] == 256);
	TEST_ASSERT(vm->registers[C] == 0);

	TEST_END(vm, test_results);

	return test_results;
}