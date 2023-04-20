/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:29:53 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/15 20:24:53 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sh;

	sh = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (sh[i] == (unsigned char)c)
			return (sh + i);
		i++;
	}
	return (NULL);
}
