| Position       | Convention System V AMD64 ABI<br>(fonctions utilisateur, `call`) | Convention syscall Linux kernel<br>(`syscall` instruction) |
|----------------|-------------------------------------------------------------------|-------------------------------------------------------------|
| 1er argument   | `rdi`                                                             | `rdi`                                                       |
| 2e argument    | `rsi`                                                             | `rsi`                                                       |
| 3e argument    | `rdx`                                                             | `rdx`                                                       |
| **4e argument**| `rcx`                                                             | **`r10`**                                                   |
| 5e argument    | `r8`                                                              | `r8`                                                        |
| 6e argument    | `r9`                                                              | `r9`                                                        |