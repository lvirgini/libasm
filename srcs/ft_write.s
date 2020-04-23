extern 	__errno_location

	global	ft_write
	section	.txt

ft_write:								; rdx have already the len			
			mov		rax, 1				; syscall nb for write in x64  / 4 for x32
			mov		rbx, rdi			; fd
			mov		rcx, rsi			; string address
			syscall						; int 0x80 sur x32
			
			cmp		rax, 0
			jl		.syscall_error		; if return is negatif	
			ret

.syscall_error:
   			neg  	rax
			mov		rdx, rax
			call	__errno_location 	
			mov		[rax], rdx			; save positive error in errno_location

    		mov		rax, -1				; return -1
    		ret
