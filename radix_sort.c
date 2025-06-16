/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:46:17 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 14:09:50 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  get_max_bits(t_stack *st)
{
    int     max_index;
    int     bits;
    t_node  *cur;

    cur = st->a;
    max_index = cur->index;
    while (cur)
    {
        if (cur->index > max_index)
            max_index = cur->index;
        cur = cur->next;
    }
    bits = 0;
    while ((max_index >> bits) != 0)
        bits++;
    return (bits);
}

void    sort_radix(t_stack *st)
{
    int i;
    int j;
    int size;
    int max_bits;

    size = st->a_size;
    max_bits = get_max_bits(st);
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j++ < size)
        {
            if (((st->a->index >> i) & 1) == 0)
                pb(st);
            else
                ra(st);
        }
        while (st->b_size > 0)
            pa(st);
        i++;
    }
}
