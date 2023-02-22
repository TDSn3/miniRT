NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
OBJS = \
	ft_atoi.o \
	ft_itoa.o \
	ft_putnbr_fd.o \
	ft_strcpy.o \
	ft_strlcpy.o \
	ft_tolower.o \
	ft_bzero.o \
	ft_memchr.o \
	ft_putstr_fd.o \
	ft_strlen.o \
	ft_toupper.o \
	ft_calloc.o \
	ft_memcmp.o \
	ft_split.o \
	ft_strmapi.o \
	ft_isalnum.o \
	ft_memcpy.o \
	ft_strchr.o \
	ft_strncmp.o \
	ft_isalpha.o \
	ft_memmove.o \
	ft_strdup.o \
	ft_strnstr.o \
	ft_isascii.o \
	ft_memset.o \
	ft_striteri.o \
	ft_strrchr.o \
	ft_isdigit.o \
	ft_putchar_fd.o \
	ft_strjoin.o \
	ft_strtrim.o \
	ft_isprint.o \
	ft_putendl_fd.o \
	ft_strlcat.o \
	ft_substr.o \
	ft_lstnew.o \
	ft_lstadd_front.o \
	ft_lstsize.o \
	ft_lstlast.o \
	ft_lstadd_back.o \
	ft_lstdelone.o \
	ft_lstclear.o \
	ft_lstiter.o \
	ft_lstmap.o \
	get_next_line.o \

all: $(NAME)

$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

.PHONY: clean fclean re
