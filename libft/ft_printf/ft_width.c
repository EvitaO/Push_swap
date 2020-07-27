/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_width.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 17:40:10 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:24:07 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_width(int k, int stop, char c)
{
	while (k > stop)
	{
		write(1, &c, 1);
		k--;
	}
}

void		ft_print_width(t_flags *check, int len, int s)
{
	if (check->percision > len)
	{
		ft_width(check->width, (check->percision + s), ' ');
		check->count = check->count + (check->width - (check->percision + s));
	}
	else if (check->width > (len + s))
	{
		ft_width(check->width, (len + s), ' ');
		check->count = check->count + (check->width - (len + s));
	}
}
