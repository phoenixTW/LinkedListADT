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

int add_to_list(LinkedList *list, Node_ptr node) {
	if(list->head == NULL){
		list->head = node;
		list->tail = node;
		return 1;
	}

	list->tail->next = node;
	list->tail = node;

	return 1;
}