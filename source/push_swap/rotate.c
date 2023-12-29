/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:36:53 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/26 18:06:10 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_stack **list)
{
	t_stack	*last;

	if (!list || !(*list)->next)
		return ;
	last = f_last_node(*list);
	last->next = *list;
	*list = (*list)->next;
	(*list)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack **a, bool printf)
{
	rotate(a);
	if (!printf)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool printf)
{
	rotate(b);
	if (!printf)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool printf)
{
	rotate(a);
	rotate(b);
	if (!printf)
		ft_printf("rr\n");
}
