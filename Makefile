# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 18:07:52 by lfabbro           #+#    #+#              #
#    Updated: 2016/10/31 21:12:14 by lfabbro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC_NAME = main.c push_swap.c\
		   check_filename.c check_list_args.c\
		   stack_from_args.c stack_from_file.c\
		   free.c help.c status.c new.c parse.c\
		   print.c print_stack.c which_moove.c\
		   moove_and_print.c\
		   sort_smart.c sort_select.c sort_three.c\
		   sort_split_select_00.c sort_split_select_01.c\
		   mooves_01.c mooves_02.c\
		   errors_00.c errors_01.c\
		   list_minmax.c\
		   is_swapped.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAMES = ft

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/
LIB_PATH = ./libft/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

## SOURCES ##
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))


## INCLUDES ##
INC = $(addprefix -I,$(INC_PATH))


## LIBRARIES ##
LIB_LINK = $(addprefix -L,$(LIB_PATH))
LIB = $(addprefix -l,$(LIB_NAMES))

.PHONY: all clean fclean re norme

## RULES ##
all:
	@make -C $(LIB_PATH)
	@echo "\x1b[44m\x1b[32mMaking push_swap\x1b[0m\x1b[0m"
	@make $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(INC) $(LIB_LINK) $(LIB) $(SRC) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean :
	@/bin/rm -fv $(OBJ)

fclean : libfclean clean
	@/bin/rm -fv $(NAME)

libre :
	@make -C $(LIB_PATH) re

libclean :
	@make -C $(LIB_PATH) clean

libfclean :
	@make -C $(LIB_PATH) fclean

re : fclean all

norme :
	norminette $(SRC)
	norminette $(INC_PATH)*
