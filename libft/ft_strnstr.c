/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:12:49 by riolivei          #+#    #+#             */
/*   Updated: 2022/11/08 17:52:53 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((n == 0 && !*s2) || !*s2)
		return ((char *)s1);
	if (n == 0)
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i + j] != '\0' && s2[j] != '\0'
			&& s1[i + j] == s2[j] && (i + j) < n)
		{
			if (s2[j + 1] == '\0')
				return ((char *)&(s1[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}
