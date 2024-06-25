/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pterekho <pterekho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:58:17 by pterekho          #+#    #+#             */
/*   Updated: 2024/06/04 18:26:48 by pterekho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *str, ...)
{
	va_list	ap;
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 's')
		{
			s = va_arg(ap, char *);
			j = 0;
			while (s[j] != '\0')
				write(2, &s[j++], 1);
			i++;
		}
		else
			write(2, &str[i], 1);
		i++;
	}
	va_end(ap);
}

void	perror_exit(void)
{
	perror("");
	exit(EXIT_FAILURE);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i++])
		free(arr[i]);
	free(arr);
}
