extern __errno_location

			global	ft_write

			section	.txt

ft_write:							; rdx have already the len					
			mov		rax, 4			; syscall nb for write
			mov		rbx, rdi		; fd
			mov		rcx, rsi		; string address
			syscall					; int 0x80 sur 32b
			cmp		rax, 0
			jl		syscall_error
			mov 	rax, 1          ; sys exit
			mov		rbx, 0
			syscall	
			ret

syscall_error:
   			neg  	rax
			mov		rdx, rax
			call	__errno_location
			mov		[rax], rdx
    		mov		rax, -1
    		ret
