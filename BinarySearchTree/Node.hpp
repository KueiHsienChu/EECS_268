template<typename T>
Node<T>::Node()
{
	m_left = nullptr;
	m_right = nullptr;
}

template<typename T>
Node<T>::Node(const Node<T>& other)
{
	m_value = other.getValue();	
	m_right = nullptr;
	m_left = nullptr;

	if(other.getLeft() != nullptr)
		m_left = new Node(*(other.getLeft()));
	if(other.getRight() != nullptr)
		m_right = new Node(*(other.getRight()));

	/*
	if(other->getLeft() != nullptr)
		Node(other->getLeft());
	if(other->getRight() != nullptr)
		Node(other->getRight());
	Node<T>* copy = new Node<T>();
	copy->setValue(other->getValue());
	*/
}

template<typename T>
Node<T>* Node<T>::getLeft() const
{
	return(m_left);
}

template<typename T>
T Node<T>::getValue() const
{
	return(m_value);
}

template<typename T>
Node<T>* Node<T>::getRight() const
{
	return(m_right);
}

template<typename T>
void Node<T>::setValue(T value)
{
	m_value = value;
}

template<typename T>
void Node<T>::setLeft(Node<T>* left)
{
	m_left = left;
}

template<typename T>
void Node<T>::setRight(Node<T>* right)
{
	m_right = right;
}
