section .text
	global _ft_strcmp

_ft_strcmp:						;rsi = s1, rsi = s2
		xor		rax, rax
		xor		rcx, rcx		;i = 0;

loop:
		mov		al, byte[rdi]  	;guarda el char para ir comparnado
		mov		bl, byte[rsi]	;""
		cmp		al, 0			;final de str?
		je		out				;jump if equal
		cmp		bl, 0			;final de str?
		je		out				;jump if not equal
		inc		rdi				;avanza el puntero de str
		inc		rsi				;avanza el puntero de str
		cmp 	al, bl 			;compara char a char
		jne		out				;jump if equal

		jmp		loop			;repite todo la función loop

out:
		movzx	rax, al 		;rax vale al, matiene signo
		movzx	rcx, bl			;rcx vale bl, mantien signo
		sub		rax, rcx		;resta rax y rcx
		ret						;return

;int		ft_strcmp(char *s1, char *s2)
;{
;	int i;

;	i = 0;
;	while ((s1[i] != '\0') || (s2[i] != '\0'))
;	{
;		if (s1[i] != s2[i])
;			return (s1[i] - s2[i]);
;		i++;
;	}
;	return (0);
;}