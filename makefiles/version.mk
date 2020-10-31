#git hash:
VM_VERSION_GIT_HASH ?= $(shell git describe --tags 2>/dev/null || git rev-parse HEAD)
VM_VERSION_GIT_HASH_SHORT ?= $(shell git describe --tags 2>/dev/null || git rev-parse --short HEAD)

#version:
VM_VERSION_MAJOR ?= 0
VM_VERSION_MINOR ?= 0
VM_VERSION_PATCH ?= 0
VM_VERSION_RELEASE_CANDIDATE ?= 0

.PHONY: configure-version
configure-version:
	./scripts/configure_version.sh \
		$(VM_NAME) \
		$(VM_VERSION_GIT_HASH) \
		$(VM_VERSION_GIT_HASH_SHORT) \
		$(VM_VERSION_MAJOR) \
		$(VM_VERSION_MINOR) \
		$(VM_VERSION_PATCH) \
		$(VM_VERSION_RELEASE_CANDIDATE)