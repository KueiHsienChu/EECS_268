#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <iostream>
#include "StackInterface.h"
#include "PreconditionViolationException.h"

template <typename T>
class Stack : public StackInterface<T>
{
	public:
		/*
		@pre:  
		@post: a stack is created; it can contains nodes that can hold different type of values
		*/
		Stack();
		/*
		@pre: a previously used stack may be in the memory	
		@post: remove the stack from the memory
		*/
		~Stack();	
		/*
		@pre: a stack may have noded that stored values that are in use
		@post: check if a stack is having any nodes
		*/
		virtual bool isEmpty() const;		
		/*
		@pre: a stack has n node
		@post: a stack has n+1 nodes
		*/
		virtual void push(const T newEntry);
		/*
		@pre: a stack has n nodes
		@post: a stack has n-1 nodes
		*/
		virtual void pop() throw(PreconditionViolationException);
		/*
		@pre: a stack contains value in the top node that is not known
		@post: show the value contained on the top of that node(in the stack)
		*/
		virtual T peek()const throw(PreconditionViolationException);
		/*
		@pre: a stack has a finite size
		@post: show the stack's size
		*/
		virtual int size() const;
		/*
		@pre: a stack contains a series of nodes and each contained a value
		@post: show the value in each node
		*/
		virtual void print() const; 	
	private:
		Node<T>* m_front;
		int m_size;		

};

#include "Stack.hpp"
#endif

