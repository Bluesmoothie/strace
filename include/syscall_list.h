#pragma once

typedef enum {
    ARCH_32BIT,
    ARCH_64BIT
}	t_arch;

extern t_arch	current_arch;

#define PRINT_SIZE_T(val, arch) \
        if ((arch) == ARCH_32BIT) { \
            printf("%u", (uint32_t)(val)); \
        } else { \
            printf("%llu", (unsigned long long)(val)); \
        }

#define PRINT_SSIZE_T(val, arch) \
        if ((arch) == ARCH_32BIT) { \
            printf("%d", (int32_t)(val)); \
        } else { \
            printf("%lld", (long long)(val)); \
        }

#define SYSCALL_MAX	467

typedef enum	e_type {
	TYPE_SSIZE_T,
	TYPE_SIZE_T,
	TYPE_INT,
	TYPE_POINTER,
	TYPE_STRING,
	TYPE_STRINGTAB,
	TYPE_LONG
}	t_type;

typedef struct	s_syscall {
	char*	name;
	t_type	return_type;
	short	arg_count;
	t_type	arg_type[6];
}	t_syscall;

const t_syscall	SYSCALL_LIST[SYSCALL_MAX + 1] = {
	[0] = {
		//ssize_t read(int fd, void* buf, size_t count)
		.name = "read",
		.return_type = TYPE_SSIZE_T,
		.arg_count = 3,
		.arg_type = {
			TYPE_INT,
			TYPE_POINTER,
			TYPE_SIZE_T
		}
	},
	[1] = {
		//ssize_t write(int fd, const void* buf, size_t count)
		.name = "write",
		.return_type = TYPE_SSIZE_T,
		.arg_count = 3,
		.arg_type = {
			TYPE_INT,
			TYPE_POINTER,
			TYPE_SIZE_T
		}
	},
	[2] = {
		//int open(const char *path, int flags, umode_t mode) Mode only if O_CREAT or O_TMPFILE in flags
		.name = "open",
		.return_type = TYPE_INT,
		.arg_count = 3,
		.arg_type = {
			TYPE_STRING,
			TYPE_INT,
			TYPE_INT
		}
	},
	[3] = {
		//int close(int fd)
		.name = "close",
		.return_type = TYPE_INT,
		.arg_count = 1,
		.arg_type = {
			TYPE_INT
		}
	},
	[14] = {
		//long rt_sigprocmask(int how, const sigset_t __user *set, sigset_t __user *oset, size_t sigsetsize)
		.name = "rt_sigprocmask",
		.return_type = TYPE_LONG,
		.arg_count = 4,
		.arg_type = {
			TYPE_INT,
			TYPE_POINTER,
			TYPE_POINTER,
			TYPE_SIZE_T
		}
	},
	[59] = {
		//int execve(const char *path, char *const _Nullable argv[], char *const _Nullable envp[])
		.name = "execve",
		.return_type = TYPE_INT,
		.arg_count = 3,
		.arg_type = {
			TYPE_STRING,
			TYPE_STRINGTAB,
			TYPE_STRINGTAB
		}
	}
};