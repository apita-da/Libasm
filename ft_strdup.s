section .text
	global _ft_strdup








char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		cont;
	int		len;

	len = ft_strlen(s1);
	if (!(s2 = malloc(sizeof(char) * len + 1)))
		return (NULL);
	cont = 0;
	while (s1[cont] != '\0')
	{
		s2[cont] = s1[cont];
		cont++;
	}
	s2[cont] = '\0';
	return (s2);
}