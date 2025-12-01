NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

MAIN_SRCS = ft_hexa.c \
	   ft_negnum.c \
	   ft_numlen.c \
	   ft_padding.c \
	   ft_printf.c \
	   ft_putchar.c \
	   ft_putnbr.c \
	   ft_putstr.c \
	   ft_putunbr.c \
	   ft_reset.c \
	   ft_strlen.c \
	   ft_toupper.c

BONUS_SRCS = ft_typechar.c \
			 ft_typehexa.c \
			 ft_typeint.c \
			 ft_typestring.c \
			 ft_typeunsint.c \
			 ft_typevoid.c \
			 ft_choseflags.c \
			 ft_putsign.c \
			 ft_prefix.c

MAIN_OBJS = $(MAIN_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ALL_OBJS = $(MAIN_OBJS) $(BONUS_OBJS)

all: $(NAME)

$(NAME): $(ALL_OBJS)
	$(AR) $(NAME) $(ALL_OBJS)

bonus: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ALL_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus