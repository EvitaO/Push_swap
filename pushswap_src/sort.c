/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   5test.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 11:34:40 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/21 01:04:46 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void			check_rotate_exacte_b(t_node **b, int pos)
{
	int			i;
	int			size;

	size = lst_size_rev(*b) + 1;
	i = 0;
	while ((*b)->pos != pos)
	{
		i++;
		*b = (*b)->prev;
	}
	*b = goto_end(b);
	if (i >= (size / 2))
	{
		while ((*b)->pos != pos)
			ft_rev_rotate_b(b);
		return ;
	}
	while ((*b)->pos != pos)
		ft_rotate_b(b);
}

void			check_rotate_exacte_a(t_node **a, int pos)
{
	int			i;
	int			size;

	size = lst_size_rev(*a) + 1;
	i = 0;
	while ((*a)->pos != pos)
	{
		i++;
		*a = (*a)->prev;
	}
	*a = goto_end(a);
	if (i >= (size / 2))
	{
		while ((*a)->pos != pos)
			ft_rev_rotate_a(a);
		return ;
	}
	while ((*a)->pos != pos)
		ft_rotate_a(a);
}

void			sort_part_3(t_node **a, t_node **b)
{
	int			tail;
	int			i;

	max_three_numb(a);
	while ((*b)->prev)
	{
		tail = end_of_list(b);
		i = checks_for_sort_a(a, b, tail);
		if ((*b)->prev->pos == (*a)->pos - 2 && i == 0)
			ft_swap_b(b);
		else if (tail == (*a)->pos - 2 && i == 0)
			ft_rev_rotate_b(b);
		if ((*b)->pos == (*a)->pos - 2 || i == 1)
			i = checks_for_sort_a_2(a, b, i);
		else
			check_rotate_exacte_b(b, (*a)->pos - 1);
	}
	if (*b)
		ft_push_a(b, a);
}

void			sort_part_2(t_node **a, t_node **b, int size, int max_pos)
{
	int			middle;
	int			i;

	middle = size - (max_pos / 2);
	if (middle >= size - 3)
		middle = size - 3;
	i = middle;
	while ((*a)->prev->prev->prev && i < size)
	{
		if ((*a)->prev->pos < middle && (*a)->pos >= middle)
			ft_swap_a(a);
		else if ((*a)->pos >= middle && end_of_list(a) < middle)
			ft_rev_rotate_a(a);
		if ((*a)->pos < middle)
		{
			ft_push_b(a, b);
			i++;
		}
		else
			check_rotate_a(a, middle);
	}
	if ((*a)->prev->prev->prev)
		sort_part_2(a, b, size, max_pos / 2);
	else
		sort_part_3(a, b);
}

void			start_sort(t_node **a, t_node **b)
{
	int			tail;
	int			size;
	int			max_pos;
	int			i;

	size = lst_size_rev(*a) + lst_size_rev(*b) + 2;
	max_pos = size - (size / 2);
	rev_max_three_numb(b);
	while ((*a)->prev->prev->prev && (*b)->pos + 1 != max_pos)
	{
		tail = end_of_list(a);
		i = checks_for_sort_b(a, b, tail);
		if ((*a)->prev->pos == (*b)->pos + 2 && (*b)->pos + 2 != max_pos &&\
			i == 0)
			ft_swap_a(a);
		else if (tail == (*b)->pos + 2 && (*b)->pos + 2 != max_pos && i == 0)
			ft_rev_rotate_a(a);
		if (((*a)->pos == (*b)->pos + 2 && (*b)->pos + 2 != max_pos) || i == 1)
			i = checks_for_sort_b_2(a, b, i);
		else
			check_rotate_exacte_a(a, (*b)->pos + 1);
	}
	sort_part_2(a, b, size, max_pos);
	max_three_numb(a);
}
