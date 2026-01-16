#pragma once

typedef void	(syscall_printer)(unsigned long args[6], unsigned long ret);

typedef struct	s_syscall {
	char*				name;
	syscall_printer*	printer;
}	t_syscall;