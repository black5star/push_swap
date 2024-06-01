/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:02:32 by hboustaj          #+#    #+#             */
/*   Updated: 2024/06/01 12:18:45 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char			*strjoin;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	strjoin = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strjoin)
		return (NULL);
	while (s1[j])
		strjoin[i++] = s1[j++];
	j = 0;
	while (s2[j])
		strjoin[i++] = s2[j++];
	strjoin[i] = '\0';
	free (s1);
	return (strjoin);
}

static char	*my_check(char	*s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			return (s);
		i++;
	}
	return (NULL);
}

static char	*first_line(char *str, int fd)
{
	char	*buffer;
	int		i;

	buffer = malloc((size_t)5 + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (!my_check(str) && i != 0)
	{
		i = read(fd, buffer, 5);
		if (i == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

static char	*static_modify(char *s)
{
	char	*str;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ftstrlen(s);
	if (!s[len])
	{
		free(s);
		return (NULL);
	}
	str = malloc(ftstrlen(s) - len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[len])
		str[i++] = s[len++];
	str[i] = '\0';
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*returned;

	if (fd < 0)
		return (0);
	line = first_line(line, fd);
	if (!line)
		returned = NULL;
	else
		returned = ftstrdup(line);
	line = static_modify(line);
	return (returned);
}
