/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floats2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 18:31:42 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:22:16 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long double	ft_make_dec_num(unsigned long long *x, long double *i, int *cnt)
{
	long double				num;

	num = 0;
	while (*i > 0 && *cnt > 0)
	{
		*x = *i * 10;
		*i = *i * 10 - *x;
		num = num * 10 + *x;
		*cnt = *cnt - 1;
	}
	while (*cnt > 0)
	{
		num = num * 10;
		*cnt = *cnt - 1;
	}
	return (num);
}

void		ft_write_flags2(t_flags *check, int sign)
{
	if (sign == 1)
		write(1, "-", 1);
	if ((check->option & PLUS) > 0 && sign == 0)
	{
		check->option &= ~(SPACE);
		write(1, "+", 1);
		check->count++;
	}
	else if (sign == 0)
	{
		write(1, " ", 1);
		check->count++;
	}
	check->option &= ~(PLUS | SPACE);
}

void		ft_ifs_flo(t_flags *check, int tot, int sign, unsigned long long x)
{
	x = x + check->floats_roundoff;
	check->count = check->count + ft_count_num(x, 10);
	if ((check->option & MINUS) == 0)
	{
		if ((check->option & ZERO) > 0)
			ft_write_flags2(check, sign);
		ft_write_width(check, tot);
	}
	if (sign == 1 && ((check->option & ZERO) == 0))
		write(1, "-", 1);
	if (((check->option & SPACE) > 0) || ((check->option & PLUS) > 0))
		ft_write_flags(check, sign);
	ft_putnbr(x);
	if (check->percision > 0 || ((check->option & HASHTAG) > 0))
	{
		write(1, ".", 1);
		check->count++;
	}
	if (check->floats_roundoff == 1)
	{
		ft_width(check->percision, 0, '0');
		if (check->option & MINUS)
			ft_write_width(check, tot);
	}
}

void		ft_put_float(unsigned long long p, int tot, t_flags *check)
{
	while (ft_count_num(p, 10) != check->percision)
	{
		write(1, "0", 1);
		check->percision--;
	}
	ft_putnbr_base(p, 10, 1);
	if (check->option & MINUS)
		ft_write_width(check, tot);
}
