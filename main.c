/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:45:55 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 14:45:46 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_small(t_stack *st, int size)
{
    if (size == 2)
        sort_two(st);
    else if (size == 3)
        sort_three(st);
    else if (size == 4)
        sort_four(st);
    else if (size == 5)
        sort_five(st);
}

int main(int argc, char **argv)
{
    t_stack *st;
	int size;

    if (argc < 2)
        return (0);
    st = init_stacks();
    if (!st)
        return (1);
    if (!parse_args(argc, argv, st))
    {
        free_stacks(st);
        return (1);
    }
    assign_indexes(st);
	size = st->a_size;
    if (size <= 2)
        sort_small(st, size);
    else if (size > 5)
        sort_radix(st);
    free_stacks(st);
    return (0);
}

