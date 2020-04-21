extern	ft_strlen

         global  ft_isspace
         section .txt

ft_isspace_plus_moins:
                cmp     byte [rdi], 32         ; space, not printable
                jle     .is_error
                cmp     byte [rdi], 43         ; +
                je      .is_plus
                cmp     byte [rdi], 45         ; -
                je      .is_neg
                cmp     byte [rdi], 127        ; not printable
                je      .is_error
                mov     rax, 0
                ret
.is_error:
                mov     rax, -2
                ret
.is_neg:         
                mov     rax, -1
                ret
.is_plus:        
                mov     rax, 1
                ret


         global  ft_atoi_base
         section .txt

ft_atoi_base :                      ;rdi = str
                                    ;rsi = base
                xor     rax, rax
                cmp     rdi, 0          ; check if str is null
                je      .error
                mov     rdx, rdi        ; save str in rdx
                mov     rdi, rsi        ; save base in rdi for strlen
                call    ft_strlen
                mov     r8, rax
                cmp     rax, 1
                jle     .error
                sub     rax, 1
                mov     rcx, rax
                mov     r9, rax
                                    ;str  = rdx     
                                    ;base = rsi(stable), rdi(change)
                                    ;len  = r8(stable), r9(change)
.check_base_loop:
                call    ft_isspace_plus_moins
                cmp     rax, 0
                jne     .error
                movzx   ax,byte [rdi]
                cmp     al,byte [rdi + rcx]
                je      .error
                loop    .check_base_loop

.check_base:
                add     rdi, 1
                sub     r9, 1
                jz      .check_done
                mov     rcx, r9 
                jmp     .check_base_loop

.check_done:           
                mov     rdi, rdx            
                xor     rdx, rdx
                xor     rbx, rbx
                mov     rcx, 1
                                    ;str = rdi
                                    ;base = rsi
                                    ;len = r8
.find_str:      
                call    ft_isspace_plus_moins
                cmp     rax, -2             ; rax have 1 or -1 if + / -
                jne     .find_done
                add     rdi, 1
                jmp     .find_str

.find_done:  
                cmp     rax, 0
                je      .transpose_loop
                add     rdi, 1              ; +1 while str is  + / -
                mul     rcx                 ; rcx have -1 or +1
                mov     rcx, rax
                call    ft_isspace_plus_moins
                jmp     .find_str

.transpose_loop:
                cmp     byte [rsi + rbx], 0
                je      .return
                movzx   r9, byte [rdi]
                cmp     r9b, byte [rsi + rbx]
                je      .transpose
                add     rbx, 1
                jmp     .transpose_loop

.transpose:      
                mul     r8                  ; rax * r8 => res * len
                add     rax, rbx            ; rax + rdx => res + index of base
                add     rdi, 1
                cmp     byte [rdi], 0
                je      .return
                xor     rbx, rbx
                jmp     .transpose_loop

.error:
                mov     rax, 0
				ret

.return:         
                cmp    rcx, 0
                jne    .negatif
                ret

.negatif:
                mul    rcx
                ret