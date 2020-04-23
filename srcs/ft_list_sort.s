extern ft_list_size

		global	ft_list_sort
		section	.txt
										;  RDI  = list
										; [RDI] = *list 
										; RSI = &cmp
ft_list_sort:
			push	r8
			push	r9					; save registers before use
			push	r10					
			push	r11
			push	r12

			mov		r8, rsi				; r8 = &cmp
			mov		r9, [rdi]			; r9 = *list

.cmp_loop_1:
			cmp		r9, 0				; if *list is Null, stop
			je		.return
			mov		r10, [r9 + 8]		; r10 = *list->next

.cmp_loop_2:
			cmp		r10, 0				; if *next is Null
			je		.get_next_loop_1	; inc *list

			mov		rdi, [r9]			; rdi = *list->data
			mov		rsi, [r10]			; rsi = *next->data
			call	r8					; call cmp

			cmp		rax, 0				; if <= 0 next ++
			jle		.get_next_loop_2

			mov		r11, [r9]			; else exchange both data
			mov		r12, [r10]
			mov		[r9], r12
			mov		[r10], r11


.get_next_loop_2:
			mov		r10, [r10 + 8]		; *next = *next->next
			jmp		.cmp_loop_2


.get_next_loop_1:
			mov		r9, [r9 + 8]		; *list = *list->next
			jmp		.cmp_loop_1

.return:
			pop		r8
			pop		r9					; restore registers used
			pop		r10
			pop		r11
			pop		r12
			ret
