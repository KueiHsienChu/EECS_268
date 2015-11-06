template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root = nullptr;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other) 
{
	m_root = new Node<T>(*(other.m_root));
	//the member of the binary search tree is a pointer
	//so once it's dereferenced, it returns a node
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	if(isEmpty())
	{
	}
	else
	{
		deleteTree(m_root);
		m_root = nullptr;
	}
}

template<typename T>
BSTI<T>* BinarySearchTree<T>::clone() 
{

	BSTI<T>* bstclone = new BinarySearchTree(*this);
	return bstclone;

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
		return add(value, m_root);
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
	Node<T>* temp = nullptr;

	if(value > subtree->getValue())
	{
		if(subtree->getRight() == nullptr)
		{
			temp = new Node<T>();
			temp->setValue(value);
			subtree->setRight(temp);
			temp = nullptr;
			return true;
		}	
		else
			return add(value, subtree->getRight());
	}
	else if(value < subtree->getValue())
 	{
		if(subtree->getLeft() == nullptr)
		{
			temp = new Node<T>();
			temp->setValue(value);
			subtree->setLeft(temp);
			temp = nullptr;
			return true;
		}	
		else
			return add(value, subtree->getLeft());
	}
	else //value == subtree->getValue()
		return false;
	
}


template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subTree)
{
	if(subTree->getLeft() != nullptr)
		deleteTree(subTree->getLeft());

	if(subTree->getRight() != nullptr)
		deleteTree(subTree->getRight());

	delete subTree;
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
	else 
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
