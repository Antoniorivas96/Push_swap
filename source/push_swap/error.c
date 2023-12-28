/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:35:27 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/26 18:02:53 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	syntax_error(char *n_post)
{
	if (!(*n_post == '+' || *n_post == '-'
			|| (*n_post >= '0' && *n_post <= '9')))
		return (1);
	else if (*n_post == '+' || (*n_post == '-'
			&& !(n_post[1] >= '0' && n_post[1] <= '9')))
		return (1);
	while (*++n_post)
	{
		if (!(*n_post >= '0' && *n_post <= '9'))
			return (1);
	}
	return (0);
}

int	duplicate(t_stack *a, int n_search)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->number == n_search)
			return (1);
		a = a->next;
	}
	return (0);
}

void	error(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*present;

	if (!a)
		return ;	
	present = *a;
	while (present)
	{
		tmp = present->next;
		present->number = 0;
		free(present);
		present = tmp;
	}
	*a = NULL;
}

void	free_error(t_stack **a)
{
	error(a);
	ft_printf("Error\n");
	exit(1);
}
