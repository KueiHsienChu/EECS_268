template <typename T>
Stack<T>::Stack()
{
	m_front = nullptr;
	m_size = 0;
}

template <typename T>
Stack<T>::~Stack()
{
	if(m_size > 0)
		pop();
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	if(m_size == 0)
		return(true);
	else
		return(false);	
}

template <typename T>
void Stack<T>::push(const T newEntry)
{	//copy from pushFront -- DoubleLinkedlist
	Node<T>* temp = new Node<T>();
	temp -> setValue(newEntry);

	if(m_size >= 1)
		temp -> setNext(m_front);
	else //m_size == 0
		temp -> setNext(nullptr);//The deepest node points to nullptr

	m_front = temp;
	temp = nullptr;
	m_size++;	
}

template <typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{	
	if(!isEmpty())	
		{
			Node<T>* temp = m_front;
			m_front = m_front -> getNext();
			delete temp;
			temp = nullptr;
			m_size--;
		}
	else 
		throw(PreconditionViolationException("Pop attempted on an empty list"));
}

template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
	if(!isEmpty())	
		{
			return(m_front -> getValue());	
		}
	else
		throw(PreconditionViolationException("Peek attempted on an empty list"));
}


template <typename T>
int Stack<T>::size() const
{
	return(m_size);
}

template <typename T>
void Stack<T>::print() const
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

