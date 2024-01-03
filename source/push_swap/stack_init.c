/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:36:59 by anrivas-          #+#    #+#             */
/*   Updated: 2024/01/02 20:49:20 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

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
		value = ft_atol(argv[cont]);
		if (value > INT_MAX || value < INT_MIN)
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
