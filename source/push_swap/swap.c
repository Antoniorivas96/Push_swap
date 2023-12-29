/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:37:12 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/29 13:36:26 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_stack **top)
{
	if (!*top || !(*top)->next)
		return ;
	*top = (*top)->next;
	(*top)->prev->prev = *top;
	(*top)->prev->next = (*top)->next;
	if ((*top)->next)
		(*top)->next->prev = (*top)->prev;
	(*top)->next = (*top)->prev;
	(*top)->prev = NULL;
}

void	sa(t_stack **a, bool printf)
{
	swap(a);
	if (!printf)
		ft_printf("sa\n");
}

void	sb(t_stack **b, bool printf)
{
	swap(b);
	if (!printf)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool printf)
{
	swap(a);
	swap(b);
	if (!printf)
		ft_printf("ss\n");
}
