/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_players_by_n.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:05:39 by dsemench          #+#    #+#             */
/*   Updated: 2017/06/09 15:05:41 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	check_after_n_file(char **argv, t_struct *pl)
{
	int		i;
	char	**tmp;

	i = 0;
	while (argv[i])
	{
		if ((ft_strequ(argv[i], "-n") && pl->fl_n > 0))
		{
			i += 2;
			if (argv[i])
			{
				tmp = ft_strsplit(argv[i], '.');
				if (!ft_strequ(tmp[len_arr(tmp) - 1], "cor"))
					ft_error("after flag '-n' number[1-4] 'file.cor'");
				ft_free_db_array(tmp);
			}
			else
				ft_error("after flag '-n' 'number[1-4]' 'file.cor'");
			i++;
		}
		else
			i++;
	}
}

int		position(char **argv, int i)
{
	int		j;
	int		res;
	char	**tmp;

	j = 0;
	res = 0;
	while (argv[j])
	{
		tmp = ft_strsplit(argv[j], '.');
		if (ft_strequ(tmp[len_arr(tmp) - 1], "cor"))
		{
			if ((j - 2) > 0)
				if (argv[j - 2] && ft_strequ(argv[j - 2], "-n") && j == i)
				{
					ft_free_db_array(tmp);
					return (res);
				}
			res++;
		}
		ft_free_db_array(tmp);
		j++;
	}
	return (res);
}

void	exchange(char **first, char **second)
{
	char *buff;

	buff = ft_strdup(*first);
	free(*first);
	*first = ft_strdup(*second);
	free(*second);
	*second = ft_strdup(buff);
	free(buff);
}

char	**ft_sort_players(char **names, char *order, int i)
{
	int		tmp;
	int		flag;
	char	buff;

	flag = 0;
	while (order[++i])
	{
		tmp = order[i - 1] - '0';
		if (tmp > order[i] - '0')
		{
			buff = order[i - 1];
			order[i - 1] = order[i];
			order[i] = buff;
			exchange(&names[i - 1], &names[i]);
			flag = 1;
		}
		else if (tmp == order[i] - '0')
			exchange(&names[i - 1], &names[i]);
		if (flag == 1)
		{
			i = 0;
			flag = 0;
		}
	}
	return (names);
}

char	**ft_move_pl_by_n(char **argv, char **names, t_struct *pl, int tmp_nb)
{
	int		i;
	char	*order;

	i = -1;
	check_after_n_file(argv, pl);
	order = ft_strnew((size_t)pl->num_pl);
	while (names[++i])
		order[i] = (char)(i + '0' + 1);
	i = 0;
	while (argv[i])
		if (ft_strequ(argv[i], "-n"))
		{
			if (argv[++i][0] - 1 - '0' < pl->num_pl)
			{
				tmp_nb = position(argv, (++i));
				order[tmp_nb] = (argv[i - 1][0]);
			}
			else
				ft_error("input number isn't correct");
		}
		else
			i++;
	names = ft_sort_players(names, order, 0);
	free(order);
	return (names);
}
