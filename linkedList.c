#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList createList (void) {
	LinkedList list = {NULL, NULL, 0};
	return list;
}

Node_ptr create_node(void *data) {
	Node_ptr node;
	node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	return node;
}