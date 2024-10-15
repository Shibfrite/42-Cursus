CC	:= gcc
CFLAGS	:= -Wall -Wextra -Werror

NAME	:= libftprintf.a

HEAD	:= ft_printf.h
SRCS	:= ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strcmp.c ft_strlcpy.c ft_strrchr.c ft_bzero.c \
	   ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_calloc.c ft_isprint.c \
	   ft_memmove.c ft_putstr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c ft_isalnum.c ft_itoa.c ft_memset.c \
	   ft_split.c ft_strjoin.c ft_strncmp.c ft_tolower.c ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c \
	   ft_strlcat.c ft_strnstr.c ft_toupper.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	   ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_printf.c ft_putaddr.c ft_puthex.c \
	   ft_putchar.c ft_putstr.c ft_putnbr.c ft_putbase.c 
OBJS	:= $(SRCS:.c=.o)

B_SRCS	:= ft_printf.c 
B_OBJS	:= $(B_SRCS:.c=.o)

RM	:= rm -f
AR	:= ar -rc

all:	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -I. -include $(HEAD) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^
	ranlib $@

bonus: $(OBJS) $(B_OBJS)
	$(AR) $(NAME) $^
	ranlib $(NAME)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
