global			_ft_strcpy

			section			.text
_ft_strcpy:	
			mov				rax, rdi
cpy_one:
			cmp				byte [rsi], 0
			jl				return
			mov				r8b, byte [rsi]
			mov				byte [rdi], r8b
			inc				rsi
			inc				rdi
			jmp				cpy_one
return:
			ret