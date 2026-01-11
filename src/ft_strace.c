#include "ft_strace.h"

void	ft_strace(char** argv, char** envp) {
	const pid_t	pid = fork();

	if (pid == -1) {
		perror("ft_strace: fork");
		exit(-1);
	}
	if (pid == 0)
		exec_child(argv, envp);

	trace(pid);
}

void	exec_child(char** argv, char** envp) {
	if (execve(argv[0], argv, envp) == -1)
		perror("ft_strace: execve");
	exit(-1);
}

void	trace(pid_t pid) {
	if (ptrace(PTRACE_SEIZE, pid, 0, 0) == -1) {
		perror("ft_strace: PTRACE_SEIZE");
		exit(-1);
	}

	int status;
	const pid_t wpid = waitpid(pid, &status, 0);
	(void)wpid;
}