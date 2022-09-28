NAME	=		ex01

SRCS	=		./main.cpp \
				./adder.cpp \
				./multiplier.cpp

OBJS		=	$(SRCS:.c=.o)

CC			=	g++

CFLAGS		=	-Wall -Wextra -Werror

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all			:	$(NAME)

fclean		:	
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all fclean re bonus
