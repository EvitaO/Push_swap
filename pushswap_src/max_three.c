/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   max_three.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 12:34:40 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/22 14:11:53 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void		max_three_numb(t_node **a)
{
	int			cnt;

	cnt = 0;
	if (!((*a)->prev->prev) && (*a)->nbr < (*a)->prev->nbr)
		return ;
	else if (!((*a)->prev->prev) && (*a)->nbr > (*a)->prev->nbr)
		ft_swap_a(a);
	while (cnt < 2 && (*a)->prev->prev)
	{
		if ((*a)->nbr < (*a)->prev->nbr && (*a)->nbr < (*a)->\
			prev->prev->nbr && (*a)->prev->nbr < (*a)->\
			prev->prev->nbr)
			return ;
		if ((*a)->nbr > (*a)->prev->nbr && (*a)->nbr > (*a)->prev->prev->nbr)
			ft_rotate_a(a);
		else if ((*a)->nbr > (*a)->prev->nbr && (*a)->nbr < (*a)->prev->\
				prev->nbr)
			ft_swap_a(a);
		else if ((*a)->nbr < (*a)->prev->nbr)
			ft_rev_rotate_a(a);
		cnt++;
	}
}

void		rev_max_three_numb(t_node **b)
{
	int			cnt;

	cnt = 0;
	if (!((*b)->prev->prev) && (*b)->nbr > (*b)->prev->nbr)
		return ;
	else if (!((*b)->prev->prev) && (*b)->nbr < (*b)->prev->nbr)
		ft_swap_b(b);
	while (cnt < 2 && (*b)->prev->prev)
	{
		if ((*b)->nbr > (*b)->prev->nbr && (*b)->nbr > (*b)->\
			prev->prev->nbr && (*b)->prev->nbr > (*b)->\
			prev->prev->nbr)
			return ;
		if ((*b)->nbr < (*b)->prev->nbr && (*b)->nbr < (*b)->prev->prev->nbr)
			ft_rotate_b(b);
		else if ((*b)->nbr < (*b)->prev->nbr && (*b)->nbr > (*b)->prev->\
				prev->nbr)
			ft_swap_b(b);
		else if ((*b)->nbr > (*b)->prev->nbr)
			ft_rev_rotate_b(b);
		cnt++;
	}
}
