/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:37:54 by riolivei          #+#    #+#             */
/*   Updated: 2022/11/08 16:01:26 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	final_str = (char *)malloc((ft_strlen(s1)
				+ ft_strlen(s2) + 1) * sizeof(char));
	if (!final_str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_strlen(s1))
		final_str[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(s2))
		final_str[i++] = s2[j++];
	final_str[i] = '\0';
	return (final_str);
}
