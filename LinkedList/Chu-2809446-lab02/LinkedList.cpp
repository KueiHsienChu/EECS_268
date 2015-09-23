#include "LinkedList.h"
#include <iostream>


LinkedList::LinkedList() // constructor
{
	m_front = nullptr;
	m_size = 0;
}

LinkedList::~LinkedList() // destructor
{	
	while(m_front != nullptr)
	{
		removeBack();
	}
	
	
}

bool LinkedList::isEmpty() const // return true if the list is empty. false otherwise
{
	if(m_size == 0)
		return true;
	else
	{	
		return false;
	}
}

int LinkedList::size() const // returns the number of elements in the list
{
	return(m_size);
}

bool LinkedList::search(int value) // The lab has T as the type. Set int for now.
{
	if(m_front != nullptr)
	{
		Node* find = m_front;
		
		// First, examine the first node.	
		if(find -> getValue() == value)
			return true;
		// Then, examine the other nodes.	
		while(find -> getNext() != nullptr)
		{
			find = find -> getNext();

			if(find -> getValue() == value)
				return true;
		}
		

	}	
	return false;
	
}

void LinkedList::printList() const // prints the list to the console. "List empty" if it's empty
{

	/* [NOT NEEDED!!! CODE HISTORY HERE]
		if(m_front == nullptr)
			std::cout << "\nList empty";
	*/
	if(m_front != nullptr)
	{
		std::cout << "\n";	
		Node* cruise = m_front;	// "cruise" pointer will get value for each node [via while loop]
		std::cout << cruise -> getValue() << " ";
		while(cruise -> getNext() != nullptr)
		{
			cruise = cruise -> getNext();
			std::cout << cruise -> getValue() << " ";
		}
	}		
}

void LinkedList::addBack(int value) // one new element to add to the end of the list
{
	Node* temp = nullptr;
	Node* last = nullptr;

	if(isEmpty())
	{
		m_front = new Node(); //if the list has an pointer obj. pointing at nullptr--create a new node obj.
		m_front -> setValue(value); //set the value to that pointer obj.
		m_size++;
	}
	else if(!isEmpty())
	{
		last = m_front; // make the "last" pointer pointed towards where m_front is pointed
		
		while(last -> getNext() != nullptr)
		{
			last = last -> getNext();
		}
		
		temp = new Node();
		temp -> setValue(value);	
		last -> setNext(temp);
		m_size++;
	}
}

void LinkedList::addFront(int value) //one element is added to the front of the list
{
	Node* temp = nullptr;
	
	temp = new Node();
	temp -> setValue(value);
	
	temp -> setNext(m_front);
	m_front = temp;	
	temp = nullptr;	
	m_size++;
}

bool LinkedList::removeBack() // one element is removed from the back of the list; returns true if the back element is removed.
{	
	/*If the list is empty, we do not remove any nodes.
	However, if the list is not, then we 
	remove the node at the end.*/
	
	if(isEmpty())
	{
		return(false);
	}
	else if(!isEmpty())
	{
		Node* last = m_front; // destination: last node (later on)
		Node* last_m1 = m_front; // destination: the node before last node (minus one; laster on)	
		Node* null = nullptr;

		if(last -> getNext() == nullptr)
		{
			m_front = nullptr; // cut the node connection 
			last_m1 = nullptr; // same as above
		}
		else
		{
			while(last -> getNext() != nullptr) 
			{	
				last_m1 = last; // (last minus 1) pointer points to where last is currently pointed
				last = last -> getNext(); // and now last pointer pointed to the next node
			}
		last_m1 ->  setNext(null); // cut the connection between the node before the last node and the last node.
		last_m1 = nullptr;
		}

		delete last; // delete the object which "last" is pointing towards to
		last = nullptr; //good habits -- make sure knowing what's inside
		
		m_size--; // decrease the list size
		return(true); // return true, since the last object on linked list has been deleted

	}

	return(false);
}

bool LinkedList::removeFront() // one element is removed from the front of the list; return true (removed), false (empty).
{	
	if(isEmpty())
	{
		return(false);
	}
	else // remove front
	{

		Node* temp = m_front;
		m_front = m_front -> getNext();
		
	
		delete temp;
		temp = nullptr;

		m_size--;
		return(true);
	}// end remove
}

