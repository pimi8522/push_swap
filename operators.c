/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:37:25 by miduarte          #+#    #+#             */
/*   Updated: 2025/05/28 11:25:29 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/* generic swap: exchange first two nodes at head=(list pointer) */
static void swap_two(t_node **head)
{
    t_node *n1, *n2;
    if (!head || !*head || !(*head)->next) return;
    n1 = *head;
    n2 = n1->next;
    /* detach n1,n2 */
    n1->next = n2->next;
    if (n2->next) n2->next->prev = n1;
    n2->prev = NULL;
    n2->next = n1;
    n1->prev = n2;
    *head = n2;
}

/* sa: swap A */
void sa(t_stack *st)
{
    swap_two(&st->a);
    write(1, "sa\n", 3);
}

/* sb: swap B */
void sb(t_stack *st)
{
    swap_two(&st->b);
    write(1, "sb\n", 3);
}

/* ss: sa & sb */
void ss(t_stack *st)
{
    swap_two(&st->a);
    swap_two(&st->b);
    write(1, "ss\n", 3);
}

/* pa: pop B → push A */
void pa(t_stack *st)
{
    t_node *n = pop_b_top(st);
    if (!n) return;
    push_a_top(st, n);
    write(1, "pa\n", 3);
}

/* pb: pop A → push B */
void pb(t_stack *st)
{
    t_node *n = pop_a_top(st);
    if (!n) return;
    push_b_top(st, n);
    write(1, "pb\n", 3);
}

/* ra: rotate A (top→bot) */
void ra(t_stack *st)
{
    t_node *n = pop_a_top(st);
    if (!n) return;
    push_a_bot(st, n);
    write(1, "ra\n", 3);
}

/* rb: rotate B */
void rb(t_stack *st)
{
    t_node *n = pop_b_top(st);
    if (!n) return;
    push_b_bot(st, n);
    write(1, "rb\n", 3);
}

/* rr: ra & rb */
void rr(t_stack *st)
{
    ra(st);
    rb(st);
    write(1, "rr\n", 3);
}

/* rra: reverse rotate A (bot→top) */
void rra(t_stack *st)
{
    t_node *n = pop_a_bot(st);
    if (!n) return;
    push_a_top(st, n);
    write(1, "rra\n", 4);
}

/* rrb: reverse rotate B */
void rrb(t_stack *st)
{
    t_node *n = pop_b_bot(st);
    if (!n) return;
    push_b_top(st, n);
    write(1, "rrb\n", 4);
}

/* rrr: rra & rrb */
void rrr(t_stack *st)
{
    rra(st);
    rrb(st);
    write(1, "rrr\n", 4);
}