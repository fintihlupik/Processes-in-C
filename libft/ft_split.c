/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pterekho <pterekho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:31:46 by pterekho          #+#    #+#             */
/*   Updated: 2024/05/30 17:31:46 by pterekho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			while (str[i] && str[i] != c)
				i++;
			count++;
		}	
	}
	return (count);
}

static int	word_len(char const *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static char	**free_mem(char **arr, int i)
{
	arr[i] = NULL;
	while (i--)
		free(arr[i]);
	free(arr);
	return (NULL);
}

static char	**arrey_malloc(char const *str, int word_number)
{
	char	**arr;

	if (!str)
		return (NULL);
	arr = malloc(sizeof(char *) * (word_number + 1));
	if (!arr)
		return (NULL);
	arr[word_number] = NULL;
	return (arr);
}

char	**ft_split(char const *str, char c)
{
	char	**arr;
	int		word_number;
	int		i;
	int		p;

	word_number = count_words(str, c);
	arr = arrey_malloc(str, word_number);
	if (!arr)
		return (NULL);
	i = 0;
	p = 0;
	while (i < word_number)
	{
		while (str[p] && str[p] == c)
			p++;
		arr[i] = ft_substr(str, p, word_len(str + p, c));
		if (arr[i] == NULL)
			return (arr = free_mem(arr, i));
		while (str[p] && str[p] != c)
			p++;
		i++;
	}
	return (arr);
}
