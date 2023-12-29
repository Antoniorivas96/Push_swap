/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    min_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:32:23 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/29 13:34:30 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	min_on_top(t_stack **a)
{
	while ((*a)->number != min_number(*a)->number)
	{
		if (min_number(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
