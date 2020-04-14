extern errno_location

			global	ft_write

			section	.txt

ft_write:							; rdx have already the len
			cmp 	rsi, 0
			;jz		ptr_null					
			mov		rax, 4			; syscall nb for write
			mov		rbx, rdi		; fd
			mov		rcx, rsi		; string address
			syscall					; int 0x80 sur 32b
			;js		syscall_error
			mov 	rax, 1          ; sys exit
			mov		rbx, 0
			syscall	
			ret

ptr_null:
			mov		rax, -1
			ret

syscall_error:
   			neg  	rax
			;call	errno_location
    		mov		rax, -1
    		ret
