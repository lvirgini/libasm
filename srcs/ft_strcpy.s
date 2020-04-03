global			ft_strcpy

		section		.txt

ft_strcpy:
			push	rbp
			mov		rbp, rsp
			mov		rax, rdi

copy:
			mov		rdx, [rsi]
			mov		[rdi], rdx
			cmp 	byte [rsi], 0
			je		return
			add		rdi, 1
			add		rsi, 1
			jmp		copy

return:
			pop rbp
			ret