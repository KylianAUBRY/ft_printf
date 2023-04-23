/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 03:55:42 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/24 01:03:19 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dest(unsigned int nbr, char *base, unsigned int size, char *dest)
{
	int	i;

	i = 0;
	if (nbr > size - 1)
	{
		i += ft_dest(nbr / size, base, size, dest);
		nbr %= size;
	}
	dest[i] = base[nbr];
	i++;
	return (i);
}

static int	ft_size(unsigned int nbr, char *base, unsigned int size)
{
	int	i;

	i = 0;
	if (nbr > size - 1)
	{
		i += ft_size(nbr / size, base, size);
		nbr %= size;
	}
	i++;
	return (i);
}

int	ft_putx(unsigned int nbr, char *base, t_chaine *chaine)
{
	int		i;
	int		temp;
	char	*dest;

	temp = 0;
	if (!nbr)
		return (-1);
	i = ft_check_base(base);
	if (i == -1)
		return (-1);
	temp += ft_size(nbr, base, i);
	dest = malloc(sizeof(char) * (temp + 1));
	ft_dest(nbr, base, i, dest);
	dest[temp] = '\0';
	chaine->dest = ft_strjoin("", dest);
	free(dest);
	return (1);
}

void	ft_hashtag(const char *src, char c, t_chaine *chaine)
{
	int		i;
	char	*dest;

	i = chaine->i;
	while (src[i] && src[i] != c && src[i] != '#')
		i++;
	if (src[i] == '#' && c == 'x')
	{
		dest = ft_strjoin("0x", chaine->dest);
		free(chaine->dest);
		chaine->dest = ft_strjoin("", dest);
		free(dest);
	}
	if (src[i] == '#' && c == 'X')
	{
		dest = ft_strjoin("0X", chaine->dest);
		free(chaine->dest);
		chaine->dest = ft_strjoin("", dest);
		free(dest);
	}
}
