/*
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
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
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

#ifndef VM_VERSION_H
#define VM_VERSION_H

#define VM_VERSION_GIT_HASH	  "c6b3514f69b6b2ec9ddca39ee0c51befda388a78"
#define VM_VERSION_GIT_HASH_SHORT "c6b3514"

#define VM_VERSION_MAJOR	     0
#define VM_VERSION_MINOR	     0
#define VM_VERSION_PATCH	     0
#define VM_VERSION_RELEASE_CANDIDATE 0

#define VM_VERSION_VARIABLE_VALUE_TO_STRING_HELPER(variable) #variable
#define VM_VERSION_VARIABLE_VALUE_TO_STRING(variable)                          \
	VM_VERSION_VARIABLE_VALUE_TO_STRING_HELPER(variable)

#define VM_VERSION_RELEASE_CANDIDATE_STATUS                                    \
	VM_VERSION_RELEASE_CANDIDATE > 0 ? 1 : 0

#if VM_VERSION_RELEASE_CANDIDATE_STATUS
#define VM_VERSION_TEXT_FORMAT(version_major,                                                           \
			       version_minor,                                                           \
			       version_patch,                                                           \
			       version_release_candidate)                                               \
	VM_VERSION_VARIABLE_VALUE_TO_STRING(version_major)                                              \
	"." VM_VERSION_VARIABLE_VALUE_TO_STRING(version_minor) "." VM_VERSION_VARIABLE_VALUE_TO_STRING( \
		version_patch) "-rc" VM_VERSION_VARIABLE_VALUE_TO_STRING(version_release_candidate)
#else
#define VM_VERSION_TEXT_FORMAT(version_major, version_minor, version_patch)    \
	VM_VERSION_VARIABLE_VALUE_TO_STRING(version_major)                     \
	"." VM_VERSION_VARIABLE_VALUE_TO_STRING(                               \
		version_minor) "." VM_VERSION_VARIABLE_VALUE_TO_STRING(version_patch)
#endif

#if VM_VERSION_RELEASE_CANDIDATE_STATUS
#define VM_VERSION_TEXT                                                        \
	VM_VERSION_TEXT_FORMAT(VM_VERSION_MAJOR,                               \
			       VM_VERSION_MINOR,                               \
			       VM_VERSION_PATCH,                               \
			       VM_VERSION_RELEASE_CANDIDATE)
#else
#define VM_VERSION_TEXT                                                        \
	VM_VERSION_TEXT_FORMAT(VM_VERSION_MAJOR,                               \
			       VM_VERSION_MINOR,                               \
			       VM_VERSION_PATCH)
#endif
#endif //VM_VERSION_H
