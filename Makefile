# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mangarci <mangarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 10:18:07 by mangarci          #+#    #+#              #
#    Updated: 2021/11/09 10:35:21 by mangarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
#CFLAGS = -Wall -Werror -Wextra
LM = -lm 
RM = rm -rfv
DEBUG_FLAG = -g 
SRCS_DIR = srcs/
SRCS = $(wildcard $(SRCS_DIR)*.c)
BONUS_DIR = srcs_bonus/
SRCS_BONUS = $(wildcard $(BONUS_DIR)*.c)
OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
LIBFT_PATH = lib/libft 
LIBFT_LIB = -L$(LIBFT_PATH) $(LIBFT_PATH)/libft.a
GNL = lib/get_next_line/*.c 
MINILIBX = -lmlx -framework OpenGL -framework AppKit

all:	libft $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(GNL) $(OBJS) -o $(NAME) $(MINILIBX) $(LM) $(LIBFT_LIB)

$(%.o): $(%.c)
				$(CC) -c $^-o $@
				@echo "Creating objects"

bonus:	libft $(OBJS_BONUS)
		$(CC) $(CFLAGS) $(GNL) $(OBJS_BONUS) -o $(NAME) $(MINILIBX) $(LM) $(LIBFT_LIB)

libft:
				make -C $(LIBFT_PATH)
				
debug:	$(OBJS)
		$(CC) $(DEBUG_FLAG) $(LM) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				@echo "Removing objects"
				$(RM) $(OBJS) $(OBJS_BONUS)
				
fclean:
				make clean
				cd lib/libft && $(MAKE) fclean
				$(RM) $(NAME)

re:
		make fclean all
		@echo "All files has been deleted and recompiled"
		
.PHONY: clean fclean all re objects debug bonus libft