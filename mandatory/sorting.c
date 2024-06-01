/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:58:00 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/30 20:57:00 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_3_nums(t_list **stack)
{
	if (ft_lstsize(*stack) == 2 && !max_num(stack, *stack))
		swap_stack(stack, NULL, "sa\n");
	else
	{
		if (!is_sorted(stack))
			return ;
		if (!max_num(stack, *stack))
			rotate_stack(stack, NULL, "ra\n");
		else if (!max_num(stack, (*stack)->next))
			rr_stack(stack, NULL, "rra\n");
		if (is_sorted(stack))
			swap_stack(stack, NULL, "sa\n");
	}
}

void	sorting_4_nums(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	int		p;

	p = find_min(stack_a);
	ptr = *stack_a;
	while (ptr)
	{
		if (!min_num(stack_a, ptr))
		{
			push_stack(stack_a, stack_b, "pb\n");
			break ;
		}
		if (p < 3)
			rotate_stack(stack_a, NULL, "ra\n");
		else
		{
			rr_stack(stack_a, NULL, "rra\n");
			ptr = *stack_a;
		}
	}
	sorting_3_nums(stack_a);
	push_stack(stack_b, stack_a, "pa\n");
}

void	sorting_5_nums(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	int		p;

	p = find_min(stack_a);
	ptr = *stack_a;
	while (ptr)
	{
		if (!min_num(stack_a, ptr))
		{
			push_stack(stack_a, stack_b, "pb\n");
			break ;
		}
		if (p < 3)
			rotate_stack(stack_a, NULL, "ra\n");
		else
		{
			rr_stack(stack_a, NULL, "rra\n");
			ptr = *stack_a;
		}
	}
	sorting_4_nums(stack_a, stack_b);
	push_stack(stack_b, stack_a, "pa\n");
}

void	more_than_5(t_list **stack_a, t_list **stack_b)
{
	int	range;
	int	size;

	range = range_calculator(stack_a);
	while (*stack_a)
	{
		size = ft_lstsize(*stack_b);
		if ((*stack_a)->index < size)
		{
			push_stack(stack_a, stack_b, "pb\n");
			rotate_stack(NULL, stack_b, "rb\n");
		}
		else if ((*stack_a)->index <= (size + range))
			push_stack(stack_a, stack_b, "pb\n");
		else
			rotate_stack(stack_a, NULL, "ra\n");
	}
	while (*stack_b)
		repush_to_a(stack_a, stack_b);
}

void	sorting(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 3)
		sorting_3_nums(stack_a);
	else if (size == 4)
		sorting_4_nums(stack_a, stack_b);
	else if (size == 5)
		sorting_5_nums(stack_a, stack_b);
	else
		more_than_5(stack_a, stack_b);
}
