/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_binary.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/08 16:35:26 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:22:40 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_check_flagsb(t_flags *check, int i)
{
	if (check->width > i)
		check->width = check->width - i;
	else
		check->width = 0;
	if ((check->option & MINUS) == 0 && (check->option & ZERO) == 0)
		ft_width(check->width, 0, ' ');
	else if ((check->option & MINUS) == 0 && (check->option & ZERO) > 0)
		ft_width(check->width, 0, '0');
}

void			ft_big_bin(int i, t_flags *check, unsigned long long num)
{
	int						x;
	char					*res;

	x = 0;
	res = ft_itoa_base(num, 2, 55);
	ft_check_flagsb(check, 64);
	while (x < (64 - i))
	{
		write(1, "0", 1);
		x++;
		if (x % 4 == 0 && x != (64 - 1))
			write(1, " ", 1);
	}
	i = 0;
	while (i + x + 1 <= 64)
	{
		write(1, &res[i], 1);
		if ((x + i + 1) % 4 == 0 && (i + x + 1) != 64)
			write(1, " ", 1);
		i++;
	}
	check->count = check->count + 79 + check->width;
	if ((check->option & MINUS) > 0)
		ft_width(check->width, 0, ' ');
}

void			ft_small_bin(int i, t_flags *check, unsigned long long num)
{
	int					k;
	char				*res;

	k = 0;
	res = ft_itoa_base(num, 2, 55);
	ft_check_flagsb(check, 32);
	while (k < (32 - i))
	{
		write(1, "0", 1);
		k++;
		if (k % 4 == 0 && k != (32 - 1))
			write(1, " ", 1);
	}
	i = 0;
	while (i + k + 1 <= 32)
	{
		write(1, &res[i], 1);
		if ((k + i + 1) % 4 == 0 && (k + i + 1) != 32)
			write(1, " ", 1);
		i++;
	}
	check->count = check->count + 39 + check->width;
}

void			print_binary(t_flags *check, va_list arg)
{
	unsigned long long			num;
	int							i;

	num = (unsigned long long)va_arg(arg, unsigned long long);
	i = ft_count_num(num, 2);
	if (i > 32)
		ft_big_bin(i, check, num);
	else
		ft_small_bin(i, check, num);
	if ((check->option & MINUS) > 0)
		ft_width(check->width, 0, ' ');
}
