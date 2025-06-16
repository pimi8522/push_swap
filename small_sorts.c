/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:14:59 by miduarte          #+#    #+#             */
/*   Updated: 2025/06/16 14:37:49 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_stack *st)
{
    if (st->a && st->a->next && st->a->value > st->a->next->value)
        sa(st);
}

void sort_three(t_stack *st)
{
    int a = st->a->value;
    int b = st->a->next->value;
    int c = st->a->next->next->value;

    if (a < b && b < c)
        return;
    else if (a > b && b < c && a < c)
        sa(st);
    else if (a > b && b > c)
    {
        sa(st);
        rra(st);
    }
    else if (a > b && b < c && a > c)
        ra(st);
    else if (a < b && b > c && a < c)
    {
        sa(st);
        ra(st);
    }
    else if (a < b && b > c && a > c)
        rra(st);
}

int find_min_position(t_node *a)
{
    int pos = 0;
	int min_pos = 0;
    int min = a->value;
    t_node *tmp = a;

    while (tmp)
    {
        if (tmp->value < min)
        {
            min = tmp->value;
            min_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    return min_pos;
}

void sort_four(t_stack *st)
{
    int min_pos = find_min_position(st->a);

    while (min_pos > 0)
    {
        ra(st);
        min_pos--;
    }
    pb(st);          
    sort_three(st);    
    pa(st);      
}

void sort_five(t_stack *st)
{
    int min_pos;
	int i = 0;
	
    while (i < 2)
    {
        min_pos = find_min_position(st->a);
        while (min_pos > 0)
        {
            ra(st);
            min_pos--;
        }
        pb(st);
		i++;
    }
    sort_three(st);
    pa(st); 
    pa(st);
}
