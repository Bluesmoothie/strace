#include <stdio.h>			//printf
#include <stdlib.h>			//exit

void	ft_strace(char** argv, char** envp);

/**
 * @brief Verify args and launch strace
 * 
 * @param argc 
 * @param argv 
 * @param envp 
 * @return int 
 */
int	main(int argc, char** argv, char** envp) {
	if (argc == 1) {
		printf("ft_strace: must have PROG\n");
		exit(1);
	}

	ft_strace(argv + 1, envp);
}
