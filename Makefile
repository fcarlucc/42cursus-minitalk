# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 14:09:06 by fcarlucc          #+#    #+#              #
#    Updated: 2023/05/26 14:19:34 by fcarlucc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_SOURCES	=	client.c
SERVER_SOURCES	=	server.c

CLIENT_OBJECTS	=	$(CLIENT_SOURCES:.c=.o)
SERVER_OBJECTS	=	$(SERVER_SOURCES:.c=.o)

NAME_CLIENT			=	client
NAME_SERVER			=	server

CC				=	gcc

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

%.o:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_CLIENT): $(CLIENT_OBJECTS)
				$(CC) $(CLIENT_OBJECTS) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_OBJECTS)
				$(CC) $(SERVER_OBJECTS) -o $(NAME_SERVER)

clean :
		$(RM) $(SERVER_OBJECTS) $(CLIENT_OBJECTS)
		
fclean : clean
		$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re : fclean all

.PHONY:			all clean fclean re