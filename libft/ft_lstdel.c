/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 21:14:53 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/06 15:21:57 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*lst;

	lst = *alst;
	while (lst)
	{
		tmp = (lst)->next;
		(*del)((lst)->content, (lst)->content_size);
		free(lst);
		lst = tmp;
	}
	*alst = NULL;
}
