/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_ld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:23:44 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/30 17:23:46 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int 	ld(t_struct *data, t_pc *p)
{
	unsigned int 	arg;
	unsigned int 	reg;
	unsigned char 	*args;
	unsigned char 	*args_len;
	unsigned char	*point;

	args = (unsigned char *)ft_strnew(3);
	args_len = (unsigned char *)ft_strnew(3);
	change_carry(p);
	move_ptr(data, &p->pc_ptr, 1);
	if (!ft_choose_arg(data, p, args, 12))
		return (0);
	get_len_write(args, args_len, 4);
	arg = get_argument(data, p, args_len[0]);
	if ((reg = get_argument(data, p, args_len[1])) > 16)
	{
		free(args);
		free(args_len);
		return (0);
	}
	if (args[0] == T_IND)
	{
		point = p->pc_ptr;
		arg = arg % IDX_MOD;
		move_ptr(data, &p->pc_ptr, arg);
		arg = get_argument(data, p, args_len[0]);
		p->pc_ptr = point;
	}
	p->r[reg] = arg;
	free(args);
	free(args_len);
	return (1);
}