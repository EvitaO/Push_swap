/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 21:04:27 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 12:44:13 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (n[k] == '\0')
		return ((char*)h);
	while (h[i] != '\0' && n[k] != '\0' && i < len)
	{
		while (h[i + k] == n[k] && h[i + k] != '\0'
				&& n[k] != '\0' && i + k < len)
			k++;
		if (n[k] == '\0')
			return ((char*)&h[i]);
		else
		{
			k = 0;
			i++;
		}
	}
	return (0);
}
