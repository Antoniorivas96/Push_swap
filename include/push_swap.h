/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:53:16 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/27 13:35:56 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
	int				push_cost;
	int				number;
	int				pos;
	bool			above_median;
	bool			cheapest;
}	t_stack;

int		syntax_error(char *n_post);
int		duplicate(t_stack *a, int n_search);
void	error(t_stack **a);
void	free_error(t_stack **a);
void	current_index(t_stack *list);
t_stack	*cheapest_node(t_stack *list);
void	easy_node(t_stack *list);
void	start_node_a(t_stack *a, t_stack *b);
void	start_node_b(t_stack *a, t_stack *b);
void	sort_more_three(t_stack **a, t_stack **b);
void	sort_three(t_stack **top);
int		list_len(t_stack *set_list);
t_stack	*f_last_node(t_stack *set_list);
bool	list_sorted(t_stack *set_list);
t_stack	*min_number(t_stack *list);
t_stack	*max_number(t_stack *list);
void	pa(t_stack **a, t_stack **b, bool ft_printf);
void	pb(t_stack **b, t_stack **a, bool ft_printf);
void	rra(t_stack **a, bool ft_printf);
void	rrb(t_stack **b, bool ft_printf);
void	rrr(t_stack **a, t_stack **b, bool ft_printf);
void	ra(t_stack **a, bool ft_printf);
void	rb(t_stack **b, bool ft_printf);
void	rr(t_stack **a, t_stack **b, bool ft_printf);
void	number_to_node(t_stack **set_list, int n);
void	start_stack_a(t_stack **a, char **argv);
void	prep_for_push(t_stack **list, t_stack *top_list, char list_name);
void	sa(t_stack **a, bool ft_printf);
void	sb(t_stack **b, bool ft_printf);
void	ss(t_stack **a, t_stack **b, bool ft_printf);

#endif
