/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:39:23 by miduarte          #+#    #+#             */
/*   Updated: 2025/05/23 15:38:10 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				value;  // The actual integer value
	int				index;  // The node's final, sorted position (more on this later)
	struct s_node	*prev;  // Pointer to the previous node in the stack
	struct s_node	*next;  // Pointer to the next node in the stack
}	t_node;

#endif