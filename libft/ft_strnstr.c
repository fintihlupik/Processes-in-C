/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pterekho <pterekho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:33:07 by pterekho          #+#    #+#             */
/*   Updated: 2024/05/30 17:33:07 by pterekho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;
	size_t	p;

	i = 0;
	p = 0;
	if (ft_strlen(needle) < 1)
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		count = 0;
		while (haystack[i] && (i < len) && haystack[i] != needle[j])
			i++;
		p = i;
		while (haystack[i] && (i < len) && haystack[i++] == needle[j++])
			count++;
		if (count == ft_strlen(needle))
			return ((char *)haystack + p);
		i = p + 1;
	}
	return (NULL);
}
