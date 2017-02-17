#include <stdio.h>
#include <string.h>
#include "llist.h"

struct tdata {
	int a;
	char name[32];
};

void print_data(void *datap)
{
	struct tdata *tdp = (struct tdata*)datap;
	printf("a = %d, name = %s\n", tdp->a, tdp->name);
}

int find_node(const void *datap, const void *key)
{
	struct tdata *tdp = (struct tdata*)datap;
	if (strcmp(tdp->name, key) == 0)
		return 0;
	else return -1;
}

int main(int argc, char *argv[])
{
	struct tdata t1;
	LLIST_T *list = llist_new(sizeof(struct tdata));
	t1.a = 1;
	strcpy(t1.name, "test1");
	llist_node_append(list, &t1);

	t1.a = 2;
	strcpy(t1.name, "test2");
	llist_node_prepend(list, &t1);
	llist_travel(list, print_data);

	struct tdata *t2 = llist_node_find(list, find_node, "test2");
	printf("found %s, value = %d\n", t2->name, t2->a);

	return 0;
}
