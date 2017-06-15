/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:50:00 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/26 16:53:34 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	out_map(t_struct *pl)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	wmove(g_out.map, 0, 0);
	while (i < MEM_SIZE)
	{
		while (i < j * 64)
		{
			if (i < MEM_SIZE)
			{
				wattron(g_out.map, A_BOLD | COLOR_PAIR(pl->color[i]));
				wprintw(g_out.map, "%02x", pl->map[i]);
				wattroff(g_out.map, A_BOLD | COLOR_PAIR(pl->color[i]));
			}
			if (i != j * 64 - 1)
				wprintw(g_out.map, " ");
			i++;
		}
		wprintw(g_out.map, "\n");
		j++;
	}
}

void	out_info1(t_struct *pl)
{
	int i;
	int j;

	werase(g_out.info1);
	wattron(g_out.info1, A_BOLD);
	mvwprintw(g_out.info1, 0, 24, "Status info:");
	wattroff(g_out.info1, A_BOLD);
	mvwprintw(g_out.info1, 5, 2, "Cycle = ");
	wattron(g_out.info1, A_BOLD | COLOR_PAIR(6));
	wprintw(g_out.info1, "%d", pl->current_cycle++);
	wattroff(g_out.info1, A_BOLD | COLOR_PAIR(6));
	i = 0;
	j = 8;
	while (i < pl->num_pl)
	{
		mvwprintw(g_out.info1, j, 2, "Player[%d] ", (int)pl->players[i]->player_number);
		wattron(g_out.info1, COLOR_PAIR(i + 1));
		wprintw(g_out.info1, "\"%s\":", pl->players[i]->name);
		mvwprintw(g_out.info1, j + 1, 4, "live in current period - [%d]", pl->players[i]->count_live);
		wattroff(g_out.info1, COLOR_PAIR(i + 1));
		j += 3;
		i++;
	}
	mvwprintw(g_out.info1, 30, 2, "Winner: ");
	wattron(g_out.info1, A_BOLD | COLOR_PAIR(pl->number_last_live_player * -1));
	wprintw(g_out.info1, "[%d]", pl->number_last_live_player);
	wattroff(g_out.info1, A_BOLD | COLOR_PAIR(pl->number_last_live_player * -1));
	wrefresh(g_out.info1);
}

void	out_info2(t_struct *pl)
{
	werase(g_out.info2);
	mvwprintw(g_out.info2, 1, 2, "CYCLE_TO_DIE = %d", pl->glob_cycles);
	mvwprintw(g_out.info2, 2, 2, "NBR_LIVE = %d", pl->nbr_live);
	mvwprintw(g_out.info2, 3, 2, "MAX_CHECKS = %d", pl->max_checks);
	wrefresh(g_out.info2);
}

void	out_info3(t_struct *pl)
{
	werase(g_out.info3);
	wattron(g_out.info3, A_BOLD);
	mvwprintw(g_out.info3, 0, 25, "Help info:");
	wattroff(g_out.info3, A_BOLD);
	mvwprintw(g_out.info3, 2, 1, "- press +/- to control speed: ");
	wattron(g_out.info3, A_BOLD | COLOR_PAIR(6));
	wprintw(g_out.info3, "%d", 51 - pl->speed / 2000);
	wattroff(g_out.info3, A_BOLD | COLOR_PAIR(6));
	mvwprintw(g_out.info3, 3, 1, "- press \"spase\" to stop VM");
	mvwprintw(g_out.info3, 4, 1, "- when VM stoped, press any key to go 1 cycle");
	wrefresh(g_out.info3);
}

void	out_start_position(t_struct *pl)
{
	t_pc *tmp;

	out_map(pl);
	tmp = pl->first;
	while (tmp)
	{
		mvwchgat(g_out.map, (tmp->pc_ptr - pl->map) / 64,
				((tmp->pc_ptr - pl->map) % 64) * 3,
				2, 0, 7, NULL);
		tmp = tmp->next;
	}
	wrefresh(g_out.map);
	out_info1(pl);
	out_info2(pl);
	out_info3(pl);
	if (wgetch(g_out.map) == ' ')
		set_del();
}

void	out_winner(t_struct *pl)
{
	int row;
	int col;

	wclear(g_out.map);
	getmaxyx(g_out.map, row, col);
	wattron(g_out.map, A_BOLD | COLOR_PAIR(pl->number_last_live_player * -1));
	mvwprintw(g_out.map, row / 2, (col - 22) / 2, "Winner is player N[%d]", (int)pl->number_last_live_player);
	wattroff(g_out.map, A_BOLD | COLOR_PAIR((int)((pl->number_last_live_player * -1) - 1)));
	wrefresh(g_out.map);
	halfdelay(200);
	wgetch(g_out.map);
}
