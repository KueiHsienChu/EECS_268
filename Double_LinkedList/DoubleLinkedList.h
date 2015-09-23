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
		@pre:
		@post:
		*/
		DoubleLinkedList();

		/*
		@pre:
		@post:
		*/
		~DoubleLinkedList();
		
		/*
		@pre:
		@post:
		*/	
		bool isEmpty() const;

		/*
		@pre:
		@post:
		*/
		int size() const;

		/*
		@pre:
		@post:
		*/
		void pushFront(T value);

		/*
		@pre:
		@post:
		*/
		void pushBack(T value);

		/*
		@pre:
		@post:
		*/
		bool removeBack();
		
		/*
		@pre:
		@post:
		*/
		bool removeFront();

		/*
		@pre:
		@post:
		*/
		bool remove(T value);

		/*
		@pre:
		@post:
		*/
		void insertAhead(T listValue, T newValue) throw(std::runtime_error);

		/*
		@pre:
		@post:
		*/
		void insertBehind(T listValue, T newValue) throw(std::runtime_error);

		/*
		@pre:
		@post:
		*/
		Node<T>* find(T value) const;

		/*
		@pre:
		@post:
		*/
		void printList() const;
	private:
		Node<T>* m_front;
		Node<T>* m_back;
		int m_size;	
};

#include "DoubleLinkedList.hpp"
#endif
