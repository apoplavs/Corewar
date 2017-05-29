#include "virtual_machine.h"

void    write_code_to_field(t_struct *pl)
{
    unsigned char   *tmp;
    int             i;

    while (pnb < pl->num_pl) {
        tmp = pl->players[pnb]->first->pc_ptr;
        i = 0;
        while (i < pl->players[pnb]->size_cd) {
            tmp[i] = pl->players[pnb]->code[i];
            ++i;
        }
        pnb++;
    }
}


void    go_some_cycles(t_struct *pl, int cycles)
{
    int i;
    int nb;
    t_pc *tmp;
    unsigned char x = 255;

    i = 0;
    while (i < cycles){
        /*--------------------*/
        move(0,0);
        halfdelay(1);
        getch();
        refresh();
        visualization(pl, 4096);
        /*-------------------*/
        nb = pl->num_pl;
        while (nb > 0){
            tmp = pl->players[nb - 1]->first;
            while (tmp)
            {

                *(tmp->pc_ptr) = x;
                int xc = (tmp->pc_ptr - pl->map) / 64;
                int yc = ((tmp->pc_ptr - pl->map) % 64)*2;
                mvchgat(xc, yc, 1, 0, 7, NULL);
                if ((tmp->pc_ptr - pl->map) < MEM_SIZE)
                    tmp->pc_ptr++;
                else {
                    tmp->pc_ptr = pl->map;
                    x = 85;
                }

              /*
               *    // отследить номер функции и установить кол-во циклов
               * if (!tmp->cycles)    //если циклы каретки 0 - выполняем функции
                    go_to_function;  //старт функций (ap,ds) - pl, caretka
                else                 //если циклы не 0 то декрементируем и идем дальше
                    tmp->cycles--;*/
                tmp = tmp->next;
            }
            nb--;
        }
        i++;
    }
}


void    start_vm(t_struct *pl)
{
    //int i;
    write_code_to_field(pl);
    go_some_cycles(pl, CYCLE_TO_DIE);
    //while (check_live(pl) != 1)        //пока не выполнится условие (1 и жива) будем добавлять по CYCLE_DELTA
    //    go_some_cycles(pl, CYCLE_TO_DIE - CYCLE_DELTA);
}
