/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 15:47:38 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 13:17:25 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*d;
	int		i;

	if ((s) && (f))
	{
		i = ft_strlen(s);
		d = (char*)malloc(sizeof(*d) * (i + 1));
		i = 0;
		if (!d)
			return (NULL);
		while (s[i] != '\0')
		{
			d[i] = (*f)((char)s[i]);
			i++;
		}
		d[i] = '\0';
		return (d);
	}
	return (NULL);
}
