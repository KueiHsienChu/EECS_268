#ifndef NODE_H
#define NODE_H


template<typename T>
class Node
{
	public:
		/*
		@pre: 
		@post:
		*/
		Node();
		Node(const Node<T>& other);
		Node<T>* getLeft();
		Node<T>* getRight();
		void setValue(T value);
		void setLeft(Node<T>* left);
		void setRight(Node<T>* right);
		
	private:
		Node<T>* m_left;
		Node<T>* m_right;
		T m_value; 

};

#include "Node.hpp"
#endif

