/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:34:14 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/23 19:16:05 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *chaine)
{
	int	i;

	i = 0;
	if (!chaine)
		return (0);
	while (chaine[i])
	{
		write(1, &chaine[i], 1);
		i++;
	}
	return (i);
}
