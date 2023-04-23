/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:23:18 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/23 03:16:24 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		t;
	int		i;

	t = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * t + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	t = 0;
	while (s2[t] != '\0')
	{
		dest[i + t] = s2[t];
		t++;
	}
	dest[i + t] = '\0';
	return (dest);
}
