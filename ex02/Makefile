NAME	=		ex02

SRCS	=		./main.cpp \
				./gray_code.cpp

OBJS		=	$(SRCS:.c=.o)

CC			=	g++

CFLAGS		=	-Wall -Wextra -Werror

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all			:	$(NAME)

fclean		:	
				rm -rf $(NAME) *.dSYM

re			:	fclean all

.PHONY		:	all fclean re bonus
