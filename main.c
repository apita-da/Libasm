/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:53:07 by apita-da          #+#    #+#             */
/*   Updated: 2021/04/06 16:48:59 by apita-da         ###   ########.fr       */
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
}