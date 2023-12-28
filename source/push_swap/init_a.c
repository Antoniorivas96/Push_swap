/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:35:36 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/26 17:53:48 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	current_index(t_stack *list)
{
	int	cont;
	int	mid;

	cont = 0;
	if (!list)
		return ;
	mid = list_len(list) / 2;
	while (list)
	{
		list->pos = cont;
		if (cont <= mid)
			list->above_median = true;
		else
			list->above_median = false;
		list = list->next;
		cont++;
	}
}

static void	target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_b;
	long	index_best_target;

	while (a)
	{
		index_best_target = LONG_MIN;
		current_b = b;
		while (current_b)
		{	
			if (current_b->number < a->number
				&& current_b->number > index_best_target)
			{
				index_best_target = current_b->number;
				target_b = current_b;
			}
			current_b = current_b->next;
		}
		if (index_best_target == LONG_MIN)
			a->target_node = max_number(b);
		else
			a->target_node = target_b;
		a = a->next;
	}
}

static void	cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = list_len(a);
	len_b = list_len(b);
	while (a)
	{
		a->push_cost = a->pos;
		if (!(a->above_median))
			a->push_cost = len_a -(a->pos);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->pos;
		else
			a->push_cost += len_b - (a->target_node->pos);
		a = a->next;
	}
}

void	easy_node(t_stack *list)
{
	long	cheapest;
	t_stack	*cheapest_node;

	if (!list)
		return ;
	cheapest = LONG_MAX;
	while (list)
	{
		if (list->push_cost < cheapest)
		{
			cheapest = list->push_cost;
			cheapest_node = list;
		}
		list = list->next;
	}
	cheapest_node->cheapest = true;
}

void	start_node_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	target_a(a, b);
	cost_a(a, b);
	easy_node(a);
}
