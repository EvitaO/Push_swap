/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_strings.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/01 17:40:12 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:23:32 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			s_with_flagwidth(t_flags *check, char *str)
{
	int			k;
	int			len;

	len = ft_strlen(str);
	k = check->width - len;
	if ((check->option & MINUS) > 0)
	{
		write(1, &(*str), len);
		ft_width(k, 0, ' ');
	}
	else
	{
		ft_width(k, 0, ' ');
		write(1, &(*str), len);
	}
	if (k > 0)
		check->count = check->count + k + len;
	else
		check->count = check->count + len;
}

void			s_flag_dot_width(t_flags *check, char *str)
{
	int				k;

	k = 0;
	if (ft_strlen(str) > check->percision)
	{
		ft_width(check->width, check->percision, ' ');
		if (check->width > check->percision)
			check->count = check->count + (check->width - check->percision);
	}
	else
	{
		ft_width(check->width, (ft_strlen(str)), ' ');
		if (check->width > ft_strlen(str))
			check->count = check->count + (check->width - ft_strlen(str));
	}
	while (check->percision > 0 && str[k] != '\0')
	{
		write(1, &str[k], 1);
		k++;
		check->percision--;
		check->count++;
	}
}

void			s_flag_minus_dot(t_flags *check, char *str)
{
	int					k;

	k = 0;
	while (check->percision > 0 && str[k] != '\0')
	{
		write(1, &str[k], 1);
		k++;
		check->percision--;
		check->count++;
	}
	ft_width(check->width, k, ' ');
	if (check->width > k)
		check->count = check->count + (check->width - k);
}

void			s_with_flag(t_flags *check, char *str)
{
	int			k;

	k = 0;
	if ((check->option & DOT) == 0)
		s_with_flagwidth(check, str);
	else if (((check->option & MINUS) > 0) && ((check->option & DOT) > 0))
		s_flag_minus_dot(check, str);
	else if (check->width == 0 && ((check->option & DOT) > 0))
	{
		while (check->percision > 0 && str[k] != '\0')
		{
			write(1, &str[k], 1);
			k++;
			check->percision--;
			check->count++;
		}
	}
	else
		s_flag_dot_width(check, str);
}
