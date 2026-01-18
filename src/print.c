#include "print.h"

void	print_syscall(unsigned long long syscall_num, struct user_regs_struct regs) {
	unsigned long	args[6];
	unsigned long	ret;
	t_syscall		syscall;
	if ((regs.cs & 0xffff) == 0x33) {			// 0x33 = user 64 bits (long mode)
		args[0] = regs.rdi;
		args[1] = regs.rsi;
		args[2] = regs.rdx;
		args[3] = regs.r10;
		args[4] = regs.r8;
		args[5] = regs.r9;
		ret = regs.rax;
		if (syscall_num > SYSCALL_MAX64) {
			fprintf(stderr, "ft_strace: unknow syscall number");
			exit(-1);
		}
		syscall = SYSCALL_TABLE64[syscall_num];
	} else if ((regs.cs & 0xffff) == 0x23) {	// 0x23 = user 32 bits (compat mode)
		args[0] = (uint32_t)regs.rbx;
		args[1] = (uint32_t)regs.rcx;
		args[2] = (uint32_t)regs.rdx;
		args[3] = (uint32_t)regs.rsi;
		args[4] = (uint32_t)regs.rdi;
		args[5] = (uint32_t)regs.rbp;
		ret = (uint32_t)regs.rax;
		if (syscall_num > SYSCALL_MAX32) {
			fprintf(stderr, "ft_strace: unknow syscall number");
			exit(-1);
		}
		syscall = SYSCALL_TABLE32[syscall_num];
	}
	if (syscall.name)
		printf("%s(", syscall.name);
	else
		printf("Not implemented yet");
	if (syscall.printer)
		syscall.printer(args, ret);
	printf("\n");
}

void	print_ret(unsigned long ret) {
	printf(") = ");
	if ((int)ret >= 0)
		printf("%d", (int)ret);
	else {
		printf("-1 ");
		detail_errno(ret);
	}
}

void	print_addr(unsigned long addr) {
	if (addr == 0)
		printf("NULL");
	else
		printf("0x%lx", addr);
}

//Very long section, for each function we have:
//Function signature from linux kernel source
//Function signature from linux user manual

