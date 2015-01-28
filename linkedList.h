typedef struct linkedList LinkedList;
typedef struct node Node;
typedef struct students Students;
typedef Students* Student_ptr;
typedef Node* Node_ptr;

struct students {
	int roll;
	int marks;
};

struct node {
	// Student_ptr student;
	void* data;
 	Node_ptr next;
};

struct linkedList {
	Node_ptr head;
	Node_ptr tail;
	int count;
};

LinkedList createList(void);