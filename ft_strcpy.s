section .text
	global _ft_strcpy

_ft_strcpy:									; dst = rdi, src = rsi
			xor		rcx, rcx				; i = 0
			cmp		rsi, 0					; !rsi, (rsi exite)
			jz		return					;salta a return si es 0
			jmp		copy					;salta a copy
increment:
			inc		rcx
copy:
			mov		dl, BYTE [rsi + rcx]  	;dl vale rsi[rcx] src
			mov		BYTE [rdi + rcx], dl	;rdi[rcx] vale dl dest
			cmp		dl, 0					;dl es 0?
			jnz		increment				;contador, cuenta uno mas '\0' del final
return:
			mov		rax, rdi				; rax vale rdi
			ret								;ret(return), rax 
