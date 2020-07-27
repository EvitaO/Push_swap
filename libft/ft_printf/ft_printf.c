/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/25 17:36:55 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:23:39 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_printf(const char *restrict format, ...)
{
	va_list			arg;
	int				res;
	int				i;
	t_flags			*check;

	i = 0;
	va_start(arg, format);
	check = (t_flags*)malloc(sizeof(t_flags));
	if (!check)
		return (-1);
	check->count = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_write_char(format[i], check);
			i++;
		}
		if (format[i] == '%')
			i = check_format(arg, (const char*)format, i, check);
	}
	va_end(arg);
	res = check->count;
	free(check);
	return (res);
}
