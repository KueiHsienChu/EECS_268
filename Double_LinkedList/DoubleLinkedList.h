#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "Node.h"
#include <stdexcept>
#include <iostream>

template <typename T>

class DoubleLinkedList
{
	public:
		/*
		@pre: --
		@post: Construct a double-linked list. 
		*/
		DoubleLinkedList();

		/*
		@pre: --
		@post: Deconstruct all the nodes in the double-linked list.
		*/
		~DoubleLinkedList();
		
		/*
		@pre: -- 
		@post: Check if the list contains any nodes.
		@return: True if it's empty, false otherwise. 
		*/	
		bool isEmpty() const;

		/*
		@pre: --
		@post: Check how many nodes are in the list.
		@return: How many nodes.
		*/
		int size() const;

		/*
		@pre: --
		@post: Add a node to the front of the list.
		*/
		void pushFront(T value);

		/*
		@pre: -- 
		@post: Add a node to the back of the list.
		*/
		void pushBack(T value);

		/*
		@pre: --
		@post: Remove a node from the back of the list.
		@return: True if a node is removed, false otherwise.
		*/
		bool removeBack();
		
		/*
		@pre: --
		@post: Remove a node from the front of the list.
		@return: True if a node is removed, false otherwise.
		*/
		bool removeFront();

		/*
		@pre: --      
		@post:Remove a node that contains a specific value that we entered.
		@return: True if a node is removed, false otherwise.
		*/
		bool remove(T value);

		/*
		@pre: -- 
		@post: Insert a value ahead a node that contains a value we specified.
		*/
		void insertAhead(T listValue, T newValue) throw(std::runtime_error);

		/*
		@pre: --
		@post: Insert a value behind a node that contains a value we specified.
		*/
		void insertBehind(T listValue, T newValue) throw(std::runtime_error);

		/*
		@pre: -- 
		@post: Find the node that contains a value we specified.
		*/
		Node<T>* find(T value) const;

		/*
		@pre: --
		@post: Print the List.
		*/
		void printList() const;
	private:
		Node<T>* m_front;
		Node<T>* m_back;
		int m_size;	
};

#include "DoubleLinkedList.hpp"
#endif
