/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   max_five.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:21:36 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/22 15:51:31 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void			max_five(t_node **a, t_node **b, int argc)
{
	if (argc == 2)
		return ;
	if (check_if_sorted(a, argc - 1) == 1)
		exit(1);
	if (argc > 4)
	{
		check_rotate_exacte_a(a, 0);
		ft_push_b(a, b);
	}
	if (argc > 5)
	{
		check_rotate_exacte_a(a, 1);
		ft_push_b(a, b);
	}
	max_three_numb(a);
	while (*b)
		ft_push_a(b, a);
}
