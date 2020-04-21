extern 	malloc

		global	ft_list_push_front
		section	.txt

ft_list_push_front:							; RDI  = begin_list  = & t_list
											;[RDI] = *begin_list = t_list = & t_list->data
											; RSI  =  data 
				push 	rdi						; save begin_list
				push	rsi						; save data

				mov		rdi, 16					; 16 bits for malloc a new t_list
				call	malloc
				cmp		rax, 0					; check return's malloc
				je		.ptr_null

				pop		rsi						; restore data
				pop		rdi						; restore begin_list

				mov		[rax], rsi				; new_list->data = data
				mov		rdx, [rdi]
				mov		[rax + 8], rdx			; new_list->next = t_list	
				mov		[rdi], rax				; *begin_list = new_list
				ret

.ptr_null:
				xor 	rax, rax
				ret	