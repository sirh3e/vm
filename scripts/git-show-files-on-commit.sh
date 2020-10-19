#!/bin/sh

set -e

GIT_HASH=$1

if [ -z "${GIT_HASH}" ]
then
    echo "GIT_HASH cannot be zero"
    exit 1
fi

git diff-tree --no-commit-id --name-only -r "${GIT_HASH}"
