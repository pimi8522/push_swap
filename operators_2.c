/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:40:44 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 14:42:25 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *st)
{
	t_node	*n;

	n = pop_a_top(st);
	if (!n)
		return ;
	push_b_top(st, n);
	write(1, "pb\n", 3);
}

void	ra(t_stack *st)
{
	t_node	*n;

	n = pop_a_top(st);
	if (!n)
		return ;
	push_a_bot(st, n);
	write(1, "ra\n", 3);
}

void	rb(t_stack *st)
{
	t_node	*n;

	n = pop_b_top(st);
	if (!n)
		return ;
	push_b_bot(st, n);
	write(1, "rb\n", 3);
}

void	rr(t_stack *st)
{
	ra(st);
	rb(st);
	write(1, "rr\n", 3);
}

void	rra(t_stack *st)
{
	t_node	*n;

	n = pop_a_bot(st);
	if (!n)
		return ;
	push_a_top(st, n);
	write(1, "rra\n", 4);
}
