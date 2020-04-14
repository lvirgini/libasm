extern	ft_strlen
            global  ft_isspace
            section .txt

ft_isspace_plus_moins:
                cmp     rsi, 13
                jle     is_error
                cmp     rsi, 43
                je      is_error
                cmp     rsi, 45
                je      is_error
                cmp     rsi, 127
                je      is_error
                mov     rax, 0
                ret
is_error:
                mov     rax, -1
                ret



            global  ft_atoi_base
            section .txt

ft_atoi_base : 
                xor     rax, rax
                cmp     rdi, 0
                je      error
                mov     rdx, rdi        ; save str in rdx
                mov     rdi, rsi        ; save base in rdi fot strlen
                call    ft_strlen
                cmp     rax, 1
                jle     error
                mov     rcx, rax
                mov     r9, rax
                                        ;str = rdx     
                                        ;base = rsi(stable), rdi(change)     
                                        ;len = r9

check_base_loop:                        ; compare between element in base for twin
                cmp     rdi, [rdi + rcx]
                loop    check_base_loop

check_base2:
                add     rdi, 1
                call    ft_isspace_plus_moins
                cmp     rax, 0
                jne     error
                mov     r9, -1
                jz      done
                mov     rcx, r9 
                jmp     check_base_loop
            
done : 
                mov     rax, 3456
                ret
error:
                mov     rax, 0
                ret