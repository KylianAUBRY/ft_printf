/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:07:29 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/24 14:46:53 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_space(const char *src, t_chaine *chaine)
{
	int	temp;
	int	i;

	i = chaine->i;
	while (src[i] == '-' && src[i + 1] == '-')
		i++;
	if (src[i] == '-')
	{
		i++;
		temp = ft_atoi(src + i);
		chaine->t += ft_putstr(chaine->dest);
		chaine->t += ft_put_nb_char(temp - ft_strlen(chaine->dest), ' ');
	}
	else
	{
		temp = ft_atoi(src + i);
		chaine->t += ft_put_nb_char(temp - ft_strlen(chaine->dest), ' ');
		chaine->t += ft_putstr(chaine->dest);
	}
}

void	ft_space_c(const char *src, char c, t_chaine *chaine)
{
	int	temp;
	int	i;

	i = chaine->i;
	while (src[i] == '-' && src[i + 1] == '-')
		i++;
	if (src[i] == '-')
	{
		i++;
		temp = ft_atoi(src + i);
		ft_putchar(c);
		chaine->t += 1;
		chaine->t += ft_put_nb_char(temp - 1, ' ');
	}
	else
	{
		temp = ft_atoi(src + i);
		chaine->t += ft_put_nb_char(temp - 1, ' ');
		ft_putchar(c);
		chaine->t += 1;
	}
}

void	ft_verif(const char *src, char c, t_chaine *chaine)
{
	int	i;

	i = chaine->i;
	while (src[i] && src[i] != c)
	{
		i++;
		chaine->flag++;
	}
}

void	ft_verif_argc(const char *src, va_list list, t_chaine *chaine)
{
	int	i;

	i = chaine->i - 1;
	while (src[++i])
	{
		if (src[i] == 'c')
			return (ft_c(src, list, chaine));
		if (src[i] == 's')
			return (ft_s(src, list, chaine));
		if (src[i] == 'p')
			return (ft_p(src, list, chaine));
		if (src[i] == 'd')
			return (ft_d(src, list, chaine));
		if (src[i] == 'i')
			return (ft_i(src, list, chaine));
		if (src[i] == 'u')
			return (ft_u(src, list, chaine));
		if (src[i] == 'x')
			return (ft_x(src, list, chaine));
		if (src[i] == 'X')
			return (ft_xx(src, list, chaine));
		if (src[i] == '%')
			return (ft_percent(src, chaine));
	}
}

int	ft_printf(const char *src, ...)
{
	t_chaine	chaine[1];
	va_list		list;

	va_start(list, src);
	chaine->i = 0;
	chaine->t = 0;
	while (src[chaine->i])
	{
		if (src[chaine->i] == '%')
		{
			chaine->i++;
			ft_verif_argc(src, list, chaine);
		}
		else
		{
			ft_putchar(src[chaine->i]);
			chaine->i++;
			chaine->t++;
		}
	}
	va_end(list);
	return (chaine->t);
}
#include <limits.h>

int	main(void)
{
	char c;
	char *chaine;
	float f;
	int i;

	c = '0';
	chaine = NULL;
	f = 3.10;
	i = 42;
	(void)chaine;
	(void)f;
	(void)c;
	(void)i;
	//printf(" %p ", -1); 
	ft_printf(" %p %p ", INT_MIN, INT_MAX); 
	return (0);
}