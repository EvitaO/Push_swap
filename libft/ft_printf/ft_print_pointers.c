/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_pointers.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/01 17:38:36 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:23:20 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_print_pointer(t_flags *check, unsigned long long ptr)
{
	char		*num;

	write(1, "0x", 2);
	check->count = check->count + 2;
	num = ft_itoa_base(ptr, 16, 87);
	ft_putstr_check(num, check);
	free(num);
}

void			p_with_flag(t_flags *check, unsigned long long ptr)
{
	int			k;
	char		*num;

	num = NULL;
	k = check->width - ft_count_num(ptr, 16) - 2;
	if (check->width == 0)
	{
		k = 0;
		ft_print_pointer(check, ptr);
	}
	else if ((check->option & MINUS) > 0)
	{
		ft_print_pointer(check, ptr);
		ft_width(k, 0, ' ');
	}
	else
	{
		ft_width(k, 0, ' ');
		ft_print_pointer(check, ptr);
	}
	if (k >= 0)
		check->count = check->count + k;
	free(num);
}
