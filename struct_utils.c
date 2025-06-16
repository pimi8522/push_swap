/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:38:13 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 14:38:14 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stacks(void)
{
    t_stack *st = malloc(sizeof(*st));
    if (!st)
        return NULL;
    st->a_size = 0;
    st->b_size = 0;
    st->a_median = 0;
    st->cheap_is_above_median = false;
    st->cheap_bf_is_above_median = false;
    st->highest_nb = NULL;
    st->lowest_nb = NULL;
    st->a = NULL;
    st->b = NULL;
    return st;
}

void free_stacks(t_stack *st)
{
    t_node *curr;
    t_node *tmp;
    if (!st)
        return;

    curr = st->a;
    while (curr)
    {
        tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    curr = st->b;
    while (curr)
    {
        tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    free(st);
}

t_node *node_new(int value)
{
    t_node *n = malloc(sizeof(*n));
    if (!n)
        return NULL;
    n->value = value;
    n->index = 0;
    n->index = -1;
    n->cost = 0;
    n->above_median = false;
    n->is_cheapest = false;
    n->prev = NULL;
    n->next = NULL;
    n->target = NULL;
    return n;
}

void push_a_top(t_stack *st, t_node *n)
{
    if (!st || !n)
        return;
    if (st->a_size++ == 0)
        st->a = st->lowest_nb = n;
    else
    {
        n->next = st->a;
        st->a->prev = n;
        st->a = n;
    }
}

t_node *pop_a_top(t_stack *st)
{
    t_node *n;
    if (!st || st->a_size < 1)
        return NULL;
    n = st->a;
    st->a = n->next;
    if (st->a)
        st->a->prev = NULL;
    st->a_size--;
    n->next = NULL;
    return n;
}

