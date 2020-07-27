/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 00:24:38 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:22:28 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		count_numb(unsigned long long n, int base)
{
	int		cnt;

	cnt = 0;
	while (n > 0)
	{
		cnt++;
		n = n / base;
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

char			*ft_itoa_base(unsigned long long n, int base, int ltr)
{
	char		*ret;
	int			cnt;
	int			i;

	i = 0;
	if (n == 0)
		return (is_null());
	cnt = count_numb(n, base);
	ret = (char*)malloc(sizeof(*ret) * (cnt + 1));
	if (!ret)
		return (NULL);
	ret[cnt] = '\0';
	cnt = cnt - 1;
	while (cnt >= 0)
	{
		if ((n % base) > 9)
			ret[cnt] = (n % base) + ltr;
		else
			ret[cnt] = (n % base) + '0';
		n = n / base;
		cnt--;
	}
	return (ret);
}
