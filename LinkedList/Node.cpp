#include "Node.h"

Node::Node() //constructor
{
	m_value = 0;
	m_next = nullptr;
}

void Node::setValue(int val)
{
	m_value = val;
}

int Node::getValue() const
{
	return(m_value);
}

void Node::setNext(Node* prev) // set m_next as nullptr
{	
	m_next = prev;	
}

Node* Node::getNext() const
{
	return m_next;
}

