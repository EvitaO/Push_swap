/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 10:31:54 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/19 11:04:15 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void			rotate(t_node **stack)
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

void			rotate_ab(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a) && (*stack_a)->prev)
		rotate(stack_a);
	if ((*stack_b) && (*stack_b)->prev)
		rotate(stack_b);
}
