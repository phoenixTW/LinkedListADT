# LinkedListADT
Linked List util written in C

								v1.0

LinkedList:

	- is a structure that holds the first and last element 
	of a linked list(head and tail). 
	It may also contain the number of elements in that list.


Node:

	- Node is a structure that contains a reference
	 to a data type and a pointer to another node(next).


LinkedList createList(void);

	- create an empty LinkedList structure.


Node * create_node(void *data);

	- Given some data, create an appropriate Node
	 structure out of it. Note the data can be of any type.

int add_to_list(LinkedList *,Node *);
	
	- It sets head and tail of a link list. 
	First node will be head of the list and
	last added list will be tail of the list.

void *get_first_element(LinkedList list);

	- This function returns the first element in the list. 