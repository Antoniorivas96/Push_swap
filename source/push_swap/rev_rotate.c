/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:36:46 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/26 18:05:36 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rev_rotate(t_stack **list)
{
	t_stack	*last;

	if (!*list || !(*list)->next)
		return ;
	last = f_last_node(*list);
	last->prev->next = NULL;
	last->next = *list;
	last->prev = NULL;
	*list = last;
	last->next->prev = last;
}

void	rra(t_stack **a, bool printf)
{
	rev_rotate(a);
	if (!printf)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool printf)
{
	rev_rotate(b);
	if (!printf)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool printf)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!printf)
		ft_printf("rrr\n");
}
