#ifndef VM_VERSION_H
#define VM_VERSION_H

#define VM_VERSION_GIT_HASH	  "12116b7be0c1b686e2ab7afd5144fa69654554b0"
#define VM_VERSION_GIT_HASH_SHORT "12116b7"

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
