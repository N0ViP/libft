/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:51:48 by yjaafar           #+#    #+#             */
/*   Updated: 2024/10/25 14:40:17 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;
	size_t	r_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	r_len = s1_len + s2_len + 1;
	res = (char *)malloc(r_len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < r_len && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (i < r_len && s2[i - s1_len])
	{
		res[i] = s2[i - s1_len];
		i++;
	}
	res[i] = '\0';
	return (res);
}
