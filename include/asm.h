/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:49:57 by yaye              #+#    #+#             */
/*   Updated: 2020/09/04 14:29:16 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

/*
** >------------------------------ HEADER FILES ------------------------------<
*/
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

/*
** fichier entête du sujet corewar (ressources) + structure op
*/
# include "op_and_op_struct.h"

/*
** >----------------------- ASM STRUCTURES AND DEFINE -----------------------<
*/

# define NAME_SIZE 4096
# define COR_MAX 2874

typedef struct	s_ope
{
	int			i_op;
	int			i_encod;
	size_t		encoded;
	size_t		p_encod;
	size_t		n_arg;
}				t_ope;

typedef struct	s_lb
{
	char		*lb;
	size_t		byte_size;
	int			i_op;
	int			i_call;
	size_t		line;
	struct s_lb	*next;
}				t_lb;

typedef struct	s_asm
{
	t_op		*op_tab;
	char		*chp;
	char		cor[COR_MAX];
	int			i;
	int			size;
	t_lb		*ldef;
	t_lb		*lcall;
	int			name;
	int			comm;
	size_t		line;
}				t_asm;

/*
** >-------------------------------- FUNCTIONS -------------------------------<
*/

void			ft_putnb(size_t n);
void			release(t_asm *a);
void			leave(t_asm *a, char *s, size_t col);
void			asto_bi(t_asm *a, int *i, int c, int bytes);
size_t			is_endline(t_asm *a, char *s);
size_t			is_opline(t_asm *a, char *s);
size_t			check_args(t_asm *a, char *s, size_t op);
void			get_labeldef(t_asm *a, char *s, size_t len);
size_t			get_labelcall(t_asm *a, char *s, size_t byte_size, t_ope *ope);
void			get_cor(t_asm *a);

#endif
