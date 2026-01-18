#pragma once

#include <sys/user.h>		//user_regs_struct
#include <stdio.h>			//printf
#include <stdint.h>			//uint32_t
#include <stdlib.h>			//exit

#include "syscall/syscall_table32.h"
#include "syscall/syscall_table64.h"

//errno.c
void	detail_errno(unsigned long code);