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
	init_tracing(pid);

	while (true) {
		wait_and_print(pid);
		if (ptrace(PTRACE_SYSCALL, pid, 0, 0) == -1) {
			perror("ft_strace: PTRACE_SYSCALL");
			exit(-1);
		}
	}
}

void	init_tracing(pid_t pid) {
	if (ptrace(PTRACE_SEIZE, pid, 0, 0) == -1) {
		perror("ft_strace: PTRACE_SEIZE");
		if (kill(pid, SIGKILL) == -1)
			perror("ft_strace: kill");
		exit(-1);
	}
	if (ptrace(PTRACE_INTERRUPT, pid, 0, 0) == -1) {
		perror("ft_strace: PTRACE_INTERRUPT");
		if (kill(pid, SIGKILL) == -1)
		perror("ft_strace: kill");
		exit(-1);
	}

	int status;
	const pid_t wpid = waitpid(pid, &status, 0);
	if (wpid == -1) {
		perror("ft_strace: waitpid");
		exit(-1);
	}
	if (!(WIFSTOPPED(status) && WSTOPSIG(status) == SIGTRAP && ((status >> 16) == PTRACE_EVENT_STOP))) {
		fprintf(stderr, "ft_strace: waitpid: error, unexpected stop during initialization");
		exit(-1);
	}

	if (ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACESYSGOOD
										| PTRACE_O_TRACEFORK
										| PTRACE_O_TRACEVFORK
										| PTRACE_O_TRACECLONE
										| PTRACE_O_TRACEEXEC 
										| PTRACE_O_TRACEEXIT
										| PTRACE_O_EXITKILL) == -1) {
	perror("ft_strace: PTRACE_SETOPTIONS");
	if (kill(pid, SIGKILL) == -1)
		perror("ft_strace: kill");
	exit(-1);
	}

	if (ptrace(PTRACE_SYSCALL, pid, 0, 0) == -1) {
		perror("ft_strace: PTRACE_SYSCALL");
		exit(-1);
	}
}

void	wait_and_print(pid_t pid) {
	static t_state state = STATE_ENTRY;

	int status;
	const pid_t wpid = waitpid(pid, &status, 0);
	if (wpid == -1) {
		perror("ft_strace: PTRACE_SYSCALL");
		exit(-1);
	}

	if (!WIFSTOPPED(status)) {
	    stop_killed(status);
		exit(0);
	}

	const int sig = WSTOPSIG(status);
	const int event = (status >> 16) & 0xFFFF;

	if (sig == (SIGTRAP | 0x80) && event == 0) {
		if (state == STATE_ENTRY) {
			decode_entry(pid);
			state = STATE_EXIT;
		}
		else {
			decode_exit(pid);
			state = STATE_ENTRY;
		}
		return;
    }
    else if (sig == SIGTRAP && event != 0) {
		special_stop(pid);
    }
    else if (sig == SIGTRAP && event == 0) {
		other_stop(pid);
    }
    else {
		signal_stop(pid);
    }
}