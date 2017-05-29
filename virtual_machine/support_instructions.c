
#include "virtual_machine.h"

unsigned int	get_argument(t_struct *data, t_pc *p, int size) // зчитує аргументи для команди
{
	unsigned int args;
	int 		i;

	args = 0;
	i = 0;
	if (((p->pc_ptr + size + 1) - data->map) >= MEM_SIZE)
	{
		p->pc_ptr = data->map;
		return (0);
	}
		p->pc_ptr++;
	while (i < size)
	{
		args = args << 8;
		args |= p->pc_ptr[i];
		i++;
	}
	p->pc_ptr += size;
	return (args);
}