void	printer__llseek(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer__newselect(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer__sysctl(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_accept(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_accept4(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_access(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_acct(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_add_key(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_adjtimex(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_afs_syscall(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_alarm(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_arch_prctl(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_bdflush(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_bind(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_bpf(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_break(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

//long	sys_brk	(unsigned long brk);
//int	brk		(void *addr);
void	printer_brk(unsigned long args[6], unsigned long ret) {
	print_addr(args[0]);
	if ((int)ret == -1)
		print_ret(ret);
	else
		printf(") = 0x%lx", ret);
}

void	printer_cachestat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_capget(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_capset(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_chdir(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_chmod(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_chown(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_chown32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_chroot(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_clock_adjtime(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_clock_adjtime64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_clock_getres(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_clock_getres_time64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_clock_gettime(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_clock_gettime64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_clock_nanosleep(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_clock_nanosleep_time64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_clock_settime(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_clock_settime64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_clone(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_clone3(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

//long	sys_close	(unsigned int fd);
//int	close		(int fd);
void	printer_close(unsigned long args[6], unsigned long ret) {
	printf("%d", (int)(args[0]));
	print_ret(ret);
}

void	printer_close_range(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_connect(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_copy_file_range(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_creat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_create_module(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_delete_module(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_dup(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_dup2(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_dup3(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_epoll_create(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_epoll_create1(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_epoll_ctl(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_epoll_ctl_old(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_epoll_pwait(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_epoll_pwait2(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_epoll_wait(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_epoll_wait_old(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_eventfd(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_eventfd2(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

//long	sys_execve	(const char __user *filename, 	const char __user *const __user *argv, 	const char __user *const __user *envp);
//int	execve		(const char *pathname, 			char *const _Nullable argv[], 			char *const _Nullable envp[]);
void	printer_execve(unsigned long args[6], unsigned long ret) {
	printf("%s, %p, %p", (char*)(args[0]), (void*)(args[1]), (void*)(args[2]));
	print_ret(ret);
}

void	printer_execveat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_exit(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

//long	sys_exit_group(int error_code);
void	printer_exit_group(unsigned long args[6], unsigned long ret) {
	printf("0) = ?");
	(void)args;
	(void)ret;
}

void	printer_faccessat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_faccessat2(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fadvise64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fadvise64_64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fallocate(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fanotify_init(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fanotify_mark(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fchdir(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fchmod(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fchmodat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fchmodat2(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fchown(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fchown32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fchownat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fcntl(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fcntl64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fdatasync(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fgetxattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_file_getattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_file_setattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_finit_module(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_flistxattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_flock(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fork(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fremovexattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fsconfig(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fsetxattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fsmount(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fsopen(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fspick(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fstat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fstat64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fstatat64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fstatfs(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fstatfs64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_fsync(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ftime(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ftruncate(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ftruncate64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_futex(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_futex_requeue(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_futex_time64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_futex_wait(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_futex_waitv(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_futex_wake(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_futimesat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_get_kernel_syms(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_get_mempolicy(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_get_robust_list(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_get_thread_area(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getcpu(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getcwd(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getdents(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getdents64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getegid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getegid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_geteuid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_geteuid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getgid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getgid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getgroups(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getgroups32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getitimer(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getpeername(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getpgid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getpgrp(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getpid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getpmsg(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getppid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getpriority(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getrandom(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getresgid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getresgid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getresuid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getresuid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getrlimit(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getrusage(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getsid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getsockname(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getsockopt(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_gettid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_gettimeofday(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getuid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getuid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getxattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_getxattrat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_gtty(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_idle(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_init_module(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_inotify_add_watch(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_inotify_init(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_inotify_init1(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_inotify_rm_watch(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_io_cancel(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_io_destroy(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_io_getevents(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_io_pgetevents(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_io_pgetevents_time64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_io_setup(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_io_submit(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_io_uring_enter(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_io_uring_register(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_io_uring_setup(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ioctl(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ioperm(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_iopl(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ioprio_get(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ioprio_set(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ipc(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_kcmp(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_kexec_file_load(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_kexec_load(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_keyctl(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_kill(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_landlock_add_rule(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_landlock_create_ruleset(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_landlock_restrict_self(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_lchown(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_lchown32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_lgetxattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_link(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_linkat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_listen(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_listmount(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_listns(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_listxattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_listxattrat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_llistxattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_lock(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_lookup_dcookie(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_lremovexattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_lseek(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_lsetxattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_lsm_get_self_attr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_lsm_list_modules(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_lsm_set_self_attr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_lstat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_lstat64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_madvise(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_map_shadow_stack(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mbind(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_membarrier(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_memfd_create(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_memfd_secret(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_migrate_pages(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mincore(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mkdir(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mkdirat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mknod(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mknodat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mlock(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mlock2(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mlockall(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mmap(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mmap2(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_modify_ldt(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mount(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mount_setattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_move_mount(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_move_pages(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mprotect(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mpx(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mq_getsetattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mq_notify(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mq_open(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mq_timedreceive(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mq_timedreceive_time64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mq_timedsend(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mq_timedsend_time64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mq_unlink(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mremap(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_mseal(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_msgctl(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_msgget(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_msgrcv(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_msgsnd(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_msync(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_munlock(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_munlockall(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_munmap(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_name_to_handle_at(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_nanosleep(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_newfstatat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_nfsservctl(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_nice(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_oldfstat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_oldlstat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_oldolduname(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_oldstat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_olduname(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_open(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_open_by_handle_at(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_open_tree(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_open_tree_attr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_openat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_openat2(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pause(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_perf_event_open(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_personality(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pidfd_getfd(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pidfd_open(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pidfd_send_signal(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pipe(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pipe2(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pivot_root(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pkey_alloc(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pkey_free(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pkey_mprotect(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_poll(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ppoll(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ppoll_time64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_prctl(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pread64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_preadv(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_preadv2(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_prlimit64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_process_madvise(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_process_mrelease(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_process_vm_readv(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_process_vm_writev(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_prof(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_profil(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pselect6(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pselect6_time64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ptrace(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_putpmsg(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pwrite64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pwritev(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_pwritev2(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_query_module(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_quotactl(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_quotactl_fd(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_read(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_readahead(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_readdir(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_readlink(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_readlinkat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_readv(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_reboot(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_recvfrom(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_recvmmsg(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_recvmmsg_time64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_recvmsg(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_remap_file_pages(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_removexattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_removexattrat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_rename(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_renameat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_renameat2(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_request_key(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_restart_syscall(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_rmdir(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_rseq(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_rt_sigaction(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_rt_sigpending(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_rt_sigprocmask(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_rt_sigqueueinfo(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_rt_sigreturn(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_rt_sigsuspend(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_rt_sigtimedwait(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_rt_sigtimedwait_time64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_rt_tgsigqueueinfo(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sched_get_priority_max(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sched_get_priority_min(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sched_getaffinity(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sched_getattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sched_getparam(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sched_getscheduler(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sched_rr_get_interval(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sched_rr_get_interval_time64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sched_setaffinity(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sched_setattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sched_setparam(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sched_setscheduler(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sched_yield(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_seccomp(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_security(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_select(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_semctl(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_semget(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_semop(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_semtimedop(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_semtimedop_time64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sendfile(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sendfile64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sendmmsg(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sendmsg(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sendto(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_set_mempolicy(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_set_mempolicy_home_node(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_set_robust_list(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_set_thread_area(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_set_tid_address(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setdomainname(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setfsgid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setfsgid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setfsuid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setfsuid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setgid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setgid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setgroups(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setgroups32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sethostname(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setitimer(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setns(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setpgid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setpriority(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setregid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setregid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setresgid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setresgid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setresuid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setresuid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setreuid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setreuid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setrlimit(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setsid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setsockopt(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_settimeofday(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setuid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setuid32(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setxattr(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_setxattrat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sgetmask(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_shmat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_shmctl(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_shmdt(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_shmget(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_shutdown(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sigaction(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sigaltstack(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_signal(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_signalfd(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_signalfd4(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sigpending(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sigprocmask(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sigreturn(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sigsuspend(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_socket(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_socketcall(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_socketpair(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_splice(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ssetmask(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_stat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_stat64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_statfs(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_statfs64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_statmount(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_statx(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_stime(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_stty(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_swapoff(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_swapon(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_symlink(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_symlinkat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sync(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sync_file_range(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_syncfs(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sysfs(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_sysinfo(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_syslog(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_tee(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_tgkill(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_time(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_timer_create(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_timer_delete(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_timer_getoverrun(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_timer_gettime(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_timer_gettime64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_timer_settime(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_timer_settime64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_timerfd_create(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_timerfd_gettime(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_timerfd_gettime64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_timerfd_settime(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_timerfd_settime64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_times(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_tkill(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_truncate(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_truncate64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_tuxcall(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ugetrlimit(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ulimit(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_umask(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_umount(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_umount2(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_uname(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_unlink(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_unlinkat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_unshare(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_uprobe(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_uretprobe(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_uselib(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_userfaultfd(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_ustat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_utime(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_utimensat(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_utimensat_time64(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_utimes(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_vfork(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_vhangup(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_vm86(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_vm86old(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_vmsplice(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_vserver(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_wait4(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_waitid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_waitpid(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_write(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}

void	printer_writev(unsigned long args[6], unsigned long ret) {
    (void)args;
    (void)ret;
}