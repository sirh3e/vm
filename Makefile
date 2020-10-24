#project
VM_NAME := VM

#git hash:
VM_VERSION_GIT_HASH ?= $(shell git describe --tags 2>/dev/null || git rev-parse HEAD)
VM_VERSION_GIT_HASH_SHORT ?= $(shell git describe --tags 2>/dev/null || git rev-parse --short HEAD)

#version:
VM_VERSION_MAJOR ?= 0
VM_VERSION_MINOR ?= 0
VM_VERSION_PATCH ?= 0
VM_VERSION_RELEASE_CANDIDATE ?= 0

# container marco
CONTAINER := docker
CONTAINER_FILE := Dockerfile.ubuntu.20.04

# target macros
TARGET := tests
MAIN_SRC := test/test.c

# compile macros
DIRS := src test
OBJS := 

# intermedia compile macros
ALL_OBJS := 
CLEAN_FILES := $(TARGET) $(OBJS)
DIST_CLEAN_FILES := $(OBJS)

# recursive wildcard
rwildcard=$(foreach d,$(wildcard $(addsuffix *,$(1))),$(call rwildcard,$(d)/,$(2))$(filter $(subst *,%,$(2)),$(d)))

# default target
default: show-info all

# non-phony targets
$(TARGET): build-subdirs $(OBJS) find-all-objs
	@echo -e "\t" CC $(CFLAGS) $(AL_OBJS) $(MAIN_SRC) -o $@
	@$(CC) $(CFLAGS) $(ALL_OBJS) $(MAIN_SRC) -o $@

.PHONY: container-build-release
container-build-release: container-prepare
		$(CONTAINER) build -f $(CONTAINER_FILE) \
			-t "$(VM_NAME):$(VM_VERSION_MAJOR).$(VM_VERSION_MINOR).$(VM_VERSION_PATCH)-focal" \
			-t "$(VM_NAME):latest" \
			.

.PHONY: container-build
container-build: container-prepare
		$(CONTAINER) build -f $(CONTAINER_FILE) \
			-t "$(VM_NAME):$(VM_VERSION_GIT_HASH)-focal" \
			-t "$(VM_NAME):latest" \
			.

.PHONY: container-prepare
container-prepare:
	cp .gitignore .dockerignore
	echo '.github' >> .dockerignore

.PHONY: check
check: 
	./$(TARGET)

# phony targets
.PHONY: all
all: configure-version $(TARGET)
	@echo Target $(TARGET) build finished.

.PHONY: clean
clean: clean-subdirs
	@echo CLEAN $(CLEAN_FILES)
	@rm -f $(CLEAN_FILES)

.PHONY: distclean
distclean: clean-subdirs
	@echo CLEAN $(DIST_CLEAN_FILES)
	@rm -f $(DIST_CLEAN_FILES)

# phony funcs
.PHONY: find-all-objs
find-all-objs:
	$(eval ALL_OBJS += $(call rwildcard,$(DIRS),*.o))

.PHONY: show-info
show-info:
	@echo Building Project

configure-version:
	./scripts/configure_version.sh \
		$(VM_NAME) \
		$(VM_VERSION_GIT_HASH) \
		$(VM_VERSION_GIT_HASH_SHORT) \
		$(VM_VERSION_MAJOR) \
		$(VM_VERSION_MINOR) \
		$(VM_VERSION_PATCH) \
		$(VM_VERSION_RELEASE_CANDIDATE)

.PHONY: shellcheck
shellcheck:
	shellcheck -a ./scripts/*.sh

# need to be placed at the end of the file
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
export PROJECT_PATH := $(patsubst %/,%,$(dir $(mkfile_path)))
export MAKE_INCLUDE=$(PROJECT_PATH)/config/make.global
export SUB_MAKE_INCLUDE=$(PROJECT_PATH)/config/submake.global
include $(MAKE_INCLUDE)
