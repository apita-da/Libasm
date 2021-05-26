/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:53:07 by apita-da          #+#    #+#             */
/*   Updated: 2021/05/26 15:04:58 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

char *s;
char *s2;
char *s3;
char *s4;

int 	main (int argc, char **argv)
{
	char *path = "Makefile";

	if (argc == 1)
		path = "results.txt";
	if (argc == 2)
		path = argv[1];
	printf("\033[31m <---------------------------------TEST FT_STRLEN---------------------------------------------->\n");
	char *s = "";
	printf("\n\033[35m **String de prueba =>  \"%s\"\n", s);
	printf("\n\033[32m Mi funcion: ft_strlen: %lu\n", ft_strlen(s));
	printf("\033[34m Original:   strlen: %lu\n", strlen(s));

	s = "Hola que tal, soy el chico de las poesias, tu fiel admirador"; 
	printf("\n\033[35m **String de prueba =>  \"%s\"\n", s);
	printf("\n\033[32m Mi funcion: ft_strlen: %lu\n", ft_strlen(s));
	printf("\033[34m Original:   strlen: %lu\n", strlen(s));
	printf("\n\033[31m <-------------------------------------------------------------------------------------------->\n");
	
	printf("\033[31m <---------------------------------TEST FT_STRCPY---------------------------------------------->\n");	
	char *src = strdup("");
	char *dst = malloc(strlen(src) * sizeof(char) + 1);

	printf("\n\033[35m ANTES   -> SRC: \"%s\" DST: \"%s\"\n", src, dst);
	char * ret = ft_strcpy(dst, src);
	printf("\n\033[32m DESPUÉS -> SRC: \"%s\" DST: \"%s\"\n", src, dst);
	printf("\033[34m RETURN: \"%s\"\n", ret);
	free(src); 
	free(dst);

	src = strdup("hola hola hola.");
	dst = malloc(strlen(src) * sizeof(char) + 1);
	
	printf("\033[35m ANTES   -> SRC: \"%s\" DST: \"%s\"\n", src, dst);
	ret = ft_strcpy(dst, src);
	printf("\033[32m DESPUÉS -> SRC: \"%s\" DST: \"%s\"\n", src, dst);
	printf("\033[34m RETURN: \"%s\"\n", ret);
	free(src); 
	free(dst);
	printf("\n\033[31m <-------------------------------------------------------------------------------------------->\n");

	printf("\033[31m <---------------------------------TEST FT_STRCMP---------------------------------------------->\n");
	char *s1 = "holi";
	char *s2 = "holi";
	printf("\033[35m S1: \"%s\" S2: \"%s\"\n", s1, s2);
	printf("\033[32m ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf("\033[34m    strcmp: %d\n", strcmp(s1, s2));

	s1 = "hol";
	s2 = "holi";
	printf("\033[35m S1: \"%s\" S2 \"%s\"\n", s1, s2);
	printf("\033[32m ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf("\033[34m   strcmp: %d\n", strcmp(s1, s2));

	s1 = "";
	s2 = "holi";
	printf("\033[35m S1: \"%s\" S2 \"%s\"\n", s1, s2);
	printf("\033[32m ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf("\033[34m   strcmp: %d\n", strcmp(s1, s2));

	s1 = "holi";
	s2 = "";
	printf("\033[35m S1: \"%s\" S2 \"%s\"\n", s1, s2);
	printf("\033[32m ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf("\033[34m   strcmp: %d\n", strcmp(s1, s2));

	s1 = "";
	s2 = "";
	printf("\033[35m S1: \"%s\" S2 \"%s\"\n", s1, s2);
	printf("\033[32m ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf("\033[34m   strcmp: %d\n", strcmp(s1, s2));

	char *s3 = "_______________________________________________________________________________________________________________________________________________________________";
	char *s4 = "string largastring largastring largastring largastring largastring largastring largastring largastring largastring largastring largastring larga";
	printf("\033[35m S1: \"%s\"\nS2 \"%s\"\n", s3, s4);
	printf("\033[32m ft_strcmp: %d\n", ft_strcmp(s3, s4));
	printf("\033[34m   strcmp: %d\n", strcmp(s3, s4));
	printf("\n\033[31m <-------------------------------------------------------------------------------------------->\n");
	
	printf("\033[31m <---------------------------------TEST FT_WRITE---------------------------------------------->\n");
	char *towrite = "hello world\n";
	printf("\033[35m ft_write: \n");
	ft_write(1, towrite, ft_strlen(towrite));
	printf("\033[35m write: \n");
	write(1, towrite, ft_strlen(towrite));
	int fd = open(path, O_WRONLY | O_CREAT, 0644);
	printf("\n\033[33m ft_write: \n");
	ft_write(fd, towrite, ft_strlen(towrite));
	printf("\n\033[33m write: \n");
	write(fd, towrite, ft_strlen(towrite));
	printf("\n\033[34m ft_write: \n");
	ft_write(18, towrite, ft_strlen(towrite));
	printf("\033[34m write: \n");
	write(18, towrite, ft_strlen(towrite));
	close(fd);
	printf("\n\033[31m <-------------------------------------------------------------------------------------------->\n");
	
	printf("\033[31m <---------------------------------TEST FT_READ---------------------------------------------->\n");
	path = "hola.txt";
	fd = open(path, O_RDONLY);
	char text[10] = "\0\0\0\0\0\0\0\0\0";
	int retu = ft_read(fd, text, 9);
	printf("\033[35m FT_READ: \"%s\"\nRETURN VAL: %d\n", text, retu);
	close(fd);
	char text3[10] = "\0\0\0\0\0\0\0\0\0";
	retu = ft_read(45, text3, 11);
	printf("\033[32m FT_READ: \"%s\"\nRETURN VAL: %s\n", text3, strerror(errno));
	char text5[10] = "\0\0\0\0\0\0\0\0\0";
	retu = ft_read(0, text5, 11);
	printf("\033[33m FT_READ: \"%s\"\nRETURN VAL: %d\n", text5, retu);
	
	fd = open(path, O_RDONLY);
	char text2[10] = "\0\0\0\0\0\0\0\0\0";
	int retn = read(fd, text2, 9);
	printf("\033[35m    READ: \"%s\"\nRETURN VAL: %d\n", text2, retn);
	close(fd);
	char text4[10] = "\0\0\0\0\0\0\0\0\0";
	retn = read(45, text4, 11);
	printf("\033[32m    READ: \"%s\"\nRETURN VAL: %s\n", text4, strerror(errno));
	char text6[10] = "\0\0\0\0\0\0\0\0\0";
	retn = read(0, text6, 11);
	printf("\033[33m READ: \"%s\"\nRETURN VAL: %d\n", text6, retn);
	
	printf("\n\033[31m <-------------------------------------------------------------------------------------------->\n");
	
	printf("\033[31m <---------------------------------TEST FT_STRDUP---------------------------------------------->\n");
	
	char *new;
	char *old = "copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string ";
	printf("\033[35m OLD: \"%s\"\n", old);
	new = ft_strdup(old);
	printf("\033[33m NEW: \"%s\"\n", new);
	free(new);
	printf("\033[34m freed string: OK\n");
	new = ft_strdup("");
	printf("\033[33m NEW: \"%s\"\n", new);
	free(new);
	printf("\033[34m freed string: OK\n");
	printf("\n\033[32m <---------------------------------THE END!!-------------------------------------------------->\n");
}