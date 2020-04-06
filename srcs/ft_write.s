			global	ft_write

			section	.txt

ft_write:						; rdx have already len
		mov		rax, 4			; syscall nb for write
		mov		rbx, 1,			; fd
		mov		ecx, esi
		syscall					;int 0x80 sur 32b
		mov 	eax, 1          ; sys exit
		mov		rbx, 0
		syscall	
		ret