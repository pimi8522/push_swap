/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:45:08 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/02 14:33:40 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void assign_indexes(t_stack *st)
{
    t_node *current;
    t_node *min;
    int     i, min_val, assigned;

    for (i = 0; i < st->a_size; i++)
    {
        current = st->a;
        min = NULL;
        min_val = INT_MAX;
        // Find unindexed min node in stack A
        while (current)
        {
            if (current->index == -1 && current->value < min_val)
            {
                min_val = current->value;
                min = current;
            }
            current = current->next;
        }
        if (min)
            min->index = i;
    }
}

/* Check that s is an optional '+'/'-' then at least one digit */
static bool is_number(const char *s)
{
    if (*s == '+' || *s == '-')
        s++;
    if (!*s)
        return (false);
    while (*s)
    {
        if (!ft_isdigit(*s))
            return (false);
        s++;
    }
    return (true);
}

/* Scan stack A for existing value to detect duplicates */
static bool exists_in_stack(t_stack *st, int value)
{
    t_node *curr = st->a;
    while (curr)
    {
        if (curr->value == value)
            return (true);
        curr = curr->next;
    }
    return (false);
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
        n = node_new((int)tmp);
        if (!n)
        {
            write(2, "Error\n", 6);
            return (false);
        }
        /* first arg must be top, so we push to bottom in input order */
        push_a_bot(st, n);
        i++;
    }
    return (true);
}
/*
Explanation of the parsing steps:

    is_number
        Allows an optional leading + or -, then requires at least one digit.
        Rejects empty strings, pure signs, or any non‐digit chars.

    Range check
        Convert to long via ft_atoi.
        If outside [INT_MIN..INT_MAX], error.

    Duplicate check
        Walk the existing st->a linked list to ensure no repeated values.

    Building stack A
        Use node_new + push_a_bot so that argv[1] becomes the top and argv[argc-1] the bottom.

    Error handling
        On any invalid input, we immediately write "Error\n" to stderr (fd=2) and return failure.

*/