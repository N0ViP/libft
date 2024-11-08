/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:45:50 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/08 03:25:57 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	num_len(int n)
{
	size_t	n_len;

	n_len = 0;
	if (n < 0)
	{
		n_len++;
		n *= -1;
	}
	while (n > 0)
	{
		n_len++;
		n /= 10;
	}
	return (n_len);
}

static char	*ft_strrev(char *str, size_t end)
{
	size_t	start;
	char	swp;

	start = 0;
	while (start < end)
	{
		swp = str[start];
		str[start] = str[end];
		str[end] = swp;
		start++;
		end--;
	}
	return (str);
}

static char	*ft_itoa_1(char *res, int n)
{
	size_t	i;
	size_t	sign;

	i = 0;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	while (n > 0)
	{
		res[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	if (sign == 1)
	{
		res[i] = 45;
		i++;
	}
	res[i] = '\0';
	res = ft_strrev(res, --i);
	return (res);
}

static char	*check(char *res, int n)
{
	char	*tmp;

	tmp = "-2147483648";
	if (n == 0)
	{
		res = (char *)malloc(2);
		if (!res)
			return (NULL);
		res[0] = 48;
		res[1] = 0;
	}
	else
	{
		res = (char *)malloc(12);
		if (!res)
			return (NULL);
		ft_strlcpy(res, tmp, 12);
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;

	res = NULL;
	if (n == 0 || n == -2147483648)
	{
		res = check(res, n);
		return (res);
	}
	res = (char *)malloc(num_len(n) + 1);
	if (!res)
		return (NULL);
	res = ft_itoa_1(res, n);
	if (!res)
		return (NULL);
	return (res);
}
