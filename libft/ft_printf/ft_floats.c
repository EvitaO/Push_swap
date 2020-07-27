/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floats.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/25 09:44:05 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:22:10 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long long	ft_flo_zero(long double i, t_flags *check)
{
	unsigned long long			x;
	unsigned long long			r;

	x = i;
	i = (i - x) * 10;
	r = i;
	if (check->percision == 0)
	{
		if (r == 5 && ((i - r) * 10 != 0) && x == 0)
			return (x + 1);
		else if (r == 5 && (x % 2) == 0)
			return (x);
		else if (x % 2 != 0 && r == 5)
			return (x + 1);
		else if (r > 5)
			return (x + 1);
		return (x);
	}
	return (x);
}

unsigned long long	roff(t_flags *c, unsigned long long x, int d, long double n)
{
	if (x == 5 && d == 0)
		n = n + 1;
	else if (x == 5)
		c->floats_roundoff = 2;
	return (n);
}

unsigned long long	ft_flo_num(long double i, t_flags *check)
{
	long double			num;
	unsigned long long	x;
	int					lastd;
	int					cnt;

	x = i * 10;
	cnt = check->percision;
	num = ft_make_dec_num(&x, &i, &cnt);
	if (cnt == 0)
	{
		lastd = x;
		x = i * 10;
		if ((x == 5 && (lastd % 2) != 0) || (x > 5))
		{
			if (ft_count_num(num, 10) == check->percision && \
				ft_count_num(num + 1, 10) == check->percision + 1)
				check->floats_roundoff = 1;
			else
				num = num + 1;
		}
		else if ((x == 5 && lastd == 0) || x == 5)
			num = roff(check, x, lastd, num);
	}
	return (num);
}

int					ft_check_pos(long double *i, t_flags *check, int b)
{
	if (b == 1)
	{
		if (*i == 1.0 / 0.0 || *i == -1.0 / 0.0 || *i != *i)
		{
			ft_nan_inf(*i, check);
			return (-1);
		}
		if (1 / *i == 1 / -0.0 || *i < 0)
			return (1);
	}
	else
	{
		if (1 / *i == 1 / -0.0)
		{
			*i = 0.0;
			return (1);
		}
		if (*i < 0)
		{
			(*i) = (*i) * -1;
			return (1);
		}
	}
	return (0);
}

void				input_flo(t_flags *check, va_list arg)
{
	long double						i;
	unsigned long long				x;
	int								sign;
	int								tot;

	tot = check->count;
	i = ft_check_arg(check, arg);
	sign = ft_check_pos(&i, check, 1);
	if ((check->option & DOT) == 0)
		check->percision = 6;
	x = 0;
	if (sign == -1)
		return ;
	check->count = check->count + check->percision + sign;
	if ((check->option & MINUS) > 0)
		ft_negwth(check, x, i, tot);
	else
		ft_negwth(check, x, i, tot);
	if (check->width > check->count - tot)
		check->count = check->count + (check->width - (check->count - tot));
}
