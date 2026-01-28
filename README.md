# WIP

This project is a Work In Progress

# Strace

A program to trace all syscalls and signals of another program

## Building

To build run
```bash
make
```

## Usage

./ft_strace [PROG]

## Result

Strace will show you all syscall like that  
```open("/dev/null", O_RDONLY) = 3```  
On error:  
```open("/foo/bar", O_RDONLY) = -1 ENOENT```  
  
On signals (not implemented yet):
```
sigsuspend([] <unfinished ...>
--- SIGINT {si_signo=SIGINT, si_code=SI_USER, si_pid=...} ---
+++ killed by SIGINT +++
```
## How it works

We use ```ptrace``` syscall to trace the program and get registers when entering and exiting a syscall
By decoding these registers we can get the original line of code (or a very similar version)

## Linux calling convention

| Position       | x86 32 bits (userspace)            | x86 32 bits (Syscalls)| x86_64 64 bits (userspace)           | x86_64 64 bits (Syscalls)|
|----------------|------------------------------------|-----------------------|--------------------------------------|--------------------------|
| 1er argument   | stack                              | ebx                   | rdi                                  | rdi                      |
| 2e argument    | stack                              | ecx                   | rsi                                  | rsi                      |
| 3e argument    | stack                              | edx                   | rdx                                  | rdx                      |
| 4e argument    | stack                              | esi                   | rcx                                  | r10                      |
| 5e argument    | stack                              | edi                   | r8                                   | r8                       |
| 6e argument    | stack                              | ebp                   | r9                                   | r9                       |
| Return         | eax                                | eax                   | rax                                  | rax                      |
| Syscall number | —                                  | eax                   | —                                    | rax                      |

To handle 32 and 64 bits binary we need to do a little conversion for 32 bit programs

32 bits register    | Place in user_regs_struct (64 bits) | Access to 32 bit value
--------------------|-------------------------------------|-------------------------------
ebx                 | rbx                                 | (uint32_t)regs.rbx
ecx                 | rcx                                 | (uint32_t)regs.rcx
edx                 | rdx                                 | (uint32_t)regs.rdx
esi                 | rsi                                 | (uint32_t)regs.rsi
edi                 | rdi                                 | (uint32_t)regs.rdi
ebp                 | rbp                                 | (uint32_t)regs.rbp
eax                 | rax                                 | (uint32_t)regs.rax
orig_eax            | orig_rax                            | (uint32_t)regs.orig_rax
eip                 | rip                                 | (uint32_t)regs.rip
esp                 | rsp                                 | (uint32_t)regs.rsp
eflags              | eflags                              | (uint32_t)regs.eflags
cs                  | cs                                  | (uint16_t)regs.cs
ds                  | ds                                  | (uint16_t)regs.ds
es                  | es                                  | (uint16_t)regs.es
fs                  | fs                                  | (uint16_t)regs.fs
gs                  | gs                                  | (uint16_t)regs.gs
ss                  | ss                                  | (uint16_t)regs.ss

To determine if a program is 32 or 64 bit we need to perform this test

```(regs.cs & 0xffff) == 0x33``` on 64 bit program
```(regs.cs & 0xffff) == 0x23``` on 32 bit program

## ext_src

These files are extracted from linux source code:
- ```syscall_32.tbl```
- ```syscall_64.tbl```
- ```syscalls.h```

Scripts are used to extract and make templates for decoding functions