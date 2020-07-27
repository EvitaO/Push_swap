/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 21:42:47 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/03 21:45:03 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*d;

	d = malloc(size);
	if (!d)
		return (NULL);
	ft_bzero(d, size);
	return (d);
}
