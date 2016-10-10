##
## Makefile for make in /home/barbe_j/rendu/CPE_2015_corewar
## 
## Made by jordan barbé
## Login   <barbe_j@epitech.net>
## 
## Started on  Sun Aug 28 20:08:51 2016 jordan barbé
## Last update Sun Aug 28 20:14:57 2016 jordan barbé
##

ASM	=	./asm

MAKE	=	make -C

all:
		$(MAKE) $(ASM)

clean:
		$(MAKE) $(ASM) clean

fclean:
		$(MAKE) $(ASM) fclean

re:		fclean all

.PHONY:		re all fclean clean
