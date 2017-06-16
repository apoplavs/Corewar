/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 12:01:52 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/16 18:46:34 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t	com_len(char *p, int *len)
{
	size_t i;

	i = 0;
	while (p[i] && p[i] != '"')
		i++;
	*len += i;
	return (i);
}

void	move_point(char *line, char **p, int dist)
{
	*p = line;
	*p = point_jump(*p);
	*p += dist;
	*p = point_jump(*p);
}

void	check_end_comment(int fd, char **str, int len_max)
{
	char	flag;
	int		len;
	char	*line;

	flag = 0;
	len = 0;
	(*str)[ft_strlen(*str)] = '\n';
	while (get_next_line(fd, &line) > 0)
	{
		if (len + (int)ft_strlen(line) >= len_max)
			break ;
		ft_strncat(*str, line, com_len(line, &len));
		if (ft_strchr(line, '"'))
		{
			flag = 1;
			break ;
		}
		(*str)[ft_strlen(*str)] = '\n';
		free(line);
	}
	free(line);
	if (flag == 0)
		ft_error("invalid file");
}

void	init_name(int fd, t_asm *file, char *line)
{
	char	*p;
	int		len;

	file->name = ft_strnew(PROG_NAME_LENGTH);
	move_point(line, &p, 5);
	if (*p != '"')
		ft_error("invalid name");
	p++;
	if ((len = (int)ft_strlen(p)) >= PROG_NAME_LENGTH)
		ft_error("invalid name");
	len = 0;
	ft_strncpy(file->name, p, com_len(p, &len));
	if (!ft_strchr(p, '"'))
		check_end_comment(fd, &file->name, PROG_NAME_LENGTH);
}

void	init_comment(int fd, t_asm *file, char *line)
{
	char	*p;
	int		len;

	file->comment = ft_strnew(COMMENT_LENGTH);
	move_point(line, &p, 8);
	if (*p != '"')
		ft_error("invalid comment");
	p++;
	if ((len = (int)ft_strlen(p)) >= COMMENT_LENGTH)
		ft_error("invalid comment");
	len = 0;
	ft_strncpy(file->comment, p, com_len(p, &len));
	if (!ft_strchr(p, '"'))
		check_end_comment(fd, &file->comment, COMMENT_LENGTH);
}
