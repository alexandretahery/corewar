/*
** asm.h for corwar in /home/tahery_b/rendu/CPE/CPE_2015_corewar
**
** Made by Tahery Alexandre
** Login   <tahery_b@epitech.net>
**
** Started on  Mon Aug  1 17:34:25 2016 Tahery Alexandre
** Last update Mon Sep  5 19:08:44 2016 jordan barbé
*/

#ifndef ASM_H_
# define ASM_H_

# define USAGE		"./asm .s\n"
# define ERROR_MALLOC	"Error: malloc failed \n"
# define ERROR_NAME	"Error : .name failed\n"
# define ERROR_COMMENT	"Error : .comment failed\n"
# define ERROR_MNEMO	"Error : mnemonique failed\n"
# define ERROR_NBR_ARG	"Error : Invalid nbr arg\n"
# define SUP_REG	"Error : Invalid registre\n"
# define ARG_LIVE	"Error : invalid arg for LIVE line : "
# define ARG_LD		"Error : invalid arg for LD line : "
# define ARG_LLD	"Error : invalid arg for LLD line : "
# define ARG_ST		"Error : invalid arg for ST line : "
# define ARG_ADD	"Error : invalid arg for ADD line : "
# define ARG_SUB	"Error : invalid arg for SUB line : "
# define ARG_ZJMP	"Error : invalid arg for ZJMP line : "
# define ARG_AND	"Error : invalid arg for AND line : "
# define ARG_OR		"Error : invalid arg for OR line : "
# define ARG_XOR	"Error : invalid arg for XOR line : "
# define ARG_LDI	"Error : invalid arg for LDI line : "
# define ARG_STI	"Error : invalid arg for STI line : "
# define ARG_AFF	"Error : invalid arg for AFF line : "
# define ARG_FORK	"Error : invalid arg for FORK line : "
# define CHECK_ERR	"There are : "
# define CHECK_ERR_NEXT	" Errors. \n"

# include "op.h"

typedef struct          s_asm
{
  int                   nbr_op;
  int			hexa;
  int			i;
  char			*name;
  char			*comment;
  char			*str;
}                       t_asm;

typedef struct		s_data
{
  header_t              head;
  int			fd;
  int			lines;
  char			**array;
  int			**array_cor;
  t_asm			in;
  char			octet;
  char			*argv;
  char			*file;
  int			i;
  int			c;
  int			save;
}			t_data;

void			my_putstr(char *);
int			check_check(char *);
int			my_strlen(char *);
int			my_puterror(char *);
int			my_strcmp(char *, char *);
int			reader(t_data *, char *);
char			*my_strcat(char *, char *);
int			my_power(int, int);
char			*my_strcpy(char *, char *);
char			*my_strdup(char *);
void			init_struct(t_data *);
int			process(t_data *, char *);
char			*the_strdup(char *, char);
int			coreheader(t_data *);
int			corewrite(t_data *);
int			my_power(int, int);
int			core_main(t_data *);
int			check_arg(char *, t_data *);
int			my_getnbr(char *);
int			stock_in_my_array(t_data*, int, int, int *);
int			remove_space_tab(char *, int);
void			count_octet(int **, t_data *);
void			my_putchar(char);
int			ld_live(t_data *, int);
int			ld(t_data *, int);
char			calc_hexa(int *);
int			*my_init_tab_1(int *);
int			st(t_data *, int);
void			write_hexa_head(t_data *, int);
int			add(t_data *, int);
int			and(t_data *, int);
int			or(t_data *, int);
int			lld(t_data *, int);
int			aff(t_data *, int);
int			zjmp(t_data *, int);
int			ldi(t_data *, int);
int			lldi(t_data *, int);
int			write_fork(t_data *, int);
int			sti(t_data *, int);
int			xor();
int			gest_err(t_data *);
int			ld_live_err(t_data *, int);
int			my_putnbr(int);
int			ld_err(t_data *, int);
int			add_err(t_data *, int);
int			sub_err(t_data *, int);
int			and_err(t_data *, int);
int			st_err(t_data *, int);
int			or_err(t_data *, int);
int			xor_err(t_data *, int);
int			zjmp_err(t_data *, int);
int			sti_err(t_data *, int);
int			print_err_full_r(t_data *, int, char *);
int			print_err_or_xor(t_data *, int, char *);
int			ldi_err(t_data *, int);
int			lld_err(t_data *, int);
int			lldi_err(t_data *, int);
int			aff_err(t_data *, int);
int			fork_err(t_data *, int);
int			check_2(char *, int);
char			calc_nbr_magic(t_data *);
int			check_case(t_data *, int);

#endif /* !ASM_H_ */
