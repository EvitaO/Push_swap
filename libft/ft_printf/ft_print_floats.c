/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_floats.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/01 18:09:13 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:22:58 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_hsp(t_flags *check)
{
	int			f;

	f = 0;
	if (check->percision > 0 || ((check->option & HASHTAG) > 0))
		f++;
	if (((check->option & SPACE) > 0) || ((check->option & PLUS) > 0))
		f++;
	return (f);
}

void	ft_write_flags(t_flags *check, int sign)
{
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
}

void	ft_write_width(t_flags *check, int tot)
{
	if ((check->option & MINUS) > 0)
	{
		check->option &= ~ZERO;
		ft_width(check->width, (check->count - tot), ' ');
	}
	else
	{
		if ((check->option & ZERO) > 0)
		{
			ft_width(check->width, (check->count - tot + \
			ft_check_hsp(check)), '0');
		}
		else
		{
			ft_width(check->width, (check->count - tot + \
			ft_check_hsp(check)), ' ');
		}
	}
}

void	ft_dec_nul(t_flags *check, unsigned long long x, int tot, int sign)
{
	check->count = check->count + ft_count_num(x, 10);
	if ((check->option & MINUS) == 0)
	{
		if ((check->option & ZERO) > 0)
		{
			ft_write_flags2(check, sign);
			sign = 0;
		}
		ft_write_width(check, tot);
	}
	if (sign == 1)
		write(1, "-", 1);
	else if (((check->option & SPACE) > 0) || ((check->option & PLUS) > 0))
		ft_write_flags(check, sign);
	ft_putnbr(x);
	if (check->percision > 0 || ((check->option & HASHTAG) > 0))
	{
		write(1, ".", 1);
		check->count++;
	}
	ft_width(check->percision, 0, '0');
	if (check->option & MINUS)
		ft_write_width(check, tot);
}

void	ft_negwth(t_flags *check, unsigned long long x, long double i, int tot)
{
	unsigned long long			p;
	int							sign;

	sign = ft_check_pos(&i, check, 2);
	x = ft_flo_zero(i, check);
	i = i - x;
	if (i == 0 || check->percision == 0)
	{
		ft_dec_nul(check, x, tot, sign);
		return ;
	}
	p = ft_flo_num(i, check);
	if (check->floats_roundoff == 2)
	{
		if (x == 0)
			p = p + 1;
		check->floats_roundoff = 0;
	}
	ft_ifs_flo(check, tot, sign, x);
	if (check->floats_roundoff == 0)
		ft_put_float(p, tot, check);
}
