#ifndef LINKED_LIST
#define LINKED_LIST
#include "Node.h"

class LinkedList
{
	public:
		/*
		@pre: The stack is empty 
		@post: A Linklist object has been constructed
		*/	
		LinkedList(); // constructor

		/*
		@pre: stack may contain linked-list objects
		@post: linked list object removed	 
		*/	
		~LinkedList(); // destructor

		/*
		@pre: called when needed 
		@post: Check if linked list has any nodes 
		@return: true or false
		*/
		bool isEmpty() const; // return true if the list is empty. false otherwise

		/*
		@pre: called when needed
		@post: check how mant nodes are created on the heap
		@return: an integer value
		*/
		int size() const; // returns the number of elements in the list

		/*
		@pre: called when needed
		@post: search if there is any matched value in the node 
		@return: ture or false
		*/
		bool search(int value); // The lab has T as the type. Set int for now.

		/*
		@pre: called when needed
		@post: print out the value of each nodes
		*/
		void printList() const; // prints the list to the console. "List empty" if it's empty

		/*
		@pre: the linklist has n nodes | n is an integer
		@post: the linklist has n + 1 nodes where the n + 1 node is added after the n node
		*/
		void addBack(int value); // one new element to add to the end of the list
		
		/*
		@pre: the linklist has n nodes | n is an integer
		@post: the linklist has n + 1 nodes where the n + 1 node is added as the first node in the list 
		*/

		void addFront(int value); //one element is added to the front of the list

		/*
		@pre: the linklist has n nodes | n is an integer
		@post: the linklist has n - 1 nodes where the last node is removed
		@return: ture if the last node is removed; false otherwise
		*/
		bool removeBack(); // one element is removed from the back of the list; returns true if the back element is removed.
		
		/*
		@pre: the linklist has n nodes | n is an integer
		@post: the linklist has n - 1 nodeds where the first node is removed
		@return: turn if the first node is removed; false otherwise
		*/
		bool removeFront(); // one element is removed from the front of the list; return true (removed), false (empty).
		
			
	private:
		Node* m_front;
		int m_size;

};

#endif
