#include<stdio.h>
#include<stdlib.h>
#include"udll.h"

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
	head->listLength = (head->listLength + 1);
	}		
} // end insert func

void remove(int index) {
	if (index == 0) { //deleting head
		if (length() == 1){
			head = NULL;
		}
		else {
			head = head->next;
			head->prev = NULL;
		}
	}
	else if (index = length()){ // deleting last
		last = last->prev;
		last->next = NULL;
	}
	else if (index =< (length()/2) ) {
		ctr = 0;
		struct Node* ptr = head;
		while (ctr > index) {
			ptr = ptr->next;
			ctr++;
		}
		ptr->prev->next = ptr->next;
	}
	else if (index > (length()/2)) { 
		ctr = 0;
		struct Node* ptr = last;
		while (ctr < index) {
			ptr = ptr->prev;
			ctr--;
		}
		ptr->prev->next = ptr->next;
	
	}
	head->listLength = (head->listLength - 1);
} //end remove func

union Data get(int index) {
	if (index =< length() ) {
		ctr = 0;
		struct Node* ptr = head;
		while (ctr < index) {
			ptr = ptr->next;
			ctr++;
		}
		return ptr->data;
	}
	if (index > (length()/2) ) {
		ctr = 0;
		struct Node* ptr = last;
		while (ctr > index) {
			ptr = ptr->pev;
			ctr--;
		}
		return ptr->data;
	}	
} // end get func	
				 			
int length() {
	if (head == NULL) {
		return 0;
	}
	else {
		return (head->listLength);
	}
} //end length func
	

