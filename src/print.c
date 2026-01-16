#include <sys/user.h>		//user_regs_struct
#include <stdio.h>			//printf
#include <stdint.h>			//uint32_t
#include <stdlib.h>			//exit

#include "syscall/syscall_table32.h"
#include "syscall/syscall_table64.h"

void	print_syscall(unsigned long long syscall_num, struct user_regs_struct regs) {
	unsigned long	args[6];
	unsigned long	ret;
	t_syscall		syscall;
	if ((regs.cs & 0xffff) == 0x33) {			// 0x33 = user 64 bits (long mode)
		args[0] = regs.rdi;
		args[1] = regs.rsi;
		args[2] = regs.rdx;
		args[3] = regs.r10;
		args[4] = regs.r8;
		args[5] = regs.r9;
		ret = regs.rax;
		if (syscall_num > SYSCALL_MAX64) {
			fprintf(stderr, "ft_strace: unknow syscall number");
			exit(-1);
		}
		syscall = SYSCALL_TABLE64[syscall_num];
	} else if ((regs.cs & 0xffff) == 0x23) {	// 0x23 = user 32 bits (compat mode)
		args[0] = (uint32_t)regs.rbx;
		args[1] = (uint32_t)regs.rcx;
		args[2] = (uint32_t)regs.rdx;
		args[3] = (uint32_t)regs.rsi;
		args[4] = (uint32_t)regs.rdi;
		args[5] = (uint32_t)regs.rbp;
		ret = (uint32_t)regs.rax;
		if (syscall_num > SYSCALL_MAX32) {
			fprintf(stderr, "ft_strace: unknow syscall number");
			exit(-1);
		}
		syscall = SYSCALL_TABLE32[syscall_num];
	}
	if (syscall.name)
		printf("%s", syscall.name);
	else
		printf("Not implemented yet");
	if (syscall.printer)
		syscall.printer(args, ret);
	printf("\n");
}

void	printer_read(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_write(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_open(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_close(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_stat(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_fstat(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_lstat(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_poll(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_lseek(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_mmap(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_mprotect(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_munmap(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_brk(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_rt_sigaction(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_rt_sigprocmask(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_rt_sigreturn(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_ioctl(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}

void	printer_pread64(unsigned long args[6], unsigned long ret) {
(void)args;
(void)ret;
}
