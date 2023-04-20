/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:33:51 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/15 19:30:21 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s != NULL)
	{
		if (s[i] == (const char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (const char)c)
		return ((char *)s + i);
	return (NULL);
}
