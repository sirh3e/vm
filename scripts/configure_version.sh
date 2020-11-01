#!/bin/sh

if [ -z "${1}" ]
then
  echo "Project name can not be null"
  exit 1
fi

PROJECT_NAME=$( echo "$1" | tr '[:lower:]' '[:upper:]' )

PROJECT_VERSION_GIT_HASH="${2}"
if [ -z "${PROJECT_VERSION_GIT_HASH}" ]
then
  echo "Project version git hash can not be null"
  exit 1
fi

PROJECT_VERSION_GIT_HASH_SHORT="${3}"
if [ -z "${PROJECT_VERSION_GIT_HASH}" ]
then
  echo "Project version git hash can not be null"
  exit 1
fi
PROJECT_VERSION_MAJOR="${4}"
case "${PROJECT_VERSION_MAJOR}" in
  ''|*[!0-9]*) echo "PROJECT_VERSION_MAJOR is not a number"; exit 1;;
esac

PROJECT_VERSION_MINOR="${5}"
case "${PROJECT_VERSION_MINOR}" in
  ''|*[!0-9]*) echo "PROJECT_VERSION_MINOR is not a number"; exit 1;;
esac

PROJECT_VERSION_PATCH="${6}"
case "${PROJECT_VERSION_PATCH}" in
  ''|*[!0-9]*) echo "PROJECT_VERSION_PATCH is not a number"; exit 1;;
esac

PROJECT_VERSION_RELEASE_CANDIDATE="${7}"
case "${PROJECT_VERSION_RELEASE_CANDIDATE}" in
  ''|*[!0-9]*) echo "PROJECT_VERSION_RELEASE_CANDIDATE is not a number"; exit 1;;
esac

echo \
"/*
* BSD 3-Clause License
*
* Copyright (c) 2020, Huber Marvin <marvin dot huber at protonmail dot com>
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* * Redistributions of source code must retain the above copyright notice, this
*   list of conditions and the following disclaimer.
*
* * Redistributions in binary form must reproduce the above copyright notice,
*   this list of conditions and the following disclaimer in the documentation
*   and/or other materials provided with the distribution.
*
* * Neither the name of the copyright holder nor the names of its
*   contributors may be used to endorse or promote products derived from
*   this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/



#ifndef ${PROJECT_NAME}_VERSION_H
#define ${PROJECT_NAME}_VERSION_H

#define ${PROJECT_NAME}_VERSION_GIT_HASH \"${PROJECT_VERSION_GIT_HASH}\"
#define ${PROJECT_NAME}_VERSION_GIT_HASH_SHORT \"${PROJECT_VERSION_GIT_HASH_SHORT}\"

#define ${PROJECT_NAME}_VERSION_MAJOR ${PROJECT_VERSION_MAJOR}
#define ${PROJECT_NAME}_VERSION_MINOR ${PROJECT_VERSION_MINOR}
#define ${PROJECT_NAME}_VERSION_PATCH ${PROJECT_VERSION_PATCH}
#define ${PROJECT_NAME}_VERSION_RELEASE_CANDIDATE ${PROJECT_VERSION_RELEASE_CANDIDATE}

#define ${PROJECT_NAME}_VERSION_VARIABLE_VALUE_TO_STRING_HELPER(variable) #variable
#define ${PROJECT_NAME}_VERSION_VARIABLE_VALUE_TO_STRING(variable) ${PROJECT_NAME}_VERSION_VARIABLE_VALUE_TO_STRING_HELPER(variable)

#define ${PROJECT_NAME}_VERSION_RELEASE_CANDIDATE_STATUS \\
        ${PROJECT_NAME}_VERSION_RELEASE_CANDIDATE > 0 ? 1 : 0

#if ${PROJECT_NAME}_VERSION_RELEASE_CANDIDATE_STATUS
    #define ${PROJECT_NAME}_VERSION_TEXT_FORMAT(version_major, version_minor, version_patch, version_release_candidate) \\
        ${PROJECT_NAME}_VERSION_VARIABLE_VALUE_TO_STRING(version_major) \".\" ${PROJECT_NAME}_VERSION_VARIABLE_VALUE_TO_STRING(version_minor) \".\" ${PROJECT_NAME}_VERSION_VARIABLE_VALUE_TO_STRING(version_patch) \"-rc\" ${PROJECT_NAME}_VERSION_VARIABLE_VALUE_TO_STRING(version_release_candidate)
#else
    #define ${PROJECT_NAME}_VERSION_TEXT_FORMAT(version_major, version_minor, version_patch) \
        ${PROJECT_NAME}_VERSION_VARIABLE_VALUE_TO_STRING(version_major) \".\" ${PROJECT_NAME}_VERSION_VARIABLE_VALUE_TO_STRING(version_minor) \".\" ${PROJECT_NAME}_VERSION_VARIABLE_VALUE_TO_STRING(version_patch)
#endif

#if ${PROJECT_NAME}_VERSION_RELEASE_CANDIDATE_STATUS
    #define ${PROJECT_NAME}_VERSION_TEXT \\
        ${PROJECT_NAME}_VERSION_TEXT_FORMAT(${PROJECT_NAME}_VERSION_MAJOR, ${PROJECT_NAME}_VERSION_MINOR, ${PROJECT_NAME}_VERSION_PATCH, ${PROJECT_NAME}_VERSION_RELEASE_CANDIDATE)
#else
    #define ${PROJECT_NAME}_VERSION_TEXT \\
        ${PROJECT_NAME}_VERSION_TEXT_FORMAT(${PROJECT_NAME}_VERSION_MAJOR, ${PROJECT_NAME}_VERSION_MINOR, ${PROJECT_NAME}_VERSION_PATCH)
#endif
#endif //${PROJECT_NAME}_VERSION_H" > src/version.h
