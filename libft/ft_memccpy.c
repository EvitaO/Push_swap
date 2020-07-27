/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 15:53:13 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/04 02:31:39 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*a;
	unsigned char		*b;
	size_t				i;

	a = (unsigned char*)src;
	b = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		if (a[i] == (unsigned char)c)
		{
			b[i] = (unsigned char)c;
			i++;
			return (&b[i]);
		}
		b[i] = a[i];
		i++;
	}
	return (NULL);
}
