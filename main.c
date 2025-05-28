/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miduarte <miduarte@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:45:55 by miduarte          #+#    #+#             */
/*   Updated: 2025/05/28 10:50:52 by miduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node *stack_a; // A pointer to the top of stack A. Initially empty to avoid undefined behaviour.
    t_node *stack_b; // A pointer to the top of stack B. Initially empty.
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || argv[1])
		push_swap(argv[1]);
	else
		return (1);

    return (0);
}