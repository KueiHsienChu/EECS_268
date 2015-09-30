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
		Stack();
		~Stack();	
		virtual bool isEmpty() const;		
		virtual void push(const T newEntry);
		virtual void pop() throw(PreconditionViolationException);
		virtual T peek()const throw(PreconditionViolationException);
		virtual int size() const;
		virtual void print() const; 	
	private:
		Node<T>* m_front;
		int m_size;		

};

#include "Stack.hpp"
#endif

