/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 13:27:34 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/19 10:20:00 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int					checks_for_sort_b(t_node **a, t_node **b, int tail)
{
	int				i;

	i = 0;
	if ((*a)->prev->pos == (*b)->pos + 1)
		ft_swap_a(a);
	else if (tail == (*b)->pos + 1)
		ft_rev_rotate_a(a);
	if ((*a)->pos == (*b)->pos + 1)
		i = 1;
	return (i);
}

int					checks_for_sort_b_2(t_node **a, t_node **b, int i)
{
	ft_push_b(a, b);
	if (i != 1)
	{
		check_rotate_exacte_a(a, (*b)->pos - 1);
		ft_push_b(a, b);
		if ((*a)->pos > (*a)->prev->pos)
			ft_swap_ab(a, b);
		else
			ft_swap_b(b);
	}
	i = 0;
	return (i);
}

int					checks_for_sort_a(t_node **a, t_node **b, int tail)
{
	int				i;

	i = 0;
	if ((*b)->prev->pos == (*a)->pos - 1)
		ft_swap_b(b);
	else if (tail == (*a)->pos - 1)
		ft_rev_rotate_b(b);
	if ((*b)->pos == (*a)->pos - 1)
		i = 1;
	return (i);
}

int					checks_for_sort_a_2(t_node **a, t_node **b, int i)
{
	ft_push_a(b, a);
	if (i != 1)
	{
		check_rotate_exacte_b(b, (*a)->pos + 1);
		ft_push_a(b, a);
		if ((*b)->pos < (*b)->prev->pos)
			ft_swap_ab(a, b);
		else
			ft_swap_a(a);
	}
	i = 0;
	return (i);
}
