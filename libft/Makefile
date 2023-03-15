NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -O3 -fPIE
FILES = \
	ft_atoi \
	ft_atod \
	ft_atouc \
	ft_itoa \
	ft_putnbr_fd \
	ft_strcpy \
	ft_strlcpy \
	ft_tolower \
	ft_bzero \
	ft_memchr \
	ft_putstr_fd \
	ft_strlen \
	ft_toupper \
	ft_calloc \
	ft_memcmp \
	ft_split \
	ft_strmapi \
	ft_isalnum \
	ft_memcpy \
	ft_strchr \
	ft_strncmp \
	ft_isalpha \
	ft_memmove \
	ft_strdup \
	ft_strnstr \
	ft_isascii \
	ft_memset \
	ft_striteri \
	ft_strrchr \
	ft_isdigit \
	ft_putchar_fd \
	ft_strjoin \
	ft_strtrim \
	ft_isprint \
	ft_putendl_fd \
	ft_strlcat \
	ft_substr \
	ft_lstnew \
	ft_lstadd_front \
	ft_lstsize \
	ft_lstlast \
	ft_lstadd_back \
	ft_lstdelone \
	ft_lstclear \
	ft_lstiter \
	ft_lstmap \
	get_next_line \

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

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
