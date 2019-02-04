/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:38:21 by aroblin           #+#    #+#             */
/*   Updated: 2018/02/22 20:12:49 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			ft_check(char **line, int fd)
{
	if (line != NULL)
		*line = NULL;
	if (fd < 0 || !line)
		return (-1);
	return (1);
}

t_src		*create_content(int fd)
{
	t_src			*src;

	if (!(src = ft_memalloc(sizeof(t_src *))))
		return (NULL);
	src->fd = fd;
	if (!(src->str = ft_strnew(0)))
		return (NULL);
	return (src);
}

t_list		*find_fd(t_list **list, int fd)
{
	t_list			*temp;

	temp = *list;
	while (temp != NULL)
	{
		if (T_SRC_FD == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = ft_lstnew(NULL, sizeof(t_src *))))
		return (NULL);
	temp->content = create_content(fd);
	ft_lstadd(list, temp);
	return (temp);
}

char		*ft_endfile(char *str)
{
	char			*temp;

	if (!(str))
		return (NULL);
	if (ft_strfind(str, '\n'))
	{
		temp = str;
		str = ft_strdup(ft_strchr(str, '\n') + 1);
		ft_strdel(&temp);
	}
	else
		ft_strdel(&str);
	return (str);
}

int			get_next_line(int fd, char **line)
{
	int				n_lus;
	char			*buff;
	t_list			*temp;
	static t_list	*list = NULL;

	n_lus = 0;
	if (!ft_check(line, fd) || read(fd, "", 0) < 0)
		return (-1);
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	temp = find_fd(&list, fd);
	while ((!ft_strfind(T_SRC_STR, '\n') &&
				(n_lus = read(fd, buff, BUFF_SIZE) > 0)))
	{
		T_SRC_STR = ft_strjoin_free_s1(&T_SRC_STR, &buff);
		ft_strclr(buff);
	}
	if (ft_strcmp(T_SRC_STR, "") != 0)
		*line = ft_strsub(T_SRC_STR, 0, ft_strpos(T_SRC_STR, '\n'));
	T_SRC_STR = ft_endfile(T_SRC_STR);
	if (T_SRC_STR == NULL && n_lus == 0 && !*line)
		return (0);
	ft_strdel(&buff);
	return (1);
}
