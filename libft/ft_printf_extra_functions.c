/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extra_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:52:33 by riolivei          #+#    #+#             */
/*   Updated: 2022/11/18 14:37:15 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_negative(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		return (147483648);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		return (n * (-1));
	}
	return (n);
}

int	unum_digits(unsigned int n)
{
	int	counter;

	counter = 0;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

int	ft_printf_itoa(int n)
{
	char	*str;
	int		array[3];

	array[0] = 0;
	if (n < 0)
		array[0]++;
	array[2] = is_negative(n);
	if (array[2] == 147483648)
		array[0] = 2;
	array[1] = num_printf_digits(array[2]);
	str = (char *)malloc(sizeof(char) * (array[1] + 1));
	if (!str)
		return (0);
	str[array[1]] = '\0';
	if (n == 0)
		str[--array[1]] = '0';
	while (array[2] != 0)
	{
		str[--array[1]] = (array[2] % 10) + 48;
		array[2] /= 10;
	}
	array[0] += full_string(str);
	free(str);
	return (array[0]);
}

int	ft_uitoa(unsigned int n)
{
	char	*str;
	int		i;
	int		count;

	if (n == 0)
		return (write(1, "0", 1));
	i = unum_digits(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i--] = '\0';
	while (n != 0)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	count = full_string(str);
	free(str);
	return (count);
}
