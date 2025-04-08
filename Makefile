# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-cast <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 12:35:19 by pde-cast          #+#    #+#              #
#    Updated: 2025/04/07 12:44:14 by pde-cast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = cc

NAM_SERVER = server
SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

NAM_CLIENT = client
SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)


PRINTF = ft_printf

all:	deps $(OBJ_CLIENT) $(OBJ_SERVER) client server
	@echo "Server And Client Are Ready!"

deps:
	@make -C $(PRINTF) --no-print-directory # Compile ft_printf first
	@make -C libft  --no-print-directory # Compile ft_printf first

client:
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF)/libftprintf.a libft/libft.a -o $(NAM_CLIENT)  # Link the library

server:
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF)/libftprintf.a libft/libft.a -o $(NAM_SERVER)  # Link the library

clean:
	@make clean -C libft --no-print-directory
	@make clean -C $(PRINTF) --no-print-directory
	@rm -fr $(OBJ_CLIENT) $(OBJ_SERVER) 

fclean: clean
	@make fclean -C libft --no-print-directory
	@make fclean -C $(PRINTF) --no-print-directory
	@rm -f $(NAM_SERVER) $(NAM_CLIENT) 
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all

