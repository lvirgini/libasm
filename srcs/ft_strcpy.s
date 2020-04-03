global			ft_strcpy

		section		.txt

ft_strcpy:
			push	rbp
			mov		rbp, rsp
			mov		rax, rsi

copy:
			mov		rdi, rdi
			cmp 	byte [rdi], 0
			je		return
			add		rdi, 1
			add		rsi, 1
			jmp		copy

return:
			pop rbp
			ret