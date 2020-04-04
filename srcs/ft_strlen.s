			global	ft_strlen

			section	.txt

ft_strlen:
			push	rbp
			mov		rbp, rsp
			xor		rax, rax

loop:	
			cmp		byte [rdi + rax], 0
			je		return
			add		rax, 1
			jmp		loop

return:		
			pop		rbp
			ret
