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
