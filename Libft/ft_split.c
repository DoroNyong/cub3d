/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:55:38 by hjang             #+#    #+#             */
/*   Updated: 2025/11/05 16:05:13 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **res, int word)
{
	while (word >= 0)
	{
		free(res[word]);
		word--;
	}
	free(res);
}

static char	**mk_char_2dimen(char const *s, char c)
{
	char	**res;
	int		index;
	int		word_len;
	int		word;

	index = 0;
	word_len = 0;
	word = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c)
		{
			if (word_len == 0)
				word++;
			word_len++;
		}
		else
			word_len = 0;
		index++;
	}
	res = (char **)malloc(sizeof(char *) * (word + 1));
	if (!res)
		return (NULL);
	return (res);
}

static char	**mk_char_1dimen(char **res, char const *s, char c)
{
	int	index;
	int	word_len;
	int	word;

	index = 0;
	word_len = 0;
	word = 0;
	while (index <= (int)ft_strlen(s))
	{
		if ((s[index] == c || s[index] == '\0') && word_len != 0)
		{
			res[word++] = (char *)malloc(sizeof(char) * (word_len + 1));
			if (!res[word - 1])
			{
				free_all(res, word - 2);
				return (NULL);
			}
			word_len = 0;
		}
		else if (s[index] != c)
			word_len++;
		index++;
	}
	res[word] = NULL;
	return (res);
}

static char	**put_word(char **res, char const *s, char c)
{
	int	index;
	int	word_len;
	int	word;

	index = 0;
	word_len = 0;
	word = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c && word_len != 0)
		{
			res[word++][word_len] = '\0';
			word_len = 0;
		}
		else if (s[index] != c)
			res[word][word_len++] = s[index];
		index++;
	}
	if (word_len != 0)
		res[word][word_len] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = mk_char_2dimen(s, c);
	if (!res)
		return (NULL);
	if (mk_char_1dimen(res, s, c) == NULL)
		return (NULL);
	return (put_word(res, s, c));
}
