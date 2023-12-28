/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:36:35 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/26 18:05:05 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack **dest, t_stack **source)
{
	t_stack	*node_push;

	if (!*source)
		return ;
	node_push = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	node_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_push;
		node_push->next = NULL;
	}
	else
	{
		node_push->next = *dest;
		node_push->next->prev = node_push;
		*dest = node_push;
	}
}

void	pa(t_stack **a, t_stack **b, bool printf)
{
	push(a, b);
	if (!printf)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, bool printf)
{
	push(b, a);
	if (!printf)
		ft_printf("pb\n");
}
