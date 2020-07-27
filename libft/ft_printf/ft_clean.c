/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_clean.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <eovertoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 12:36:18 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/27 12:21:57 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				ft_clean_struct(t_flags *check)
{
	check->width = 0;
	check->percision = 0;
	check->option = 0;
	check->type = 0;
	check->floats_roundoff = 0;
}
