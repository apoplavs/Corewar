/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:07:29 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/12 17:16:35 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		write_file(t_asm *file)
{
t_line		*line;
	int 	i;

	i = 0;

	line = file->code;
	ft_printf("filename = %s\n", file->filename);
	ft_printf("name = %s\n", file->name);
	ft_printf("comment = %s\n", file->comment);

	while (line)
	{
		ft_printf("line %d =   %s\n", ++i, line->line);
		line = line->next;
	}
}


int 		main(int argc, char **argv)
{
	int 	fd;
	t_asm	*file;

	if (argc != 2)
		ft_error("\nusage: ./asm file.s");
	if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		ft_error("invalid file");
	file = init_file();
	read_filename(fd, argv[1], file);
	read_file(fd, file);
	write_file(file);
}
