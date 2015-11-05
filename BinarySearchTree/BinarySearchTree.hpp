template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root = nullptr;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other) 
{
	
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	
}

template<typename T>
BSTI<T>* BinarySearchTree<T>::clone() 
{
}

template<typename T>
bool BinarySearchTree<T>::isEmpty() const
{
	if(m_root == nullptr)
		return true;
	else
		return false;	
}

template<typename T>
void BinarySearchTree<T>::printTree(Order order) const
{
	
}

template<typename T>
void BinarySearchTree<T>::sortedPrint()const
{

}

template<typename T>
bool BinarySearchTree<T>::add(T value) 
{
	if(isEmpty())
	{
		Node<T>* temp = new Node<T>();
		temp -> setValue(value);
		m_root = temp;
		temp = nullptr;

		return(true);
	}
	else if( value == m_root->getValue() )
		return false;
	else
	{
		if(value > m_root->getValue())
			return add( value, m_root->getRight() );
		else if( value < m_root->getValue() )
			return add(value, m_root->getLeft() );
	}
		

}

template<typename T>
bool BinarySearchTree<T>::search(T value) const 
{

}

template<typename T>
std::vector<T> BinarySearchTree<T>::treeToVector(Order order) const 
{

}

///////////////////////////////////////////private methods/////////////////////////////////////////////

template<typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subtree)
{
	Node<T>* temp = new Node<T>();
	temp -> setValue(value);

	if(subtree == nullptr)
	{
		subtree = temp;
		subtree->setValue(value);
		temp = nullptr;
		return true;
	}
	else if( value == subtree->getValue() )
		return false;
	else if( value > subtree->getValue() )
	{
		delete temp;
		temp = nullptr;
		return add( value, subtree->getRight() );
	}
	else if( value < subtree->getValue() )
	{
		delete temp;
		temp = nullptr;
		return add( value, subtree->getLeft() );
	}
		
		
}


template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subTree)
{

}

template<typename T>
bool BinarySearchTree<T>::search(T value, Node<T>* subtree)
{

}

template<typename T>
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order) const
{

}

