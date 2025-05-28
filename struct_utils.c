#include "push_swap.h"

/* Allocate and zero‐init your global state */
t_stack *init_stacks(void)
{
    t_stack *st = malloc(sizeof(*st));
    if (!st) return NULL;
    st->a_size = 0;
    st->b_size = 0;
    st->a_median = 0;
    st->cheap_is_above_median = false;
    st->cheap_bf_is_above_median = false;
    st->highest_nb = NULL;
    st->lowest_nb = NULL;
    st->a = NULL;
    st->b = NULL;
    return st;
}

/* Free all nodes in both stacks, then the struct itself */
void free_stacks(t_stack *st)
{
    t_node *curr, *tmp;
    if (!st) return;

    curr = st->a;
    while (curr)
    {
        tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    curr = st->b;
    while (curr)
    {
        tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    free(st);
}

/* Simple constructor for a single node */
t_node *node_new(int value)
{
    t_node *n = malloc(sizeof(*n));
    if (!n) return NULL;
    n->value = value;
    n->index = 0;
    n->cost = 0;
    n->above_median = false;
    n->is_cheapest = false;
    n->prev = NULL;
    n->next = NULL;
    n->target = NULL;
    return n;
}

/*–– Push/Pop at top/bottom of Stack A ––*/
void push_a_top(t_stack *st, t_node *n)
{
    if (!st || !n) return;
    if (st->a_size++ == 0)
        st->a = st->lowest_nb = n;
    else
    {
        n->next = st->a;
        st->a->prev = n;
        st->a = n;
    }
}

t_node *pop_a_top(t_stack *st)
{
    t_node *n;
    if (!st || st->a_size < 1) return NULL;
    n = st->a;
    st->a = n->next;
    if (st->a) st->a->prev = NULL;
    st->a_size--;
    n->next = NULL;
    return n;
}

void push_a_bot(t_stack *st, t_node *n)
{
    t_node *tail = st->a;
    if (!st || !n) return;
    if (st->a_size++ == 0)
    {
        st->a = n;
    }
    else
    {
        while (tail->next)
            tail = tail->next;
        tail->next = n;
        n->prev = tail;
    }
}

t_node *pop_a_bot(t_stack *st)
{
    t_node *tail, *prev;
    if (!st || st->a_size < 1) return NULL;
    tail = st->a;
    while (tail->next)
        tail = tail->next;
    prev = tail->prev;
    if (prev)
        prev->next = NULL;
    else
        st->a = NULL;
    st->a_size--;
    tail->prev = NULL;
    return tail;
}

/*–– Push/Pop at top/bottom of Stack B ––*/
void push_b_top(t_stack *st, t_node *n) { if (st->b_size++ == 0) st->b = n; else { n->next = st->b; st->b->prev = n; st->b = n; } }
t_node *pop_b_top(t_stack *st)       { t_node *n = st->b; if (!n) return NULL; st->b = n->next; if (st->b) st->b->prev = NULL; n->next = NULL; st->b_size--; return n; }
void push_b_bot(t_stack *st, t_node *n) { t_node *t = st->b; if (st->b_size++ == 0) st->b = n; else { while (t->next) t = t->next; t->next = n; n->prev = t; } }
t_node *pop_b_bot(t_stack *st)       { t_node *t = st->b, *p; if (!t) return NULL; while (t->next) t = t->next; p = t->prev; if (p) p->next = NULL; else st->b = NULL; st->b_size--; t->prev = NULL; return t; }