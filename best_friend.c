/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_friend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:30:14 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 10:47:13 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * For each node in stack B, find its "best friend" in stack A,
 * i.e., the node in A after which this B node should be inserted for sort order.
 * Sets the .target field of each node in B.
 */
void assign_best_friends(t_stack *st)
{
    t_node *b_curr = st->b;
    while (b_curr)
    {
        t_node *a_curr = st->a;
        t_node *best = NULL;
        int min_diff = INT_MAX;

        // Find the node in A with the smallest value greater than b_curr->value
        while (a_curr)
        {
            int diff = a_curr->value - b_curr->value;
            if (diff > 0 && diff < min_diff)
            {
                min_diff = diff;
                best = a_curr;
            }
            a_curr = a_curr->next;
        }

        // If no such node (B value is greater than all in A), pick the smallest in A
        if (!best)
        {
            a_curr = st->a;
            best = a_curr;
            while (a_curr)
            {
                if (a_curr->value < best->value)
                    best = a_curr;
                a_curr = a_curr->next;
            }
        }

        b_curr->target = best;
        b_curr = b_curr->next;
    }
}

/* Helper: returns number of rotations to bring 'node' to top of stack */
static int rotations_to_top(t_node *head, t_node *node) {
    int rot = 0;
    while (head && head != node) {
        rot++;
        head = head->next;
    }
    return rot;
}

/* Assign costs for each node in B (rotations needed in A and B) */
static void assign_costs(t_stack *st) {
    t_node *b = st->b;
    int b_size = st->b_size;
    int a_size = st->a_size;

    while (b) {
        // Cost to bring B node to top of B
        int b_rot = rotations_to_top(st->b, b);
        if (b_rot > b_size / 2)
            b->cost = b_size - b_rot;
        else
            b->cost = b_rot;

        // Cost to bring its best friend to top of A
        int a_rot = rotations_to_top(st->a, b->target);
        if (a_rot > a_size / 2)
            b->cost += a_size - a_rot;
        else
            b->cost += a_rot;

        b = b->next;
    }
}

/* Returns pointer to cheapest node in B (lowest cost) */
static t_node *find_cheapest(t_stack *st) {
    t_node *b = st->b, *cheapest = b;
    int min_cost = b ? b->cost : 0x7fffffff;
    while (b) {
        if (b->cost < min_cost) {
            min_cost = b->cost;
            cheapest = b;
        }
        b = b->next;
    }
    return cheapest;
}

/* Rotate A until 'target' is at top */
static void rotate_a_to_target(t_stack *st, t_node *target) {
    int pos = rotations_to_top(st->a, target);
    if (pos <= st->a_size / 2) {
        while (st->a != target) ra(st);
    } else {
        while (st->a != target) rra(st);
    }
}

/* Rotate B until 'node' is at top */
static void rotate_b_to_top(t_stack *st, t_node *node) {
    int pos = rotations_to_top(st->b, node);
    if (pos <= st->b_size / 2) {
        while (st->b != node) rb(st);
    } else {
        while (st->b != node) rrb(st);
    }
}

/* Main sorting routine for >5 elements */
void sort_bff(t_stack *st) {
    int pushed = 0;

    // Push all except 3 elements to B
    while (st->a_size > 3) {
        pb(st);
        pushed++;
    }

    // Sort remaining 3 in A
    sort_three(st);

    // Process B
    while (st->b_size > 0) {
        assign_best_friends(st);
        assign_costs(st);
        t_node *cheapest = find_cheapest(st);
        rotate_b_to_top(st, cheapest);
        rotate_a_to_target(st, cheapest->target);
        pa(st);
    }

    // Final rotate A so that smallest value is at top
    t_node *min = st->a, *cur = st->a;
    while (cur) {
        if (cur->value < min->value)
            min = cur;
        cur = cur->next;
    }
    int min_pos = rotations_to_top(st->a, min);
    if (min_pos <= st->a_size / 2) {
        while (st->a != min) ra(st);
    } else {
        while (st->a != min) rra(st);
    }
}
