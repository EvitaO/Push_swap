/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_ints.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/01 17:50:42 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:23:11 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				ft_percent_flag(t_flags *check)
{
	if (check->width == 0)
	{
		write(1, &check->type, 1);
		check->count++;
	}
	else if (check->width > 0 && ((check->option & MINUS) == 0))
	{
		if ((check->option & ZERO) > 0)
			ft_width(check->width, 1, '0');
		else
			ft_width(check->width, 1, ' ');
		write(1, &check->type, 1);
		check->count = check->count + check->width;
	}
	else if (check->width > 0 && ((check->option & MINUS) > 0))
	{
		write(1, &check->type, 1);
		if ((check->option & ZERO) > 0)
			ft_width(check->width, 1, '0');
		else
			ft_width(check->width, 1, ' ');
		check->count = check->count + check->width;
	}
}

void				ft_check_width(int len, t_flags *check, int s)
{
	if (s == 0 && ((check->option & PLUS) || (check->option & SPACE)))
		s = 1;
	if ((check->option & ZERO) == 0)
	{
		if (check->percision > (len + s))
		{
			ft_width(check->width - s, check->percision, ' ');
			if ((check->width - s) > check->percision)
				check->count = check->count + \
				((check->width - s) - check->percision);
		}
		else
			ft_print_width(check, len, s);
	}
}

void				ft_print_plus_space_min(t_flags *check, int sign)
{
	if (((check->option & PLUS) > 0) && sign == 0)
	{
		check->option &= ~SPACE;
		write(1, "+", 1);
		check->count++;
	}
	if (((check->option & SPACE) > 0) && sign == 0)
	{
		write(1, " ", 1);
		check->count++;
	}
	if (sign == 1)
	{
		write(1, "-", 1);
		check->count++;
	}
}

int					ft_print_flags(t_flags *check, int sign, int len)
{
	ft_print_plus_space_min(check, sign);
	if (((check->option & PLUS) > 0) || ((check->option & SPACE) > 0))
		sign = 1;
	if ((check->option & ZERO) > 0)
	{
		while (check->width > check->percision && check->width > (len + sign))
		{
			write(1, "0", 1);
			check->width--;
			check->count++;
		}
	}
	while (check->percision > len)
	{
		write(1, "0", 1);
		len++;
		check->count++;
	}
	return (sign);
}

void				ft_di_int(char *num, int s, t_flags *check)
{
	int			len;
	int			i;

	i = 0;
	len = ft_strlen(num);
	if ((check->option & MINUS) > 0)
		check->option &= ~ZERO;
	if ((check->option & DOT) > 0)
		check->option &= ~ZERO;
	if ((check->option & MINUS) == 0)
		ft_check_width(len, check, s);
	s = ft_print_flags(check, s, len);
	ft_putstr_check(num, check);
	if (((check->option & MINUS) > 0) && check->percision > len)
	{
		ft_width(check->width, (check->percision + s), ' ');
		if (check->width > (check->percision + s))
			check->count = check->count + check->width - (check->percision + s);
	}
	else if (((check->option & MINUS)) && ((len + s) >= check->percision))
	{
		ft_width(check->width, (len + s), ' ');
		if (check->width >= (len + s))
			check->count = check->count + (check->width - (len + s));
	}
}
