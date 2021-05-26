section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
		call	_ft_strlen
		add		rax, 1		;adding '\0'
		push	rdi			;pushing str to stack
		mov		rdi, rax	;rax is rdi
		call	_malloc		;check malloc error
		jc		error
		mov		rdi, rax
		pop		rcx			;get str from stack
		mov		rsi, rcx
		call	_ft_strcpy
		ret

error:
		xor rax, rax		;exit code
		ret

; char	*ft_strdup(const char *s1)
; {
; 	char	*s2;
; 	int		cont;
; 	int		len;

; 	len = ft_strlen(s1);
; 	if (!(s2 = malloc(sizeof(char) * len + 1)))
; 		return (NULL);
; 	cont = 0;
; 	while (s1[cont] != '\0')
; 	{
; 		s2[cont] = s1[cont];
; 		cont++;
; 	}
; 	s2[cont] = '\0';
; 	return (s2);
; }