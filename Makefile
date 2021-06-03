NAME = miniRT
FLAGS = -Wall -Wextra -Werror
SRCS_C = main.c\
		 parsing/string.c\
		 parsing/atoi.c\
		 parsing/list.c\
		 parsing/set_list.c\
		 parsing/error.c\
		 parsing/split.c\
		 parsing/check.c\
		 parsing/element_1.c\
	   	 parsing/element_2.c\
		 gnl/get_next_line.c\
		 gnl/get_next_line_utils.c\
		 rendering/set_image.c\
		 rendering/set_object.c\
		 rendering/create.c\
		 rendering/vec.c
SRCS = $(addprefix src/, $(SRCS_C))

OBJS = $(SRCS:.c=.o)
.c.o :
	gcc $(FLAGS) -c $< -o $@ -I include

$(NAME) : $(OBJS)
	@gcc $(FLAGS) -L./mlx -lmlx -framework OpenGL -framework Appkit $(OBJS) -o $(NAME)
all : $(NAME)

clean :
	rm -rf $(OBJS)
fclean :	clean
	rm -rf $(NAME)
re :	fclean all

.PHONY : all clean fclean re
