section .text
	global _ft_strcmp

__ft_strcmp:				;rsi = s1, rdi = s2
		xor		rcx, rcx	;i = 0;
		cmp		rsi, 0		;rsi existe
		cmp		rdi, 0		;rdi existe




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