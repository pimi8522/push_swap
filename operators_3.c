/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:42:03 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 14:42:30 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrb(t_stack *st)
{
    t_node *n = pop_b_bot(st);
    if (!n) return;
    push_b_top(st, n);
    write(1, "rrb\n", 4);
}

void rrr(t_stack *st)
{
    rra(st);
    rrb(st);
    write(1, "rrr\n", 4);
}
