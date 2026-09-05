/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjang <hjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:57:43 by hjang             #+#    #+#             */
/*   Updated: 2024/10/29 16:29:35 by hjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*new_node(t_list *tmp, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_new;
	void	*f_res;

	f_res = f(tmp->content);
	if (!f_res)
		return (NULL);
	res_new = ft_lstnew(f_res);
	if (!res_new)
	{
		del(f_res);
		return (NULL);
	}
	return (res_new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*res;
	t_list	*res_new;

	tmp = lst;
	res = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (tmp != NULL)
	{
		res_new = new_node(tmp, f, del);
		if (!res_new)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, res_new);
		tmp = tmp->next;
	}
	return (res);
}
