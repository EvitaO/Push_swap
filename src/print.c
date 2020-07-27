/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 17:18:02 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/22 12:26:05 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void			print_list(t_node **a, t_node **b)
{
	ft_printf("-----------------STACK_A-----------------\n");
	if (*a)
	{
		while ((*a)->prev)
		{
			ft_printf("nbr	%i------position	%i\n", (*a)->nbr, (*a)->pos);
			*a = (*a)->prev;
		}
		ft_printf("nbr	%i------position	%i\n", (*a)->nbr, (*a)->pos);
	}
	ft_printf("-----------------------------------------\n");
	ft_printf("-----------------STACK_B-----------------\n");
	if (*b)
	{
		while ((*b)->prev)
		{
			ft_printf("nbr	%i------position	%i\n", (*b)->nbr, (*b)->pos);
			*b = (*b)->prev;
		}
		ft_printf("nbr	%i------position	%i\n", (*b)->nbr, (*b)->pos);
	}
}

t_node			*goto_end(t_node **stack)
{
	if (*stack)
	{
		while ((*stack)->next)
			*stack = (*stack)->next;
	}
	return (*stack);
}
