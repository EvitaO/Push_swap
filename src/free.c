/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 11:12:16 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/19 12:50:37 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void			free_list(t_node **a, t_node **b)
{
	t_node		*tmp;

	if (!*a)
		return ;
	while (*a)
	{
		tmp = *a;
		*a = (*a)->prev;
		free(tmp);
	}
	free(*a);
	if (!*b)
		return ;
	while (*b)
	{
		tmp = *b;
		*b = (*b)->prev;
		free(tmp);
	}
	free(*b);
}
