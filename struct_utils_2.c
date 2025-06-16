/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:34:47 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 15:15:31 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_bot(t_stack *st, t_node *n)
{
	t_node	*tail;

	tail = st->a;
	if (!st || !n)
		return ;
	if (st->a_size++ == 0)
	{
		st->a = n;
	}
	else
	{
		while (tail->next)
			tail = tail->next;
		tail->next = n;
		n->prev = tail;
	}
}

t_node	*pop_a_bot(t_stack *st)
{
	t_node	*tail;
	t_node	*prev;

	if (!st || st->a_size < 1)
		return (NULL);
	tail = st->a;
	while (tail->next)
		tail = tail->next;
	prev = tail->prev;
	if (prev)
		prev->next = NULL;
	else
		st->a = NULL;
	st->a_size--;
	tail->prev = NULL;
	return (tail);
}

void	push_b_top(t_stack *st, t_node *n)
{
	if (st->b_size++ == 0)
		st->b = n;
	else
	{
		n->next = st->b;
		st->b->prev = n;
		st->b = n;
	}
}

t_node	*pop_b_top(t_stack *st)
{
	t_node	*n;

	n = st->b;
	if (!n)
		return (NULL);
	st->b = n->next;
	if (st->b)
		st->b->prev = NULL;
	n->next = NULL;
	st->b_size--;
	return (n);
}

void	push_b_bot(t_stack *st, t_node *n)
{
	t_node	*t;

	t = st->b;
	if (st->b_size++ == 0)
		st->b = n;
	else
	{
		while (t->next)
			t = t->next;
		t->next = n;
		n->prev = t;
	}
}
