#pragma once

#include "syscall.h"
#include "print.h"

#define SYSCALL_MAX64	547

const t_syscall	SYSCALL_TABLE64[SYSCALL_MAX64 + 1] = {
	[0]		= {"read", &printer_read},
	[1]		= {"write", &printer_write},
	[2]		= {"open", &printer_open},
	[3]		= {"close", &printer_close},
	[4]		= {"stat", &printer_stat},
	[5]		= {"fstat", &printer_fstat},
	[6]		= {"lstat", &printer_lstat},
	[7]		= {"poll", &printer_poll},
	[8]		= {"lseek", &printer_lseek},
	[9]		= {"mmap", &printer_mmap},
	[10]	= {"mprotect", &printer_mprotect},
	[11]	= {"munmap", &printer_munmap},
	[12]	= {"brk", &printer_brk},
	[13]	= {"rt_sigaction", &printer_rt_sigaction},
	[14]	= {"rt_sigprocmask", &printer_rt_sigprocmask},
	[15]	= {"rt_sigreturn", &printer_rt_sigreturn},
	[16]	= {"ioctl", &printer_ioctl},
	[17]	= {"pread64", &printer_pread64},
};