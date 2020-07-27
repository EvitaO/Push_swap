/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_swap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 10:29:50 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/19 11:04:31 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void		check_swap(t_node **stack)
{
	int				numb;
	int				pos;

	if (*stack && (*stack)->prev)
	{
		numb = (*stack)->nbr;
		(*stack)->nbr = (*stack)->prev->nbr;
		(*stack)->prev->nbr = numb;
		pos = (*stack)->pos;
		(*stack)->pos = (*stack)->prev->pos;
		(*stack)->prev->pos = pos;
	}
}

void		swap_ab(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a) && (*stack_a)->prev)
		check_swap(stack_a);
	if ((*stack_b) && (*stack_b)->prev)
		check_swap(stack_b);
}
