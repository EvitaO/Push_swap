/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:40:50 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/19 10:19:41 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void			ft_rev_rotate(t_node **stack)
{
	t_node		*head;

	if ((*stack) && (*stack)->prev)
	{
		while ((*stack)->prev)
			*stack = (*stack)->prev;
		head = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = head;
		(*stack)->next->next = NULL;
		(*stack)->next->prev = *stack;
		*stack = (*stack)->next;
	}
}

void			ft_rev_rotate_a(t_node **stack)
{
	t_node		*head;

	if ((*stack) && (*stack)->prev)
	{
		while ((*stack)->prev)
			*stack = (*stack)->prev;
		head = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = head;
		(*stack)->next->next = NULL;
		(*stack)->next->prev = *stack;
		*stack = (*stack)->next;
	}
	ft_printf("rra\n");
}

void			ft_rev_rotate_b(t_node **stack)
{
	t_node		*head;

	if ((*stack) && (*stack)->prev)
	{
		while ((*stack)->prev)
			*stack = (*stack)->prev;
		head = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = head;
		(*stack)->next->next = NULL;
		(*stack)->next->prev = *stack;
		*stack = (*stack)->next;
	}
	ft_printf("rrb\n");
}

void			ft_rev_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a) && (*stack_a)->prev)
		ft_rev_rotate(stack_a);
	if ((*stack_b) && (*stack_b)->prev)
		ft_rev_rotate(stack_b);
	ft_printf("rrr\n");
}
