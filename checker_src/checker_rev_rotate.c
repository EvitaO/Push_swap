/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_rev_rotate.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 10:30:58 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/19 11:04:02 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void			rev_rotate(t_node **stack)
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

void			rev_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a) && (*stack_a)->prev)
		rev_rotate(stack_a);
	if ((*stack_b) && (*stack_b)->prev)
		rev_rotate(stack_b);
}
