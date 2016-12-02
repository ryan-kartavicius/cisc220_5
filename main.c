#include<stdio.h>
#include<stdlib.h>

void main(){
	union Data {
		int 0;
		int* 1;
		float 2;
		float* 3;
		char 4;
		char* 5;
	};
// 	union Data data; // might need this line (not sure)
	struct Node {
		union Data data;
		struct Node* next;
		struct Node* prev;
	};
	typedef struct Node Node;

	struct headNode { 
		union Data data;
		int listLength;
		struct Node* next;
		struct Node* prev;
	}
	typedef struct Node Node;
	
	headNode* head = NULL;
	Node* last = NULL;

	// This is where we need to call the methods with our chosen values for testing
	

} //end main
	

