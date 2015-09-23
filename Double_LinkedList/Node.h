#ifndef NODE_H
#define NODE_H

template <typename T>

class Node
{
	public:
		/*
		@pre:
		@post:
		*/
		Node();

		/*
		@pre:
		@post:
		*/
		void setValue(T value);			

		/*
		@pre:
		@post:
		*/
		T getValue() const;		

		/*
		@pre:
		@post:
		*/
		void setNext(Node<T>* next);
		
		/*
		@pre:
		@post:
		*/
		void setPrevious(Node<T>* previous);		

		/*
		@pre:
		@post:
		*/
		Node<T>* getPrevious() const;
		/*
		@pre:
		@post:
		*/
		Node<T>* getNext() const;

	private:
		T m_value;
		Node<T>* m_previous;
		Node<T>* m_next;
};

#include "Node.hpp"
#endif
