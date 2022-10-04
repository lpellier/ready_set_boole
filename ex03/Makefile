NAME	=		ex03

SRCS	=		./main.cpp \
				./eval_formula.cpp

OBJS		=	$(SRCS:.c=.o)

CC			=	g++

CFLAGS		=	-Wall -Wextra -Werror -g3

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all			:	$(NAME)

fclean		:	
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all fclean re bonus
