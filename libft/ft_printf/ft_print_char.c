/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/01 17:46:22 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:22:46 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				ft_print_char(char a, t_flags *check)
{
	if (check->width == 0)
	{
		write(1, &a, 1);
		check->count++;
	}
	else if ((check->option & MINUS) > 0)
	{
		write(1, &a, 1);
		ft_width(check->width, 1, ' ');
	}
	else
	{
		ft_width(check->width, 1, ' ');
		write(1, &a, 1);
	}
	check->count = check->count + check->width;
}

void				ft_write_char(char c, t_flags *check)
{
	write(1, &c, 1);
	check->count++;
}
