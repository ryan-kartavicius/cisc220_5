#ifndef udll_h_
#define udll_h_

//header file - includes declaration of functions
 
//function to insert data at a specific index of a doubly linked list
void insert(int index, union Data data);

//function to delete data at a specific index of a doubly linked list
void remove(int index);

//function to return data from a doubly linked list at a specific index
union Data get(int index);

//function to return the length of doubly linked list
int length();
