/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/01 17:02:56 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:23:48 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_base(unsigned long long nbr, int base, int ltr)
{
	if (base < 2)
		return ;
	else if (nbr >= (unsigned long long)base)
	{
		ft_putnbr_base((nbr / base), base, ltr);
		ft_putnbr_base((nbr % base), base, ltr);
	}
	else if (nbr > 9 && ltr == 1)
		ft_putchar(nbr % base + 55);
	else if (nbr > 9 && ltr == 2)
		ft_putchar(nbr % base + 87);
	else if (nbr < (unsigned long long)base)
		ft_putchar(nbr + '0');
}
