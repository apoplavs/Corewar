/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 20:51:26 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/17 20:51:37 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		set_args(char *a1, char *a2, char *a3, char **params)
{
	*a1 = 0;
	*a2 = 0;
	*a3 = 0;
	if (params[0])
		*a1 = type_arg(params[0]);
	if (params[1])
		*a2 = type_arg(params[1]);
	if (params[2])
		*a3 = type_arg(params[2]);
}

char 		type_arg(char *arg)
{
	if (arg[0] == 'r' && ft_isdigit(arg[1]))
	{
		check_t_reg(arg);
		return (T_REG);
	}
	else if (arg[0] == DIRECT_CHAR)
	{
		check_t_dir(arg);
		return (T_DIR);
	}
	else if (arg[0] == '-' || ft_isdigit(arg[0]) || arg[0] == LABEL_CHAR)
	{
		check_t_ind(arg);
		return (T_IND);
	}
	else
		exit_notice("invalid argument : ", arg);
	return (0);
}

void		parse3(char **tab, t_line *str)
{

}

void		parse2(char **tab, t_line *str)
{
	char 	**params;
	char 	a1;
	char 	a2;
	char 	a3;

	params = ft_strsplit(tab[1], SEPARATOR_CHAR);
	set_args(&a1, &a2, &a3, params);
	// continued here

}

void		parse1(char **tab, t_line *str)
{
	check_label_name(tab[0]);
}

void 		ft_parse_lines(t_line *str)
{
	char 	**tab;
	t_line	*start;

	start = str;
	while (str->next->next)
	{
		tab = ft_strsplit(str->line, ' ');
		if (tab[0] && tab[1] && tab[2] && !tab[3])
			parse3(tab, start);
		else if (tab[0] && tab[1] && !tab[2])
			parse2(tab, start);
		else if (tab[0] && !tab[1])
			parse1(tab, start);
		else
			exit_notice("invalid instruction : ", str->line);
		del_tab(tab);
		str = str->next;
	}
}