segment .text
	global _ft_write
	extern ___error

; ft_write (rdi, rsi, rdx)
_ft_write:
	mov r8, rdx				; save rdx = len in r8
	mov rax, 0x2000004		; set call to write
    syscall					; call rax (write)
		jc exit_error		; if doesn't work, write set flags carry to 1 so jmp exit error
	ret

exit_error:
	push rax
	call ___error
	pop rdx
	mov [rax], rdx
	mov rax, -1				; set return to -1
	ret						; return
