/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:08:16 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/24 01:09:49 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_chaine
{
	int		i;
	int		t;
	int		temp;
	int		flag;
	char	*dest;
	char	*noname;
}			t_chaine;

int			ft_printf(const char *src, ...);
void		ft_putchar(char c);
void		ft_putmemory(unsigned long long *nbr, char *base, t_chaine *chaine);
int			ft_put_nb_char(int i, char c);
int			count_nb(int n);
char		*ft_strlcut(char *src, int i);
char		*ft_itoa_unsign(unsigned int n);
int			ft_putx(unsigned int t, char *base, t_chaine *chaine);
int			ft_check_base(char *base);
void		ft_point(const char *src, char c, t_chaine *chaine);
void		ft_point_z(const char *src, char c, t_chaine *chaine);
void		ft_hashtag(const char *src, char c, t_chaine *chaine);
void		ft_null(const char *src, char c, t_chaine *chaine);
void		ft_c(const char *src, va_list list, t_chaine *chaine);
void		ft_s(const char *src, va_list list, t_chaine *chaine);
void		ft_p(const char *src, va_list list, t_chaine *chaine);
void		ft_d(const char *src, va_list list, t_chaine *chaine);
void		ft_i(const char *src, va_list list, t_chaine *chaine);
void		ft_u(const char *src, va_list list, t_chaine *chaine);
void		ft_x(const char *src, va_list list, t_chaine *chaine);
void		ft_xx(const char *src, va_list list, t_chaine *chaine);
void		ft_percent(const char *src, t_chaine *chaine);
void		ft_strjoin_z(int temp, t_chaine *chaine, char *dest);
int			ft_strjoin_sp(int temp, t_chaine *chaine, char *dest,
				const char *src);
void		ft_zero(const char *src, char c, t_chaine *chaine, int t);
void		ft_signe(const char *src, char c, t_chaine *chaine);
void		ft_verif(const char *src, char c, t_chaine *chaine);
void		ft_space_c(const char *src, char c, t_chaine *chaine);
void		ft_space(const char *src, t_chaine *chaine);

#endif