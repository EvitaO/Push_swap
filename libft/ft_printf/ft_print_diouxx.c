/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_diouxx.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/01 18:12:36 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:22:52 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_width_hexaocta(t_flags *check, char *str, char *num, int i)
{
	if (num[0] == '0' && ((check->option & DOT) > 0) && check->percision == 0)
	{
		ft_width(check->width, 0, ' ');
		check->count = check->count + check->width;
	}
	else if ((check->option & MINUS) > 0)
	{
		ft_putstr(str);
		ft_putstr_check(num, check);
		ft_width(check->width, (ft_strlen(num) + i), ' ');
		if (check->width > (ft_strlen(num) + i))
			check->count = check->count + (check->width - (ft_strlen(num) + i));
	}
	else
	{
		ft_width(check->width, (ft_strlen(num) + i), ' ');
		ft_putstr(str);
		if ((check->option & ZERO) > 0 && num[0] == '0')
			num[0] = '\0';
		ft_putstr_check(num, check);
		if (check->width > (ft_strlen(num) + i))
			check->count = check->count + (check->width - (ft_strlen(num) + i));
	}
	check->count = check->count + i;
	free(str);
}

char			*ft_check_change(t_flags *check, int len, char **num)
{
	char		*str;

	if ((check->option & DOT) > 0 && *num[0] == '0')
	{
		if (check->type != 'o')
			*num[0] = '\0';
		check->option &= ~HASHTAG;
	}
	if (check->percision > 0 && check->type != 'o' &&\
		(*num[0] == '0' || *num[0] == '\0'))
		check->percision++;
	if ((check->option & MINUS) > 0)
		check->option &= ~ZERO;
	if ((check->option & DOT) > 0)
		check->option &= ~ZERO;
	if (check->width > check->percision)
		str = (char*)malloc((len + check->width + 2));
	else
		str = (char*)malloc((len + check->percision + 2));
	if (!str)
		return (NULL);
	return (str);
}

char			*ft_check_hash(t_flags *check, int *i, char *str, int *len)
{
	int			k;

	k = *i;
	if (check->type == 'o' || check->type == 'u')
	{
		str[k] = '0';
		k++;
		if (check->percision > 0)
			*len = *len + 1;
	}
	else
	{
		str[k] = '0';
		str[k + 1] = check->type;
		k = k + 2;
	}
	*i = k;
	return (str);
}

void			ft_put_zeros(t_flags *check, int len, int *i, char *str)
{
	while (check->percision > len)
	{
		str[*i] = '0';
		(*i)++;
		check->percision--;
		if (check->percision <= len)
			return ;
	}
	while (len + (*i) < check->width)
	{
		str[*i] = '0';
		(*i)++;
	}
}

void			ft_hexaocta(char *num, t_flags *check)
{
	int				len;
	int				i;
	char			*str;

	i = 0;
	len = ft_strlen(num);
	str = ft_check_change(check, len, &num);
	if ((check->option & HASHTAG) > 0 && num[0] != '0')
		str = ft_check_hash(check, &i, str, &len);
	if (check->percision > len)
		ft_put_zeros(check, len, &i, str);
	if ((check->option & HASHTAG) > 0 && num[0] == '0')
	{
		str[i] = '0';
		i++;
		num[0] = '\0';
	}
	if ((check->option & ZERO) > 0 && check->width > 0)
	{
		if (num[0] == '0' || num[0] == '\0')
			len = 0;
		ft_put_zeros(check, len, &i, str);
	}
	str[i] = '\0';
	ft_width_hexaocta(check, str, num, i);
}
