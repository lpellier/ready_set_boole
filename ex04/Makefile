NAME	=		ex04

SRCS	=		./main.cpp \
				./eval_formula.cpp \
				./truth_table.cpp

OBJS		=	$(SRCS:.c=.o)

CC			=	g++

CFLAGS		=	-Wall -Wextra -Werror -g3

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all			:	$(NAME)

fclean		:	
				rm -rf $(NAME) *.dSYM

re			:	fclean all

.PHONY		:	all fclean re bonus
