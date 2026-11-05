# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/05 14:02:03 by lensauva          #+#    #+#              #
#    Updated: 2026/11/05 15:24:17 by lensauva         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ================================ PROJET ==================================== #

NAME		:= libft.a
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

# ============================== DOSSIERS ==================================== #

SRC_DIR		:= src
OBJ_DIR		:= obj
INC_DIR		:= include

# =============================== SOURCES ==================================== #

SRC_FILES	:= ft_isalpha.c \
			   ft_isdigit.c \
			   ft_isalnum.c \
			   ft_isascii.c \
			   ft_isprint.c \
			   ft_strlen.c \
			   ft_memset.c \
			   ft_bzero.c \
			   ft_memmove.c \
			   ft_memcpy.c \
			   ft_strlcpy.c \
			   ft_strlcat.c \
			   ft_toupper.c \
			   ft_tolower.c \
			   ft_strchr.c \
			   ft_strrchr.c \
			   ft_strncmp.c \
			   ft_memchr.c \
			   ft_memcmp.c \
			   ft_strnstr.c \
			   ft_atoi.c \
			   ft_calloc.c \
			   ft_strdup.c

SRCS		:= $(SRC_FILES)
OBJS		:= $(SRCS:%.c=%.o)
DEPS		:= $(OBJS:.o=.d)

# ================================ FLAGS ===================================== #

# -MMD : génère un .d (liste des headers utilisés) à côté de chaque .o
# -MP  : ajoute une cible vide par header (évite l'erreur si un header est supprimé)
CPPFLAGS	:= -I$(INC_DIR) -MMD -MP

# ================================ REGLES ==================================== #

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs -o $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
