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

void traverse(LinkedList, void (*)(void *data))

		- Write a generic traverse function that can go through a list
		 and process each element. Note that the second argument to
		 traverse is a function pointer that takes a reference to data 
		 as its argument. This traverse function should, for instance, 
		 let you traverse a list and print all its elements. 

		 					v2.0

void * getElementAt(LinkedList, int )

		- Given an index as an integer, return the data reference 
		contained at that position in the list. 
		For ex: getElementAt(2) should return the element at index 2. 
		This is basically like an array's [] operator. Return NULL if index is invalid.


int indexOf(LinkedList, void *)

		- Given an element, find the first index at which this element 
		occurs in a list. Return -1 if not found.

void * deleteElementAt(LinkedList, int)

		- Given an index, delete the element at that list. 
		Return the data referenced by the node at that position. 

