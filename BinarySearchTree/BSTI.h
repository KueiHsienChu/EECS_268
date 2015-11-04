#ifndef BSTI_H
#define BSTI_H

#include <vector>

enum Order
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};


template <typename T>

class BSTI
{
	public:	
		/*
		@pre: 
		@post:
		*/
		virtual ~BSTI(){};
		/*
		@pre: 
		@post:
		*/
		virtual BSTI<T>* clone() = 0; 
		/*
		@pre: 
		@post:
		*/
		virtual bool isEmpty() const = 0; 
		/*
		@pre: 
		@post:
		*/
		virtual bool add(T value) = 0;
		/*
		@pre: 
		@post:
		*/
		virtual bool search(T value) const = 0; 
		/*
		@pre: 
		@post:
		*/
		virtual void printTree(Order order) const = 0; 
		/*
		@pre: 
		@post:
		*/
		virtual void sortedPrint() const = 0; 
		/*
		@pre: 
		@post:
		*/
		virtual std::vector<T> treeToVector(Order order) const = 0; 

};



#endif
