/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 18:05:48 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/19 10:20:05 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void		swap(t_node **stack)
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

void		ft_swap_a(t_node **stack)
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
	ft_printf("sa\n");
}

void		ft_swap_b(t_node **stack)
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
	ft_printf("sb\n");
}

void		ft_swap_ab(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a) && (*stack_a)->prev)
		swap(stack_a);
	if ((*stack_b) && (*stack_b)->prev)
		swap(stack_b);
	ft_printf("ss\n");
}
