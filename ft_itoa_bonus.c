/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:16:16 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/14 14:03:01 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_nums_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_itoa(int n, char *count_str)
{
	int		len;
	long	number;
	int		i;

	i = 0;
	while (count_str[i])
		count_str[i] = 0;
	number = n;
	len = ft_nums_len(n);
	if (number == 0)
		count_str[0] = '0';
	count_str[len] = '\0';
	if (number < 0)
	{
		count_str[0] = '-';
		number *= -1;
	}
	while (number > 0)
	{
		count_str[--len] = (number % 10) + '0';
		number = number / 10;
	}
}
