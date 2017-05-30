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

int 	ld(t_struct *pl, t_pc *list, int size)
{
	unsigned int arg;

	if ((arg = get_argument(pl, list, 4)) == 0)
		return (0);
	return (1);
}