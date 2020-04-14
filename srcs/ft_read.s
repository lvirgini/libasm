extern errno_location

			global	ft_read

			section	.txt

ft_read:				
			mov		rax, 3			; syscall nb for read
			mov		rbx, rdi		; fd
			mov		rcx, rsi		; buffer address to copy
			syscall					; int 0x80 sur 32b
			js		syscall_error
			mov 	rax, 1          ; sys exit
			mov		rbx, 0
			syscall	
			ret


syscall_error:
   			neg  	rax
			call	errno_location
    		mov		rax, -1
    		ret