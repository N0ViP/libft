/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:28:38 by yjaafar           #+#    #+#             */
/*   Updated: 2024/10/28 10:25:29 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nl;
	t_list	*nn;

	nn = NULL;
	nl = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		nn = ft_lstnew(lst->content);
		if (!nn)
		{
			ft_lstclear(&nl, del);
			return (NULL);
		}
		nn->content = f(nn->content);
		ft_lstadd_back(&nl, nn);
		lst = lst->next;
	}
	return (nl);
}
