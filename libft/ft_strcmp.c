/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 13:31:20 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/03/23 13:46:15 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		a = s1[i];
		b = s2[i];
		if (a != b)
			return (a - b);
		else
			i++;
	}
	a = s1[i];
	b = s2[i];
	if (a == b)
		return (0);
	else
		return (a - b);
}
