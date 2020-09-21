#!/bin/sh

cmake CMakeLists.txt \
	&& make \
	&& ./vm

