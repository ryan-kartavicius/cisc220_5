#include<stdio.h>
#include<stdlib.h>

struct Node* createNode(union Data data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;

void insert (int index, union Data data, int type){
	if (head == NULL) {
		head->data = data;
		head->next = NULL;
		head->prev = NULL;
		head->listLength = 1;
	}	
	else { 
		Node* newNode = data;
		if (index == 0) { // inserting at begining
			if (length() == 1) {
				head->prev = newNode;
				last = head;
				newNode->next = last;
				head = newNode;
			}
			else {
				head->prev = newNode;
				newNode->next = head;
				head = newNode;
		}
		else if (index == length()) { // insert data at end
			if (length() == 1) {
				head->next = newNode;
				newNode->prev = head;
				last = newNode;
			}
			else {
				last->next = newNode;
				newNode->prev = last;
				last = newNode;
			}
		}
		else if (index =< (length()/2) ) {
			ctr = 0;
			struct Node* ptr = head;
			while (ctr < index) {
				ptr = ptr->next;
				ctr++;
			}
			newNode->next = ptr->next;
			newNode->prev = ptr;
			ptr->next->prev = newNode;
			ptr->next = newNode;
		}
		else if (index > (length()/2) ) {
			ctr = 0;
			struct Node* ptr = last;
			while (ctr > index) {
				ptr = ptr->prev;
				ctr--;
			}
			newNode->next = ptr->next;
			newNode->prev = ptr;
			ptr->next->prev = newNode;
			ptr->next = newNode;
		}
	}		
}
void remove(int index) {
	if (index == 0) { //deleting head
		if (length() == 1){
			head = NULL;
		}	
				 			
int length() {
	if (head == NULL) {
		return 0;
	}
	else {
		return (head->listLength);
	}
}
	
