extern free

		global	ft_list_remove_if
		section .txt

ft_list_remove_if:						; RDI = **list
										; [RDI] = *list
										; RSI = data_to_remove
										; RDX = ft_cmp
										; RCX = ft_free_data

				;cmp 	rdi, 0
				;je		.return
				
				;mov		r9, [rdi]			; save  *list = &data
				mov		r9 , rdi				; save **list = &list
				mov		r11, rsi			; save data_to_remove
				mov		r12, rdx			; save ft_cmp
				
.compare:	
				cmp		r9 , 0 				; if list is NULL
				je		.return

				mov		rdi, [r9]			; rdi = &data
				mov		rdi, [rdi]			; rdi = data
				call 	rdx					; call ft_cmp
				mov		rdx, r12			; restore ft_cmp
				mov		rsi, r11			; restore data_to_remove
				cmp		rax, 0				; if data = data_to_remove
				je		.remove_element

				mov		r9, [r9]			; else go to next
				lea		r9, [r9 + 8]


.compare2:	
				cmp		r9 , 0 				; if list is NULL
				je		.return

				mov		rdi, [r9]			; rdi = &data
				mov		rdi, [rdi]			; rdi = data		
				call 	rdx					; call ft_cmp
				mov		rdx, r12			; restore ft_cmp
				mov		rsi, r11			; restore data_to_remove
				cmp		rax, 0				; if data = data_to_remove
				ret
				je		.remove_element

				mov		r9, [r9]			; else go to next
				lea		r9, [r9 + 8]



.remove_element:
				mov		r10, r9				; save list
				mov		rax, r10
				ret
				mov		rdi, [r9]			; data in rdi for free data
				call	rcx					; free data
				mov		rax, r10
				ret
				mov		r10, r9
				mov		rax, r9
				ret
				cmp		r9, 0
				je		.return
				jmp		.compare
				
.remove_first:
				lea		r10, [r9 + 8]		;	save next to **list
				mov		rdi, r9				; 
				call 	free				; free list
				cmp		qword [r10], 0		; verif if next was NULL
				je		.return
				mov		r9, [r10]			; move first list in r9 for compare
				jmp		.compare
				

.return:
				ret