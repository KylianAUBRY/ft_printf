/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:53:07 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/16 17:07:25 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*tmp;
	t_list	*temp;

	if (!lst)
		return (NULL);
	tmp = lst;
	dest = ft_lstnew((*f)(tmp->content));
	if (!dest)
		return (NULL);
	tmp = tmp->next;
	while (tmp != NULL)
	{
		temp = ft_lstnew((*f)(tmp->content));
		if (!temp)
		{
			ft_lstclear(&dest, del);
			return (NULL);
		}
		ft_lstadd_back(&dest, temp);
		tmp = tmp->next;
	}
	return (dest);
}
