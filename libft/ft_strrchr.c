/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:22:23 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/15 19:27:11 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s != NULL)
		i++;
	while (i >= 0)
	{
		if (s[i] == (const char)c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
