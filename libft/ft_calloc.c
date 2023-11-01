/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:49:56 by riolivei          #+#    #+#             */
/*   Updated: 2022/11/03 18:15:11 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t items, size_t n)
{
	char				*allocated;
	unsigned int		total;
	size_t				i;

	total = items * n;
	allocated = (char *)malloc(total);
	if (allocated == NULL)
		return (NULL);
	i = 0;
	while (total > 0)
	{
		allocated[i] = 0;
		total--;
		i++;
	}
	return ((void *)allocated);
}
