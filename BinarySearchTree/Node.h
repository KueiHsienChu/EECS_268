#ifndef NODE_H
#define NODE_H


template<typename T>
class Node
{
	public:
		/*
		@pre: 
		@post: Sets m_left and m_right to nullptr; leave m_value alone 
		since we don't know what type we're dealing with so we don't 
		know what a good default value is.
		*/
		Node();
		
		/*
		@pre: 
		@post: Create a deep copy of the other node, meaning it also 
		creates copies of any nodes being pointed to by other
		*/
		Node(const Node<T>& other);

		/*
		@pre: 
		@post: return m_left
		*/
		Node<T>* getLeft();

		/*
		@pre: 
		@post: return m_right
		*/
		Node<T>* getRight();

		/*
		@pre: 
		@post: set m_value
		*/
		void setValue(T value);
		
		/*
		@pre: 
		@post: set m_left
		*/
		void setLeft(Node<T>* left);

		/*
		@pre: 
		@post: set m_right
		*/
		void setRight(Node<T>* right);
		
	private:
		Node<T>* m_left;
		Node<T>* m_right;
		T m_value; 

};

#include "Node.hpp"
#endif

