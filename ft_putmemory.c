/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmemory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:31:39 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/24 01:03:41 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[i])
	{
		while (base[j])
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	if (i < 2)
		return (-1);
	return (i);
}

static int	ft_memory_dest(unsigned long long nbr, char *base,
		unsigned int size, char *dest)
{
	int	i;

	i = 0;
	if (nbr > size - 1)
	{
		i += ft_memory_dest(nbr / size, base, size, dest);
		nbr %= size;
	}
	dest[i] = base[nbr];
	i++;
	return (i);
}

static int	ft_memory_size(unsigned long long nbr, char *base,
		unsigned int size)
{
	int	i;

	i = 0;
	if (nbr > size - 1)
	{
		i += ft_memory_size(nbr / size, base, size);
		nbr %= size;
	}
	i++;
	return (i);
}

void	ft_putmemory(unsigned long long *nbr, char *base, t_chaine *chaine)
{
	int		i;
	int		temp;
	char	*dest;

	i = ft_check_base(base);
	if (i == -1)
		return ;
	temp = 2;
	if ((long)nbr < 0)
		nbr[0] = -nbr[0];
	temp += ft_memory_size(nbr[0], base, i);
	dest = malloc(sizeof(char) * (temp + 1));
	ft_memory_dest(nbr[0], base, i, dest);
	chaine->dest = ft_strjoin("0x", dest);
	chaine->dest[temp] = '\0';
	free(dest);
}
