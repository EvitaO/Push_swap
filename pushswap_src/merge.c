/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4test.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 10:39:33 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/22 15:56:21 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int				end_of_list(t_node **s)
{
	int			i;

	while ((*s)->prev)
		*s = (*s)->prev;
	i = (*s)->pos;
	*s = goto_end(s);
	return (i);
}

void			check_rotate_a(t_node **a, int pos)
{
	int			i;

	i = 0;
	while ((*a)->pos >= pos)
	{
		i++;
		*a = (*a)->prev;
	}
	*a = goto_end(a);
	if (i >= pos)
	{
		while ((*a)->pos >= pos)
			ft_rev_rotate_a(a);
		return ;
	}
	while ((*a)->pos >= pos)
		ft_rotate_a(a);
}

void			check_rotate_b(t_node **b, int pos)
{
	int			i;

	i = 0;
	while ((*b)->pos < pos)
	{
		i++;
		*b = (*b)->prev;
	}
	*b = goto_end(b);
	if (i >= pos)
	{
		while ((*b)->pos < pos)
			ft_rev_rotate_b(b);
		return ;
	}
	while ((*b)->pos < pos)
		ft_rotate_b(b);
}

void			merge_to_a(t_node **a, t_node **b, int middle)
{
	int			i;

	middle = (middle / 2);
	if (middle == 2 || middle == 1)
		middle = 3;
	i = middle;
	while (*b && i > 0 && (*b)->prev->prev->prev)
	{
		if ((*b)->prev->pos >= middle && (*b)->pos < middle)
			ft_swap_b(b);
		else if ((*b)->pos < middle && end_of_list(b) >= middle)
			ft_rev_rotate_b(b);
		if ((*b)->pos >= middle)
		{
			ft_push_a(b, a);
			i--;
		}
		else
			check_rotate_b(b, middle);
	}
	if ((*b)->prev->prev->prev)
		merge_to_a(a, b, middle);
	else
		start_sort(a, b);
}

void			merge_to_b(t_node **a, t_node **b, int size)
{
	int			middle;
	int			i;
	int			tail;

	middle = (size / 2);
	i = middle;
	while (*a && i > 0)
	{
		tail = end_of_list(a);
		if ((*a)->prev->pos < middle && (*a)->pos >= middle)
			ft_swap_a(a);
		else if ((*a)->pos >= middle && tail < middle)
			ft_rev_rotate_a(a);
		if ((*a)->pos < middle)
		{
			ft_push_b(a, b);
			i--;
		}
		else
			check_rotate_a(a, middle);
	}
	merge_to_a(a, b, middle);
}
