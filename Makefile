NAME = push_swap

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

SRCS = main.c struct_utils.c sort.c best_friend.c parsing.c operators.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT_A   = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF_A   = $(PRINTF_DIR)/libftprintf.a

INCLUDES = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)
LIBS = $(LIBFT_A) $(PRINTF_A)

BANNER = \
"\033[1;35m"\
"  _____           _        _____                       _____            _        \n"\
" |  __ \\         | |      / ____|                     / ____|          | |       \n"\
" | |__) |   _ ___| |__   | (_____      ____ _ _ __   | (___  _   _  ___| | _____ \n"\
" |  ___/ | | / __| '_ \\   \\___ \\ \\ /\\ / / _\` | '_ \\   \\___ \\| | | |/ __| |/ / __|\n"\
" | |   | |_| \\__ \\ | | |  ____) \\ V  V / (_| | |_) |  ____) | |_| | (__|   <\\__ \\\n"\
" |_|    \\__,_|___/_| |_| |_____/ \\_/\\_/ \\__,_| .__/  |_____/ \\__,_|\\___|_|\\_\\___/\n"\
"                                             | |                                 \n"\
"                                             |_|                                 \n"\
"\033[0m"

all: banner $(NAME)

banner:
	@echo $(BANNER)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(LIBFT_A) $(PRINTF_A) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re banner