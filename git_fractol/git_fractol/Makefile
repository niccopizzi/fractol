CFLAGS =  -g -Wall -Wextra -Werror

NAME = fractol

LIB = -lmlx -lX11 -lXext -lm libft.a 

MY_SOURCES = init.c \
			hooks.c \
			utils.c \
			./fractals/mandelbrot.c \
			./fractals/julia.c \
			./fractals/burning_ship.c	 

all: $(NAME)

$(NAME): $(MY_SOURCES)
	@cc $(CFLAGS) $(MY_SOURCES) -o $(NAME) $(LIB)
	@echo "... Amazing! I managed to compile fractol"

%.o :%.c
	@cc $(CFLAGS) -g -c $< -o $@ 
	@echo "$< compiled."

clean:
	@$(RM) $(MY_OBJECTS)
	@echo "Objects files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re bonus