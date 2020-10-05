/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and_op_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:38:27 by mdavid            #+#    #+#             */
/*   Updated: 2020/09/05 00:39:14 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_AND_OP_STRUCT_H
# define OP_AND_OP_STRUCT_H

# include <stddef.h>

# ifndef OP_H
#  define OP_H
#  include "op.h"
# endif

typedef struct			s_op
{
	char				*name;
	size_t				n_arg;
	size_t				type[MAX_ARGS_NUMBER];
	size_t				code;
	size_t				cycle;
	char				*desc;
	size_t				encod;
	size_t				direct_size;
}						t_op;

#endif
