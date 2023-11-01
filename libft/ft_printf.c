/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:57:03 by riolivei          #+#    #+#             */
/*   Updated: 2022/11/18 14:24:42 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_printf_digits(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

int	full_string(char *str)
{
	int	i;
	int	count;

	if (!str)
	{
		count = full_string("(null)");
		return (count);
	}
	i = -1;
	count = 0;
	while (str[++i])
		count += character(str[i]);
	return (count);
}

int	character(int c)
{
	write(1, &c, 1);
	return (1);
}

int	conversion(int c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = character(va_arg(args, int));
	else if (c == 's')
		count = full_string(va_arg(args, char *));
	else if (c == 'p')
		count = voidptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		count = ft_printf_itoa(va_arg(args, int));
	else if (c == 'u')
		count = ft_uitoa(va_arg(args, unsigned int));
	else if (c == 'x')
		count = hexa(va_arg(args, unsigned int), 'l');
	else if (c == 'X')
		count = hexa(va_arg(args, unsigned int), 'u');
	else if (c == '%')
		count = character('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	count = 0;
	i = -1;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			count += conversion(str[i + 1], args);
			i++;
		}
		else
			count += character(str[i]);
	}
	va_end(args);
	return (count);
}
