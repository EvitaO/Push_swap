/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 16:26:24 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/27 13:31:40 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort_alg(t_node **stack_a, t_node **stack_b, int argc)
{
	if (check_if_sorted(stack_a, argc - 1) == 1)
		return ;
	if (argc >= 2 && argc <= 6)
		max_five(stack_a, stack_b, argc);
	else
		merge_to_b(stack_a, stack_b, argc - 1);
}

int		main(int argc, char **argv)
{
	t_node		*stack_a;
	t_node		*stack_b;
	t_options	option;

	if (argc < 2)
		return (0);
	first_elem(&stack_a, &stack_b);
	set_option(argv[1], &option);
	if (argc == 2)
		argc = str_argument(argv, &stack_a);
	else
	{
		ft_check_input(argv, argc);
		make_list(&stack_a, argc, argv);
	}
	put_pos(&stack_a, argc - 1);
	if (option.i != 0)
		argc--;
	sort_alg(&stack_a, &stack_b, argc);
	if (option.i == 1)
		do_option(&stack_a, &stack_b);
	free_list(&stack_a, &stack_b);
	return (0);
}
