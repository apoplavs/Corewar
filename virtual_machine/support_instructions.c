
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
		args |= *p->pc_ptr;//args |= function from igor move ptn;
		move_ptr(data, &p->pc_ptr, 1);
		i++;
	}
	return (args);
}

void		get_len_write(unsigned char *args, unsigned char *args_len, int len_dir)
{
	int 	i;

	i = 0;
	while (i < 4)
	{
		if (args[i] == T_DIR)
			args_len[i] = (unsigned char)len_dir;
		else if (args[i] == T_IND)
			args_len[i] = 2;
		else if (args[i] == T_REG)
			args_len[i] = 1;
		i++;
	}
}