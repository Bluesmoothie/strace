#pragma once

#include <sys/wait.h>		//pid_t
#include <sys/ptrace.h>		//ptrace
#include <linux/elf.h>      //NT_PRSTATUS
#include <sys/user.h>		//user_regs_struct
#include <sys/uio.h>		//iovec
#include <stdio.h>			//perror
#include <stdlib.h>			//exit