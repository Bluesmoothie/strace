#include "stop.h"

void	decode_entry(pid_t pid) {
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
	printf("Syscall : %llu\n", (unsigned long long)regs.orig_rax);
}

void	decode_exit(pid_t pid) {
	(void)pid;
	printf("Getting exit stop, not implemented yet\n");
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