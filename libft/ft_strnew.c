/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 21:31:15 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/03 21:34:39 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*d;

	d = malloc(size + 1);
	if (!d)
		return (NULL);
	ft_memset(d, '\0', size + 1);
	return (d);
}
