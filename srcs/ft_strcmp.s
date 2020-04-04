			global	ft_strcmp

			section	.txt

ft_strcmp:
			push	rbp
			mov		rbp, rsp
			
compare:
			movzx	rax, byte [rdi]
			movzx	rdx, byte [rsi]
			sub		rax, rdx
			jnz		return
			cmp 	byte [rdi], 0
			jz		return
			add		rdi, 1
			add		rsi, 1
			jmp		compare

return:		
			pop		rbp
			ret