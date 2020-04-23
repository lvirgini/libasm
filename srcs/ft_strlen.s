	global	ft_strlen
	section	.txt

ft_strlen:
			xor		rax, rax				; rax = 0

.loop:	
			cmp		byte [rdi + rax], 0		; compare s[rax] and 0
			je		.return					; if egal stop
			add		rax, 1					; then rax ++
			jmp		.loop

.return:
			ret
