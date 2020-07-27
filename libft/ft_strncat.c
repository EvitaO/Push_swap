/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 11:33:12 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 12:46:44 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	y;
	size_t	z;

	y = 0;
	z = 0;
	while (s1[y] != '\0')
		y++;
	z = y;
	y = 0;
	while (s2[y] != '\0' && y < n)
	{
		s1[z] = s2[y];
		z++;
		y++;
	}
	s1[z] = '\0';
	return (s1);
}
