/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 13:30:26 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/22 15:20:54 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int					execute(char *line, t_node **a, t_node **b)
{
	if (ft_strcmp(line, "sa") == 0)
		check_swap(a);
	else if (ft_strcmp(line, "ss") == 0)
		swap_ab(a, b);
	else if (ft_strcmp(line, "sb") == 0)
		check_swap(b);
	else if (ft_strcmp(line, "pa") == 0)
		push(b, a);
	else if (ft_strcmp(line, "pb") == 0)
		push(a, b);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_ab(a, b);
	else if (ft_strcmp(line, "rra") == 0)
		rev_rotate(a);
	else if (ft_strcmp(line, "rrb") == 0)
		rev_rotate(b);
	else if (ft_strcmp(line, "rrr") == 0)
		rev_rotate_ab(a, b);
	else
		return (1);
	return (0);
}

void				checker(t_node **a, t_node **b)
{
	char			*line;

	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (execute(line, a, b) == 1)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		free(line);
	}
	free(line);
}

int					main(int argc, char **argv)
{
	t_node			*a;
	t_node			*b;

	first_elem(&a, &b);
	if (argc < 2)
		return (0);
	else if (argc == 2)
		argc = str_argument(argv, &a);
	else
	{
		ft_check_input(argv, argc);
		make_list(&a, argc, argv);
	}
	checker(&a, &b);
	if (check_if_sorted(&a, argc - 1) == 1 && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(&a, &b);
	return (0);
}
