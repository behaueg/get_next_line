/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:46:24 by behaudeg          #+#    #+#             */
/*   Updated: 2019/06/05 10:46:26 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>

int				get_next_line(const int fd, char **line);

typedef struct	s_gnl
{
	char	*str;
	int		retour;
	int		i;
}				t_gnl;

#endif
