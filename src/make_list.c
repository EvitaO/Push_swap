/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 10:11:48 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/21 03:17:27 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_node			*make_node(char *str, t_node **stack_a)
{
	t_node		*tmp;

	tmp = (t_node*)malloc(sizeof(t_node));
	tmp->pos = -1;
	tmp->nbr = ft_atoi(str);
	if (*stack_a)
		tmp->prev = *stack_a;
	else
		tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void			make_list(t_node **stack_a, int argc, char **argv)
{
	int			i;

	i = argc - 1;
	(*stack_a)->nbr = ft_atoi(argv[i]);
	(*stack_a)->next = NULL;
	i--;
	while (i >= 0)
	{
		if (ft_strcmp("./checker", argv[i]) != 0 && \
			ft_strcmp("./push_swap", argv[i]) != 0 && \
			ft_strcmp("-s", argv[i]) != 0 && ft_strcmp("-h", argv[i]) != 0)
		{
			(*stack_a)->next = make_node(argv[i], stack_a);
			*stack_a = (*stack_a)->next;
		}
		i--;
	}
}

void			first_elem(t_node **a, t_node **b)
{
	*b = NULL;
	*a = (t_node*)malloc(sizeof(t_node));
	(*a)->prev = NULL;
	(*a)->pos = -1;
}
