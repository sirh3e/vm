# container marco
CONTAINER := docker
CONTAINER_FILE := Dockerfile.ubuntu.20.04

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