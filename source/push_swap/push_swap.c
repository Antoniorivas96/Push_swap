/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrivas- <anrivas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:36:27 by anrivas-          #+#    #+#             */
/*   Updated: 2023/12/27 13:36:32 by anrivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	start_stack_a(&a, argv + 1);
	if (!list_sorted(a))
	{
		if (list_len(a) == 2)
		{
			sa(&a, false);
		}
		else if (list_len(a) == 3)
			sort_three(&a);
		else
			sort_more_three(&a, &b);
	}
	error(&a);
	return (0);
}
