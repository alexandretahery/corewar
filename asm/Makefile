##
## Makefile for my_ls in /home/tahery_b/rendu/PSU/PSU_2015_my_ls
##
## Made by Alexandre Tahery
## Login   <tahery_b@epitech.net>
##
## Started on  Wed Apr 27 22:16:06 2016 Alexandre Tahery
## Last update Mon Sep  5 19:08:54 2016 jordan barbé
##

NAME	= asm

SRC	= main.c \
	  reader.c\
	  base.c \
	  base_next.c \
	  base_next_next.c \
	  get_next_line.c \
	  process.c \
	  coreheader.c \
	  corewrite.c \
	  core_main.c \
	  op.c \
	  arg.c \
	  stock_array.c \
	  compt_octet.c \
	  live_ld.c \
	  st.c \
	  add.c \
	  and.c \
	  or.c \
	  sti.c \
	  lld.c \
	  ldi.c \
	  fork.c \
	  error.c \
	  error_next.c \
	  error_next_next.c \
	  error_next_next_next.c \
	  init_struct.c\
	  or_next.c \
	  check_2.c

OBJ	= $(SRC:.c=.o)

CFLAGS	+= -W -Wall -ansi -pedantic -I./include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
