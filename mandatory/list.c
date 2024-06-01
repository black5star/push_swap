/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:08:41 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/30 19:39:39 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = lst;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		(*lst)->next = NULL;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_swap(t_list *stack_a)
{
	t_list	*temp;

	if (ft_lstsize(stack_a) <= 1)
		return ;
	temp = malloc(sizeof(t_list));
	temp->content = stack_a->content;
	temp->index = stack_a->index;
	stack_a->content = stack_a->next->content;
	stack_a->index = stack_a->next->index;
	stack_a->next->content = temp->content;
	stack_a->next->index = temp->index;
	free(temp);
}
