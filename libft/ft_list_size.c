/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_size.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 13:29:33 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 13:53:42 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *lst)
{
	int			i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			lst = lst->next;
			i++;
		}
		return (i);
	}
	return (0);
}
