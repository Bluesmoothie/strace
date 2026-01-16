#pragma once

void	printer_read(unsigned long args[6], unsigned long ret);
void	printer_write(unsigned long args[6], unsigned long ret);
void	printer_open(unsigned long args[6], unsigned long ret);
void	printer_close(unsigned long args[6], unsigned long ret);
void	printer_stat(unsigned long args[6], unsigned long ret);
void	printer_fstat(unsigned long args[6], unsigned long ret);
void	printer_lstat(unsigned long args[6], unsigned long ret);
void	printer_poll(unsigned long args[6], unsigned long ret);
void	printer_lseek(unsigned long args[6], unsigned long ret);
void	printer_mmap(unsigned long args[6], unsigned long ret);
void	printer_mprotect(unsigned long args[6], unsigned long ret);
void	printer_munmap(unsigned long args[6], unsigned long ret);
void	printer_brk(unsigned long args[6], unsigned long ret);
void	printer_rt_sigaction(unsigned long args[6], unsigned long ret);
void	printer_rt_sigprocmask(unsigned long args[6], unsigned long ret);
void	printer_rt_sigreturn(unsigned long args[6], unsigned long ret);
void	printer_ioctl(unsigned long args[6], unsigned long ret);
void	printer_pread64(unsigned long args[6], unsigned long ret);