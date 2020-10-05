/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:29:46 by mdavid            #+#    #+#             */
/*   Updated: 2020/09/02 16:30:16 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"

/*
** Function: unique_opt
** Description:
**	Verifies if the option flag does not appears already previously.
** Return:
**	1: if the option flag is unique
**	0: if we already encounter the option flag
*/

static int		unique_opt(t_parse *p, char *str)
{
	int		stat;

	stat = 2;
	if (ft_strequ(str, "-dump") == 1)
		return (stat = (p->options->dump == true) ? 0 : 1);
	if (ft_strequ(str, "-a") == 1)
		return (stat = (p->options->aff == true) ? 0 : 1);
	if (ft_strequ(str, "-v") == 1)
		return (stat = (p->options->verbose == true) ? 0 : 1);
	if (ft_strequ(str, "-SDL") == 1)
		return (stat = (p->options->sdl == true) ? 0 : 1);
	if (ft_strequ(str, "-m") == 1)
		return (stat = (p->options->music == true) ? 0 : 1);
	return (stat);
}

/*
** Function: is_options_flag
** Description:
**	Verifies if the specific argument (av) is an authorized flag.
** Return:
**	true: if flag is correct
**	false: otherwise
*/

static bool		is_options_flag(char *av)
{
	if (ft_strequ(av, "-dump") || ft_strequ(av, "-v")
		|| ft_strequ(av, "-a") || ft_strequ(av, "-SDL")
		|| ft_strequ(av, "-m"))
		return (true);
	return (false);
}

/*
** Function: vm_options_flag2
** Description:
**	Second part of vm_options_flag.
**	Here it's check if argument is the verbose, the music or the visualizer.
** Return:
**	0: if no error encounter.
**	CD_[ERROR]: the associate error code.
*/

static int		vm_options_flag2(char **av, t_parse **p, int *i)
{
	if (av[*i] && ((*p)->options->verbose = ft_strequ(av[*i], "-v")) == 1)
	{
		if (av[++(*i)] && in_verbose_range(av[*i]))
			(*p)->options->v_lvl = (u_int8_t)ft_atoi(av[(*i)++]);
		else
			return ((int)CD_VERB);
	}
	if (av[*i] && ft_strequ(av[*i], "-m") == 1)
	{
		if (av[++(*i)] && ft_strequ(av[(*i)++], "on") == 1)
			(*p)->options->music = true;
		else
			return ((int)CD_MUSIC);
	}
	if (av[*i] && ft_strequ(av[*i], "-SDL") == 1)
	{
		(*i)++;
		(*p)->options->sdl = true;
	}
	if (unique_opt(*p, av[*i]) == 0)
		return ((int)CD_UNIQ);
	return (0);
}

/*
** Function:
** Description:
**	Checks the presence of option flags and their arguments. It stocks the
**	setting of options and option arguments in p->options.
**	The first argument option invalid brings a return of the associated CODE
**	ERROR.
** Return:
**		0: if all present option flags and arguments are valid.
**		CODE ERROR: if the option argument is invalid.
*/

int				vm_options_flag1(char **av, t_parse **p, int *i)
{
	int		code_error;

	code_error = 0;
	while (av[*i] && is_options_flag(av[*i]))
	{
		if (av[*i] && ft_strequ(av[*i], "-a") == 1)
		{
			(*i)++;
			(*p)->options->aff = true;
		}
		if (is_dump_option(av[*i], *p) == 1)
		{
			if (av[++(*i)] && ft_is_positive_int(av[*i]) != -1)
				(*p)->options->dump_cycle = ft_atoi(av[(*i)++]);
			else
				return ((int)CD_DUMP);
		}
		if ((code_error = vm_options_flag2(av, p, i)) != 0)
			return (code_error);
	}
	return (0);
}

/*
** Function: vm_parsing
** Description:
**	Parsing of the standard inputs of the executable corewar (the VM)
**	the informations are stored in the structure p of type t_parse.
**	Notice that we just verified the validity of the arguments on the stdin
**	and not the validity of the bytecode files (which is performed later).
** Return:
**	0: No error has been risen
**	CD_ERROR: code error specific to the first detected error.
*/

int				vm_parsing(char **av, t_parse **p)
{
	int		i;
	int		code_error;

	i = 1;
	if ((code_error = vm_options_flag1(av, p, &i)) != 0)
		return (vm_error_manager(code_error, p, NULL));
	while (av[i] && (*p)->nb_champ < 5)
	{
		if (id_number_chp_flag(p, av, &i) == 0)
			return (vm_error_manager((int)CD_BD_VAL, p, NULL));
		if (av[i] && !is_valid_champ_filename(av[i]))
			return (vm_error_manager((int)CD_BD_FILE, p, NULL));
		if (av[i] && (code_error = vm_create_champion(&((*p)->lst_champs), \
			av[i++], *p)))
			return (vm_error_manager(code_error, p, NULL));
	}
	if ((*p)->nb_champ == 0)
		return (vm_error_manager((int)CD_EMPTY_CHP, p, NULL));
	if ((*p)->nb_champ > (int)MAX_PLAYERS)
		return (vm_error_manager((int)CD_MAX_CHAMP, p, NULL));
	return (0);
}
