/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_size_back.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:27:37 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/19 10:18:50 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int		lst_size_rev(t_node *lst)
{
	int			i;

	i = 0;
	if (lst)
	{
		while (lst && lst->prev)
		{
			lst = lst->prev;
			i++;
		}
		lst = goto_end(&lst);
		return (i);
	}
	lst = goto_end(&lst);
	return (0);
}
