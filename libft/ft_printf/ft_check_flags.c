/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_flags.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/04 13:15:42 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:21:41 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_num(t_flags *check, const char *format, int j, va_list a)
{
	int				k;
	int				res;

	k = 0;
	res = 0;
	if (format[j] == '*')
		return (ft_wildcard_num(check, a, format, j));
	else
	{
		if (format[j - 1] == '.')
			k = 1;
		while (format[j] >= '0' && format[j] <= '9' && format[j] != '\0')
		{
			res = res * 10;
			res = res + format[j] - '0';
			j++;
		}
		if (k == 1)
			check->percision = res;
		else
			check->width = res;
	}
	return (j);
}

int		ft_check_hh_ll(t_flags *check, const char *f, int j)
{
	if (f[j + 1] == 'h')
		check->option |= HH;
	if (f[j + 1] == 'l')
		check->option |= ELLELL;
	j++;
	return (j);
}

int		ft_put_flag_on(t_flags *check, const char *f, int j, va_list a)
{
	if (f[j] == '0' && f[j - 1] != '.')
		check->option |= ZERO;
	else if (f[j] == '-')
		check->option |= MINUS;
	else if (f[j] == '#')
		check->option |= HASHTAG;
	else if (f[j] == '+')
		check->option |= PLUS;
	else if (f[j] == ' ')
		check->option |= SPACE;
	else if (f[j] == '.')
		check->option |= DOT;
	else if (f[j] == 'h' && f[j + 1] != 'h')
		check->option |= H;
	else if (f[j] == 'l' && f[j + 1] != 'l')
		check->option |= ELL;
	else if (f[j] == 'L')
		check->option |= L;
	else if (f[j] == 'h' || f[j] == 'l')
		j = ft_check_hh_ll(check, f, j);
	else if (f[j] == '*')
		j = check_num(check, f, j, a);
	return (j);
}

int		check_flags(va_list a, const char *f, int j, t_flags *check)
{
	int				i;

	i = 0;
	while (f[j] != '\0' && f[j] != '%' && !ft_strchr("scpdiouXxfbR", f[j]))
	{
		if (f[j] == '0' && f[j + 1] > '0' && f[j + 1] <= '9' && f[j - 1] == '.')
			j = check_num(check, f, j, a) - 1;
		else if (ft_strchr(FLAGS, f[j]))
			j = ft_put_flag_on(check, f, j, a);
		else if (f[j] > '0' && f[j] <= '9')
			j = check_num(check, f, j, a) - 1;
		else
			break ;
		j++;
	}
	check->type = f[j];
	read_struct(check, a);
	return (j);
}

int		check_format(va_list arg, const char *format, int j, t_flags *check)
{
	int						i;

	i = 0;
	ft_clean_struct(check);
	if (format[j + 1])
		j++;
	else
		return (j + 1);
	if (format[j] == '%')
		ft_write_char(format[j], check);
	else if (format[j])
	{
		j = check_flags(arg, format, j, check) + 1;
		return (j);
	}
	return (j + 1);
}
