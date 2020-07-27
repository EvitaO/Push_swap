/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_input_octal.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 20:25:43 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:22:22 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			input_octal_special(t_flags *check)
{
	int					k;

	k = 0;
	if ((check->option & HASHTAG) > 0)
		k = 1;
	if ((check->option & MINUS) > 0 && (check->option & HASHTAG) > 0)
	{
		if ((check->option & HASHTAG) > 0)
		{
			ft_write_char('0', check);
			check->width--;
		}
		ft_width(check->width, k, ' ');
	}
	else
	{
		ft_width(check->width, k, ' ');
		if ((check->option & HASHTAG) > 0)
		{
			ft_write_char('0', check);
			check->width--;
		}
	}
	if (check->width > 0)
		check->count = check->count + check->width;
}

void			input_base(t_flags *check, va_list arg)
{
	unsigned long long		i;
	char					*num;

	num = NULL;
	if (check->type == 'o')
	{
		check->option &= ~(SPACE | PLUS);
		if ((check->option & DOT) > 0)
			check->option &= ~ZERO;
		i = ft_check_arg(check, arg);
		if (i == 0 && ((check->option & DOT) > 0) && check->percision == 0)
			input_octal_special(check);
		else
		{
			num = ft_itoa_base(i, 8, 87);
			ft_hexaocta(num, check);
		}
	}
	else if (check->type == 'p')
	{
		check->option &= ~(HASHTAG | SPACE | PLUS | ZERO | DOT);
		i = va_arg(arg, unsigned long);
		p_with_flag(check, i);
	}
	free(num);
}
