/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/06 14:25:22 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 20:29:06 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(const char *str)
{
	int			l;
	char		*d;
	int			k;

	if (!str)
		return (NULL);
	k = 0;
	d = ft_strdup(str);
	l = ft_strlen(str) - 1;
	while (l >= 0)
	{
		d[k] = str[l];
		k++;
		l--;
	}
	return (d);
}
