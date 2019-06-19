/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:46:15 by behaudeg          #+#    #+#             */
/*   Updated: 2019/06/05 10:46:18 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl		get_line(t_gnl val, char **line, char **str, int fd)
{
	char			*tmp;

	tmp = NULL;
	if (str[fd] && str[fd][val.i] == '\n')
	{
		if (!(*line = ft_strsub(str[fd], 0, val.i)))
			val.retour = -1;
		tmp = str[fd];
		if (!(str[fd] = ft_strdup(tmp + val.i + 1)))
			val.retour = -1;
		ft_strdel(&tmp);
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd] && str[fd][val.i] == '\0')
	{
		if (!(*line = ft_strdup(str[fd])))
			val.retour = -1;
		ft_strdel(&str[fd]);
	}
	val.str = str[fd];
	return (val);
}

t_gnl		read_line(int fd, char **str, t_gnl val)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;

	buff[0] = '\0';
	ret = 0;
	while (!(ft_strchr(buff, '\n')) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(str[fd] = ft_strjoin_free(str[fd], buff, 1)))
			val.retour = -1;
	}
	val.str = str[fd];
	return (val);
}

int			get_next_line(const int fd, char **line)
{
	static char		*str[OPEN_MAX];
	t_gnl			val;

	val.retour = 0;
	val.str = NULL;
	val.i = 0;
	if (line == NULL || fd < 0 || read(fd, 0, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!(str[fd]) && !(str[fd] = ft_strnew(0)))
		val.retour = -1;
	val = read_line(fd, str, val);
	str[fd] = val.str;
	if (str[fd] == NULL || str[fd][0] == '\0')
		return (0);
	while (str[fd] && str[fd][val.i] && str[fd][val.i] != '\n')
		val.i++;
	val = get_line(val, line, str, fd);
	str[fd] = val.str;
	return ((val.retour == -1) ? -1 : 1);
}
