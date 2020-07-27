/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 17:32:01 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 20:34:44 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		size;
	int		l;

	if (!s)
		return (0);
	i = 0;
	size = 0;
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	l = i;
	while (s[i] != '\0')
		i++;
	i = i - 1;
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		i--;
	size = i;
	size = size - l + 1;
	return (ft_strsub(s, (unsigned int)l, (size_t)size));
}
