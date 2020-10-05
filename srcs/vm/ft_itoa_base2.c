/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:52:05 by armajchr          #+#    #+#             */
/*   Updated: 2020/08/27 01:07:30 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"

char	*ft_itoa_base2(unsigned long long nb, char *base)
{
	int					count;
	unsigned long long	tmp;
	unsigned int		base_lenght;
	char				*res;

	base_lenght = ft_strlen(base);
	count = 1;
	tmp = nb;
	while (tmp >= base_lenght && (tmp /= base_lenght))
		count++;
	tmp = nb;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	res[count] = '\0';
	while (tmp >= base_lenght)
	{
		count--;
		res[count] = base[tmp % base_lenght];
		tmp /= base_lenght;
	}
	count--;
	res[count] = base[tmp % base_lenght];
	return (res);
}
