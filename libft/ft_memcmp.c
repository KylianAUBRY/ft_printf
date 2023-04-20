/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:26:09 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/15 19:09:47 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sh1;
	unsigned char	*sh2;

	sh1 = (unsigned char *)s1;
	sh2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{	
		if (sh1[i] != sh2[i])
			return (sh1[i] - sh2[i]);
		i++;
	}
	return (0);
}
