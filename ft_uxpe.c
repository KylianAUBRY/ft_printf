/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uxpe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:58:29 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/24 01:03:09 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u(const char *src, va_list list, t_chaine *chaine)
{
	unsigned int	i;

	i = va_arg(list, unsigned int);
	chaine->flag = 0;
	ft_verif(src, 'u', chaine);
	chaine->dest = ft_itoa_unsign(i);
	ft_point_z(src, 'd', chaine);
	ft_signe(src, 'u', chaine);
	ft_zero(src, 'u', chaine, 0);
	ft_space(src, chaine);
	chaine->i += chaine->flag + 1;
	free(chaine->dest);
}

void	ft_x(const char *src, va_list list, t_chaine *chaine)
{
	int	i;

	i = chaine->i;
	while (src[i] && src[i] != 'x' && src[i] != '#')
		i++;
	i = 0;
	if (src[i] == '#')
		i = 2;
	chaine->flag = 0;
	ft_verif(src, 'x', chaine);
	if (ft_putx(va_arg(list, int), "0123456789abcdef", chaine) == -1)
	{
		chaine->dest = ft_strjoin("", "0");
		ft_point_z(src, 'x', chaine);
		ft_zero(src, 'x', chaine, i);
	}
	else
	{
		ft_point_z(src, 'x', chaine);
		ft_zero(src, 'x', chaine, i);
		ft_hashtag(src, 'x', chaine);
	}
	ft_space(src, chaine);
	chaine->i += chaine->flag + 1;
	free(chaine->dest);
}

void	ft_xx(const char *src, va_list list, t_chaine *chaine)
{
	int	i;

	i = chaine->i;
	while (src[i] && src[i] != 'X' && src[i] != '#')
		i++;
	i = 0;
	if (src[i] == '#')
		i = 2;
	chaine->flag = 0;
	ft_verif(src, 'X', chaine);
	if (ft_putx(va_arg(list, int), "0123456789ABCDEF", chaine) == -1)
	{
		chaine->dest = ft_strjoin("", "0");
		ft_point_z(src, 'X', chaine);
		ft_zero(src, 'X', chaine, i);
	}
	else
	{
		ft_point_z(src, 'X', chaine);
		ft_zero(src, 'X', chaine, i);
		ft_hashtag(src, 'X', chaine);
	}
	ft_space(src, chaine);
	chaine->i += chaine->flag + 1;
	free(chaine->dest);
}

void	ft_percent(const char *src, t_chaine *chaine)
{
	chaine->flag = 0;
	ft_verif(src, '%', chaine);
	ft_putchar('%');
	chaine->i += chaine->flag + 1;
	chaine->t += 1;
}
