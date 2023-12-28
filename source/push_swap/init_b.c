/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:35:48 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/26 17:53:48 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_a;
	long	index_best_target;

	while (b)
	{
		index_best_target = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number
				&& current_a->number < index_best_target)
			{
				index_best_target = current_a->number;
				target_a = current_a;
			}
			current_a = current_a->next;
		}
		if (index_best_target == LONG_MAX)
			b->target_node = min_number(a);
		else
			b->target_node = target_a;
		b = b->next;
	}
}

void	start_node_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	target_b(a, b);
}
