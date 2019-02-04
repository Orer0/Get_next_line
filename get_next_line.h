/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:27:52 by aroblin           #+#    #+#             */
/*   Updated: 2018/02/22 18:56:06 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "libft/libft.h"
# define BUFF_SIZE 9999
# define T_SRC_STR ((t_src *)(temp->content))->str
# define T_SRC_FD ((t_src *)(temp->content))->fd

int					get_next_line(int fd, char **line);


typedef struct	s_src
{
	char	*str;
	int		fd;
}				t_src;

#endif

