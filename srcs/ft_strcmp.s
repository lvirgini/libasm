		global	ft_strcmp
		section	.txt

ft_strcmp:
			push	rbp
			mov		rbp, rsp
			
.compare:
			movzx	rax, byte [rdi]		; get value *s1
			movzx	rdx, byte [rsi]		; get value *s2
			sub		rax, rdx			; compare values
			jnz		.return				; if not 0, they are differents
			cmp 	byte [rdi], 0		
			jz		.return				; if they are same and  = 0 it is the end \0
			add		rdi, 1				; next index 
			add		rsi, 1
			jmp		.compare

.return:		
			pop		rbp
			ret