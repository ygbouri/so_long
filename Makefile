# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 22:21:29 by ygbouri           #+#    #+#              #
#    Updated: 2022/04/08 03:43:44 by ygbouri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	so_long_manda/so_long.c\
		so_long_manda/so_long_utiles.c\
		so_long_manda/so_long_utiles1.c\
		so_long_manda/so_long_utiles2.c\
		so_long_manda/so_long_utiles3.c\
		so_long_manda/so_long_utiles4.c\
		so_long_manda/so_long_utiles5.c\
		so_long_manda/so_long_utiles6.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		
OBJ = $(SRC:.c=.o)

SRCB = so_long_bonus/so_long_bonus.c\
	   so_long_bonus/so_long_utiles_bonus.c\
	   so_long_bonus/so_long_utiles1_bonus.c\
	   so_long_bonus/so_long_utiles2_bonus.c\
	   so_long_bonus/so_long_utiles3_bonus.c\
	   so_long_bonus/so_long_utiles4_bonus.c\
	   so_long_bonus/so_long_utiles5_bonus.c\
	   so_long_bonus/so_long_utiles6_bonus.c\
	   so_long_bonus/ft_itoa.c\
	   get_next_line/get_next_line.c\
	   get_next_line/get_next_line_utils.c\

OBJB = $(SRCB:.c=.o)
CC = @gcc

NAME = so_long_manda/so_long
NAMEB = so_long_bonus/so_long_bonus
MLX = -framework OpenGL -framework AppKit 
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf/libftprintf.a
PRINTF_DIR = ft_printf/ 
HEADER = so_long_manda/so_long.h
HEADERB = so_long_bonus/so_long_bonus.h
all : $(NAME)

$(NAME) : $(OBJ) $(PRINTF) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -lmlx  $(MLX) -o $(NAME) -g
	@echo "done for so_long"

$(NAMEB) : $(OBJB) $(PRINTF) $(HEADERB)
	@$(CC) $(CFLAGS) $(OBJB) $(PRINTF) -lmlx  $(MLX) -o $(NAME) -g

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "done for PRINTF"

clean :
	@$(MAKE) clean -C $(PRINTF_DIR)
	@rm -rf $(OBJ)
	@rm -rf $(OBJB)
	@echo "clean"

fclean : clean
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@rm -rf $(NAME)
	@rm -rf $(NAMEB)

bonus : $(NAMEB)
	@$(CC) $(CFLAGS) $(OBJB) $(PRINTF) -lmlx  $(MLX) -o $(NAMEB) -g
	@echo "done for so_long"

re : fclean all

