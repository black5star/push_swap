/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboustaj <hboustaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:50:55 by hboustaj          #+#    #+#             */
/*   Updated: 2024/06/01 12:16:53 by hboustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

//in utils_bonus.c file
void	indexing(t_list **stack_a, int *arr, int len);
void	putindex(t_list **stack_a, int *arr, int len);
int		is_sorted(t_list **stack);
int		check_b(t_list **stack);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//in parsing_bonus.c file
int		check_str(char *s);
int		total_nums(int ac, char *av[]);
t_list	**push_to_stack(int *arr, int len);
void	spliting(char *str, int i, int *arr);
int		*check_params(int ac, char *av[], int total);

// in error_bonus.c file
void	spliting_free(char **splt, int j);
void	ft_free(t_list **stack_a, t_list **stack_b);
void	ft_error(char *str, int num);
void	free_exit(int *arr);

//in split_bonus.c file
char	**ft_split(char const *s, char c);

//in get_next_line file
char	*ft_strjoin(char *s1, char const *s2);
char	*get_next_line(int fd);

//in utils2_bonus.c file
size_t	ftstrlen(const char *s);
char	*ftstrdup(const char *s1);
int		ft_execute(t_list **stack_a, t_list **stack_b, char *str);
void	ft_read(t_list **stack_a, t_list **stack_b);
void	free_stack(t_list **stack);

//in libft_bonus.c file
int		ft_atoi(const char	*str, int *arr);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_compare(int *arr, int len);

//in list_bonus.c file
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *node);
void	ft_swap(t_list *stack_a);

//in rules_bonus.c file
void	swap_stack(t_list **stack_a, t_list **stack_b);
void	push_stack(t_list **from, t_list **to);
void	rotate_stack(t_list **stack_a, t_list **stack_b);
void	rotate_reverse(t_list **stack);
void	rr_stack(t_list **stack_a, t_list **stack_b);

#endif
