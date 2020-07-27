/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_position.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 14:20:37 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/21 01:03:19 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void		set_position(t_node **a, int num, int p)
{
	while (*a && (*a)->prev)
	{
		if ((*a)->nbr < num && (*a)->pos == -1)
			num = (*a)->nbr;
		*a = (*a)->prev;
	}
	if ((*a)->nbr < num && (*a)->pos == -1)
		num = (*a)->nbr;
	*a = goto_end(a);
	while ((*a)->nbr != num)
		*a = (*a)->prev;
	if ((*a)->pos == -1)
		(*a)->pos = p;
}

int			find_nbr(t_node **a)
{
	while ((*a) && (*a)->prev && (*a)->pos != -1)
		*a = (*a)->prev;
	return ((*a)->nbr);
}

void		put_pos(t_node **a, int size)
{
	int			num;
	int			p;

	p = 0;
	while (size > 0)
	{
		*a = goto_end(a);
		num = find_nbr(a);
		set_position(a, num, p);
		*a = goto_end(a);
		p++;
		size--;
	}
	num = find_nbr(a);
	set_position(a, num, p);
	*a = goto_end(a);
}
