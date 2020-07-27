/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 18:49:24 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/03/28 21:02:20 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *h, const char *n)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	if (n[k] == '\0')
		return ((char*)h);
	if (h == n)
		return ((char*)h);
	while (h[i] != '\0' && n[k] != '\0')
	{
		while (h[i + k] == n[k] && h[i + k] != '\0' && n[k] != '\0')
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
