#pragma once

#include <sys/ptrace.h>		//ptrace
#include <unistd.h>			//fork
#include <sys/wait.h>		//waitpid
#include <stdio.h>			//perror
#include <stdlib.h>			//exit

typedef enum	e_state {
	STATE_ENTRY,
	STATE_EXIT
}	t_state;

//	ft_trace.c
void	exec_child(char** argv, char** envp);
void	trace(pid_t pid);
void	init_tracing(pid_t pid);
void	wait_and_print(pid_t pid);

//	stop.c
void	decode_entry(pid_t pid);
void	decode_exit(pid_t pid);
void	special_stop(pid_t pid);
void	other_stop(pid_t pid);
void	signal_stop(pid_t pid);
void	stop_killed(int status);