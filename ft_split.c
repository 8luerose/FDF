/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:06:11 by taehkwon          #+#    #+#             */
/*   Updated: 2023/06/29 20:13:31 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(char const *str, char delim)
{
	size_t	cnt;
	int		prev_word_flag;

	prev_word_flag = 0;
	cnt = 0;
	while (*str)
	{
		if (*str == delim)
			prev_word_flag = 0;
		else if (prev_word_flag == 0 && *str != delim)
		{
			prev_word_flag = 1;
			cnt++;
		}
		str++;
	}
	return (cnt);
}

static char	*next_word(char **s, char c)
{
	char	*word_start;
	char	*word_end;
	char	*word;

	while (**s == c)
		(*s)++;
	word_start = *s;
	word_end = ft_strchr(*s, c);
	if (word_end == 0)
	{
		word = ft_strdup(word_start);
		*s = (*s + (ft_strlen(word_start)));
	}
	else
	{
		word = ft_substr(word_start, 0, word_end - word_start);
		*s = word_end;
	}
	return (word);
}

static void	free_split(char **s, int i)
{
	while (i >= 0)
	{
		free (s[i]);
		i--;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*s_p;
	int		cnt;
	int		i;

	if (!s)
		return (0);
	cnt = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!result)
		return (0);
	s_p = (char *)s;
	i = 0;
	while (i < cnt)
	{
		result[i] = next_word(&s_p, c);
		if (!result[i])
		{
			free_split(result, i);
			return (0);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
