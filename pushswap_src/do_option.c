/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_option.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 02:50:53 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/21 03:40:33 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void			do_option(t_node **a, t_node **b)
{
	print_list(a, b);
	*a = goto_end(a);
	*b = goto_end(b);
}

void			do_help(void)
{
	ft_printf("usage: ./push_swap [-hs] numbers ...\n\
			\nh: print this help message\
			\ns: print the stacks after sorting\n\
			\npush_swap sorts numbers in ascending order\n");
}

void			set_option(char *str, t_options *option)
{
	if (ft_strcmp("-s", str) == 0)
		option->i = 1;
	else if (ft_strcmp("-h", str) == 0)
	{
		do_help();
		exit(1);
	}
	else
		option->i = 0;
}
