#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


#include "BSTI.h"
#include "Node.h"


template<typename T>
class BinarySearchTree : public BSTI<T> 
{
	public:
		/*
		@pre: 
		@post: Sets m_root to nullptr 
		*/
		BinarySearchTree();

		/*
		@pre: 
		@post: Copy Constructor; creates a deep copy of the other BST. ***This method should be called in the clone() method***
		*/
	 	BinarySearchTree(const BinarySearchTree<T>& other);

		/*
		@pre: 
		@post: Calls private method, deleteTree(Node<T>* subTree) and passes in m_root as the starting point for deletion 
		*/
		~BinarySearchTree();

		/*
		@pre: 
		@post: Creates a deep copy of this; Returns a pointer to a deep copy of this.
		*/
		BSTI<T>* clone(); 

		/*
		@pre: 
		@post:
		*/
		bool isEmpty() const;

		/*
		@pre: 
		@post:
		*/
		bool add(T value);

		/*
		@pre: 
		@post:
		*/
		bool search(T value) const;

		/*
		@pre: 
		@post:
		*/
		std::vector<T> treeToVector(Order order) const;

	
	private:
		/*
		@pre: 
		@post:
		*/
		bool add(T value, Node<T>* subtree);
		void deleteTree(Node<T>* subTree);
		bool search(T value, Node<T>* subtree);
		void printTree(Node<T>* subtree, Order order) const;

		Node<T>* m_root;
};

#include "BinarySearchTree.hpp"
#endif
