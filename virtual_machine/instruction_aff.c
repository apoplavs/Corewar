#include "virtual_machine.h"

int 	aff(t_struct *data, t_pc *p)
{
    move_ptr(data, &p->pc_ptr, 2);
    return (0);
}
