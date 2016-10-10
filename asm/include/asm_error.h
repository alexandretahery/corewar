/*
** asm_error.h for error in /home/barbe_j/rendu/CPE_2015_corewar/v2
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Sat Aug 27 15:27:24 2016 jordan barbé
** Last update Sat Aug 27 17:06:08 2016 jordan barbé
*/

#ifndef ASM_ERROR_H_
# define ASM_ERROR_H_

# include <stdlib.h>
# include "asm.h"

static int      (*ptr_err[17])(t_data *, int) =
{
  ld_live_err,
  ld_err,
  st_err,
  add_err,
  sub_err,
  and_err,
  or_err,
  xor_err,
  zjmp_err,
  ldi_err,
  sti_err,
  fork_err,
  lld_err,
  lldi_err,
  lldi_err,
  aff_err,
  NULL
};

#endif /* !ASM_ERROR_H_ */
