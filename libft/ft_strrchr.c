/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 18:17:14 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 20:28:10 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				r;

	i = 0;
	r = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			r = i;
		i++;
	}
	if (c == '\0')
		return ((char*)&s[i]);
	if ((r > 0) || (r == 0 && s[0] == c))
		return ((char*)&s[r]);
	return (0);
}
