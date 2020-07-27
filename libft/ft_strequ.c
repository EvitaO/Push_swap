/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 16:28:23 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/03/29 16:33:28 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if ((!s1) || (!s2))
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
