#include "virtual_machine.h"

void out_map(t_struct *pl)
{
    int			i;
    int			j;

    i = 0;
    j = 1;
    wmove(map, 0, 0);
    while (i < MEM_SIZE)
    {
        while (i < j * 64)
        {
            if (i < MEM_SIZE)
            {
                wattron(map, A_BOLD | COLOR_PAIR(pl->color[i]));
                wprintw(map, "%02x", pl->map[i]);
                wattroff(map, A_BOLD | COLOR_PAIR(pl->color[i]));
            }
            if (i != j * 64 - 1)
                wprintw(map, " ");
            i++;
        }
        wprintw(map, "\n");
        j++;
    }
}

void    out_info1(t_struct *pl)
{
    int i;
    int j;

    werase(info1);
    wattron(info1, A_BOLD);
    mvwprintw(info1, 0, 24, "Status info:");
    wattroff(info1, A_BOLD);
    mvwprintw(info1, 5, 2, "Cycle = ");
    wattron(info1, A_BOLD | COLOR_PAIR(6));
    wprintw(info1, "%d", pl->iterator++);
    wattroff(info1, A_BOLD | COLOR_PAIR(6));
    i = 0;
    j = 8;
    while (i < pl->num_pl){
        wattron(info1, COLOR_PAIR(i + 1));
        mvwprintw(info1, j, 2, "Player[%d] say live - [%d] times %s",
        (int)pl->players[i]->player_number, pl->players[i]->count_live,
        pl->players[i]->name);
        wattroff(info1, COLOR_PAIR(i + 1));
        j += 2;
        i++;
    }
    mvwprintw(info1, 30, 2, "Winner: ");
    wattron(info1, A_BOLD | COLOR_PAIR(pl->number_last_live_player * -1));
    wprintw(info1, "[%d]", pl->number_last_live_player);
    wattroff(info1, A_BOLD | COLOR_PAIR(pl->number_last_live_player * -1));
    wrefresh(info1);
}

void    out_info2(t_struct *pl)
{
    werase(info2);
    mvwprintw(info2, 1, 2, "CYCLE_TO_DIE = %d", pl->glob_cycles);
    mvwprintw(info2, 2, 2, "NBR_LIVE = %d", pl->nbr_live);
    mvwprintw(info2, 3, 2, "MAX_CHECKS = %d", pl->max_checks);
    wrefresh(info2);
}

void    out_info3(t_struct *pl)
{
    werase(info3);
    wattron(info3, A_BOLD);
    mvwprintw(info3, 0, 25, "Help info:");
    wattroff(info3, A_BOLD);
    mvwprintw(info3, 2, 1, "- press +/- to control speed: ");
    wattron(info3, A_BOLD | COLOR_PAIR(6));
    wprintw(info3, "%d", 51 - pl->speed/2000);
    wattroff(info3, A_BOLD | COLOR_PAIR(6));
    mvwprintw(info3, 3, 1, "- press \"spase\" to stop VM");
    mvwprintw(info3, 4, 1, "- when VM stoped, press any key to go 1 cycle");
    wrefresh(info3);
}

void    out_start_position(t_struct *pl)
{
    t_pc *tmp;

    out_map(pl);
    tmp = pl->first;
    while (tmp)
    {
        mvwchgat(map, (tmp->pc_ptr - pl->map) / 64,
                 ((tmp->pc_ptr - pl->map) % 64) * 3,
                 2, 0, 7, NULL);
        tmp = tmp->next;
    }
    wrefresh (map);
    out_info1(pl);
    out_info2(pl);
    out_info3(pl);
    if (wgetch(map) == ' ')
        set_del();
}

void    out_winner(t_struct *pl)
{
    int row;
    int col;

    wclear(map);
    getmaxyx(map, row, col);
    wattron(map, A_BOLD | COLOR_PAIR(pl->number_last_live_player * -1));
    mvwprintw(map, row / 2, (col - 22) / 2, "Winner is player N[%d]", (int) pl->number_last_live_player);
    wattroff(map, A_BOLD | COLOR_PAIR((int) ((pl->number_last_live_player * -1) - 1)));
    wrefresh (map);
    halfdelay(200);
    wgetch(map);
}