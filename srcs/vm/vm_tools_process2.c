/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_tools_process2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:34:01 by armajchr          #+#    #+#             */
/*   Updated: 2020/09/04 14:46:45 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Function: vm_proc_kill_no_live
** Description:
**	[put some explanations here !]
** Return:
**	1: if at least one process remaind in the list cw->process after killing
**		concerned processes.
**	0: if no process remainds or if the number of processes exceed INT_MAX
*/

static void	vm_kill2(t_cw *cw, t_list **before, t_list *next, t_list **xplr)
{
	if (cw->options->v_lvl & 0b00001000)
		vprint_deaths(cw, (t_process*)((*xplr)->cnt));
	if (*xplr - cw->process == 0)
	{
		cw->process = next;
		*before = next;
	}
	else
		(*before)->next = next;
}

int			vm_proc_kill_not_living(t_cw *cw)
{
	t_list		*xplr;
	t_list		*next;
	t_list		*before;

	xplr = cw->process;
	while (xplr)
	{
		next = xplr->next;
		((t_process*)(xplr->cnt))->n_lives = 0;
		if (cw->tot_cycle - ((t_process*)(xplr->cnt))->last_live \
			+ ((cw->cycle_to_die > 0) ? -1 : 0) >= cw->cycle_to_die)
		{
			vm_kill2(cw, &before, next, &xplr);
			ft_lstdelone(&xplr, &ft_lst_fdel_proc);
		}
		else
			before = xplr;
		xplr = next;
	}
	return ((ft_lst_len(cw->process) == 0) ? 0 : 1);
}

/*
** Function: is_valid_reg
** Description:
**	CHECK IF THE REGISTER VALUES ∈ [1; REG_NUMBER].
**
**	HOW <n> AND <mask> WORK:
**	n = 0		mask = 2^(7 - 2 * n) + 2^(6 - 2 * n) = 0b11000000
**	n = 1		mask = 2^(7 - 2 * n) + 2^(6 - 2 * n) = 0b00110000
**	n = 2		mask = 2^(7 - 2 * n) + 2^(6 - 2 * n) = 0b00001100
*/

bool		is_valid_reg(t_cw *cw, t_process *p)
{
	size_t		n;
	int			mask;
	int			arg;
	int			j;

	n = 0;
	j = 0;
	while (n < cw->op_tab[p->opcode - 1].n_arg)
	{
		mask = ft_power(2, 7 - (2 * n)) + ft_power(2, 6 - (2 * n));
		arg = get_arg_value(cw, p, p->i + 2 + j, \
			(cw->arena[(p->i + 1) % MEM_SIZE] & mask) >> (6 - (2 * n)));
		j = j + instruction_width(cw->arena[(p->i + 1) % MEM_SIZE] \
			& mask, cw->op_tab[p->opcode - 1]);
		if (((cw->arena[(p->i + 1) % MEM_SIZE] & mask) >> (6 - (2 * n))) \
			== REG_CODE)
		{
			if (arg < 1 || arg > REG_NUMBER)
				return (false);
		}
		n += 1;
	}
	return (true);
}
