template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{	//default constructor
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	while(!isEmpty())
		removeBack();		
}
		
template <typename T>
bool DoubleLinkedList<T>::isEmpty() const
{	//check if the list is empty
	if(m_size == 0)
		return(true);
	else
		return(false);
}

template <typename T>
int DoubleLinkedList<T>::size() const
{	//check the size of the list
	return(m_size);
}

template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
	Node<T>* temp = new Node<T>();
	temp -> setValue(value);
	temp -> setNext(m_front);
	m_front = temp;
	temp = nullptr;
	m_size++;	
}

template <typename T>
void DoubleLinkedList<T>::pushBack(T value)
{	
	Node<T>* temp = new Node<T>();
	temp -> setValue(value);

	if(isEmpty())
		{
			m_front = temp;
			temp = nullptr;
			m_size++;
		}
	else
		{	//well I wrote the logic of it all on paper..	
			Node<T>* forward = m_front;
			while(forward -> getNext() != nullptr)
				forward = forward -> getNext();
			temp -> setPrevious(forward);
			forward -> setNext(temp);
			temp = nullptr;
			forward = nullptr;
			m_size++;
		}
}

template <typename T>
bool DoubleLinkedList<T>::removeBack()
{
	if(isEmpty())
		{
			std::cout << "\nList empty";	
			return(false);
		}
	else
		{
			Node<T>* last = m_front; //create two pointers
			Node<T>* next_to_last = m_front;
			while(last -> getNext() != nullptr) //while the next node is not pointing towards a nullptr..
				{
					next_to_last = last; //so for the first node, next_to_last is still equal to m_front
					last = last -> getNext(); //last moves to the next node	
				}
			next_to_last -> setNext(nullptr); 
			last -> setPrevious(nullptr);
			delete last;
			last = nullptr;
			next_to_last = nullptr;
			m_size--;
			std::cout << "\nBack of list removed";
		return(true);
		}	
}

template <typename T>
bool DoubleLinkedList<T>::removeFront()
{
	if(isEmpty())
		{
			std::cout << "\nList empty";	
			return(false);
		}
	else
		{
			Node<T>* temp = m_front;
			Node<T>* temp2 = m_front;
			if(m_size > 1)
			{
				temp = m_front -> getNext();
				temp -> setPrevious(nullptr);
				m_front = temp;
			}
				delete temp2;
				temp = nullptr; temp2 = nullptr;
			if(m_size == 0)
				m_front = nullptr;
				m_size--;
				
				std::cout << "\nFront of list removed";
				return(true);
			
		}
}

template <typename T>
bool DoubleLinkedList<T>::remove(T value) //perhaps I should use find(), anyway..
{
	if(isEmpty())
		{
			std::cout << "\nList empty";	
			return(false);
		}
	else
		{
			Node<T>* p1 = m_front; //p1 will be the pointer that points to the node with value(if node is found)
			Node<T>* p2 = m_front; //p2 will be the pointer that points to the node before p1 
			
			while(p1 -> getValue() != value && p1 -> getNext() != nullptr)
				{	//find the node that contains the value
					p2 = p1;
					p1 = p1 -> getNext();
				}
			if(p1 -> getValue() == value)
				{	
					Node<T>* p3 = nullptr; //p3 to the rescue
					if(p1 -> getNext() == nullptr || p1 -> getPrevious() == nullptr) 
					//if p1 ends up pointing at the first or the last node
						{
							if(p1 -> getPrevious() == nullptr && m_size >= 1)//first node
								m_front = p1 -> getNext(); //m_front get to the next next node
							if(p1 -> getNext() != nullptr)//in case it's the first node
								{
									p3 = p1 -> getNext();
									p3 -> setPrevious(nullptr);
								}
							p1 -> setPrevious(nullptr);
							p2 -> setNext(nullptr);
							delete p1;
							p1 = nullptr; p2 = nullptr; p3 = nullptr;
							m_size--;
						}
					else
						{
							p3 = p1 -> getNext();
							p1 -> setPrevious(nullptr);
							p2 -> setNext(p3);
							p3 -> setPrevious(p2);
							p1 -> setNext(nullptr);
							delete p1; 
							p1 = nullptr; p2 = nullptr; p3 = nullptr;
							m_size--;
						}	
					return(true);
				}
			else
				return(false);
			}	
}

template <typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue) throw(std::runtime_error)
{
	if(find(listValue) != nullptr)
		{
			Node<T>* right_there = find(listValue); //right_there is the pointer pointing at the node that is found
			
			if(right_there -> getPrevious() == nullptr) //for the case that value contained at the first node
				pushFront(newValue);
			else //for nodes that are either in between or the last 
				{
					Node<T>* p1 = new Node<T>(); //create a new node p1
					p1 -> setValue(newValue); //set value
					p1 -> setNext(right_there); //p1's node pointer pointer at right_there
					Node<T>* p2 = p1 -> getNext(); //create a p2 that is also pointing at right_there
					Node<T>* p3 = p2 -> getPrevious(); //create a p3: pointing at right_there's previous node
					p2 -> setPrevious(p1);
					p3 -> setNext(p1);
					p1 -> setPrevious(p3);
					p1 = nullptr; p2 = nullptr; p3 = nullptr;
					m_size++; //increase size by 1
				}
			right_there = nullptr; //;-)
		}
	else
		throw(std::runtime_error("\nNo value is found on the list! Insert failed"));
}

template <typename T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue) throw(std::runtime_error)
{
	if(find(listValue) != nullptr)
		{	
			if(find(listValue) -> getNext() == nullptr)
				pushBack(newValue);
			else //different implementation. using only one node..[guess it might take longer..]
				{
					Node<T>* p1 = new Node<T>();
					p1 -> setValue(newValue);
					p1 -> setNext(find(listValue) -> getNext());
					p1 -> setPrevious(find(listValue));
					find(listValue) -> getNext() -> setPrevious(p1);
					find(listValue) -> setNext(p1);
					p1 = nullptr;
					m_size++;
				}
		}
	else
		throw(std::runtime_error("\nNo value is found on the list! Insert failed"));
}

template <typename T>
Node<T>* DoubleLinkedList<T>::find(T value) const
{
	Node<T>* search = m_front;

	//check the first node
	if(isEmpty())
		return(nullptr);
	else if(search -> getValue() == value) 
		return(search);//if the first node contains the value, return the pointer which points to the 1st node
	else
		{
			while(search -> getValue() != value && search -> getNext() != nullptr)
				{ //if value is correct, while loop terminates since first condition is false
					search = search -> getNext();
				}
			if(search -> getValue() == value)
				return(search);
			else
				return(nullptr);
		}
}

template <typename T>
void DoubleLinkedList<T>::printList() const
{
	if(!isEmpty())
		{	
			Node<T>* cruise = m_front;
			while(cruise != nullptr)
				{
					std::cout << cruise -> getValue() << " ";
					cruise = cruise -> getNext();	
				}
		}
	else
		std::cout << "";	
}

