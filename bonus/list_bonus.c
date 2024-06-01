/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:18:34 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/31 20:46:19 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_lstadd_front(t_list **lst, t_list *node)
{
	if (!*lst)
	{
		*lst = node;
		(*lst)->next = NULL;
	}
	else
	{
		node->next = *lst;
		*lst = node;
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
