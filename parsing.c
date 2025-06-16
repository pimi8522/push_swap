/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:45:08 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 14:58:09 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool gauntlet(const char *s, t_stack *st)
{
    long  tmp;

    if (!is_number(s))
        return (write(2, "Error\n", 6), false);
    tmp = ft_atoi(s);
    if (tmp > INT_MAX || tmp < INT_MIN)
        return (write(2, "Error\n", 6), false);
    if (exists_in_stack(st, (int)tmp))
        return (write(2, "Error\n", 6), false);
    return (true);
}

bool parse_args(int argc, char **argv, t_stack *st)
{
    int     i;
    long    tmp;
    t_node *n;

    if (argc < 2)
        return (false);
    i = 1;
    while (i < argc)
    {
        if (!gauntlet(argv[i], st))
            return (false);
        tmp = ft_atoi(argv[i]);
        n = node_new((int)tmp);
        if (!n)
            return (write(2, "Error\n", 6), false);
        push_a_bot(st, n);
        i++;
    }
    return (true);
}