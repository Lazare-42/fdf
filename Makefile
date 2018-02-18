NAME = fdf

SOURCES = camera_move.c \
		  main.c \
		  matrix.c \
		  parsing.c \
		  screen_management.c \
		  center_matrix.c \


LIBDIR = libft
MINILIBXDIR = minilibx_macos
SDIR = srcs
ODIR = bin
CFLAGS = -Wall -Wextra -Werror
INCDIR = includes
LDFLAGS = -L$(LIBDIR) -lft -L$(MINILIBXDIR) -lmlx -framework AppKit -framework OpenGL
LNCURSES = -lncurses
CC = clang
SRCS = $(addprefix $(SDIR)/, $(SOURCES:.c=.c))
OBJS = $(addprefix $(ODIR)/, $(SOURCES:.c=.o))
OK = echo "[32m OK ✓ [0m"

all: lib mkbin $(NAME)

lib:
	@echo "Archiving libft ..."
	@make -C $(LIBDIR)
	@$(OK)

mkbin:
	@mkdir -p $(ODIR)


$(NAME): $(OBJS)
	@ echo "[35m Compiling FDF...[0m"
	@$(CC) $(CFLAGS)  -o $(NAME) $(OBJS) -I$(INCDIR) $(LDFLAGS) $(LNCURSES)
	@$(OK)

$(ODIR)/%.o : $(SDIR)/%.c
	@ echo "[34m Assembling FDF object: [0m" $@
	@ $(CC) $(CFLAGS) -c -o $@ $< -I$(INCDIR)

clean:
	@ echo "[31m Cleaning FDF... [0m"
	@/bin/rm -rf $(ODIR)
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
