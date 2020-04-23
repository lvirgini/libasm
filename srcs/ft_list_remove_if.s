extern free

		global	ft_list_remove_if
		section .txt

ft_list_remove_if:							; RDI = list
											; [RDI] = *list ou &(**list) ou &(*list)->data
											; [[RDI]] = *list->data
													;mov	r, [rdi] 	then mov r, [r]

											; [[RDI] + 8] = *list->next 
													;mov	r, [rdi] 	then mov rax, [r + 8]

											; RSI = data_to_remove
											; RDX = ft_cmp
											; RCX = ft_free_data
				push	r10
				push	r11
				push	r12
				push 	r13					; push registers before use them
				push	r14
				push 	r15

				mov		r13, rdi			; save list
				mov		r11, rsi			; save data to remove
				mov		r12, rdx			; save ft_cmp
				mov		r14, rcx			; save free

.compare:
				mov		r10, [r13]			; r10 = *list
				cmp		r10, 0				; if *list is Null stop
				je		.return

				mov		rdi, [r10]			; mov *list->data in rdi
				mov		rsi, r11			; mov data to remove in rsi
				call	r12					; call ft_cmp
				cmp		rax, 0				; if result is same, go to free_data & list
				je		.list_to_free
											; else go to next_list :
				lea		r13, [r10 + 8]		; list = &(*list)->next
				jmp		.compare


.list_to_free:
				mov		rdi, [r10]
				call	r14					; free_fct(*list->data)
				mov		r15, [r10 + 8]		; save &(*list)->next

				mov		rdi, r10				; free *list
				call 	free

				mov		qword [r13] , r15	; save in next before, &(*list)->next
				jmp		.compare


.return:
				pop		r10
				pop		r11
				pop		r12
				pop	 	r13					; restore registers after use them
				pop		r14
				pop	 	r15
				ret
