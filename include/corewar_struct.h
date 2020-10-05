/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:16:11 by mdavid            #+#    #+#             */
/*   Updated: 2020/09/04 15:43:28 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_STRUCT_H
# define COREWAR_STRUCT_H

/*
** fichiers entête externes à Corewar
*/
# include <stdbool.h>

/*
** fichiers entête internes à Corewar
*/
# include "../libft/include/libft.h"

/*
** fichier entête du sujet corewar (ressources) + structure op
*/

# include "op_and_op_struct.h"

/*
** Définition des structures de la partie vm (parsing etc...)
*/

typedef struct		s_color_champ
{
	size_t			start;
	size_t			end;
}					t_color_champ;

typedef struct		s_options
{
	bool			dump;
	int				dump_cycle;
	bool			n;
	bool			aff;
	bool			sdl;
	bool			music;
	bool			verbose;
	int				v_p;
	u_int8_t		v_lvl;
}					t_options;

typedef struct		s_arg
{
	int				type[3];
	int				arg[3];
	int				widht;
}					t_arg;

typedef struct		s_champ
{
	int				id;
	char			*champ_file;
	char			*name;
	char			*comment;
	int				l_bytecode;
	char			*bytecode;
	int				mem_pos;
}					t_champ;

typedef struct		s_parse
{
	int				nb_champ;
	int				id_champ;
	int				*id_available;
	t_options		*options;
	t_list			*lst_champs;
	char			**error;
}					t_parse;

typedef struct		s_process
{
	int				id;
	bool			carry;
	int				opcode;
	int				n_lives;
	int				last_live;
	int				wait_cycles;
	int				i;
	int				pc;
	int				*registers;
	t_champ			*champ;
}					t_process;

typedef struct		s_corewar
{
	t_op			*op_tab;
	char			*arena;
	int				*id_arena;
	t_list			*process;
	int				n_champ;
	int				champ_lives[4];
	t_list			*lst_champs;
	int				i_cycle;
	int				cycle_to_die;
	int				tot_lives;
	int				ctd_lives;
	int				i_check;
	int				tot_cycle;
	int				last_champ;
	t_options		*options;
}					t_cw;

#endif
