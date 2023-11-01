/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:10:29 by riolivei          #+#    #+#             */
/*   Updated: 2022/11/08 17:29:04 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*final_dest;
	unsigned char	*final_src;
	size_t			i;

	if (!src && !dest)
		return (NULL);
	final_dest = dest;
	final_src = src;
	i = -1;
	while (++i < n)
		*final_dest++ = *final_src++;
	return (dest);
}
