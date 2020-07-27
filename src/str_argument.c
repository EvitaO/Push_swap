/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_argument.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 13:17:51 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/27 13:33:51 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int					str_argument(char **argv, t_node **stack_a)
{
	int				i;
	int				ret;

	i = 1;
	argv = ft_strsplit(argv[1], ' ');
	if (!argv[0])
		exit(-1);
	while (argv[i])
		i++;
	ret = i;
	ft_check_input(argv, ret);
	make_list(stack_a, ret, argv);
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	return (ret + 1);
}
