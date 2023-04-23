/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:00:20 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/24 01:25:31 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strjoin_z(int temp, t_chaine *chaine, char *dest)
{
	int		i;
	int		t;
	char	*test;

	i = 0;
	t = 0;
	if (chaine->dest[i] == ' ' || chaine->dest[i] == '+'
		|| chaine->dest[i] == '-')
	{
		dest[i] = chaine->dest[i];
		i++;
		t++;
	}
	while (temp > 0)
	{
		dest[i] = '0';
		i++;
		temp--;
	}
	dest[i] = '\0';
	test = ft_strjoin(dest, chaine->dest + t);
	free(dest);
	free(chaine->dest);
	chaine->dest = ft_strjoin("", test);
	free(test);
}

int	ft_strjoin_sp(int temp, t_chaine *chaine, char *dest, const char *src)
{
	int		i;
	int		j;
	char	*test;

	j = chaine->i;
	i = 0;
	while (src[j] && src[j] != '.' && src[j] != '%')
		j++;
	if (src[j] == '.')
	{
		while (temp > 0)
		{
			dest[i] = ' ';
			i++;
			temp--;
		}
		dest[i] = '\0';
		test = ft_strjoin(dest, chaine->dest);
		free(dest);
		free(chaine->dest);
		chaine->dest = ft_strjoin("", test);
		free(test);
		return (-1);
	}
	return (1);
}

void	ft_zero(const char *src, char c, t_chaine *chaine, int t)
{
	int		i;
	int		temp;
	char	*dest;

	i = chaine->i;
	if (!chaine->dest || !c)
		return ;
	while (src[i] && src[i] != c && src[i] != '0' && (src[i - 1] > '9'
			|| src[i - 1] < '0'))
		i++;
	if (src[i] == '0')
	{
		temp = ft_atoi(src + i) - (ft_strlen(chaine->dest) + t);
		if (temp > 0)
		{
			if (chaine->dest[i] == ' ' || chaine->dest[i] == '+'
				|| chaine->dest[i] == '-')
				temp++;
			dest = malloc(sizeof(char) * (temp + 2));
			if (!dest || ft_strjoin_sp(temp, chaine, dest, src) == -1)
				return ;
			ft_strjoin_z(temp, chaine, dest);
		}
	}
}

void	ft_signe(const char *src, char c, t_chaine *chaine)
{
	int		i;
	char	*dest;

	i = chaine->i;
	while (src[i] && src[i] != ' ' && src[i] != '+' && src[i] != c)
		i++;
	if (src[i] == ' ' || src[i] == '+')
	{
		if (chaine->dest[0] != '-' && src[i] == ' ')
			dest = ft_strjoin(" ", chaine->dest);
		if (chaine->dest[0] != '-' && src[i] == '+')
			dest = ft_strjoin("+", chaine->dest);
		if (chaine->dest[0] != '-' && (src[i] == '+' || src[i] == ' '))
		{
			free(chaine->dest);
			chaine->dest = ft_strjoin("", dest);
			free(dest);
		}
	}
}
