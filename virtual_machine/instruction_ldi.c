/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_ldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:08:07 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/01 16:08:13 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int 	ldi(t_struct *data, t_pc *p)
{
	long int 		arg[2];
	unsigned int 	reg;
	unsigned char 	*args;
	unsigned char 	*args_len;
	unsigned char	*point;

	move_ptr(data, &p->pc_ptr, 1);
	point = p->pc_ptr;
	args = (unsigned char *)ft_strnew(3);
	args_len = (unsigned char *)ft_strnew(3);
	if (!ft_choose_arg(data, &point, args, 1))
		return (free_for_functions(args, args_len, 0));
	get_len_write(args, args_len, 4);
	arg = get_argument(data, &point, args_len[0]);
	if ((reg = get_argument(data, &point, args_len[1])) > 16)
		return (free_for_functions(args, args_len, 0));
	if (args[0] == T_IND)
	{
		point = p->pc_ptr - 1;
		arg = cast_if_negative(arg);
		arg = arg % IDX_MOD;
		move_ptr(data, &point, arg);
		arg = get_argument(data, &point, 4);
	}
	p->r[reg] = arg;
	move_ptr(data, &p->pc_ptr, (args_len[0] + args_len[1] + args_len[2] + 1));
	change_carry(p, p->r[reg]);
	return (free_for_functions(args, args_len, 1));
}