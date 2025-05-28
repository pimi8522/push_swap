/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:39:23 by miduarte          #+#    #+#             */
/*   Updated: 2025/05/28 11:30:29 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"

/*
 * A node in either stack
 */
typedef struct s_node
{
    int             value;
    int             index;
    int             cost;
    bool            above_median;
    bool            is_cheapest;
    struct s_node  *prev;
    struct s_node  *next;
    struct s_node  *target;
}               t_node;

/*
 * Global state: sizes, medians, pointers to each stack top
 */
typedef struct s_stack
{
    int     a_size;
    int     b_size;
    int     a_median;
    bool    cheap_is_above_median;
    bool    cheap_bf_is_above_median;
    t_node *highest_nb;
    t_node *lowest_nb;
    t_node *a;    /* top of stack A */
    t_node *b;    /* top of stack B */
}               t_stack;

/*
 * struct_utils.c
 */
t_stack *init_stacks(void);
void     free_stacks(t_stack *st);

t_node  *node_new(int value);

/* raw list ops on A */
void     push_a_top(t_stack *st, t_node *n);
t_node  *pop_a_top(t_stack *st);
void     push_a_bot(t_stack *st, t_node *n);
t_node  *pop_a_bot(t_stack *st);

/* raw list ops on B */
void     push_b_top(t_stack *st, t_node *n);
t_node  *pop_b_top(t_stack *st);
void     push_b_bot(t_stack *st, t_node *n);
t_node  *pop_b_bot(t_stack *st);

/*
 * operators.c
 */
void sa(t_stack *st);
void sb(t_stack *st);
void ss(t_stack *st);
void pa(t_stack *st);
void pb(t_stack *st);
void ra(t_stack *st);
void rb(t_stack *st);
void rr(t_stack *st);
void rra(t_stack *st);
void rrb(t_stack *st);
void rrr(t_stack *st);

/*
 * best_friend.c (your existing routines)
 */

#endif