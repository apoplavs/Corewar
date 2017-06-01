/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_zjmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:06:56 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/01 14:07:05 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int 	zjmp(t_struct *data, t_pc *p)
{
	long int 		arg;
	unsigned char	*point;

	if (p->carry == 0)
		return (0);
	move_ptr(data, &p->pc_ptr, 1);
	point = p->pc_ptr;
	arg = get_argument(data, &point, 2);
	arg = cast_if_negative(arg);
	move_ptr(data, &p->pc_ptr, arg);
	return (1);
}