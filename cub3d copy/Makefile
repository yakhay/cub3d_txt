# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 13:59:19 by yakhay            #+#    #+#              #
#    Updated: 2023/08/07 18:21:53 by yakhay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = get_next_line.c get_next_line_utils.c main.c move.c calcul_ray_x.c calcul_ray_y.c
OBJS = $(SRCS:.c=.o)
OBJB = $(BONUS:.c=.o)


RM				= rm -f
CFLAGS			=  -Wall -Wextra -Werror -fsanitize=address -g3 #

NAME			= CUB3D



all:			$(NAME)


$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(SRCS) ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
				$(RM) $(OBJS) $(OBJB)

fclean:			clean
				$(RM) $(NAME) $(NAME2)

re:				fclean $(NAME)



.PHONY:			all clean fclean re
