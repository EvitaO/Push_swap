/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_num.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/01 16:59:13 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:22:03 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_count_num(unsigned long long n, int base)
{
	int		cnt;

	cnt = 0;
	if (n == 0)
		cnt = 1;
	while (n > 0)
	{
		cnt++;
		n = n / base;
	}
	return (cnt);
}

int		ft_wildcard_num(t_flags *check, va_list a, const char *format, int j)
{
	if (format[j - 1] != '.')
		check->width = va_arg(a, int);
	if (check->width < 0)
	{
		check->width = check->width * -1;
		check->option |= MINUS;
	}
	else if (format[j - 1] == '.')
		check->percision = va_arg(a, int);
	if (check->percision < 0)
	{
		check->percision = 0;
		check->option &= ~(DOT);
	}
	return (j);
}
