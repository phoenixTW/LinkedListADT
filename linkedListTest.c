#include "expr_assert.h"
#include "linkedList.h"

void test_create_a_linkedList_which_will_contains_head_and_tail () {
	LinkedList list;
	list = createList();

	assertEqual(list.head, 0x0);
	assertEqual(list.tail, 0x0);
	assertEqual(list.count, 0);
}

void test_create_node_should_create_a_node_for_a_int_type_data () {
	Node_ptr node;
	int data = 2;
	node = create_node(&data);
	assertEqual(*((int*)(node->data)), data);
	assertEqual(node->next, 0x0);
}

void test_create_node_should_create_a_node_for_a_float_type_data () {
	Node_ptr node;
	float data = 2.1;
	node = create_node(&data);
	assertEqual(*((float*)(node->data)), data);
	assertEqual(node->next, 0x0);
}

void test_create_node_should_create_a_node_for_a_char_type_data () {
	Node_ptr node;
	char data = 'A';
	node = create_node(&data);
	assertEqual(*((char*)(node->data)), data);
	assertEqual(node->next, 0x0);
}
