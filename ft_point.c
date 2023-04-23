/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:54:03 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/24 01:03:58 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_point(const char *src, char c, t_chaine *chaine)
{
	int		i;
	int		j;
	char	*dest;

	i = chaine->i;
	while (src[i] && src[i] != '.' && src[i] != c)
		i++;
	if (src[i] == '.')
	{
		j = ft_atoi(src + i + 1);
		if (ft_strlen(chaine->dest) > (size_t)j)
		{
			dest = malloc(sizeof(char) * (j + 1));
			i = 0;
			while (chaine->dest[i] && i < j)
			{
				dest[i] = chaine->dest[i];
				i++;
			}
			dest[i] = '\0';
			free(chaine->dest);
			chaine->dest = dest;
		}
	}
}

void	ft_unsigned(int j, t_chaine *chaine)
{
	int		i;
	char	*dest;
	char	*z;

	i = 0;
	if ((int)(ft_strlen(chaine->dest)) < j)
	{
		dest = malloc(sizeof(char) * (j - ft_strlen(chaine->dest) + 1));
		while (i < (j - (int)ft_strlen(chaine->dest)))
		{
			dest[i] = '0';
			i++;
		}
		dest[i] = '\0';
		z = ft_strjoin(dest, chaine->dest);
		free(dest);
		free(chaine->dest);
		chaine->dest = ft_strjoin("", z);
		free(z);
	}
}

void	ft_signed(int j, t_chaine *chaine)
{
	int		i;
	char	*dest;
	char	*z;

	i = 1;
	if ((int)(ft_strlen(chaine->dest) - 1) < j)
	{
		dest = malloc(sizeof(char) * (j - ft_strlen(chaine->dest) + 3));
		dest[0] = chaine->dest[0];
		while (i - 1 < (j - ((int)ft_strlen(chaine->dest) - 1)))
		{
			dest[i] = '0';
			i++;
		}
		dest[i] = '\0';
		z = ft_strjoin(dest, chaine->dest + 1);
		free(dest);
		free(chaine->dest);
		chaine->dest = ft_strjoin("", z);
		free(z);
	}
}

void	ft_point_z(const char *src, char c, t_chaine *chaine)
{
	int	i;
	int	j;

	i = chaine->i;
	while (src[i] && src[i] != '.' && src[i] != c)
		i++;
	if (src[i] == '.')
	{
		j = ft_atoi(src + i + 1);
		if (j == 0 && chaine->dest[0] == '0')
		{
			free(chaine->dest);
			chaine->dest = ft_strjoin("", "");
			return ;
		}
		if (chaine->dest[0] == '-')
			ft_signed(j, chaine);
		else
			ft_unsigned(j, chaine);
	}
}

void	ft_null(const char *src, char c, t_chaine *chaine)
{
	int	i;
	int	j;

	i = chaine->i;
	while (src[i] && src[i] != c && src[i] != '.')
		i++;
	if (src[i] == '.')
	{
		j = ft_atoi(src + i + 1);
		if (j < 6)
			chaine->dest = ft_strjoin("", "");
		else
		{
			chaine->dest = ft_strjoin("", "(null)");
			ft_point(src, 's', chaine);
		}
	}
	else
		chaine->dest = ft_strjoin("", "(null)");
}
