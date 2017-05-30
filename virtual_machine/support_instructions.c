
#include "virtual_machine.h"

void 			change_carry(t_pc *list)
{
	if (list->carry == 0)
		list->carry = 1;
	else
		list->carry = 0;
}

unsigned int	get_argument(t_struct *data, t_pc *p, int size) // зчитує аргументи для команди
{
	unsigned int args;
	int 		i;

	args = 0;
	i = 0;
	move_ptr(data, &p->pc_ptr, 1);
	while (i < size)
	{
		args = args << 8;
		move_ptr(data, &p->pc_ptr, 1);
		args |= *p->pc_ptr;//args |= function from igor move ptn;
		i++;
	}
	return (args);
}
