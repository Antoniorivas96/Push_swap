/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:35:57 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/26 18:44:41 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static	void rotate_two(t_stack **a, t_stack **b, t_stack *cheapest_nd)
{
	while (*b != cheapest_nd->target_node && *a != cheapest_nd)
	{
		rr(a, b, false);
		current_index(*a);
		current_index(*b);
	}	
}

static	void rev_rotate_two(t_stack **a, t_stack **b, t_stack *cheapest_nd)
{
	while (*b != cheapest_nd->target_node && *a != cheapest_nd)
	{
		rrr(a, b, false);
		current_index(*a);
		current_index(*b);
	}	
}
static void move_nbr_a_to_b(t_stack **a, t_stack **b)
{
	t_stack *cheapest_nd;
	
	cheapest_nd = cheapest_node(*a);
	if (cheapest_nd->above_median && cheapest_nd->target_node->above_median)
		rotate_two(a, b, cheapest_nd);
	else if (!(cheapest_nd->above_median) && !(cheapest_nd->target_node->above_median))
		rev_rotate_two(a, b, cheapest_nd);
	prep_for_push(a, cheapest_nd, 'a');	
	prep_for_push(b, cheapest_nd->target_node, 'b');
	pb(b, a, false);
}
static	void move_nbr_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a,(*b)->target_node, 'a');
	pa(a, b, false);
}
static	void	min_on_top(t_stack **a)
{
	while ((*a)->number != min_number(*a)->number)
	{
		if (min_number(*a)->above_median)
		ra(a, false);
		else
			rra(a, false);
	}
}
void	sort_more_three(t_stack **a, t_stack **b)
 {
	int len_a;
	
	len_a = list_len(*a);
	
	if (len_a-- > 3 && !list_sorted(*a))
	{
		pb(b, a, false);
	}
	if (len_a-- > 3 && !list_sorted(*a))
	{
		pb(b, a, false);
	}
	while (len_a-- > 3 && !list_sorted(*a))
	{
		start_node_a(*a, *b);
		move_nbr_a_to_b(a, b);
	}
	sort_three(a);
	while(*b)
	{
		start_node_b(*a, *b);
		move_nbr_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
