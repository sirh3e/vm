cmake_minimum_required(VERSION 3.16)
project(vm C)

set(CMAKE_C_STANDARD 99)

add_executable(vm main.c
        ./src/vm.c
./src/instruction/add.c
./src/instruction/and.c
./src/instruction/dec.c
./src/instruction/div.c
./src/instruction/halt.c
./src/instruction/inc.c
./src/instruction/load.c
./src/instruction/log.c
./src/instruction/mul.c
./src/instruction/neg.c
./src/instruction/or.c
./src/instruction/pop.c
./src/instruction/push.c
./src/instruction/save.c
./src/instruction/shl.c
./src/instruction/shr.c
./src/instruction/sub.c
./src/instruction/xor.c src/instruction/label.c)
