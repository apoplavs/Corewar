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

#ifndef COREVAR_INSTRUCTIONS_H
#define COREVAR_INSTRUCTIONS_H


int		ft_choose_arg(t_struct *data, t_pc *p, unsigned char *args, int n);
void		get_len_write(unsigned char *args, unsigned char *args_len, int len_dir);


#endif //COREVAR_INSTRUCTIONS_H
