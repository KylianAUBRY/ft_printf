/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:19:53 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/20 20:37:00 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_verif_2(const char *src, char c, t_chaine *chaine)
{
	int	i;

	i = chaine->i - 1;
	while (src[++i] && src[i] != c)
	{
		if (src[i] == '.' && (c == 'n' || c == 'c' || c == 's' || c == '%'))
			return (0);
		if (src[i] != '%' && c == '%')
			return (0);
	}
	if (!src[i])
		return (0);
	return (1);
}

int	ft_verif(const char *src, char c, t_chaine *chaine)
{
	int	i;
	int	tps;
	int	tps1;

	tps = 0;
	tps1 = 0;
	i = chaine->i - 1;
	while (src[++i] && src[i] != c)
	{
		if (src[i] == '-')
			tps = 1;
		if (src[i] == '0' && (src[i - 1] < '0' || src[i - 1] > '9'))
			tps1 = 1;
		if (src[i] == '#' && (c == 'c' || c == 'd' || c == 'i' || c == 'n'
				|| c == 'p' || c == 's' || c == 'u' || c == 'x' || c == '%'))
			return (0);
		if ((src[i] == '0' || src[i] == ' ' || src[i] == '+') && (c == 'c'
				|| c == 's' || c == '%'))
			return (0);
		if (src[i] == '-' && (c == 'n' || c == '%'))
			return (0);
	}
	if (!src[i] || (tps + tps1) == 2)
		return (0);
	return (ft_verif_2(src, c, chaine));
}

void	ft_c(const char *src, va_list list, t_chaine *chaine)
{
	int	i;
	int	temp;

	i = chaine->i;
	if (ft_verif(src, 'c', chaine) == 0)
		return ;
	if (src[i] == '-')
	{
		i++;
		ft_putchar(va_arg(list, int));
		temp = ft_atoi(src + i) - 1;
		ft_put_nb_char(temp, ' ');
		chaine->i += 2 + count_nb(temp);
		chaine->t += 1 + temp;
	}
	else
	{
		temp = ft_atoi(src + i) - 1;
		ft_put_nb_char(temp, ' ');
		ft_putchar(va_arg(list, int));
		chaine->i += 1 + count_nb(temp);
		chaine->t += 1 + temp;
	}
}

void	ft_s(const char *src, va_list list, t_chaine *chaine)
{
	int	i;
	int	temp;

	i = chaine->i;
	if (ft_verif(src, 's', chaine) == 0)
		return ;
	if (src[i] == '-')
	{
		i++;
		chaine->dest = va_arg(list, char *);
		ft_putstr(chaine->dest);
		temp = ft_atoi(src + i) - ft_strlen(chaine->dest);
		ft_put_nb_char(temp, ' ');
		chaine->i += 2 + count_nb(temp);
		chaine->t += ft_strlen(chaine->dest) + temp;
	}
	else
	{
		chaine->dest = va_arg(list, char *);
		temp = ft_atoi(src + i) - ft_strlen(chaine->dest);
		ft_put_nb_char(temp, ' ');
		ft_putstr(chaine->dest);
		chaine->i += 1 + count_nb(temp);
		chaine->t += ft_strlen(chaine->dest) + temp;
	}
}

void	ft_p(const char *src, va_list list, t_chaine *chaine)
{
	if (ft_verif(src, 'p', chaine) == 0)
		return ;
	(void)list;
}

void	ft_d(const char *src, va_list list, t_chaine *chaine)
{
	if (ft_verif(src, 'd', chaine) == 0)
		return ;
	(void)list;
}

void	ft_i(const char *src, va_list list, t_chaine *chaine)
{
	if (ft_verif(src, 'i', chaine) == 0)
		return ;
	(void)list;
}

void	ft_u(const char *src, va_list list, t_chaine *chaine)
{
	if (ft_verif(src, 'u', chaine) == 0)
		return ;
	(void)list;
}

void	ft_x(const char *src, va_list list, t_chaine *chaine)
{
	if (ft_verif(src, 'x', chaine) == 0)
		return ;
	(void)list;
}

void	ft_xx(const char *src, va_list list, t_chaine *chaine)
{
	if (ft_verif(src, 'X', chaine) == 0)
		return ;
	(void)list;
}

void	ft_percent(const char *src, t_chaine *chaine)
{
	if (ft_verif(src, '%', chaine) == 0)
		return ;
	ft_putchar('%');
	chaine->t += 1;
	chaine->t += 1;
}

void	ft_verif_argc(const char *src, va_list list, t_chaine *chaine)
{
	int	i;

	i = chaine->i - 1;
	while (src[++i])
	{
		if (src[i] == 'c')
			(ft_c(src, list, chaine));
		if (src[i] == 's')
			(ft_s(src, list, chaine));
		if (src[i] == 'p')
			(ft_p(src, list, chaine));
		if (src[i] == 'd')
			(ft_d(src, list, chaine));
		if (src[i] == 'i')
			(ft_i(src, list, chaine));
		if (src[i] == 'u')
			(ft_u(src, list, chaine));
		if (src[i] == 'x')
			(ft_x(src, list, chaine));
		if (src[i] == 'X')
			(ft_xx(src, list, chaine));
		if (src[i] == '%')
			(ft_percent(src, chaine));
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
		}
	}
	va_end(list);
	return (chaine->t);
}

int	main(void)
{
	char	c;
	char	*chaine;
	float	f;
	int		i;

	c = 'a';
	chaine = "hello";
	f = 3.10;
	i = 555;
	(void)i;
	(void)f;
	(void)c;
	(void)chaine;
	ft_printf("%%", chaine);
	//printf("%%");
	return (0);
}
/*int	wft_valeur(const char *src, va_list list, t_chaine *chaine)
{
	int			t;
	int			tmp;
	t_chaine	chaine[1];
	va_list		list;
	t_chaine	chaine[1];
	t_chaine	chaine[1];

	int itmp
	t = 0;
	tmp = 0;
	itmp = chaine ->i;
	if (ft_verif_argc(src, chaine) == -1)
		return (0);
	
	if (src[chaine->i] >= '1' && src[chaine->i] <= '9')
	{
		tmp = ft_atoi(src + chaine->i);
		chaine->i += count_nb(tmp);
	//	chaine->t += count_nb(tmp);
	//	ft_put_nb_char(tmp, ' ');
	}
	if (src[chaine->i] == 'c')
		ft_putchar(va_arg(list, int));
	return (t);
}*/