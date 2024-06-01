/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:11:07 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/31 18:58:39 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		*arr;
	int		total;

	if (ac < 2)
		return (0);
	total = total_nums(ac, av);
	arr = check_params(ac, av, total);
	stack_a = push_to_stack(arr, total);
	stack_b = malloc(sizeof(t_list *));
	(*stack_b) = NULL;
	if (is_sorted(stack_a) == -1)
		sorting(stack_a, stack_b);
	ft_free(stack_a, stack_b);
}
