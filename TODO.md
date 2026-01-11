On each system call:
```open("/dev/null", O_RDONLY) = 3```  

If return is -1 add errno symbol:
```open("/foo/bar", O_RDONLY) = -1 ENOENT```  

On signals:
```sigsuspend([] <unfinished ...>
--- SIGINT {si_signo=SIGINT, si_code=SI_USER, si_pid=...} ---
+++ killed by SIGINT +++```

