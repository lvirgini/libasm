	global	ft_strcpy
	section	.txt

ft_strcpy:
			mov		rax, rdi		; rdi = dst 

.copy:
			mov		rdx, [rsi]		; rsi = src   [rsi] = *src
			mov		[rdi], rdx		
			cmp 	byte [rsi], 0	; if *src = \0  stop copy
			je		.return
			add		rdi, 1			; else increment strings
			add		rsi, 1
			jmp		.copy

.return:
			ret