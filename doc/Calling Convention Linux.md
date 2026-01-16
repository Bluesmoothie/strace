| Position       | x86 32 bits (userspace)            | x86 32 bits (Syscalls) | x86_64 64 bits (userspace)         | x86_64 64 bits (Syscalls)|
|----------------|------------------------------------|-----------------------|--------------------------------------|--------------------------|
| 1er argument   | Pile (stack)                       | ebx                   | rdi                                  | rdi                      |
| 2e argument    | Pile (stack)                       | ecx                   | rsi                                  | rsi                      |
| 3e argument    | Pile (stack)                       | edx                   | rdx                                  | rdx                      |
| 4e argument    | Pile (stack)                       | esi                   | rcx                                  | r10                      |
| 5e argument    | Pile (stack)                       | edi                   | r8                                   | r8                       |
| 6e argument    | Pile (stack)                       | ebp                   | r9                                   | r9                       |
| Return         | eax                                | eax                   | rax                                  | rax                      |
| Syscall number | —                                  | eax                   | —                                    | rax                      |
