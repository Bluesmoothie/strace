#include "stop.h"

static unsigned long long	g_syscall_num = 0;

bool	decode_entry(pid_t pid) {
	g_syscall_num = get_reg_set(pid).orig_rax;
	return(g_syscall_num == 59);
}

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