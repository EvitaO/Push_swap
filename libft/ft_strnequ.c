/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnequ.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 16:34:32 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/03/29 16:44:28 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!s1) || (!s2))
		return (0);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	if ((s1[i] == s2[i]) || (i == n))
		return (1);
	return (0);
}
