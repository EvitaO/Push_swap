/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 17:15:43 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 20:21:32 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		k;

	if ((!s1) || (!s2))
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	ret = (char*)malloc(sizeof(*ret) * (i + 1));
	i = 0;
	k = 0;
	if (!ret)
		return (NULL);
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		ret[i] = s2[k];
		i++;
		k++;
	}
	ret[i] = '\0';
	return (ret);
}
