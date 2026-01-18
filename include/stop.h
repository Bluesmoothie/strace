#pragma once

#include <sys/wait.h>		//pid_t
#include <sys/ptrace.h>		//ptrace
#include <linux/elf.h>      //NT_PRSTATUS
#include <sys/user.h>		//user_regs_struct
#include <sys/uio.h>		//iovec
#include <stdio.h>			//perror
#include <stdlib.h>			//exit

#define NO_RETURN_FUNC(x)	(x == 231)

//stop.c
struct	user_regs_struct	get_reg_set(pid_t pid);

//print.c
void	print_syscall(unsigned long long syscall_num, struct user_regs_struct regs);