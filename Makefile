# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 17:50:02 by tnakajo           #+#    #+#              #
#    Updated: 2023/05/26 17:51:37 by tnakajo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	= main.c
OBJECTS	= $(SOURCES:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all:
	@cd ft_printf && make all
	@cd libft && make all
	$(CC) $(CFLAGS) server.c -no-pie ft_printf/libftprintf.a libft/libft.a -o server	
	$(CC) $(CFLAGS) client.c -no-pie ft_printf/libftprintf.a libft/libft.a -o client
	
clean:
	@cd ft_printf && make clean
	@cd libft && make clean
	@rm -f server
	@rm -f client

fclean: clean
	@cd ft_printf && make fclean
	@cd libft && make fclean

re: fclean all

bonus: fclean
	@cd ft_printf && make all
	@cd libft && make all
	$(CC) $(CFLAGS) server.c -no-pie ft_printf/libftprintf.a libft/libft.a -o server	
	$(CC) $(CFLAGS) client.c -no-pie ft_printf/libftprintf.a libft/libft.a -o client