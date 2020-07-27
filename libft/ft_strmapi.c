/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 16:19:25 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 13:18:07 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*d;

	if ((s) && (f))
	{
		i = ft_strlen(s);
		d = (char*)malloc(sizeof(*d) * (i + 1));
		i = 0;
		if (!d)
			return (NULL);
		while (s[i] != '\0')
		{
			d[i] = (*f)((unsigned int)i, s[i]);
			i++;
		}
		d[i] = '\0';
		return (d);
	}
	return (NULL);
}
