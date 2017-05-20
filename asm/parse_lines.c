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

void		parse3(char **tab, t_line *str)
{

}

void		parse2(char **tab, t_line *str)
{
	char 	**params;
	char 	a1;
	char 	a2;
	char 	a3;
	int 	i;

	params = ft_strsplit(tab[1], SEPARATOR_CHAR);
	set_args(&a1, &a2, &a3, params);
	i = get_instruction(tab[0]);

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