# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 14:34:23 by miduarte          #+#    #+#              #
#    Updated: 2025/06/16 12:23:42 by miduarte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = push_swap

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

SRCS = main.c struct_utils.c small_sorts.c parsing.c operators.c radix_sort.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT_A   = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(LIBFT_DIR)
LIBS = $(LIBFT_A)
BANNER = \
"\033[1;35m"\
"  _____           _        _____                       _____            _        \n"\
" |  __ \\         | |      / ____|                     / ____|          | |       \n"\
" | |__) |   _ ___| |__   | (_____      ____ _ _ __   | (___  _   _  ___| | _____ \n"\
" |  ___/ | | / __| '_ \\   \\___ \\ \\ /\\ / / _\` | '_ \\   \\___ \\| | | |/ __| |/ / __|\n"\
" | |   | |_| \\__ \\ | | |  ____) \\ V  V / (_| | |_) |  ____) | |_| | (__|   <\\__ \\ \n"\
" |_|    \\__,_|___/_| |_| |_____/ \\_/\\_/ \\__,_| .__/  |_____/ \\__,_|\\___|_|\\_\\___/\n"\
"                                             | |                                 \n"\
"                                             |_|                                 \n"\
"\033[0m"

all: banner $(NAME)

banner:
	@echo $(BANNER)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT_A) $(PRINTF_A) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re banner