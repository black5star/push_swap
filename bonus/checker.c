/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:50:34 by hboustaj          #+#    #+#             */
/*   Updated: 2024/06/02 10:53:32 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	ft_read(stack_a, stack_b);
	if (!is_sorted(stack_a) && !check_b(stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free(stack_a, stack_b);
}
