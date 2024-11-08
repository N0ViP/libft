/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:18:20 by yjaafar           #+#    #+#             */
/*   Updated: 2024/10/29 23:29:28 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

static size_t	ft_cnt_word(const char *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cnt);
}

static char	**ft_alloc(char ***res, const char *s, char c, size_t i)
{
	size_t	j;
	size_t	cnt_char;

	j = 0;
	while (s[i])
	{
		cnt_char = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			cnt_char++;
			i++;
		}
		(*res)[j] = (char *)malloc(cnt_char + 1);
		if (!(*res)[j])
		{
			ft_free(*res);
			free(*res);
			return (NULL);
		}
		j++;
	}
	return (*res);
}

static char	**ft_copy(char **res, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			res[j][k] = s[i];
			i++;
			k++;
		}
		if (k > 0)
		{
			res[j][k] = '\0';
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	cnt_word;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	cnt_word = ft_cnt_word(s, c);
	res = (char **)malloc(sizeof(char *) * (cnt_word + 1));
	if (!res)
		return (NULL);
	res = ft_alloc(&res, s, c, i);
	if (!res)
		return (NULL);
	res = ft_copy(res, s, c);
	return (res);
}
