SERVER_NAME = server
SERVER_SRCS = server_srcs/main.c server_srcs/utils.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_NAME = client
CLIENT_SRCS = client_srcs/main.c client_srcs/parsing.c client_srcs/send.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_NAME_BONUS = server_bonus
CLIENT_NAME_BONUS = client_bonus
SERVER_SRCS_BONUS = bonus/server_srcs/main_bonus.c bonus/server_srcs/utils_bonus.c
SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_SRCS_BONUS = bonus/client_srcs/main_bonus.c bonus/client_srcs/parsing_bonus.c bonus/client_srcs/send_bonus.c
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Ilibft
LIBFT = libft/
MAKE = make -C
LIBFTFLAGS = -Llibft -lft 
LIB = libft/libft.a

ifdef WITH_BONUS
SERVER_SRCS = $(SERVER_SRCS_BONUS)
CLIENT_SRCS = $(CLIENT_SRCS_BONUS)
endif

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS) $(LIB) 
	$(CC) $(CFLAGS) $(SERVER_SRCS) $(LIBFTFLAGS) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIB) 
	$(CC) $(CFLAGS) $(CLIENT_SRCS) $(LIBFTFLAGS) -o $(CLIENT_NAME)

.c.o:
	$(CC) $(CFLAGS) $< -c -o $@

$(LIB):
	$(MAKE) $(LIBFT)

clean:
	$(MAKE) $(LIBFT) clean
	rm -f $(SERVER_OBJS)
	rm -f $(CLIENT_OBJS)
	rm -f $(SERVER_OBJS_BONUS)
	rm -f $(CLIENT_OBJS_BONUS)

fclean: clean
	$(MAKE) $(LIBFT) fclean
	rm -f $(SERVER_NAME)
	rm -f $(CLIENT_NAME)

re: fclean all

bonus:
	make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus
