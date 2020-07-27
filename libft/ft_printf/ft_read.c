/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 14:28:25 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:24:01 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				read_struct(t_flags *check, va_list arg)
{
	if (check->type == 's' || check->type == 'c')
		input_char_str(check, arg);
	else if (check->type == 'X' || check->type == 'x')
		input_hex(check, arg);
	else if (check->type == 'p' || check->type == 'o')
		input_base(check, arg);
	else if (check->type == 'd' || check->type == 'i' || check->type == 'u')
		input_int(check, arg);
	else if (check->type == 'f')
		input_flo(check, arg);
	else if (check->type == 'b')
		print_binary(check, arg);
	else
		ft_percent_flag(check);
}

long double			ft_check_arg(t_flags *check, va_list arg)
{
	if (check->type == 'f' && ((check->option & L) > 0))
		return ((va_arg(arg, long double)));
	else if (check->type == 'f' && ((check->option & L) == 0))
		return ((double)(va_arg(arg, double)));
	else if ((check->option & ELLELL) > 0)
		return ((unsigned long long)(va_arg(arg, unsigned long long)));
	else if ((check->option & ELL) > 0)
		return ((unsigned long)(va_arg(arg, unsigned long)));
	else if ((check->option & HH) > 0)
		return ((unsigned char)(va_arg(arg, unsigned int)));
	else if ((check->option & H) > 0)
		return ((unsigned short)(va_arg(arg, unsigned int)));
	else
		return ((unsigned int)va_arg(arg, unsigned int));
}

long long			ft_check_argid(t_flags *check, va_list arg)
{
	if ((check->option & ELLELL) > 0)
		return ((long long)va_arg(arg, long long));
	else if ((check->option & ELL) > 0)
		return ((long)va_arg(arg, long long));
	else if ((check->option & HH) > 0)
		return ((signed char)(va_arg(arg, int)));
	else if ((check->option & H) > 0)
		return ((short)(va_arg(arg, int)));
	else
		return ((int)va_arg(arg, int));
}
