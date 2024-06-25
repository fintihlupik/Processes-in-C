/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pterekho <pterekho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:32:36 by pterekho          #+#    #+#             */
/*   Updated: 2024/05/30 17:32:36 by pterekho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(sizeof(char) * len);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = 0;
	return (new_str);
}
