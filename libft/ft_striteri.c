/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 15:27:36 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/03/29 15:46:32 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if ((s) && (f))
	{
		while (s[i] != '\0')
		{
			(*f)((unsigned int)i, &s[i]);
			i++;
		}
	}
}
