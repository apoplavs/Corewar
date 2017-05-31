
#include "virtual_machine.h"

int 	add(t_struct *data, t_pc *p)
{
	unsigned int 	reg[3];
	unsigned char 	*args;
	unsigned char 	*args_len;
	unsigned char	*point;

	args = (unsigned char *)ft_strnew(3);
	args_len = (unsigned char *)ft_strnew(3);
	change_carry(p);
	move_ptr(data, &p->pc_ptr, 1);
	point = p->pc_ptr;
	if (!ft_choose_arg(data, p, args, 3))
		return (0);
	get_len_write(args, args_len, 0);
	if (((reg[0] = get_argument(data, p, args_len[0])) > 16)
		|| ((reg[1] = get_argument(data, p, args_len[1])) > 16)
		|| ((reg[3] = get_argument(data, p, args_len[2])) > 16))
	{
		p->pc_ptr = point;
		return (free_for_functions(args, args_len, 0));
	}
	p->r[reg[2]] = p->r[reg[0]] + p->r[reg[1]];

	return (free_for_functions(args, args_len, 1));
}