/*
COPYRIGHT INFORMATION

MADE BY CHENGLIN LU
*/
#ifndef _BINARY_TREE
#define _BINARY_TREE

#include<iostream>
#include<string>
using namespace std;


template<class ItemType>
class BinaryNode
{
private:
	ItemType              *item;         // Data portion
	BinaryNode<ItemType>* leftPtr;		// Pointer to left child
	BinaryNode<ItemType>* rightPtr;		// Pointer to right child

public:
	// constructors
	BinaryNode(ItemType *anItem)	{item = anItem; leftPtr = 0; rightPtr = 0;}
	BinaryNode(ItemType *anItem,
		       BinaryNode<ItemType>* left,
			   BinaryNode<ItemType>* right) {item = anItem; leftPtr = left; rightPtr = right;}
	~BinaryNode() {}

	// setters
	void setItem(ItemType *anItem) {item = anItem;}
	void setLeftPtr(BinaryNode<ItemType>* left) {leftPtr = left;}
    void setRightPtr(BinaryNode<ItemType>* right) {rightPtr = right;}
	// getters
	ItemType* getItem() 	 {return item;}
	BinaryNode<ItemType>* getLeftPtr() const  {return leftPtr;}
	BinaryNode<ItemType>* getRightPtr() const {return rightPtr;}

	bool isLeaf() const {return ((leftPtr == 0) && (rightPtr == 0));}
};

template<class ItemType>
class BinaryTree
{
protected:
	BinaryNode<ItemType>*  rootPtr;		// ptr to root node
	int count;							// number of nodes in tree

public:
	//OPERATORS
	BinaryTree & operator = (const BinaryTree & sourceTree);

	//STRUCTORS
 	BinaryTree() {rootPtr = 0; count = 0;}
	BinaryTree(const BinaryTree<ItemType> & tree) { rootPtr = copyTree(BinaryNode<ItemType>::tree.rootPtr); }
	virtual ~BinaryTree() { 
		destroyTree(rootPtr); 
	}

	//MAIN FUNCS
 	bool isEmpty() const	{return count == 0;}
	int size() const	    {return count;}
	void clear()			{destroyTree(rootPtr); rootPtr = 0; count = 0;}
	void preOrder(void visit(ItemType &)) const {_preorder(visit, rootPtr);}
	void inOrder(void visit(ItemType &)) const  {_inorder(visit, rootPtr);}
	void postOrder(void visit(ItemType &)) const{_postorder(visit, rootPtr);}

private:
	// destoryer and  copier
	void destroyTree(BinaryNode<ItemType>* nodePtr);
	BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* nodePtr);

	// internal traverse
	void _preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;

};

////////////////////////////////================PRIVATE FUNC===============/////////////////////////////////
////////////////////////////////================PRIVATE FUNC===============/////////////////////////////////
////////////////////////////////================PRIVATE FUNC===============/////////////////////////////////

//=========================================================================
//Take a treeRoot, destory its subs
template<class ItemType>
void BinaryTree<ItemType>::destroyTree(BinaryNode<ItemType>* nodePtr)
{
	if (nodePtr != 0)
	{
		destroyTree(nodePtr->getLeftPtr());
		destroyTree(nodePtr->getRightPtr());
		delete nodePtr;
	}
}

//=========================================================================
//Take an treeRoot, copy a same tree out, and return new tree
template<class ItemType>
BinaryNode<ItemType>* BinaryTree<ItemType>::copyTree(const BinaryNode<ItemType>* nodePtr)
{
	if (nodePtr==NULL) return NULL;
	else {
		BinaryNode<ItemType>* newNode = new BinaryNode<ItemType>(nodePtr->getItem());
		newNode->setLeftPtr(copyTree(nodePtr->getLeftPtr()));
		newNode->setRightPtr(copyTree(nodePtr->getRightPtr()));
		return newNode;
	}
}

//=========================================================================
//Recursive Function of traverse by preorder
template<class ItemType>
void BinaryTree<ItemType>::_preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr != 0)
	{
		ItemType item = nodePtr->getItem();
		visit(item);
		_preorder(visit, nodePtr->getLeftPtr());
		_preorder(visit, nodePtr->getRightPtr());
	}
}

//=========================================================================
//Recursive Function of traverse by inorder
template<class ItemType>
void BinaryTree<ItemType>::_inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr != 0)
	{
		_inorder(visit, nodePtr->getLeftPtr());
		ItemType item = *nodePtr->getItem();
		visit(item);
		_inorder(visit, nodePtr->getRightPtr());
	}
}

//=========================================================================
//Recursive Function of traverse by postorder
template<class ItemType>
void BinaryTree<ItemType>::_postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr != 0)
	{
		_postorder(visit, nodePtr->getLeftPtr());
		_postorder(visit, nodePtr->getRightPtr());
		ItemType item = nodePtr->getItem();
		visit(item);
	}
}

//=========================================================================
//Copy a tree for the being equal tree
template<class ItemType>
BinaryTree<ItemType> & BinaryTree<ItemType>::operator=(const BinaryTree<ItemType> & sourceTree)
{
	destroyTree(rootPtr);
	rootPtr = copyTree(sourceTree.rootPtr);
	return *this;
}


#endif
