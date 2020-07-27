/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 21:48:31 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 20:10:41 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		d;
	size_t		s;
	size_t		i;

	d = (size_t)dst;
	s = (size_t)src;
	i = len - 1;
	if (len > (d - s))
	{
		while ((int)i >= 0)
		{
			((char*)dst)[i] = ((const char*)src)[i];
			i--;
		}
		return (dst);
	}
	i = 0;
	while (i < len)
	{
		((char*)dst)[i] = ((const char*)src)[i];
		i++;
	}
	return (dst);
}
