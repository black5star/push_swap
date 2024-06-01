/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:13:34 by hboustaj          #+#    #+#             */
/*   Updated: 2024/06/01 12:17:58 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	spliting_free(char **splt, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(splt[i]);
		i++;
	}
	free(splt);
}

void	ft_free(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	free(stack_a);
	if (stack_b)
		free_stack(stack_b);
	free(stack_b);
}

void	ft_error(char *str, int num)
{
	if (str)
		ft_putstr_fd(str, 2);
	exit(num);
}

void	free_exit(int *arr)
{
	free(arr);
	ft_error("Error\n", 255);
}
