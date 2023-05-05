NAME = libftprintf.a

LIBFT = libft.a

LIBDIR = ./libft/

SRCS = ft_printf.c \
		ft_putmemory.c \
		utils_1.c \
		ft_putx.c \
		ft_point.c \
		ft_cspdi.c \
		ft_uxpe.c \
		ft_zspace.c \

AR = ar rcs

OBJS =	${SRCS:.c=.o}


CC =	cc

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -Ilibft

$(NAME): ${OBJS}
		cd ./libft && $(MAKE) && cp -v ${LIBFT} ../${NAME}
		$(AR) $(NAME) ${OBJS} 
		
bonus : $(NAME)

compile: $(OBJS)
		$(MAKE) -C libft
		$(CC) $(CFLAGS) -o a.out $(OBJS) libft/libft.a -Ilibft

all:	${NAME}

clean:
		rm -f ${OBJS}
		cd ${LIBDIR} && ${MAKE} clean

fclean:	clean
		rm -f ${NAME}
		cd ${LIBDIR} && ${MAKE} fclean

re:	fclean all

.PHONY: all clean fclean re