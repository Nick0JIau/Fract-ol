/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:05:24 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/11/06 17:48:46 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *s, char c, size_t i)
{
	size_t len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static char	**ft_copy(char const *s, char c, char **str)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			str[j][k] = s[i];
			k++;
			i++;
		}
		str[j][k] = '\0';
		j++;
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s || !(str = (char**)malloc(sizeof(char*) * (ft_wordcount(s, c) + 1))))
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!(str[j] = (char*)malloc(sizeof(char) * (ft_wordlen(s, c, i)))))
		{
			ft_memdel((void*)str);
			return (0);
		}
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	j = ft_wordcount(s, c);
	str = ft_copy(s, c, str);
	str[j] = NULL;
	return (str);
}
