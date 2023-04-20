NAME = libftprintf.a

SRCS = ft_printf.c \
		

AR = ar rcs

OBJS =	${SRCS:.c=.o}


CC =	cc

CFLAGS	=	-Wall -Wextra -Werror -g3 #-fsanitize=address

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -Ilibft

$(NAME): ${OBJS}
		$(MAKE) -C libft
		$(AR) $(NAME) ${OBJS}
		
compile: $(OBJS)
		$(MAKE) -C libft
		$(CC) $(CFLAGS) -o a.out $(OBJS) libft/libft.a -Ilibft

all:	${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re