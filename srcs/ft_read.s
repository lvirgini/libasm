extern	__errno_location

		global	ft_read
		section	.txt

ft_read:				
			mov		rax, 0				; syscall nb for read / 3 for x32
			mov		rbx, rdi			; fd
			mov		rcx, rsi			; buffer address to copy
			syscall						; int 0x80 for x32

			cmp		rax, 0
			jl		.syscall_error		; if return is negatif
			ret

.syscall_error:
   			neg  	rax
			mov		rdx, rax
			call	__errno_location	; save positive error return in errno
    		mov		rax, -1
    		ret