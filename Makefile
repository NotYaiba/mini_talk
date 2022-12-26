SRCS = server.c\
		tools.c\
		tools2.c\

SRCSB =	client.c\
		tools.c\
		tools2.c\

SRCSBONUS = server_bonus.c\
		tools.c\
		tools2.c\

SRCCBONUS =	client_bonus.c\
		tools.c\
		tools2.c\

OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}

OBJSBONUS = ${SRCSBONUS:.c=.o}
OBJSCBONUS = ${SRCCBONUS:.c=.o}

NAME = server
NAMEB = client

NAMEBONUS = server_bonus
NAMECBONUS = client_bonus

FLAGS = -Wall -Wextra -Werror


all :  $(NAME) $(NAMEB)

bonus : $(NAMEBONUS) $(NAMECBONUS)

$(NAME) : ${OBJS}
		@gcc $(FLAGS)  ${OBJS} -g -o$(NAME)
$(NAMEB) : ${OBJSB}
		@gcc $(FLAGS) ${OBJSB} -g -o$(NAMEB)

$(NAMEBONUS) : $(OBJSBONUS)
		@gcc $(FLAGS) ${OBJSBONUS} -g -o$(NAMEBONUS)

$(NAMECBONUS) : ${OBJSCBONUS}
		@gcc  $(FLAGS) ${OBJSCBONUS} -g -o$(NAMECBONUS)

clean :
		@rm -f ${OBJS}
		@rm -f ${OBJSB}
		@rm -f ${OBJSBONUS}
		@rm -f ${OBJSCBONUS}

fclean : clean
		@rm -f $(NAME) $(NAMEB) $(NAMEBONUS) $(NAMECBONUS)
re : fclean
		make all
