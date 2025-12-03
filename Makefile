NAME = libftprintf.a

SRCS =	ft_printf.c ft_printf_csp.c ft_printf_idu.c ft_printf_helper.c \
		ft_printf_xX.c ft_printf_helper2.c

OBJS = $(SRCS:.c=.o)

LIBFT_OBJS =  $(shell ar t ./libft/libft.a)

OBJS_BONUS = $(SRCS:.c=.o)

INC_DIR = includes

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) libft.a
	ar x ./libft/libft.a 
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

libft.a:
	$(MAKE) -C libft libft.a

bonus: all

.bonus: $(NAME)
	@touch .bonus
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $(LIBFT_OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus