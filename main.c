/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:53:07 by apita-da          #+#    #+#             */
/*   Updated: 2021/05/24 15:04:17 by apita-da         ###   ########.fr       */
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
	char* sterro = "Bad file desciptor\n";
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
	char *towrite = " hello world\n";
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
	printf("\n\033[31m <-------------------------------------------------------------------------------------------->\n");
	
	printf("\033[31m <---------------------------------TEST FT_READ---------------------------------------------->\n");
	fd = open(path, O_RDONLY);
	char text[10] = "\0\0\0\0\0\0\0\0\0";
	int retu = ft_read(fd, text, 11);
	close(fd);
	printf("FT_READ: \"%s\"\nRETURN VAL: %d\n", text, retu);
	char text2[10] = "\0\0\0\0\0\0\0\0\0";
	retu = ft_read(45, text2, 11);
	printf("FT_READ: \"%s\"\nRETURN VAL: %s\n", text2, sterro);
	char text5[10] = "\0\0\0\0\0\0\0\0\0";
	retu = ft_read(0, text5, 11);
	printf("FT_READ: \"%s\"\nRETURN VAL: %d\n", text2, retu);

	fd = open(path, O_RDONLY);
	char text4[10] = "\0\0\0\0\0\0\0\0\0";
	retu = read(fd, text4, 11);
	printf("   READ: \"%s\"\nRETURN VAL: %d\n", text4, retu);

	char text3[10] = "\0\0\0\0\0\0\0\0\0";
	retu = read(45, text2, 11);
	printf("   READ: \"%s\"\nRETURN VAL: %s\n", text3, strerror(errno));

	close(fd);
	char text6[10] = "\0\0\0\0\0\0\0\0\0";
	retu = ft_read(0, text6, 11);
	printf("FT_READ: \"%s\"\nRETURN VAL: %d\n", text2, retu);
	printf("\n\033[31m <-------------------------------------------------------------------------------------------->\n");
	
	// printf("\033[31m <---------------------------------TEST FT_STRDUP---------------------------------------------->\n");
	
	// char *new;
	// char *old = "copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string copiar esta string ";
	// new = ft_strdup(old);
	// printf("NEW: \"%s\"\n", new);
	// free(new);
	// printf("freed string: OK\n");
	// new = ft_strdup("");
	// printf("NEW: \"%s\"\n", new);
	// free(new);
	// printf("freed string: OK\n");
	printf("\n\033[32m <---------------------------------THE END!!-------------------------------------------------->\n");
}