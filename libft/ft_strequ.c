/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stredu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:18:46 by mroland-          #+#    #+#             */
/*   Updated: 2018/12/06 18:17:35 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int equ;

	if (s1 && s2)
	{
		equ = ft_strcmp(s1, s2);
		if (equ == 0)
			return (1);
	}
	return (0);
}
