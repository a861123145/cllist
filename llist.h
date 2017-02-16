#ifndef LLIST_H
#define LLIST_H

typedef void node_proc_fun_t(void*);
typedef int node_comp_fun_t(const void*, const void*);

typedef void LLIST_T;

LLIST_T *llist_new(int elmsize);
int llist_delete(LLIST_T *ptr);

int llist_node_append(LLIST_T *ptr, const void *datap);
int llist_node_prepend(LLIST_T *ptr, const void *datap);

int llist_travel(LLIST_T *ptr, node_proc_fun_t *comp);

void llist_node_delete(LLIST_T *ptr, node_comp_fun_t *comp, const void *key);
void *llist_node_find(LLIST_T *ptr, node_comp_fun_t *comp, const void *key);

#endif
