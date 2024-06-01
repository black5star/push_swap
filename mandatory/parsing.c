/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:09:14 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/31 13:52:10 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_str(char *s)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (s[++i])
	{
		if ((s[i] != ' ' && s[i] != '+' && s[i] != '-' && (s[i] < '0'
					|| s[i] > '9')) || ((s[i] == '+' || s[i] == '-' )
				&& (s[i + 1] < '0' || s[i + 1] > '9')))
			ft_error("Error\n", 255);
	}
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != ' ')
			i++;
		if (s[i - 1] && s[i - 1] != ' ')
			counter++;
		while (s[i] && s[i] == ' ')
			i++;
	}
	if (counter == 0)
		ft_error("Error\n", 255);
	return (counter);
}

int	total_nums(int ac, char *av[])
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			ft_error("Error\n", 255);
		total += check_str(av[i]);
		i++;
	}
	return (total);
}

t_list	**push_to_stack(int *arr, int len)
{
	t_list	**stack_a;
	t_list	*tmp;
	t_list	*new_node;
	int		i;

	stack_a = malloc(len * sizeof(t_list *));
	if (stack_a == NULL)
	{
		free(arr);
		exit(1);
	}
	tmp = NULL;
	i = len - 1;
	while (i >= 0)
	{
		new_node = ft_lstnew(arr[i]);
		new_node->next = tmp;
		tmp = new_node;
		stack_a[i] = tmp;
		i--;
	}
	putindex(stack_a, arr, len);
	free(arr);
	return (stack_a);
}

void	spliting(char *str, int i, int *arr)
{
	char	**splt;
	int		j;

	j = 0;
	splt = ft_split(str, ' ');
	j = 0;
	while (splt[j])
	{
		arr[i] = ft_atoi(splt[j], arr);
		i++;
		j++;
	}
	spliting_free(splt, j);
}

int	*check_params(int ac, char *av[], int total)
{
	int	i;
	int	j;
	int	num;
	int	*arr;

	arr = malloc(sizeof(int) * total);
	i = 1;
	j = 0;
	while (i < ac)
	{
		num = check_str(av[i]);
		if (num == 1)
			arr[j] = ft_atoi(av[i], arr);
		else
		{
			spliting(av[i], j, arr);
		}
		i++;
		j += num;
	}
	ft_compare(arr, total);
	return (arr);
}
