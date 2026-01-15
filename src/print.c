#include <sys/user.h>		//user_regs_struct
#include <stdio.h>			//printf

#include "syscall_list.h"

void	print_syscall(unsigned long long syscall_num, struct user_regs_struct regs) {
	printf("%s()\n", SYSCALL_LIST[syscall_num].name);
	(void)regs;
}