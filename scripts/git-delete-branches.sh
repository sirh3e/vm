#!/bin/sh

BRANCH_NAME=$1

if [ -z "${BRANCH_NAME}" ]
then
    echo "BRANCH_NAME cannot be empty"
    return 1
fi

git branch -d "${BRANCH_NAME}"
git push origin -d "${BRANCH_NAME}"
