/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:58:02 by mdavid            #+#    #+#             */
/*   Updated: 2020/09/05 01:04:18 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

# define FILE_BIG		250

# define NB_ERROR_MSG	27
# define CD_USAGE		0
# define CD_P_STRUCT	1
# define CD_P_IDTAB		2
# define CD_P_OPT		3
# define CD_DUMP 		4
# define CD_VERB		5
# define CD_MUSIC		6
# define CD_UNIQ		7
# define CD_BD_VAL		8
# define CD_BD_FILE		9
# define CD_DUPL_N		10
# define CD_FILE_BIG	11
# define CD_MEM_CHAMP	12
# define CD_EMPTY_CHP	13
# define CD_MAX_CHAMP	14
# define CD_INV_FD		15
# define CD_MAGIC_EXEC	16
# define CD_CHP_SIZ		17
# define CD_CHP_ERR		18
# define CD_SORT_CHP	19
# define CD_PROC_MEM	20
# define CD_CW_STRUCT	21
# define CD_ARENA		22
# define CD_ID_ARENA	23
# define CD_INI_PROC	24
# define CD_FORK		25
# define FIN_DU_GAME	26

# define M_P_STRUCT		"Error: [Mem. allocation] failed for t_parse *p."
# define M_P_IDTAB		"Error: [Mem. allocation] failed for p->id_available"
# define M_P_OPT		"Error: [Mem. allocation] failed for p->options."
# define M_VERB			"Error: [Verbose flag] invalid or no parameter."
# define M_MUSIC		"Error: [Music flag] invalid parameter."
# define M_UNIQ			"Error: [Flag] dupplicate option flag."
# define M_DUPL_N		"Error: [Number flag] <-n id>, repetition of ID."
# define M_FILE_BIG		"Error: champion file name too big."
# define M_MEM_CHAMP	"Error: [Mem. allocation] during champion processing."
# define M_EMPTY_CHP	"Error: you must precise 1 champion at least."
# define M_MAX_CHAMP	"Error: a maximum of 4 champions is allowed."
# define M_INV_FD		"Error: invalid fd, file or path may not exist."
# define M_MAGIC_EXEC	"Error: COREWAR_EXEC_MAGIC number into file."
# define M_CHP_ERR		"Error: Corrupted code in champion's file."
# define M_SORT_CHP		"Error: Issue during the sorting process of champ list."
# define M_PROC_MEM		"Error: [Mem. allocation] fork/lfork failed allocate."
# define M_CW_STRUCT	"Error: [Mem. allocation] failed for t_cw *cw."
# define M_ARENA		"Error: [Mem. allocation] failed for cw->arena."
# define M_ID_ARENA		"Error: [Mem. allocation] failed for cw->id_arena."
# define M_INI_PROC		"Error: [Mem. allocation] failed during initial proc."
# define M_FORK			"Error: [Mem. allocation] failed for a fork/lfork."
# define M_FIN			"FIN DU GAME."

#endif
