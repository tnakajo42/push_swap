# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 20:26:36 by tnakajo           #+#    #+#              #
#    Updated: 2023/06/30 19:49:04 by tnakajo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_BONUS	= checker
CC			= cc -Wall -Wextra -Werror
RM			= rm -f
RM_RF		= rm -rf

LIBFT		= libft.a
LIBFT_DIR	= ./libft
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

GIT_VISUALIZER	= git clone https://github.com/o-reo/push_swap_visualizer.git _push_swap_visualizer
VISUALIZER		= ./_push_swap_visualizer
OPEN_VISUALIZER	= ./_push_swap_visualizer/build/bin/visualizer
GIT_LEAK_TESTER	= git clone https://github.com/IDC87/push_swap_leak_tester.git _push_swap_leak_tester
LEAK_TESTER		= ./_push_swap_leak_tester
LEAK_TESTER_SH	= test_leaks.sh
CREAR			= clear

SRCS	=	./main/push_swap.c \
			./main/argument_validation.c \
			./main/create_stack.c \
			./main/operations/swap.c \
			./main/operations/push.c \
			./main/operations/rotate.c \
			./main/operations/reverse_rotate.c \
			./turk_method/turk_method.c \
			./turk_method/sort_four.c \
			./turk_method/sort_five.c \
			./turk_method/push_form_a_to_b.c \
			./turk_method/is_ordered.c \
			./turk_method/is_sorted.c \
			./turk_method/fill_moves.c \
			./turk_method/position_in_b.c \
			./turk_method/distance_from_top.c \
			./turk_method/position_in_a.c \
			./turk_method/size_of_stack.c \
			./turk_method/empty_b.c \
			./turk_method/finish_a.c \

SRCS_BONUS	=	./bonus/checker_bonus.c \
				./bonus/get_next_line_bonus/get_next_line_bonus.c \
				./bonus/get_next_line_bonus/get_next_line_utils_bonus.c \
				./bonus/operations/push_bonus.c \
				./bonus/operations/rotate_bonus.c \
				./bonus/operations/reverse_rotate_bonus.c \
				./bonus/operations/swap_bonus.c \
				./main/argument_validation.c \
				./main/create_stack.c \
				./turk_method/is_sorted.c \

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

DEPS	=	./main/push_swap.h \
			./turk_method/turk_method.h \

DEPS_BONUS	=	./bonus/operations/rules.h \
				./bonus/get_next_line_bonus/get_next_line_bonus.h \
				./main/argument_validation.h \
				./main/linked_list.h \
				./turk_method/turk_method.h \

%.o: %.c
		$(CC) -c -o $@ $<

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $@ $(LIBFT)

all: $(NAME) $(NAME_BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)
	mv $(LIBFT_PATH) ./

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(OBJS_BONUS) -o $@ $(LIBFT)

bonus: $(NAME_BONUS)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(LIBFT)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

download_visualizer :
	$(GIT_VISUALIZER) && $(CREAR)
	mkdir $(VISUALIZER)/build
	cd $(VISUALIZER)/build && cmake .. && $(CREAR)
	cd $(VISUALIZER)/build && make && $(CREAR)
	make re && $(CREAR)
	$(OPEN_VISUALIZER) && $(CREAR)
	$(RM) imgui.ini && $(RM_RF) $(VISUALIZER) && make fclean && $(CREAR)

download_leak_tester :
	$(GIT_LEAK_TESTER) && $(CREAR)
	cd $(LEAK_TESTER) && mv $(LEAK_TESTER_SH) ../$(LEAK_TESTER_SH)
	make re
	make bonus && $(CREAR)
	bash $(LEAK_TESTER_SH)
	$(RM) $(LEAK_TESTER_SH) && $(RM_RF) $(LEAK_TESTER) && make fclean
	
.PHONY: all clean fclean re
