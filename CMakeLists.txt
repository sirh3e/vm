cmake_minimum_required(VERSION 3.16)
project(vm C)

set(CMAKE_C_STANDARD 99)

add_executable(tests test/test.c src/instruction/add.c src/instruction/and.c src/instruction/dec.c src/instruction/div.c src/instruction/halt.c src/instruction/inc.c src/instruction/load.c src/instruction/log.c src/instruction/mul.c src/instruction/neg.c src/instruction/or.c src/instruction/pop.c src/instruction/push.c src/instruction/save.c src/instruction/shl.c src/instruction/shr.c src/instruction/sub.c src/instruction/xor.c src/instructions.h src/macros.h src/types.h src/vm.c src/vm.h test/instruction/test_add.c test/instruction/test_and.c test/instruction/test_dec.c test/test.c test/test.h test/test_instructions.h test/instruction/test_div.c test/instruction/test_halt.c test/instruction/test_inc.c test/instruction/test_load.c test/instruction/test_log.c test/instruction/test_mul.c test/instruction/test_neg.c test/instruction/test_or.c)
