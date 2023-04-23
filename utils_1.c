/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:36:17 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/24 01:02:40 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strlcut(char *src, int i)
{
	int		j;
	int		t;
	char	*dest;

	j = 0;
	t = ft_strlen(src);
	if (t > i)
		dest = malloc(sizeof(char) * (t + 1));
	else
		dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	while (src[j] && j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	count_nb(int n)
{
	int	t;

	t = 0;
	if (n <= 0)
		t++;
	while (n != 0)
	{
		n /= 10;
		t++;
	}
	return (t);
}

int	ft_put_nb_char(int i, char c)
{
	int	t;

	t = 0;
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
		t++;
	}
	return (t);
}

int	count_nb_unsign(unsigned int n)
{
	int	t;

	t = 0;
	if (n == 0)
		t++;
	while (n != 0)
	{
		n /= 10;
		t++;
	}
	return (t);
}

char	*ft_itoa_unsign(unsigned int n)
{
	char			*dest;
	int				i;
	unsigned int	nb;

	nb = n;
	i = count_nb_unsign(n) - 1;
	dest = malloc(sizeof(char) * (count_nb_unsign(n) + 1));
	if (!dest)
		return (NULL);
	if (n == 0)
	{
		dest[0] = '0';
		dest[1] = '\0';
		return (dest);
	}
	while (nb != 0)
	{
		dest[i] = (nb % 10) + '0';
		i--;
		nb /= 10;
	}
	dest[count_nb_unsign(n)] = '\0';
	return (dest);
}
