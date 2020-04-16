	global	ft_list_size
	section	.txt

ft_list_size:
			xor 	rax, rax			
			
.loop:
			cmp		rdi, 0			; verif if list then next is NULL
			je		.return
			mov		rdi, [rdi + 8]	; rdi + 8 = next : list = list->next
			add		rax, 1			
			jmp		.loop

.return:
			ret