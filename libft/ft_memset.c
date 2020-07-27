/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 15:06:03 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 20:12:36 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ret;

	ret = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		ret[i] = c;
		i++;
	}
	return (ret);
}
