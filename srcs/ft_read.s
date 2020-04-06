		global	ft_read

		section	.txt

ft_read:				
		mov		rax, 3			; syscall nb for read
		mov		rbx, rdi		; fd
		mov		rcx, rsi		; buffer address to copy
		syscall					; int 0x80 sur 32b
		mov 	rax, 1          ; sys exit
		mov		rbx, 0
		syscall	
		ret