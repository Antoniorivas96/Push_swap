/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:36:06 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/26 17:53:48 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack **top)
{
	t_stack	*biggest;

	biggest = max_number(*top);
	if (biggest == *top)
		ra(top, false);
	else if ((*top)->next == biggest)
		rra(top, false);
	if ((*top)->number > (*top)->next->number)
		sa(top, false);
}
