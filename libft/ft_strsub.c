/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 16:46:31 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 20:33:09 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	int		i;
	size_t	j;

	if (!s)
		return (0);
	j = (size_t)start;
	i = 0;
	ret = (char*)malloc(sizeof(*ret) * (len + 1));
	if (!ret)
		return (0);
	while (s[start] != '\0' && (size_t)start < (len + j))
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}
