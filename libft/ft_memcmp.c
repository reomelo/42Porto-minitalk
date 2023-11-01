/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:02:35 by riolivei          #+#    #+#             */
/*   Updated: 2022/11/08 17:21:05 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*string1;
	const unsigned char	*string2;
	size_t				i;

	string1 = str1;
	string2 = str2;
	i = 0;
	if (n == 0)
		return (0);
	while (string1[i] == string2[i] && i < (n - 1))
		i++;
	return (string1[i] - string2[i]);
}
