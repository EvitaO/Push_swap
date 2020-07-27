/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 17:42:45 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 20:07:13 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*ret;
	size_t			i;

	a = (unsigned char)c;
	i = 0;
	ret = (unsigned char*)s;
	while (i < n)
	{
		if (ret[i] == a)
			return (&ret[i]);
		i++;
	}
	return (NULL);
}
