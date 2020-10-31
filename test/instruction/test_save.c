//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

test_vm_result test_vm_instruction_save()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	i32 program[] = {
		INSTRUCTION_ADD, -963,	 4589,	INSTRUCTION_SAVE, A,

		INSTRUCTION_ADD, 369825, 63512, INSTRUCTION_SAVE, B,

		INSTRUCTION_ADD, 1,	 2,	INSTRUCTION_SAVE, C,
	};

	VM_INIT(program);
	TEST_BEGIN();

	TEST_ASSERT(vm->instruction_index == 0);
	TEST_ASSERT(vm->stack_index == 0);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->instruction_index == 5);
	TEST_ASSERT(vm->stack_index == 1);
	TEST_ASSERT(vm->stack[vm->stack_index - 1] == -963);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->instruction_index == 10);
	TEST_ASSERT(vm->stack_index == 2);
	TEST_ASSERT(vm->stack[vm->stack_index - 1] == 63512);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->instruction_index == 15);
	TEST_ASSERT(vm->stack_index == 3);
	TEST_ASSERT(vm->stack[vm->stack_index - 1] == 3);

	TEST_END(vm, test_results);

	return test_results;
}