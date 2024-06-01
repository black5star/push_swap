/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:21:05 by hboustaj          #+#    #+#             */
/*   Updated: 2024/06/01 12:21:47 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	indexing(t_list **stack_a, int *arr, int len)
{
	t_list	*ptr;
	int		i;

	ptr = *stack_a;
	i = 0;
	while (ptr != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (arr[i] == ptr->content)
				ptr->index = i;
			i++;
		}
		ptr = ptr->next;
	}
}

void	putindex(t_list **stack_a, int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	indexing(stack_a, arr, len);
}

int	is_sorted(t_list **stack)
{
	t_list	*ptr;

	ptr = *stack;
	while (ptr)
	{
		if (ptr->next && (ptr->index > ptr->next->index))
			return (-1);
		ptr = ptr->next;
	}
	return (0);
}

int	check_b(t_list **stack)
{
	if (stack && *stack)
		return (-1);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
