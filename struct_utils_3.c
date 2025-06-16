/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:37:11 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 15:18:04 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_b_bot(t_stack *st)
{
	t_node	*t;
	t_node	*p;

	t = st->b;
	if (!t)
		return (NULL);
	while (t->next)
		t = t->next;
	p = t->prev;
	if (p)
		p->next = NULL;
	else
		st->b = NULL;
	st->b_size--;
	t->prev = NULL;
	return (t);
}
