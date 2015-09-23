#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		/*
		@pre: a constructor waiting to be called 
		@post: constructor a node
		*/
		Node();

		/*
		@pre: value is an integer, say n, in the node
		@post: value has changed to another integer, m
		*/
		void setValue(int value);

		/*
		@pre: a node has contain a integer n.
		@post: get the value n of the node.
		@return: the value of that node.
		*/
		int getValue() const;

		/*
		@pre: assign the current node's pointer
		@post: set the pointer in the node to point at another node or a nullptr
		*/
		void setNext(Node* prev);
		
		/*
		@pre: assign the current node's pointer 
		@post: get what the assigned pointer's target pointer is pointed at.
		@return: nullptr or some node's addres
		*/
		Node* getNext() const;
	
	private:
		int m_value;
		Node* m_next;
};

#endif
