/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:52:49 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/21 16:48:54 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	*str;
	char	**ptr;
	int		i;
	int		words;
	int		a;

	str = (char *)s;
	if (!s || !(ptr = (char**)malloc(sizeof(char**) * count_words(str, c))))
		return (NULL);
	i = 0;
	words = -1;
	while (!(a = 0) && (++words + 1) && str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (!(ptr[words] = (char*)malloc(sizeof(char*) * count_let(str, i, c))))
			return (NULL);
		while ((str[i] != c) && (str[i] != '\0'))
			ptr[words][a++] = str[i++];
		ptr[words][a] = '\0';
		if (str[i] == '\0' && str[i - 1] == c)
			words--;
	}
	ptr[words] = NULL;
	return (ptr);
}
