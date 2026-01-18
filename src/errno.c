#define _GNU_SOURCE			//stererrorname_np
#include <string.h>			//strerror, strerrorname_np
#include <stdio.h>			//printf

void	detail_errno(unsigned long code) {
	printf("%s (%s)", strerrorname_np(-code), strerror(-code));
}