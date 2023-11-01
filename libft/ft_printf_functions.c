/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:47:01 by riolivei          #+#    #+#             */
/*   Updated: 2022/11/18 13:50:07 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hexa(unsigned int n, int c)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += hexa(n / 16, c);
		count += hexa(n % 16, c);
	}
	else
	{
		if (n <= 9)
			count += character((n + '0'));
		else
		{
			if (c == 'l')
				count += character((n - 10 + 'a'));
			if (c == 'u')
				count += character((n - 10 + 'A'));
		}
	}
	return (count);
}

int	voidptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count = full_string("(nil)");
		return (count);
	}
	count += write(1, "0x", 2);
	count += voidptr_put(ptr);
	return (count);
}

int	voidptr_put(uintptr_t n)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += voidptr_put(n / 16);
		count += voidptr_put(n % 16);
	}
	else
	{
		if (n <= 9)
			count += character(n + '0');
		else
			count += character(n - 10 + 'a');
	}
	return (count);
}
