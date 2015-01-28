#include "expr_assert.h"
#include "linkedList.h"

void test_create_a_linkedList_which_will_contains_head_and_tail () {
	LinkedList list;
	list = createList();

	assertEqual(list.head, 0x0);
	assertEqual(list.tail, 0x0);
	assertEqual(list.count, 0);

	free(list);
}