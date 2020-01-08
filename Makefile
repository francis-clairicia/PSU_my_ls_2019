##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

MAIN		=	main.c

SRC_DIR		=	src

SRC_TEST	=	$(SRC_DIR)/my_ls.c					\
				$(SRC_DIR)/print_file.c				\
				$(SRC_DIR)/print_dir_content.c		\
				$(SRC_DIR)/print_long_format.c		\
				$(SRC_DIR)/print_infos.c			\
				$(SRC_DIR)/print_permissions.c		\
				$(SRC_DIR)/print_user_group.c		\
				$(SRC_DIR)/print_major_minor.c		\
				$(SRC_DIR)/print_time.c				\
				$(SRC_DIR)/print_error.c			\
				$(SRC_DIR)/get_flags.c				\
				$(SRC_DIR)/get_files_and_folders.c	\
				$(SRC_DIR)/get_file_infos.c			\
				$(SRC_DIR)/get_files_from_dir.c		\
				$(SRC_DIR)/free_files_list.c		\
				$(SRC_DIR)/get_padding.c			\
				$(SRC_DIR)/sort_files.c				\
				$(SRC_DIR)/sorting_methods.c		\
				$(SRC_DIR)/join_path.c				\
				$(SRC_DIR)/set_up_list.c

SRC			=	$(SRC_TEST)

CFLAGS		=	-I./include/ -Wall -Wextra

LIB			=	-L./lib -lmy

OBJ			=	$(MAIN:.c=.o) $(SRC:.c=.o)

NAME		=	my_ls

all:	$(NAME)

lib:
	make -s -C ./lib/my

$(NAME):	lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB)
	rm -f $(OBJ)

tests_run:	lib
	@find . -name "*.gc*" -delete
	gcc -o unit_tests $(SRC_TEST) tests/*.c $(LIB) $(CFLAGS) --coverage -lcriterion
	./unit_tests
	rm -f unit_tests test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

debug:	lib
	gcc -g -o $(NAME) $(MAIN) $(SRC) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f unit_tests *.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all lib tests_run debug clean fclean re
