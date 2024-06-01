/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:08:33 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/30 17:57:20 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list **stack_a, t_list **stack_b, char *str)
{
	if (stack_a)
		ft_swap(*stack_a);
	if (stack_b)
		ft_swap(*stack_b);
	ft_putstr_fd(str, 1);
}

void	push_stack(t_list	**from,	t_list **to, char *str)
{
	t_list	*temp;

	temp = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = temp;
	ft_putstr_fd(str, 1);
}

void	rotate_stack(t_list	**stack_a,	t_list	**stack_b,	char *str)
{
	t_list	*temp;

	if (stack_a)
	{
		temp = *stack_a;
		while (temp)
		{
			ft_swap(temp);
			temp = temp->next;
		}
	}
	if (stack_b)
	{
		temp = *stack_b;
		while (temp)
		{
			ft_swap(temp);
			temp = temp->next;
		}
	}
	ft_putstr_fd(str, 1);
}

void	rotate_reverse(t_list	**stack)
{
	int		size;
	t_list	*temp1;
	t_list	*temp2;

	size = ft_lstsize(*stack);
	temp1 = *stack;
	while (size - 1 > 1)
	{
		temp1 = temp1->next;
		size--;
	}
	temp2 = temp1->next;
	temp1->next = NULL;
	ft_lstadd_front(stack, temp2);
}

void	rr_stack(t_list	**stack_a,	t_list	**stack_b, char *str)
{
	if (stack_a)
		rotate_reverse(stack_a);
	if (stack_b)
		rotate_reverse(stack_b);
	ft_putstr_fd(str, 1);
}
