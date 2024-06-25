/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pterekho <pterekho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:33:22 by pterekho          #+#    #+#             */
/*   Updated: 2024/05/30 17:33:22 by pterekho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (start > i)
		len = 0;
	if (len > i - start)
		len = i - start;
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (len--)
		substr[i++] = s[start++];
	substr[i] = 0;
	return (substr);
}
