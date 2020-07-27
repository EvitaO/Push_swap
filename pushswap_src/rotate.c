/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:40:50 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/19 10:19:49 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void			ft_rotate(t_node **stack)
{
	t_node		*head;

	head = *stack;
	if ((*stack) && (*stack)->prev)
	{
		*stack = (*stack)->prev;
		(*stack)->next = NULL;
		while ((*stack)->prev)
			*stack = (*stack)->prev;
		(*stack)->prev = head;
		(*stack)->prev->prev = NULL;
		(*stack)->prev->next = *stack;
		while ((*stack)->next)
			*stack = (*stack)->next;
	}
}

void			ft_rotate_a(t_node **stack)
{
	t_node		*head;

	head = *stack;
	if ((*stack) && (*stack)->prev)
	{
		*stack = (*stack)->prev;
		(*stack)->next = NULL;
		while ((*stack)->prev)
			*stack = (*stack)->prev;
		(*stack)->prev = head;
		(*stack)->prev->prev = NULL;
		(*stack)->prev->next = *stack;
		while ((*stack)->next)
			*stack = (*stack)->next;
	}
	ft_printf("ra\n");
}

void			ft_rotate_b(t_node **stack)
{
	t_node		*head;

	head = *stack;
	if ((*stack) && (*stack)->prev)
	{
		*stack = (*stack)->prev;
		(*stack)->next = NULL;
		while ((*stack)->prev)
			*stack = (*stack)->prev;
		(*stack)->prev = head;
		(*stack)->prev->prev = NULL;
		(*stack)->prev->next = *stack;
		while ((*stack)->next)
			*stack = (*stack)->next;
	}
	ft_printf("rb\n");
}

void			ft_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a) && (*stack_a)->prev)
		ft_rotate(stack_a);
	if ((*stack_b) && (*stack_b)->prev)
		ft_rotate(stack_b);
	ft_printf("rr\n");
}
