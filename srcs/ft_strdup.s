extern 	malloc
extern	ft_strlen
extern	ft_strcpy

	global	ft_strdup
	section .txt

ft_strdup:
			push 	r9			; push register for use it
			mov		r9, rdi		; save address src
			call 	ft_strlen
			add		rax, 1		; rax = len, + 1 for malloc
			mov	 	rdi, rax
			call 	malloc
			cmp		rax, 0		; verif malloc return
			je		.ptr_null
			mov		rdi, rax	; rdi = rax = address ptr malloc
			mov		rsi, r9		; rsi = address src
			call	ft_strcpy
			jmp		.return

.ptr_null:
			xor 	rax, rax

.return:
			pop		r9			; restore register after use
			ret