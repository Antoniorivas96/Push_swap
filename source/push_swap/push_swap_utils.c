/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:36:15 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/26 18:36:17 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	list_len(t_stack *set_list)
{
	int	cont;

	if (!set_list)
		return (0);
	cont = 0;
	while (set_list)
	{
		set_list = set_list->next;
		cont++;
	}
	return (cont);
}

t_stack	*f_last_node(t_stack *set_list)
{
	if (!set_list)
		return (NULL);
	while (set_list->next)
		set_list = set_list->next;
	return (set_list);
}

bool	list_sorted(t_stack *set_list)
{
	if (!set_list)
		return (1);
	while (set_list->next)
	{
		if (set_list->number > set_list->next->number)
			return (false);
		set_list = set_list->next;
	}
	return (true);
}

t_stack	*min_number(t_stack *list)
{
	long	min;
	t_stack	*min_numbered;

	if (!list)
		return (NULL);
	min = LONG_MAX;
	while (list)
	{
		if (list->number < min)
		{
			min = list->number;
			min_numbered = list;
		}
		list = list->next;
	}
	return (min_numbered);
}

t_stack	*max_number(t_stack *list)
{
	long	max;
	t_stack	*max_nbr;

	if (!list)
		return (NULL);
	max = LONG_MIN;
	while (list)
	{
		if (list->number > max)
		{
			max = list->number;
			max_nbr = list;
		}
		list = list->next;
	}
	return (max_nbr);
}
