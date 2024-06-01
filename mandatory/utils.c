/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:08:24 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/30 19:43:08 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	max_num(t_list **stack, t_list *ptr)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		if (ptr->index < temp->index)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

int	min_num(t_list **stack, t_list *ptr)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		if (ptr->index > temp->index)
			return (-1);
		temp = temp->next;
	}
	return (0);
}
