//
// Created by sirh3e on 10/17/2020.
//

#include "../test.h"

test_vm_result test_vm_instruction_label()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	i32 program[] = { INSTRUCTION_LABEL, INSTRUCTION_JMP, 0 };

	VM_INIT(program);
	TEST_BEGIN();

	for (int i = 0; i < 5; ++i)
	{
		TEST_ASSERT(vm->instruction_index == 0);
		TEST_ASSERT(vm->instructions[vm->instruction_index] ==
			    INSTRUCTION_LABEL);

		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // label
		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // jmp, 0
	}

	TEST_END(vm, test_results);

	return test_results;
}