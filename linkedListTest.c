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

void test_get_last_element_should_return_the_last_element_of_the_list () {
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);

	assertEqual(*(int*)get_last_element(list), data2);
	free(node1);
	free(node2);
}

void test_getElementAt_should_return_2_for_index_value_of_0 () {
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);

	assertEqual(*(int*)getElementAt(list, 0), data1);	
}

void test_getElementAt_should_return_4_for_index_value_of_1 () {
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);

	assertEqual(*(int*)getElementAt(list, 1), data2);	
}

void test_getElementAt_should_return_NULL_for_index_value_of_2 () {
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);

	assertEqual(getElementAt(list, 2), 0x0);	
}

// int indexOf(LinkedList, void *)

void test_indexOf_should_return_1_for_value_2 () {
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);

	assertEqual(indexOf(list, &data1), 0);
}

void test_indexOf_should_return_minus_of_1_for_value_6 () {
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);

	assertEqual(indexOf(list, &data3), -1);
}