/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 18:16:01 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/19 10:19:16 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void			ft_push_a(t_node **stack_src, t_node **stack_des)
{
	if (*stack_src)
	{
		if (!(*stack_des))
			*stack_des = *stack_src;
		else
			(*stack_des)->next = *stack_src;
		if ((*stack_src)->prev)
		{
			*stack_src = (*stack_src)->prev;
			(*stack_src)->next = NULL;
		}
		else
			*stack_src = NULL;
		if ((*stack_des)->next)
		{
			(*stack_des)->next->prev = *stack_des;
			*stack_des = (*stack_des)->next;
		}
		else
			(*stack_des)->prev = NULL;
	}
	ft_printf("pa\n");
}

void			ft_push_b(t_node **stack_src, t_node **stack_des)
{
	if (*stack_src)
	{
		if (!(*stack_des))
			*stack_des = *stack_src;
		else
			(*stack_des)->next = *stack_src;
		if ((*stack_src)->prev)
		{
			*stack_src = (*stack_src)->prev;
			(*stack_src)->next = NULL;
		}
		else
			*stack_src = NULL;
		if ((*stack_des)->next)
		{
			(*stack_des)->next->prev = *stack_des;
			*stack_des = (*stack_des)->next;
		}
		else
			(*stack_des)->prev = NULL;
	}
	ft_printf("pb\n");
}
