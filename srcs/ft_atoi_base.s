extern	ft_strlen

            global  ft_isspace
            section .txt

ft_isspace_plus_moins:
                cmp     rsi, 32         ; space, not printable
                jle     is_error
                cmp     rsi, 43         ; +
                je      is_plus
                cmp     rsi, 45         ; -
                je      is_neg
                cmp     rsi, 127        ; space
                je      is_error
                mov     rax, 0
                ret
is_error:
                mov     rax, -2
                ret
is_neg:         
                mov     rax, -1
                ret
is_plus:        
                mov     rax, 1
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
                                        ;str  = rdx     
                                        ;base = rsi(stable), rdi(change)     
                                        ;len  = r8(stable), r9(change)
check_base_loop:
                cmp     rdi, [rdi + rcx]
                loop    check_base_loop

check_base2:
                add     rdi, 1
                call    ft_isspace_plus_moins
                cmp     rax, 0
                jne     error
                add     r9, -1
                jz      done
                mov     rcx, r9 
                jmp     check_base_loop

done:           
                mov      rdi, rdx       
                                        ;str = rdi
                                        ;base = rsi
find_str :      
                call    ft_isspace_plus_moins
                cmp     rax, 0          ; rax have 1 or -1 if + / -
                je      translate
                add     rdi, 1
                jmp     find_str

translate:
                cmp     rdi, rsi

test:
                xor      rax, rax
                mov     al, [rdi]
                ret
error:
                mov     rax, 0
                ret