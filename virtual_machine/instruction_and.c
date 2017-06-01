/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_and.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:04:25 by dsemench          #+#    #+#             */
/*   Updated: 2017/06/01 14:04:26 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int 	and(t_struct *data, t_pc *p)
{
	long int		arg[3];
	unsigned char	*args;
	unsigned char	*args_len;
	unsigned char	*point;

	args = (unsigned char *)ft_strnew(3);
	args_len = (unsigned char *)ft_strnew(3);
	change_carry(p);
	move_ptr(data, &p->pc_ptr, 1);
	point = p->pc_ptr;
	if (!ft_choose_arg(data, &point, args, 5))
		return (free_for_functions(args, args_len, 0));
	get_len_write(args, args_len, 4);
	if (((arg[0] = get_argument(data, &point, args_len[1])) > 16 && args[1] == T_REG)
		|| ((arg[1] = get_argument(data, &point, args_len[2])) > 16 && args[2] == T_REG)
		|| ((arg[2] = get_argument(data, &point, args_len[3])) > 16 && args[3] == T_REG))
		return (free_for_functions(args, args_len, 0));
	if (args[1] == T_IND)
	{
		point = p->pc_ptr - 1;
		arg[0] = cast_if_negative(arg[0]);
		move_ptr(data, &point, arg[0]);
		arg[0] = get_argument(data, &point, 4);
	}
	else if (args[1] == T_DIR)
	{

	}
	if (args[2] == T_IND)
	{
		point = p->pc_ptr - 1;
		arg[1] = cast_if_negative(arg[1]);
		move_ptr(data, &point, arg[1]);
		arg[1] = get_argument(data, &point, 4);
	}
	else if (args[2] == T_DIR)
	{

	}
	if (args[3] == T_IND)
	{
		point = p->pc_ptr - 1;
		arg[2] = cast_if_negative(arg[2]);
		move_ptr(data, &point, arg[2]);
		arg[2] = get_argument(data, &point, 4);
	}
	else if (args[3] == T_DIR)
	{

	}
}
