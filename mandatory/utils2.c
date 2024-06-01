/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:57:43 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/31 20:21:30 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list **stack)
{
	t_list	*temp;
	int		i;

	temp = *stack;
	i = 1;
	while (temp)
	{
		if (!max_num(stack, temp))
			return (i);
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_min(t_list **stack)
{
	t_list	*temp;
	int		i;

	temp = *stack;
	i = 1;
	while (temp)
	{
		if (!min_num(stack, temp))
			return (i);
		temp = temp->next;
		i++;
	}
	return (i);
}

int	range_calculator(t_list **stack)
{
	int	size;

	size = ft_lstsize(*stack);
	if (size <= 15)
		return (2);
	else if (size <= 100)
		return (15);
	else if (size <= 250)
		return (23);
	else if (size <= 500)
		return (34);
	return (45);
}

void	repush_to_a(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size;

	i = find_max(stack_b);
	size = ft_lstsize(*stack_b);
	if (i <= (size / 2) + 1)
		while (--i)
			rotate_stack(NULL, stack_b, "rb\n");
	else if (i > (size / 2) + 1)
	{
		while (i <= size)
		{
			rr_stack(NULL, stack_b, "rrb\n");
			i++;
		}
	}
	push_stack(stack_b, stack_a, "pa\n");
}
