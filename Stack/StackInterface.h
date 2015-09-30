#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H
#include "PreconditionViolationException.h"

template <typename T>

class StackInterface
{

	public:
		/*
		@pre:
		@post:
		*/
		virtual ~StackInterface() {};

		/*
		@pre:
		@post: returns true if the stack is empty, false otherwise
		*/
		virtual bool isEmpty() const = 0;

		/*
		@pre:
		@post: Entry added to top of stack
		*/
		virtual void push(const T newEntry) = 0;

		/*
		@pre: Assumes the stack is not empty
		@post: Top of the stack is removed; lhrows PreconditionViolationException when a
		 pop is attempted on an empty stack. Does not return a value in this case.
		*/
		virtual void pop() throw(PreconditionViolationException) = 0;

		/*
		@pre: Assumes the stack is not empty
		@post: Returns the value at the top of the stack
		@return: Throws a PreconditionViolationException is attempted on an empty stack. Does not return a value in this case.
		*/
		virtual T peek() const throw(PreconditionViolationException) = 0;

		/*
		@pre:
		@post:
		@return: Returns the size of the stack
		*/
		virtual int size() const = 0;
		/*
		@pre:
		@post: Prints the contents of the stack or prints the empty string if it is empty
		Example: If you push 5, push 10, and push 15 note that the printing of the stack should print "15 10 5" 
		*/
		virtual void print() const = 0;

};

#endif
