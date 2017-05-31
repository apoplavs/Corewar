/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:56:00 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/30 17:56:04 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

# include "virtual_machine.h"

/*
**checking_instructions.c
*/
int			ft_choose_arg(t_struct *data, t_pc *p, unsigned char *args, int n);
void		get_len_write(unsigned char *args, unsigned char *args_len, int len_dir);


/*
**instruction_ld.c
*/
int 		ld(t_struct *data, t_pc *p);

/*
**instruction_lld.c
*/
int 		lld(t_struct *data, t_pc *p);

/*
**instruction_live.c
*/
int					live(t_struct *data, t_pc *p);

/*
**support_instructions.c
*/
void			get_len_write(unsigned char *args, unsigned char *args_len, int len_dir);
unsigned int	get_argument(t_struct *data, t_pc *p, int size); // зчитує аргументи для команди
void 			change_carry(t_pc *list);

#endif //COREVAR_INSTRUCTIONS_H
