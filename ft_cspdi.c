/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cspdi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:56:24 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/24 01:07:14 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c(const char *src, va_list list, t_chaine *chaine)
{
	int	c;

	c = va_arg(list, int);
	chaine->flag = 0;
	ft_verif(src, 'c', chaine);
	ft_space_c(src, c, chaine);
	chaine->i += chaine->flag + 1;
}

void	ft_s(const char *src, va_list list, t_chaine *chaine)
{
	char	*i;

	i = va_arg(list, char *);
	chaine->flag = 0;
	ft_verif(src, 's', chaine);
	if (!i)
	{
		ft_null(src, 's', chaine);
		ft_space(src, chaine);
		chaine->i += chaine->flag + 1;
		free(chaine->dest);
		return ;
	}
	else
		chaine->dest = ft_strjoin("", i);
	ft_point(src, 's', chaine);
	ft_space(src, chaine);
	chaine->i += chaine->flag + 1;
	free(chaine->dest);
}

void	ft_p(const char *src, va_list list, t_chaine *chaine)
{
	unsigned long long	p;

	chaine->flag = 0;
	ft_verif(src, 'p', chaine);
	p = va_arg(list, unsigned long long);
	if (!p)
		chaine->dest = ft_strjoin("", "(nil)");
	else
		ft_putmemory(&p, "0123456789abcdef", chaine);
	ft_space(src, chaine);
	chaine->i += chaine->flag + 1;
	free(chaine->dest);
}

void	ft_d(const char *src, va_list list, t_chaine *chaine)
{
	int	i;

	i = va_arg(list, int);
	chaine->flag = 0;
	ft_verif(src, 'd', chaine);
	chaine->dest = ft_itoa(i);
	ft_point_z(src, 'd', chaine);
	ft_signe(src, 'd', chaine);
	ft_zero(src, 'd', chaine, 0);
	ft_space(src, chaine);
	chaine->i += chaine->flag + 1;
	free(chaine->dest);
}

void	ft_i(const char *src, va_list list, t_chaine *chaine)
{
	int	i;

	i = va_arg(list, int);
	chaine->flag = 0;
	ft_verif(src, 'i', chaine);
	chaine->dest = ft_itoa(i);
	ft_point_z(src, 'i', chaine);
	ft_signe(src, 'i', chaine);
	ft_zero(src, 'i', chaine, 0);
	ft_space(src, chaine);
	chaine->i += chaine->flag + 1;
	free(chaine->dest);
}
