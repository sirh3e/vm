//
// Created by sirh3e on 11/1/2020.
//

#include "test.h"

#include <stdlib.h>
#include <string.h>

test_vm_result test_string_new();
test_vm_result test_string_init();
test_vm_result test_string_free();

test_vm_result test_string()
{
	test_vm_result TEST_RESULTS_INIT(test_result);
	test_vm_result TEST_RESULTS_INIT(test_results);

	test_result = test_string_new();
	RESULTS_ADD_RESULT(test_results, test_result);

	test_result = test_string_init();
	RESULTS_ADD_RESULT(test_results, test_result);

	test_result = test_string_free();
	RESULTS_ADD_RESULT(test_results, test_result);

	return test_result;
}

test_vm_result test_string_new()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	TEST_BEGIN();

	String *string = string_new();

	TEST_ASSERT(string != NULL);
	TEST_ASSERT(string->allocated == 0);
	TEST_ASSERT(string->length == 0);

	string_free(string);
	TEST_END(test_results);

	return test_results;
}

test_vm_result test_string_init()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	TEST_BEGIN();

	String *string = string_new();

	TEST_ASSERT(string != NULL);
	TEST_ASSERT(string->allocated == 0);
	TEST_ASSERT(string->length == 0);

	char *text = "hello world";
	TEST_ASSERT(string_init(string, text) == 0);
	TEST_ASSERT(string->length == strlen(string->data) + 1);

	string_free(string);
	TEST_END(test_results);

	return test_results;
}

test_vm_result test_string_free()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	TEST_BEGIN();

	String *string = string_new();

	TEST_ASSERT(string != NULL);
	TEST_ASSERT(string->allocated == 0);
	TEST_ASSERT(string->length == 0);

	char *text = "hello world";
	TEST_ASSERT(string_init(string, text) == 0);
	TEST_ASSERT(string->length == strlen(string->data) + 1);

	string_free(string);
	TEST_END(test_results);

	return test_results;
}