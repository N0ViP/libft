/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:28:14 by yjaafar           #+#    #+#             */
/*   Updated: 2024/10/24 14:49:58 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n > 0)
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		c = (n % 10) + 48;
		write(fd, &c, 1);
	}
}
