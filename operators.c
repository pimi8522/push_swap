/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:37:25 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 15:07:09 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_two(t_node **head)
{
	t_node	*n1;
	t_node	*n2;

	if (!head || !*head || !(*head)->next)
		return ;
	n1 = *head;
	n2 = n1->next;
	n1->next = n2->next;
	if (n2->next)
		n2->next->prev = n1;
	n2->prev = NULL;
	n2->next = n1;
	n1->prev = n2;
	*head = n2;
}

void	sa(t_stack *st)
{
	swap_two(&st->a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *st)
{
	swap_two(&st->b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *st)
{
	swap_two(&st->a);
	swap_two(&st->b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *st)
{
	t_node	*n;

	n = pop_b_top(st);
	if (!n)
		return ;
	push_a_top(st, n);
	write(1, "pa\n", 3);
}
