NAME	= maze

SOURCE_DIR	=	src/
SOURCES		=	$(addprefix $(SOURCE_DIR), \
					app_cleanup.c \
					app_execute.c \
					app_init.c \
					app_loop.c \
					app_log.c \
					app_on_event.c \
					app_render.c \
					main.c \
				)
OBJECT_DIR	=	obj/
OBJECTS		=	$(patsubst $(SOURCE_DIR)%.c,$(OBJECT_DIR)%.o, $(SOURCES))

CFLAGS		:=	-Wall -Wextra -Werror
IFLAGS		:=	-Iinclude
LFLAGS		:=	-lSDL2


all:
	@echo 'Choose your OS:'
	@echo ' - windows'
	@echo ' - linux'

windows: $(NAME).exe

linux: $(NAME)

$(NAME).exe: $(SOURCES)
	gcc $(CFLAGS) $(IFLAGS) -o $@ $(SOURCES) $(LFLAGS)

$(NAME): $(OBJECTS)
	gcc $(CFLAGS) $(IFLAGS) -o $@ $(OBJECTS) $(LFLAGS)

$(OBJECT_DIR)%.o:	$(SOURCE_DIR)%.c | $(OBJECT_DIR)
	gcc $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(OBJECT_DIR):
	mkdir $@

clean:
	rm -rf $(OBJECT_DIR)

fclean:	clean
	rm -f $(NAME) $(NAME).exe

re:	fclean
	@make --no-print-directory all
