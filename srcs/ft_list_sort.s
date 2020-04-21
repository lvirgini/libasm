extern ft_list_size

		global	ft_list_sort
		section	.txt
										;  RDI  = &t
										; [RDI] = t
										; RSI = &cmp
ft_list_sort:
			cmp		rdi, 0				; verif if list doesn t exist
			je		.return
			mov		rbx, rdi			; RBX = **first index
			mov		r8, rsi				; R8  = *cmp
			mov		rdi, [rbx]			; RDI = t, &data  [RDI] = data 
			call	ft_list_size
			mov		rcx, rax			; RCX =  list size

.compare:
			mov		rdi, [rbx]			; RDI = t, &data  [RDI] = data 
			mov		rsi, [rdi + 8]		; RDI + 8 = &next  [RDI + 8] = next
			
			;mov		rax, [rdi]
			;ret
			call 	r8
			cmp		rax, 0
			jnl		.change_place

.next:		add		rdi, 8
			add 	rsi, 8
			cmp		rsi, 0
			sub		rcx, 1


.change_place:
			mov		rdx, [rdi]
			mov		rcx, [rsi]
			mov		[rsi], rdx
			mov		[rdi], rcx
			add		rcx, 1

.return:
			ret
