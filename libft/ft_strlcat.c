/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 14:34:25 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 20:23:50 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len_src;
	size_t		l;
	size_t		len_dst;

	l = 0;
	len_dst = ft_strlen(dst);
	i = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= size)
		return (size + len_src);
	while (i < (size - 1) && src[l])
	{
		dst[i] = src[l];
		i++;
		l++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}
