//
// Created by sirh3e on 9/20/2020.
//

#ifndef VM_TEST_H
#define VM_TEST_H

#define COLOR_REST "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"

#define TEST_BEGIN() \
            printf("[ BEGIN  ] %s\n", __func__)

#define TEST_END() \
            printf("[ END    ] %s\n", __func__)

#define TEST_ASSERT(expression, message) \
            printf("[ %s%s%s ] %s %s %d \n", expression ? COLOR_GREEN : COLOR_RED, expression ? "PASSED" : "FAILED", COLOR_REST, message, __FILE__, __LINE__); \
            test_results |= expression ? 0 : 1

int test();

#endif //VM_TEST_H
