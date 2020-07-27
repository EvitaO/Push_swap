/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 13:11:58 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:21:48 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			input_hex(t_flags *check, va_list arg)
{
	unsigned long long		i;
	char					*num;

	i = 0;
	num = NULL;
	check->option &= ~(SPACE | PLUS);
	i = ft_check_arg(check, arg);
	if (check->type == 'X')
		num = ft_itoa_base(i, 16, 55);
	else
		num = ft_itoa_base(i, 16, 87);
	ft_hexaocta(num, check);
	free(num);
}

void			ft_print_width_sp(t_flags *check)
{
	int				sign;

	sign = 0;
	if ((check->option & PLUS) || (check->option & SPACE))
		sign = 1;
	if (check->width == 0 && sign == 1)
		check->count++;
	if ((check->option & MINUS) > 0)
	{
		if ((check->option & PLUS))
			write(1, "+", 1);
		else if (check->option & SPACE)
			write(1, " ", 1);
		ft_width(check->width - sign, 0, ' ');
	}
	else
	{
		ft_width(check->width - sign, 0, ' ');
		if ((check->option & PLUS))
			write(1, "+", 1);
		else if (check->option & SPACE)
			write(1, " ", 1);
	}
}

void			ft_input_id(t_flags *check, va_list arg)
{
	long long					a;
	int							sign;
	char						*num;

	sign = 0;
	a = 0;
	check->option &= ~(HASHTAG);
	a = ft_check_argid(check, arg);
	if (a == 0 && check->percision == 0 && ((check->option & DOT) > 0))
	{
		check->count = check->count + check->width;
		ft_print_width_sp(check);
		return ;
	}
	if (a < 0)
	{
		sign = 1;
		a = a * -1;
	}
	num = ft_itoa_base(a, 10, 87);
	ft_di_int(num, sign, check);
	free(num);
}

void			input_int(t_flags *check, va_list arg)
{
	unsigned long long			uint;
	char						*num;

	uint = 0;
	num = NULL;
	if (check->type == 'u')
	{
		check->option &= ~(HASHTAG | SPACE | PLUS);
		uint = ft_check_arg(check, arg);
		num = ft_itoa_base(uint, 10, 87);
		ft_hexaocta(num, check);
	}
	else
		ft_input_id(check, arg);
	free(num);
}

void			input_char_str(t_flags *check, va_list arg)
{
	char					*s;
	char					a;

	a = 0;
	if (check->type == 's')
	{
		check->option &= ~(HASHTAG | SPACE | PLUS | ZERO);
		s = va_arg(arg, char *);
		if (s == NULL)
			s = "(null)";
		if (check->width == 0 && ((check->option & DOT) == 0))
			ft_putstr_check(s, check);
		else
			s_with_flag(check, s);
	}
	else if (check->type == 'c')
	{
		check->option &= ~(HASHTAG | SPACE | PLUS | ZERO | DOT);
		a = va_arg(arg, int);
		ft_print_char(a, check);
	}
}
