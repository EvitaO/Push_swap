/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 01:09:06 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/01/23 13:01:58 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_result(char **str, char *tmp, char **line, int fd)
{
	unsigned int			i;
	size_t					len;
	unsigned int			line_len;
	char					*clr;

	i = 0;
	if (!str[fd])
		return (-1);
	len = ft_strlen(str[fd]);
	if (tmp)
		*tmp = '\0';
	line_len = ft_strlen(str[fd]);
	*line = ft_strdup(str[fd]);
	if (*line == NULL)
		return (-1);
	clr = str[fd];
	str[fd] = ft_strsub(str[fd], (line_len + 1), (len - line_len - 1));
	if (str[fd] == NULL)
		return (-1);
	free(clr);
	return (1);
}

static int			read_and_save(char **str, char *buf, int fd, char **tmp)
{
	if (str[fd] == NULL)
	{
		str[fd] = ft_strnew(0);
		if (!str[fd])
			return (-1);
	}
	*tmp = ft_strjoin(str[fd], buf);
	if (*tmp == NULL)
		return (-1);
	free(str[fd]);
	str[fd] = ft_strdup(*tmp);
	if (str[fd] == NULL)
		return (-1);
	free(*tmp);
	*tmp = ft_strchr(str[fd], '\n');
	return (0);
}

static int			ft_ret(char **line)
{
	*line = ft_strnew(0);
	if (*line == NULL)
		return (-1);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				n;
	static char		*str[4096];
	char			*tmp;
	int				res;

	n = 1;
	tmp = NULL;
	if (fd < 0 || line == NULL || fd > 4096 || (read(fd, buf, 0) < 0))
		return (-1);
	while (n > 0)
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		n = read(fd, buf, BUFF_SIZE);
		res = read_and_save(str, buf, fd, &tmp);
		if (res == -1)
			return (-1);
		if (tmp != NULL)
			break ;
	}
	if (n < 0)
		return (-1);
	else if (n == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (ft_ret(line));
	return (ft_result(str, tmp, line, fd));
}
