/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:57:44 by riolivei          #+#    #+#             */
/*   Updated: 2022/11/08 17:49:03 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;
	size_t	extra;

	if (size == 0)
		return (ft_strlen(src));
	len_s = ft_strlen(src);
	len_d = ft_strlen(dest);
	extra = len_d;
	i = 0;
	if (size < len_d)
		return (size + len_s);
	while (src[i] != '\0' && extra < (size - 1))
	{
		dest[extra] = src[i];
		extra++;
		i++;
	}
	dest[extra] = '\0';
	return (len_d + len_s);
}
