/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:10:58 by julberna          #+#    #+#             */
/*   Updated: 2023/10/26 20:18:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char *s, char c)
{
	int	i;
	int	words;
	int	start;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0')
		{
			if (s[i] != c)
				break ;
			i++;
		}
		start = i;
		while (s[i] != '\0')
		{
			if (s[i] == c)
				break ;
			i++;
		}
		if (i > start)
			words++;
	}
	return (words);
}

static void	ft_word_processing(const char *s, char c, char **split, int i)
{
	int		start;
	size_t	string_index;

	string_index = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0')
		{
			if (s[i] != c)
				break ;
			i++;
		}
		start = i;
		while (s[i] != '\0')
		{
			if (s[i] == c)
				break ;
			i++;
		}
		if (i > start)
		{
			split[string_index] = ft_substr(s, start, (i - start));
			string_index++;
		}
	}
}

char	**ft_split(const char *s, char c)
{
	int		i;
	char	**split;
	size_t	word_count;

	i = 0;
	if (s == NULL)
		return (NULL);
	word_count = ft_wordcount((char *)s, c);
	split = (char **)ft_calloc((word_count + 1), sizeof(char *));
	if (!split)
		return (NULL);
	ft_word_processing(s, c, split, i);
	return (split);
}
