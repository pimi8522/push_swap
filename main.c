/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:45:55 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/02 12:35:37 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *st;

    /* nothing to do if no numbers passed */
    if (argc < 2)
        return (0);
		
    st = init_stack();
    if (!st)
        return (1);

    /* parse + validate; on error prints "Error\n" and returns false */
    if (!parse_args(argc, argv, st))
    {
        free_stack(st);
        return (1);
    }

    /* assign ranks and run best-friend sort */
    assign_indexes(st);
	//sort
	//depending on number of tings run small sorts

    free_state(st);
    return (0);
}

/*
In the design sketched, the single t_stack *st you see in main() isn’t just “stack A” or “stack B” – it’s the entire program state. In my version, t_stack contains inside it:

    t_node *a; → head (top) of stack A
    t_node *b; → head (top) of stack B
    int a_size, b_size; → sizes of each
    plus any other book-keeping (medians, cost flags, etc.)

Because that one struct holds both stacks (and all their metadata), you only ever need to:

t_stack *st = init_state();

rather than separately doing

t_stack *a = init_stack();
t_stack *b = init_stack();

It keeps all of your state in one place, makes it easy to pass around (every function just takes a single t_stack *st), and still avoids any true global variables. If you preferred, you could certainly split them into two independent t_stack objects (a and b), but then you’d also need a third struct to hold your medians, cheapest-node flags, etc., and you’d have to pass three pointers around instead of one. This combined-state pattern is just one way to keep your code a bit more centralized.*/
