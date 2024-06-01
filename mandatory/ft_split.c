/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:08:46 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/30 17:14:15 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	char_counter(char *str, char c)
{
	unsigned int	counter;

	counter = 0;
	while (str[counter])
	{
		if (str[counter] == c)
			return (counter);
		counter++;
	}
	return (counter);
}

static char	*str_cut(char *s, unsigned int i)
{
	char			*str;
	unsigned int	counter;

	if (!s)
		return (NULL);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	counter = 0;
	while (s[counter] && counter < i)
	{
		str[counter] = s[counter];
		counter++;
	}
	str[counter] = '\0';
	return (str);
}

static int	words_count(char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		counter++;
		while (str[i] != c && str[i])
			i++;
		while (str[i] == c && str[i])
			i++;
	}
	return (counter);
}

static void	**my_copying(char **str, char *p, char c, int words_number)
{
	int	i;

	i = 0;
	while (i < words_number)
	{
		while (*p == c && *p)
			p++;
		if (*p != c && *p)
		{
			str[i] = str_cut(p, char_counter(p, c));
			if (!str[i])
			{
				while (i >= 0)
					free (str[--i]);
				free (str);
				free (p);
				return ((void *)0);
			}
			i++;
		}
		while (*p != c && *p)
			p++;
	}
	return ((void **)str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*ptr;
	char	*p;
	int		words_number;

	if (!s)
		return (NULL);
	ptr = ft_strdup(s);
	if (!ptr)
		return (NULL);
	p = ptr;
	words_number = words_count(ptr, c);
	str = (char **)malloc((words_number + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	my_copying(str, ptr, c, words_number);
	str[words_number] = NULL;
	free (p);
	return (str);
}
