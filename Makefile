# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 16:16:34 by mgrandia          #+#    #+#              #
#    Updated: 2025/03/08 20:53:34 by mgrandia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror -g

INC = -I./

SRC = $(wildcard *.c)

OBJDIR = obj

OBJS = $(SRC:%.c=$(OBJDIR)/%.o)

LIBFT = ./Libft/libft.a  # Asegúrate de que esta ruta sea correcta

# Ejecuta make en la carpeta Libft antes de crear libftprintf.a
all: $(LIBFT) $(NAME)

# Regla para compilar la librería Libft
$(LIBFT):
	make -C ./Libft

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(FLAGS) -c $< -I $(INC) -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS)
	make -C ./Libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./Libft fclean
	
re: fclean all

.PHONY: all clean fclean re

