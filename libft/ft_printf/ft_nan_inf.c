/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nan_inf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 13:34:48 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:22:34 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_write_inf_nan(long double i, t_flags *check)
{
	if (i != i)
	{
		write(1, "nan", 3);
		check->count = check->count + 3;
	}
	else if (i == 1.0 / 0.0)
	{
		if ((check->option & PLUS) > 0)
			write(1, "+", 1);
		write(1, "inf", 3);
		check->count = check->count + 3;
	}
	else
	{
		write(1, "-inf", 4);
		check->count = check->count + 4;
	}
}

void			ft_nan_inf(long double i, t_flags *check)
{
	int				k;

	k = 0;
	if ((check->option & PLUS) > 0 && (i == (1.0 / 0.0)))
		k = 1;
	if ((check->option & MINUS) == 0)
	{
		if (i == (-1.0 / 0.0))
			ft_width(check->width, 4, ' ');
		else
			ft_width(check->width, (3 + k), ' ');
		ft_write_inf_nan(i, check);
	}
	else
	{
		ft_write_inf_nan(i, check);
		if (i == (-1.0 / 0.0))
			ft_width(check->width, 4, ' ');
		else
			ft_width(check->width, (3 + k), ' ');
	}
	if (i == (-1.0 / 0.0) && check->width > 4)
		check->count = check->count + (check->width - 4);
	else if (i != (-1.0 / 0.0) && check->width > 3)
		check->count = check->count + (check->width - 3);
}
