On each system call:
```open("/dev/null", O_RDONLY) = 3```  

If return is -1 add errno symbol:
```open("/foo/bar", O_RDONLY) = -1 ENOENT```  

On signals:
```sigsuspend([] <unfinished ...>
--- SIGINT {si_signo=SIGINT, si_code=SI_USER, si_pid=...} ---
+++ killed by SIGINT +++```


différenciation 32/64bits =>
ptrace(PTRACE_GETREGSET, pid, NT_PRSTATUS, &iov);

if ((regs.cs & 0xffff) == 0x33) {  // 0x33 = user 64 bits (long mode)
    // 64 bits
} else if ((regs.cs & 0xffff) == 0x23) {  // 0x23 = user 32 bits (compat mode)
    // 32 bits
}