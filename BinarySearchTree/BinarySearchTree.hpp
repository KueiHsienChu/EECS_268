template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root = nullptr;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other) 
{
	//if(!other.isEmpty())
	
	//Node<T>* temp = new Node<T>();
	//temp->setValue(m_root->getValue);
	
	
	
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
		deleteTree(m_root);
}

template<typename T>
BSTI<T>* BinarySearchTree<T>::clone() 
{
		/*
	if(isEmpty())
		return(nullptr);
	else
	{
		BSTI<T>* temp = new BinarySearchTree<T>();
		
		*/
		
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
	switch(order)
	{
		case PRE_ORDER: {
					
				}
		
		case IN_ORDER:  {
					
				}
		
		case POST_ORDER:{
					
				}
		
		default:{
					
			}
	}
	
}

template<typename T>
void BinarySearchTree<T>::sortedPrint()const
{
	
}

template<typename T>
bool BinarySearchTree<T>::add(T value) 
{

	if(m_root == nullptr)
	{
		m_root = new Node<T>();
		m_root->setValue(value);

		return(true);
	}
	
	else
	{
		if( value == m_root->getValue() )
			return false;
		if(value > m_root->getValue())
			return add( value, m_root->getRight() );
		else
			return add( value, m_root->getLeft() );
	}
	
		

}

template<typename T>
bool BinarySearchTree<T>::search(T value) const 
{
	return search(value, m_root);
}

template<typename T>
std::vector<T> BinarySearchTree<T>::treeToVector(Order order) const 
{
	
	std::vector<T> vector;
	
	if(m_root == nullptr)
		return vector;
	else
	{
		treeToVector(order, m_root, vector);
		return vector;
	}
}

///////////////////////////////////////////private methods/////////////////////////////////////////////

template<typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subtree)
{
	if(subtree == nullptr)
	{
		//std::cout << "\nPROCESSED subtree == nullptr\n\n";
		subtree = new Node<T>();
		subtree->setValue(value);
		//std::cout << subtree->getValue() << "\n";
		return true;
	}
	else 
	{
		if( value == subtree->getValue() )
			return false;
		if( value > subtree->getValue() )
			return add( value, subtree->getRight() );
		if( value < subtree->getValue() )
			return add( value, subtree->getLeft() );
	}
}


template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subTree)
{
	if(subTree != nullptr)
	{
		deleteTree(subTree->getLeft());
		deleteTree(subTree->getRight());
		delete subTree;
		subTree = nullptr;
	}
}

template<typename T>
bool BinarySearchTree<T>::search(T value, Node<T>* subtree) const
{
	if(subtree == nullptr)
		return false;
	else if(value == subtree->getValue())
		return true;
	else if(value > subtree->getValue())
		return search(value, subtree->getRight());
	else if(value < subtree->getValue())
		return search(value, subtree->getLeft());
}

template<typename T>
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order) const
{

}

template<typename T>
void BinarySearchTree<T>::treeToVector(Order order, Node<T>* subtree, std::vector<T>& vec) const
{
	switch(order)
	{
		case PRE_ORDER: {
					vec.push_back(subtree->getValue());
					treeToVector(order, subtree->getLeft(), vec);			
					treeToVector(order, subtree->getRight(), vec);
			
					break;
				}

		case IN_ORDER:  {
					treeToVector(order, subtree->getLeft(), vec);	
					vec.push_back(subtree->getValue());
					treeToVector(order, subtree->getRight(), vec);
	
					break;
				}

		case POST_ORDER:{	
					treeToVector(order, subtree->getLeft(), vec);	
					treeToVector(order, subtree->getRight(), vec);
					vec.push_back(subtree->getValue());
			
					break;
				}

		default:{
				break;
			}
	}

}
