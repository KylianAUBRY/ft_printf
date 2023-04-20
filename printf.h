/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:21:56 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/20 19:38:58 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_chaine
{
	int	i;
	int	t;
	int temp;
	char *dest;
}		t_chaine;

int		ft_printf(const char *src, ...);
void	ft_putchar(char c);

#endif