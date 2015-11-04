template<typename T>
Node<T>::Node()
{
	m_left = nullptr;
	m_right = nullptr;
}

template<typename T>
Node<T>::Node(const Node<T>& other)
{
}

template<typename T>
Node<T>* Node<T>::getLeft()
{
	return(m_left);
}

template<typename T>
Node<T>* Node<T>::getRight()
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
