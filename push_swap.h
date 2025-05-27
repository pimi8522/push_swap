/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:39:23 by miduarte          #+#    #+#             */
/*   Updated: 2025/05/27 11:01:52 by miduarte         ###   ########.fr       */
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
 * A node in the stack
 */
typedef struct s_node
{
    int             value;
	int				index;
	int				cost;
	bool			above_median;
	bool			is_cheapest;
    struct s_node  *prev;
    struct s_node  *next;
	struct s_node  *target;
}               t_node;

/*
 * A stack with quick access to top, bottom, and its size
 */
typedef struct s_stack
{
    t_node  *top;
    t_node  *bot;
    int      size;
}               t_stack;


#endif