section .text
	global _ft_strcmp





int		ft_strcmp(char *s1, char *s2)
{
	int cont;

	cont = 0;
	while ((s1[cont] != '\0') || (s2[cont] != '\0'))
	{
		if (s1[cont] != s2[cont])
			return (s1[cont] - s2[cont]);
		cont++;
	}
	return (0);
}