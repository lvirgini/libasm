extern 	malloc
extern	ft_strlen
extern	ft_strcpy

			global	ft_strdup

			section .txt

ft_strdup:
			mov		r9, rdi		;rdi = *src
			call 	ft_strlen
			add		rax, 1		;rax = len, + 1 for malloc
			mov	 	rdi, rax
			call 	malloc
			cmp		rax, 0
			je		ptr_null
			mov		rdi, rax
			mov		rsi, r9
			call	ft_strcpy
			ret

ptr_null:
			xor 	rax, rax
			ret	
