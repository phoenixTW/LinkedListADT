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
	free(node);
}

void test_create_node_should_create_a_node_for_a_float_type_data () {
	Node_ptr node;
	float data = 2.1;
	node = create_node(&data);
	assertEqual(*((float*)(node->data)), data);
	assertEqual(node->next, 0x0);
	free(node);
}

void test_create_node_should_create_a_node_for_a_char_type_data () {
	Node_ptr node;
	char data = 'A';
	node = create_node(&data);
	assertEqual(*((char*)(node->data)), data);
	assertEqual(node->next, 0x0);
	free(node);
}

void test_add_to_list_should_add_a_node_into_a_linkedList_with_a_int_type_data () {
	int data = 2;
	LinkedList list = createList();
	Node_ptr node = create_node(&data);

	assertEqual(add_to_list(&list, node), 1);
	assertEqual(list.head, node);
	assertEqual(list.tail, node);
	assertEqual(node->next, 0x0);

	free(node);
}

void test_add_to_list_should_add_two_nodes_into_a_linkedList_with_a_int_type_data () {
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2);

	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);
	assertEqual(list.head, node1);
	assertEqual(list.tail, node2);
	assertEqual(node1->next, node2);

	free(node1);
	free(node2);
}

void test_get_first_element_should_return_the_first_element_of_the_list () {
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);


	assertEqual(*(int*)get_first_element(list), data1);
	free(node1);
	free(node2);
}