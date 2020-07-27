/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorted.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 15:20:14 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/22 15:20:56 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int					check_if_sorted(t_node **a, int size)
{
	int				i;

	i = 0;
	while (*a && (*a)->prev && (*a)->nbr < (*a)->prev->nbr)
	{
		*a = (*a)->prev;
		i++;
	}
	*a = goto_end(a);
	if (i + 1 == size)
		return (1);
	return (0);
}
