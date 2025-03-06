SERVER_NAME			=	server
CLIENT_NAME			=	client
SERVER_NAME_BONUS	=	server_bonus
CLIENT_NAME_BONUS	=	client_bonus
HEADER				=	minitalk.h
CC					=	cc
CFLAGS				=	-g -Wall -Wextra -Werror
RM					=	rm -f

SRCS_SERVER			=	server.c utils.c
SRCS_CLIENT			=	client.c utils.c
SRCS_SERVER_BONUS	=	server_bonus.c utils.c
SRCS_CLIENT_BONUS	=	client_bonus.c utils.c

OBJS_SERVER			=	$(SRCS_SERVER:%.c=%.o)
OBJS_CLIENT			=	$(SRCS_CLIENT:%.c=%.o)
OBJS_SERVER_BONUS	=	$(SRCS_SERVER_BONUS:%.c=%.o)
OBJS_CLIENT_BONUS	=	$(SRCS_CLIENT_BONUS:%.c=%.o)

all:	$(SERVER_NAME) $(CLIENT_NAME)

bonus:	$(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

$(SERVER_NAME): $(OBJS_SERVER) $(HEADER)
	$(CC) $(OBJS_SERVER) $(CFLAGS) -o $(SERVER_NAME)

$(CLIENT_NAME): $(OBJS_CLIENT) $(HEADER)
	$(CC) $(OBJS_CLIENT) $(CFLAGS) -o $(CLIENT_NAME)

$(SERVER_NAME_BONUS): $(OBJS_SERVER_BONUS) $(HEADER)
	$(CC) $(OBJS_SERVER_BONUS) $(CFLAGS) -o $(SERVER_NAME_BONUS)

$(CLIENT_NAME_BONUS): $(OBJS_CLIENT_BONUS) $(HEADER)
	$(CC) $(OBJS_CLIENT_BONUS) $(CFLAGS) -o $(CLIENT_NAME_BONUS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
