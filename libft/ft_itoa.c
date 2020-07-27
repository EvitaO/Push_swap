/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 00:24:38 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 20:01:19 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_numb(int n)
{
	int		cnt;

	cnt = 0;
	if (n < 0)
	{
		cnt++;
		n = n * -1;
	}
	while (n > 0)
	{
		cnt++;
		n = n / 10;
	}
	return (cnt);
}

static char		*is_null(void)
{
	char	*ret;

	ret = (char*)malloc(sizeof(*ret) * (2));
	if (!ret)
		return (NULL);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

static char		*min_int(void)
{
	char	*str;
	char	*ret;
	int		i;

	i = 0;
	str = "-2147483648";
	ret = (char*)malloc(sizeof(*ret) * (12));
	if (!ret)
		return (NULL);
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char		*make_str(char *ret, int cnt, int n, int i)
{
	while (cnt >= i)
	{
		ret[cnt] = (n % 10) + '0';
		n = n / 10;
		cnt--;
	}
	return (ret);
}

char			*ft_itoa(int n)
{
	char		*ret;
	int			cnt;
	int			i;

	i = 0;
	if (n == 0)
		return (is_null());
	if (n == -2147483648)
		return (min_int());
	cnt = count_numb(n);
	ret = (char*)malloc(sizeof(*ret) * (cnt + 1));
	if (!ret)
		return (NULL);
	if (n < 0)
	{
		ret[i] = '-';
		n = n * -1;
		i++;
	}
	ret[cnt] = '\0';
	cnt = cnt - 1;
	return (make_str(ret, cnt, n, i));
}
