# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjang <hjang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 18:04:40 by hjang             #+#    #+#              #
#    Updated: 2024/10/25 16:37:16 by hjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES1 = \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c

SOURCES2 = \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SOURCES = \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRCS = $(SOURCES1) $(SOURCES2)

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SOURCES:.c=.o)

BONUS_FLAG = .bonus_applied

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar crs $@ $^

bonus : $(NAME) $(BONUS_FLAG)

$(BONUS_FLAG) : $(OBJS_BONUS)
	ar crs $(NAME) $(OBJS_BONUS)
	touch $(BONUS_FLAG)

all : $(NAME)

clean :
	rm -f $(OBJS) $(OBJS_BONUS) $(BONUS_FLAG)

fclean : clean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re