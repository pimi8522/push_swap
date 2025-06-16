/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:45:08 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 14:47:32 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void gauntlet(int argc, char **argv, t_stack *st)
{
    long tmp;
    int i;

    i = 1;
    if (!is_number(argv[i]))
    {
        write(2, "Error\n", 6);
        return (false);
    }
    tmp = ft_atoi(argv[i]);
    if (tmp > INT_MAX || tmp < INT_MIN)
    {
        write(2, "Error\n", 6);
        return (false);
    }
    if (exists_in_stack(st, (int)tmp))
    {
        write(2, "Error\n", 6);
        return (false);
    }
}

bool parse_args(int argc, char **argv, t_stack *st)
{
    int      i;
    long     tmp;
    t_node  *n;

    if (argc < 2)
        return (false);
    i = 1;
    while (i < argc)
    {
        gauntlet(argc, argv, st);
        n = node_new((int)tmp);
        if (!n)
        {
            write(2, "Error\n", 6);
            return (false);
        }
        push_a_bot(st, n);
        i++;
    }
    return (true);
}
