/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_parsing_champ_code.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:44:39 by mdavid            #+#    #+#             */
/*   Updated: 2020/09/05 01:10:28 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "vm.h"

/*
** Function: vm_champ_file_parse
** Description:
**	[put some description here]
** Return:
**	0: success in getting magic_key, name, comment and bytecode
**	   of the current champion.
**	1: otherwise
*/

static int		vm_champ_file_parse(t_champ *ichamp, t_parse **p)
{
	int			magic_key;
	int			fd;

	if ((fd = open(ichamp->champ_file, O_RDONLY)) <= 2)
		return (vm_error_manager((int)CD_INV_FD, p, NULL));
	magic_key = get_champ_magic_key(fd);
	if (magic_key - (int)(COREWAR_EXEC_MAGIC) != 0)
		return (vm_error_manager((int)CD_MAGIC_EXEC, p, NULL));
	ichamp->name = get_champ_name(fd);
	if ((ichamp->l_bytecode = get_champ_l_bcode(fd)) > (int)CHAMP_MAX_SIZE
		|| ichamp->l_bytecode < 0)
	{
		ichamp->l_bytecode < 0 ? ft_printf("Error: corrupted .cor file.\n") :
			ft_printf("Error: File %s has too large code (%d > %d).\n", \
			ichamp->name, ichamp->l_bytecode, (int)CHAMP_MAX_SIZE);
		return (vm_error_manager((int)CD_CHP_SIZ, p, NULL));
	}
	ichamp->comment = get_champ_comment(fd);
	ichamp->bytecode = get_champ_bcode(fd, ichamp->l_bytecode);
	ichamp->mem_pos = 0;
	close(fd);
	if (!(ichamp->name) || !(ichamp->comment) || !(ichamp->bytecode))
		return (vm_error_manager((int)CD_CHP_ERR, p, NULL));
	return (0);
}

/*
** Function: vm_champ_code_parse
** Description:
**	Parsing of the champions bytecode, this part couple the parsing and basics
**	tests on the contains of the files.
** Return:
**	0: If parsing of champion is fine.
**	CODE_ERROR: otherwise.
*/

int				vm_champ_parse(t_list **lst_champs, t_parse **p)
{
	t_list		*xplr;
	t_champ		*ichamp;
	int			code_error;

	xplr = *lst_champs;
	while (xplr)
	{
		ichamp = (t_champ*)(xplr->cnt);
		if ((code_error = vm_champ_file_parse(ichamp, p)) != 0)
			return (code_error);
		xplr = xplr->next;
	}
	return (0);
}
