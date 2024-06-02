/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:04:25 by hboustaj          #+#    #+#             */
/*   Updated: 2024/06/02 10:55:46 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ftstrlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ftstrdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = malloc(ftstrlen(s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i] && s1[i] != '\n')
	{
		s2[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	if (s2[0] == '\0')
	{
		free(s2);
		return (NULL);
	}
	return (s2);
}

int	ft_execute(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap_stack(stack_a, NULL);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap_stack(NULL, stack_b);
	else if (!ft_strncmp(str, "ss\n", 3))
		swap_stack(stack_a, stack_b);
	else if (!ft_strncmp(str, "pa\n", 3))
		push_stack(stack_b, stack_a);
	else if (!ft_strncmp(str, "pb\n", 3))
		push_stack(stack_a, stack_b);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate_stack(stack_a, NULL);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate_stack(NULL, stack_b);
	else if (!ft_strncmp(str, "rra\n", 4))
		rr_stack(stack_a, NULL);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rr_stack(NULL, stack_b);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rr_stack(stack_a, stack_b);
	else
		return (-1);
	return (0);
}

void	ft_read(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (ft_execute(stack_a, stack_b, str))
		{
			free(str);
			ft_free(stack_a, stack_b);
			ft_error("Error\n", 255);
		}
		free(str);
	}
}

void	free_stack(t_list **stack)
{
	t_list	*ptr;
	t_list	*p;

	ptr = *stack;
	if (ptr != NULL)
		p = ptr->next;
	if (ptr != NULL)
	{
		while (ptr != NULL)
		{
			free(ptr);
			ptr = p;
			if (ptr != NULL)
				p = p->next;
		}
	}
}
