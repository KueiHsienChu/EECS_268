template <typename T>
Stack<T>::Stack()
{
	m_front = nullptr;
	m_size = 0;
}

template <typename T>
Stack<T>::~Stack()
{
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
	temp -> setNext(m_front);
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
		}
	else
		throw(std::runtime_error("Pop attempted on an empty list"));
}

template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
	if(!isEmpty())	
		{
			return(m_front -> getValue());	
		}
	else
		throw(std::runtime_error("Peek attempted on an empty list"));
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

