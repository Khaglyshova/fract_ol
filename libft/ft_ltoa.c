/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:53:59 by mroland-          #+#    #+#             */
/*   Updated: 2019/06/26 20:54:30 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_size(long long n)
{
	long long	i;
	int			flag;

	flag = 0;
	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		flag = 1;
		n = -n;
	}
	while (0 < n)
	{
		n = n / 10;
		i++;
	}
	return (i + flag);
}

static char			intinstr(int n)
{
	char	sim;

	sim = n + '0';
	return (sim);
}

static char			*numb(long long n, long long size)
{
	long long				i;
	long long				res2;
	char					*str;
	int						flag;

	flag = 0;
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	i = size - 1;
	if (n < 0)
	{
		n = -n;
		flag = 1;
	}
	while (i >= 0)
	{
		res2 = n % 10;
		n = n / 10;
		str[i--] = intinstr(res2);
	}
	if (flag == 1)
		str[0] = '-';
	return (str);
}

char				*ft_ltoa(long long n)
{
	char			*str;
	long long		size;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	size = ft_size(n);
	str = numb(n, size);
	if (!str)
		return (NULL);
	return (str);
}
