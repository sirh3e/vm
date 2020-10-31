//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

test_vm_result test_vm_instruction_load()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	i32 program[] = {
		INSTRUCTION_PUSH, 16,	INSTRUCTION_LOAD, A,

		INSTRUCTION_PUSH, 64,	INSTRUCTION_LOAD, A,

		INSTRUCTION_PUSH, 128,	INSTRUCTION_LOAD, B,

		INSTRUCTION_PUSH, 256,	INSTRUCTION_LOAD, B,

		INSTRUCTION_PUSH, 512,	INSTRUCTION_LOAD, C,

		INSTRUCTION_PUSH, 1024, INSTRUCTION_LOAD, C,
	};

	VM_INIT(program);
	TEST_BEGIN();

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->stack[vm->stack_index - 1] == 16);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == 16);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->stack[vm->stack_index - 1] == 64);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == 64);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->stack[vm->stack_index - 1] == 128);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[B] == 128);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->stack[vm->stack_index - 1] == 256);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[B] == 256);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->stack[vm->stack_index - 1] == 512);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[C] == 512);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->stack[vm->stack_index - 1] == 1024);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[C] == 1024);

	TEST_END(vm, test_results);

	return test_results;
}