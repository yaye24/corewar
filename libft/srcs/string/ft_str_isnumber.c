/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isnumber.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 17:10:19 by mdavid            #+#    #+#             */
/*   Updated: 2020/09/04 15:48:27 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function: ft_str_isnumber
** Description:
**	Function checks if the str is only made of digits.
** Return:
**	1: if str only digits
**	0: otherwise
*/

int		ft_str_isnumber(char *str)
{
	int		i;

	i = 0;
	if (!str || !(*str))
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
