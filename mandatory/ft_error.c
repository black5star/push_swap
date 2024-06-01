/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:53:37 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/30 19:45:22 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_list	*ptr;
	t_list	*p;

	ptr = *stack_a;
	p = ptr->next;
	while (ptr->next)
	{
		free(ptr);
		ptr = p;
		p = p->next;
	}
	free(ptr);
	free(stack_a);
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
