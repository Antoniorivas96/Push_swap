/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:36:59 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/29 13:38:52 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	number_to_node(t_stack **set_list, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!set_list)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->number = n;
	if (!(*set_list))
	{
		*set_list = node;
		node->prev = NULL;
	}
	else
	{
		last_node = f_last_node(*set_list);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	start_stack_a(t_stack **a, char **argv)
{
	long	value;
	int		cont;

	cont = 0;
	while (argv[cont])
	{
		if (syntax_error(argv[cont]))
			free_error(a);
		value = ft_atoi(argv[cont]);
		if (cont > INT_MAX || cont < INT_MIN)
			free_error(a);
		if (duplicate(*a, (int)value))
			free_error(a);
		number_to_node(a, (int)value);
		cont++;
	}
}

t_stack	*cheapest_node(t_stack *set_list)
{
	if (!set_list)
		return (NULL);
	while (set_list)
	{
		if (set_list->cheapest)
			return (set_list);
		set_list = set_list->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **list, t_stack *top_list, char list_name)
{
	while (*list != top_list)
	{
		if (list_name == 'a')
		{
			if (top_list->above_median)
				ra(list, false);
			else
				rra(list, false);
		}
		else if (list_name == 'b')
		{
			if (top_list->above_median)
				rb(list, false);
			else
				rrb(list, false);
		}
	}
}
