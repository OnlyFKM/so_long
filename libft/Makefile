# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 11:09:23 by frcastil          #+#    #+#              #
#    Updated: 2023/10/02 15:43:23 by frcastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = $(wildcard *.c)

BONUS = ft_lstnew_bonus.c\
    ft_lstadd_front_bonus.c\
    ft_lstsize_bonus.c\
    ft_lstlast_bonus.c\
    ft_lstadd_back_bonus.c\
    ft_lstdelone_bonus.c\
    ft_lstclear_bonus.c\
    ft_lstiter_bonus.c\
    ft_lstmap_bonus.c

OBJECTS = $(notdir $(FILES:.c=.o))

BONUS_OBJ = $(BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(FILES)
	@gcc $(FLAGS) -c $(FILES)

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJ)

fclean:
	@rm -f $(NAME) $(OBJECTS) $(BONUS_OBJ)

re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJ)
	@ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJ)

.PHONY: all bonus clean fclean re