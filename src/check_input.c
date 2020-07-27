/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 10:56:14 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/02/21 03:15:43 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

double			ft_atoidouble(const char *str)
{
	int		i;
	double	sign;
	double	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] == '\t') || (str[i] == '\v') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\f') || (str[i] == ' '))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void			ft_check_numb(char **str, int argc)
{
	int			i;

	i = 0;
	while (str[i] && i < argc)
	{
		if (ft_strcmp("./checker", str[i]) == 0 || \
				ft_strcmp("./push_swap", str[i]) == 0)
			i++;
		if (i == 1 && (ft_strcmp("-s", str[i]) == 0 || \
				ft_strcmp("-h", str[i]) == 0))
			i++;
		if (ft_atoidouble(str[i]) > 2147483647 \
				|| ft_atoidouble(str[i]) < -2147483648)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		if (ft_isnum(str[i]) == 1)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		i++;
	}
}

void			ft_check_input(char **str, int argc)
{
	int			i;
	int			j;

	i = 0;
	while (str[i] && i < argc)
	{
		j = 0;
		while (argc > j)
		{
			if (i != j && ft_strcmp("./checker", str[i]) != 0 && \
				ft_strcmp("./push_swap", str[i]) != 0)
			{
				if (ft_strcmp(str[i], str[j]) == 0)
				{
					ft_printf("Error\n");
					exit(-1);
				}
			}
			j++;
		}
		i++;
	}
	ft_check_numb(str, argc);
}
