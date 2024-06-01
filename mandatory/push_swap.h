/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:11:19 by hboustaj          #+#    #+#             */
/*   Updated: 2024/05/31 17:58:36 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

//in utils.c file
void	indexing(t_list **stack_a, int *arr, int len);
void	putindex(t_list **stack_a, int *arr, int len);
int		is_sorted(t_list **stack);
int		max_num(t_list **stack, t_list *ptr);
int		min_num(t_list **stack, t_list *ptr);

//in utils2.c file
int		find_max(t_list	**stack);
int		find_min(t_list	**stack);
int		range_calculator(t_list **stack);
void	repush_to_a(t_list **stack_a, t_list **stack_b);

//in parsing.c file
int		check_str(char *s);
int		total_nums(int ac, char *av[]);
t_list	**push_to_stack(int *arr, int len);
void	spliting(char *str, int i, int *arr);
int		*check_params(int ac, char *av[], int total);

// in ft_error.c file
void	spliting_free(char **splt, int j);
void	ft_free(t_list **stack_a, t_list **stack_b);
void	ft_error(char *str, int num);
void	free_exit(int *arr);

//in ft_split.c file
char	**ft_split(char const *s, char c);

//in libft.c file
int		ft_atoi(const char	*str, int *arr);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_compare(int *arr, int len);

//in list.c file
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_swap(t_list *stack_a);

//in rules.c file
void	swap_stack(t_list **stack_a, t_list **stack_b, char *str);
void	push_stack(t_list **from, t_list **to, char *str);
void	rotate_stack(t_list **stack_a, t_list **stack_b, char *str);
void	rotate_reverse(t_list **stack);
void	rr_stack(t_list **stack_a, t_list **stack_b, char *str);

//in sorting.c file
void	sorting_3_nums(t_list **stack);
void	sorting_4_nums(t_list **stack_a, t_list **stack_b);
void	sorting_5_nums(t_list **stack_a, t_list **stack_b);
void	more_than_5(t_list **stack_a, t_list **stack_b);
void	sorting(t_list **stack_a, t_list **stack_b);

#endif
