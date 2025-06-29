/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:39:23 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 15:12:13 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/* ============================================================================
 * Structures
 * ============================================================================
 */

/* Node in stack (doubly linked list) */
typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	bool			above_median;
	bool			is_cheapest;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
}					t_node;

/* Global stack state */
typedef struct s_stack
{
	int				a_size;
	int				b_size;
	int				a_median;
	bool			cheap_is_above_median;
	bool			cheap_bf_is_above_median;
	t_node			*highest_nb;
	t_node			*lowest_nb;
	t_node			*a;/* top of stack A */
	t_node			*b;/* top of stack B */
}					t_stack;

/* ============================================================================
 * struct_utils.c
 * ============================================================================
 */
t_stack				*init_stacks(void);
void				free_stacks(t_stack *st);

t_node				*node_new(int value);

/* Raw list ops on A */
void				push_a_top(t_stack *st, t_node *n);
t_node				*pop_a_top(t_stack *st);
void				push_a_bot(t_stack *st, t_node *n);
t_node				*pop_a_bot(t_stack *st);

/* Raw list ops on B */
void				push_b_top(t_stack *st, t_node *n);
t_node				*pop_b_top(t_stack *st);
void				push_b_bot(t_stack *st, t_node *n);
t_node				*pop_b_bot(t_stack *st);

/* ============================================================================
 * operators.c
 * ============================================================================
 */
void				sa(t_stack *st);
void				sb(t_stack *st);
void				ss(t_stack *st);
void				pa(t_stack *st);
void				pb(t_stack *st);
void				ra(t_stack *st);
void				rb(t_stack *st);
void				rr(t_stack *st);
void				rra(t_stack *st);
void				rrb(t_stack *st);
void				rrr(t_stack *st);

/* ============================================================================
 * radix_sort.c
 * ============================================================================
 */
void				sort_radix(t_stack *st);

/* ============================================================================
 * parsing.c
 * ============================================================================
 */
bool				parse_args(int argc, char **argv, t_stack *st);
void				assign_indexes(t_stack *st);
bool				is_number(const char *s);
bool				exists_in_stack(t_stack *st, int value);

/* ============================================================================
 * small_sorts.c
 * ============================================================================
 */

void				sort_two(t_stack *st);
void				sort_three(t_stack *st);
int					find_min_position(t_node *a);
void				sort_four(t_stack *st);
void				sort_five(t_stack *st);

#endif