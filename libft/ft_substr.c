/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:14:07 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/15 17:24:41 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (len == 0 || ft_strlen(s) <= start)
	{
		dest = malloc(sizeof(char) * 1);
		dest[0] = '\0';
		return (dest);
	}
	if (ft_strlen(s) - start >= len)
		dest = malloc(sizeof(char) * (len + 1));
	else
		dest = malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	if (!dest)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
