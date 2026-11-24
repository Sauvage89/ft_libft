# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/05 14:02:03 by lensauva          #+#    #+#              #
#    Updated: 2026/11/24 15:34:17 by lensauva         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ================================ PROJET ==================================== #

NAME		:= libft.a
CC			:= cc

# ================================ FLAGS ==================================== #

CFLAGS		:= -Wall -Wextra -Werror
CINCLUDE	:= -MMD

# =============================== SOURCES ==================================== #

SRC_FILES	:= ft_is.c \
			   ft_strlen.c \
			   ft_bzero.c \
			   ft_mem.c \
			   ft_strl.c \
			   ft_toupper.c \
			   ft_tolower.c \
			   ft_strchr.c \
			   ft_strrchr.c \
			   ft_strncmp.c \
			   ft_strnstr.c \
			   ft_atoi.c \
			   ft_calloc.c \
			   ft_strdup.c \
			   ft_substr.c \
			   ft_strjoin.c \
			   ft_strtrim.c \
			   ft_split.c \
			   ft_itoa.c \
			   ft_strmapi.c \
			   ft_striteri.c \
			   ft_put.c \
			   ft_lst_1.c \
			   ft_lst_2.c

SRCS		:= $(SRC_FILES)
OBJS		:= $(SRCS:%.c=%.o)
DEPS		:= $(OBJS:%.o=%.d)

# ================================ REGLES ==================================== #

all: $(NAME)

$(NAME): $(OBJS) Makefile
	ar rcs -o $@ $(OBJS)

%.o: %.c Makefile
	$(CC) $(CFLAGS) $(CINCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
