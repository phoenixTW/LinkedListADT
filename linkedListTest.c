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
	free(node1);
	free(node2);
}

void test_getElementAt_should_return_4_for_index_value_of_1 () {
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);

	assertEqual(*(int*)getElementAt(list, 1), data2);	

	free(node1);
	free(node2);
}

void test_getElementAt_should_return_NULL_for_index_value_of_2 () {
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);

	assertEqual(getElementAt(list, 2), 0x0);	

	free(node1);
	free(node2);
}

void test_indexOf_should_return_1_for_value_2 () {
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);

	assertEqual(indexOf(list, &data1), 0);

	free(node1);
	free(node2);
}

void test_indexOf_should_return_minus_of_1_for_value_6 () {
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);

	assertEqual(indexOf(list, &data3), -1);

	free(node1);
	free(node2);
}

// void * deleteElementAt(LinkedList, int)

void test_deleteElementAt_should_return_4_from_a_list_and_delete_that_node () {
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2), node3 = create_node(&data3);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);
	assertEqual(add_to_list(&list, node3), 1);

	assertEqual(*(int*)deleteElementAt(&list, 1), data2);
	assertEqual(list.count, 2);

	free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementAt_should_return_NULL_when_index_is_3 () {
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2), node3 = create_node(&data3);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);
	assertEqual(add_to_list(&list, node3), 1);

	assertEqual(deleteElementAt(&list, 3), 0x0);

	free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementAt_should_return_2_when_index_is_0 () {
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2), node3 = create_node(&data3);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);
	assertEqual(add_to_list(&list, node3), 1);

	assertEqual(*(int*)deleteElementAt(&list, 0), data1);
	assertEqual(list.head, node2);

	free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementAt_should_return_6_when_index_is_2 () {
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2), node3 = create_node(&data3);
	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);
	assertEqual(add_to_list(&list, node3), 1);

	assertEqual(*(int*)deleteElementAt(&list, 2), data3);
	assertEqual(list.tail, node2);

	free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementAt_should_return_2_when_index_is_0_when_there_is_1_element_in_the_list () {
	int data = 2;
	LinkedList list = createList();
	Node_ptr node = create_node(&data);
	assertEqual(add_to_list(&list, node), 1);

	assertEqual(*(int*)deleteElementAt(&list, 0), data);
	assertEqual(list.tail, 0x0);
	assertEqual(list.head, 0x0);

	free(node);
}

// int asArray(LinkedList, void **)

void test_asArray_should_return_1_for_one_node_list () {
	int data = 2;
	int* array;
	LinkedList list = createList();
	Node_ptr node = create_node(&data);
	array = calloc(sizeof(int*), 1);

	assertEqual(add_to_list(&list, node), 1);
	assertEqual(asArray(list, &array), 1);
	assertEqual((int*)array[0], data);

	free(node);
}

void test_asArray_should_return_3_for_three_node_list () {
	int data1 = 2, data2 = 4, data3 = 6;
	int* array;
	LinkedList list = createList();
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2), node3 = create_node(&data3);
	array = calloc(sizeof(int), 3);

	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);
	assertEqual(add_to_list(&list, node3), 1);
	assertEqual(asArray(list, array), 3);
	assertEqual(*(int*)array[0], data1);
	assertEqual(*(int*)array[1], data2);
	assertEqual(*(int*)array[2], data3);

	free(node1);
	free(node2);
	free(node3);
	free(array);
}

int numberGreaterThan (void *element) {
	return (int*)element > 2;
}

void test_filter_should_return_a_new_linked_list () {
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList(), *greaterThan2;
	Node_ptr node1 = create_node(&data1), node2 = create_node(&data2), node3 = create_node(&data3);

	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);
	assertEqual(add_to_list(&list, node3), 1);

	// greaterThan2 = filter(list, numberGreaterThan);
}
