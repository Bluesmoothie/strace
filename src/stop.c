#include "stop.h"

static unsigned long long	g_syscall_num = 0;

/**
 * @brief Save syscall number from registers to g_syscall_num
 * 
 * @param pid The pid of the tracee
 * @return int 1 if execve, -1 if the function doesn't return, 0 if none of the above
 */
int		decode_entry(pid_t pid) {
	struct user_regs_struct	regs = get_reg_set(pid);
	g_syscall_num = regs.orig_rax;

	if ((regs.cs & 0xffff) == 0x33) {			// 0x33 = user 64 bits (long mode)
		if (g_syscall_num == 59)
			return (1);
		if (NO_RETURN64(g_syscall_num)) {
			print_syscall(g_syscall_num, regs);
			return (-1);
		}
	} else if ((regs.cs & 0xffff) == 0x23) {	// 0x23 = user 32 bits (compat mode)
		if (g_syscall_num == 11)
			return (1);
		if (NO_RETURN32(g_syscall_num)) {
			print_syscall(g_syscall_num, regs);
			return (-1);
		}
	}
	return (0);
}

/**
 * @brief Get registers and send them with g_syscall_num to the printer function
 * 
 * @param pid 
 */
void	decode_exit(pid_t pid) {
	print_syscall(g_syscall_num, get_reg_set(pid));
}

void	special_stop(pid_t pid) {
	(void)pid;
	printf("Getting special stop, not implemented yet\nABORTING\n");
	exit(-1);
}

void	other_stop(pid_t pid) {
	(void)pid;
	printf("Getting other stop, not implemented yet\nABORTING\n");
	exit(-1);
}

void	signal_stop(pid_t pid) {
	(void)pid;
	printf("Getting signal stop, not implemented yet\nABORTING\n");
	exit(-1);
}

void	stop_killed(int status) {
	(void)status;
	printf("Getting kill stop, not implemented yet\nABORTING\n");
	exit(-1);
}

/**
 * @brief Get the reg set object
 * 
 * @param pid The pid of the tracee
 * @return struct user_regs_struct 
 */
struct user_regs_struct	get_reg_set(pid_t pid) {
	struct user_regs_struct	regs;
	struct iovec			iov;

	iov.iov_base = &regs;
	iov.iov_len = sizeof(regs);

	if (ptrace(PTRACE_GETREGSET, pid, NT_PRSTATUS, &iov) == -1) {
		perror("ft_strace: PTRACE_GETREGSET");
		exit(-1);
	}
	if (iov.iov_len != sizeof(regs)) {
		fprintf(stderr, "ft_strace: PTRACE_GETREGSET: error, struct size doesn't match");
		exit(-1);
	}

	return (regs);
}