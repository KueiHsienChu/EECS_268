#ifndef NODE_H
#define NODE_H

template <typename T>

class Node
{
	public:
		/*
		@pre: --
		@post: Construct a node that contains two null pointer;
		 one points to the front, and another points to the back; 
		 and a value that is T().
		*/
		Node();

		/*
		@pre: The pointer's node contains value say, a_1.
		@post: The pointer's node now contains value, a_2, that entered through the set method. 
		 a has been replaced.
		*/
		void setValue(T value);			

		/*
		@pre: -- 
		@post: Get the value that contains in the node where the pointer is pointing to.
		@return: Returns the value.
		*/
		T getValue() const;		

		/*
		@pre: --
		@post: Assign the pointer's node's pointer to point to where the other pointer(the parameter) is pointing at. 
		 Should point to a node that is after itself.
		*/
		void setNext(Node<T>* next);
		
		/*
		@pre: --
		@post: Get the next node's address.
		*/
		Node<T>* getNext() const;

	private:
		T m_value;
		Node<T>* m_next;
};

#include "Node.hpp"
#endif
