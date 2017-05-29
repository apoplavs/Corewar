#include "virtual_machine.h"

void    init_pc(t_struct *pl, unsigned char *ptr)
{
    t_pc *tmp;

    if (!(tmp = (t_pc*)malloc(sizeof(t_pc))))
        exit(1);
    tmp->pc_ptr = ptr;
    tmp->carry = 0;
    tmp->cycles = 0;
    tmp->live = 0;
    ft_fill_int(tmp->r, 17, 0);
    if (pl->last) {
        pl->last->next = tmp;
        tmp->prev = pl->last;
    }
    else
        tmp->prev = NULL;
    pl->last = tmp;
    if (pl->first == NULL)
        pl->first = tmp;
    tmp->next = NULL;
}


void    delete_pc(t_struct *pl, t_pc **del)
{
    if (*del == pl->last && *del == pl->first)
    {
        free(*del);
        return;
    }
    else if (*del == pl->last && *del != pl->first)
        (*del)->prev->next = NULL;
    else
    {
        (*del)->prev->next = (*del)->next;
        (*del)->next->prev = (*del)->prev;
    }
    free(*del);
}
