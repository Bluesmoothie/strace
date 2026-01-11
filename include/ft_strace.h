#pragma once

#include <sys/ptrace.h>		//ptrace
#include <unistd.h>			//fork
#include <sys/wait.h>		//waitpid
#include <stdio.h>			//perror
#include <stdlib.h>			//exit

void	exec_child(char** argv, char** envp);
void	trace(pid_t pid);