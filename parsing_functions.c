/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:20:01 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 15:10:21 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indexes(t_stack *st)
{
	t_node	*current;
	t_node	*min;
	int		i;
	int		min_val;

	i = 0;
	while (i < st->a_size)
	{
		current = st->a;
		min = NULL;
		min_val = INT_MAX;
		while (current)
		{
			if (current->index == -1 && current->value < min_val)
			{
				min_val = current->value;
				min = current;
			}
			current = current->next;
		}
		if (min)
			min->index = i;
		i++;
	}
}

bool	is_number(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (false);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}

bool	exists_in_stack(t_stack *st, int value)
{
	t_node	*curr;

	curr = st->a;
	while (curr)
	{
		if (curr->value == value)
			return (true);
		curr = curr->next;
	}
	return (false);
}
