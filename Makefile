# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 12:51:38 by apita-da          #+#    #+#              #
#    Updated: 2021/04/13 13:44:48 by apita-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colores #
# usar con @echo "" en name, exec, clean y fclean#
_END	= \x1b[0m
_BOLD	= \x1b[1m
_UNDER	= \x1b[4m
_REV	= \x1b[7m

_GREY		=	\x1b[30m
_RED		=	\x1b[31m
_GREEN		=	\x1b[32m
_YELLOW		=	\x1b[33m
_BLUE		=	\x1b[34m
_PURPLE		=	\x1b[35m
_CYAN		=	\x1b[36m
_WHITE		=	\x1b[37m

#invertidos, backgrounds#

_IGREY		=	\x1b[40m
_IRED		=	\x1b[41m
_IGREEN		=	\x1b[42m
_IYELLOW	=	\x1b[43m
_IBLUE		=	\x1b[44m
_IPURPLE	=	\x1b[45m
_ICYAN		=	\x1b[46m
_IWHITE		=	\x1b[47m

SRCS	=	ft_strlen.s	\
			ft_strcpy.s	\
			ft_strcmp.s	\
			ft_write.s	\
			ft_read.s \
			ft_strdup.s
OBJS	=	$(SRCS:.s=.o)
NAME	=	libasm.a
EXEC	=	tester
NASM	=	nasm -f macho64

%.o: %.s
	$(NASM) $<

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(_GREEN) All files compiled. $(_END)✅"
	ar rcs $(NAME) $(OBJS)
	@echo "$(_GREEN) Library '$(NAME)' compiled. $(_END)✅"

clean:
	rm -f $(OBJS)
	@echo "$(_RED)'"$(OBJS)"' has been deleted. $(_END)🗑️"

fclean: clean
	rm -f $(EXEC)
	@echo "$(_RED)'"$(EXEC)"' has been deleted. $(_END)🗑️"	
	rm -f libasm.a
	@echo "$(_RED)'"$(NAME)"' has been deleted. $(_END)🗑️"

re:	fclean all

main: $(NAME)
	gcc -Wall -Wextra -Werror main.c -L. $(NAME) -o $(EXEC)
	./$(EXEC)

.PHONY: clean fclean re main