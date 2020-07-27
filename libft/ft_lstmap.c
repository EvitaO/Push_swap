/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/06 15:25:12 by eovertoo      #+#    #+#                 */
/*   Updated: 2019/04/10 20:04:03 by eovertoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;
	t_list		*head;

	if (!lst)
		return (0);
	head = (*f)(lst);
	new = head;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tmp = (*f)(lst);
		head->next = tmp;
		head = head->next;
	}
	return (new);
}
