/*
COPYRIGHT INFORMATION

DEVELOPED BY JUN LI
*/
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTree.h"
#include<iostream>
#include<string>
#include"Queue.h"
//#include"DLinklist"
using namespace std;

template<class ItemType>
class BinarySearchTree : public BinaryTree<ItemType>
{
private:
    // internal insert node: insert newNode in nodePtr subtree
    BinaryNode<ItemType>* _insert(BinaryNode<ItemType>* nodePtr,
        BinaryNode<ItemType>* newNode, string getName(ItemType *item));

    // internal remove node: locate and delete target node under nodePtr subtree
    BinaryNode<ItemType>* _remove(BinaryNode<ItemType>* nodePtr,
        const ItemType target, bool & success, string getName(ItemType *item));

    // delete target node from tree, called by internal remove node
    BinaryNode<ItemType>* deleteNode(BinaryNode<ItemType>* targetNodePtr);

    // remove the leftmost node in the left subtree of nodePtr
    BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* nodePtr,
        ItemType & successor);

	// search for target node
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
                         ItemType & target, string getName(ItemType *item)) const;

	// process indented elements
	void _indented(BinaryNode<ItemType>* nodePtr,
                                  int level, void visit(ItemType&)) const;

public:
	// insert a node at the correct location
    bool insert(ItemType *newEntry, string getName(ItemType *item));
	// remove a node if found
	bool remove(const ItemType &anEntry, string getID(ItemType *item));
	// find a target node
	Queue<ItemType>* getEntries
          (ItemType & anEntry, string getName(ItemType *item)) const;

	// get Indented
	void indented(void visit(ItemType&)) const
                     { _indented(BinaryTree<ItemType>::rootPtr,1,visit); }
	//Traverse by level
	void levelTraverse(void visit(ItemType&));

};

////////////////////////////////================PUBLIC FUNC===============/////////////////////////////////
////////////////////////////////================PUBLIC FUNC===============/////////////////////////////////
////////////////////////////////================PUBLIC FUNC===============/////////////////////////////////

//=========================================================================
//Take an object and insert in the tree
template<class ItemType>
bool BinarySearchTree<ItemType>::insert(ItemType  *newEntry,
                                        string getName(ItemType *item))
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
	BinaryTree<ItemType>::rootPtr = _insert(BinaryTree<ItemType>::rootPtr, newNodePtr,getName);
	return true;
}

//=========================================================================
//Take an object as target and delete the one in the tree
template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType & target,
                                        string getID(ItemType *item))
{
	bool isSuccessful = false;
	BinaryTree<ItemType>::rootPtr = _remove(BinaryTree<ItemType>::rootPtr, target, isSuccessful,getID);
	return isSuccessful;
}

//=========================================================================
//Take an object as target and return the items in the database
template<class ItemType>
Queue<ItemType>* BinarySearchTree<ItemType>::getEntries
    (ItemType& anEntry, string getName(ItemType *item)) const
{
	//VARS
	BinaryNode<ItemType>* found;
    Queue<ItemType> *myQ = new Queue<ItemType>;

	//CALL
	found = findNode(BinaryTree<ItemType>::rootPtr, anEntry, getName);
	while (found) {
        myQ->enqueue(*found->getItem());
        found = findNode(found->getRightPtr(), anEntry, getName);
	}
	return myQ;
}

//=========================================================================
//Using a Queue to print the item by levels
template<class ItemType>
void BinarySearchTree<ItemType>::levelTraverse(void visit(ItemType&)) {
	//VARS
	Queue<BinaryNode<ItemType>*> coreQueue;
	BinaryNode<ItemType>* theNode;

	//INIT
	if (BinaryTree<ItemType>::rootPtr) coreQueue.enqueue(BinaryTree<ItemType>::rootPtr);

	//GO OVER THE QUEUE
	while (!coreQueue.isEmpty()) {
		coreQueue.dequeue(theNode);
		if (theNode->getLeftPtr()) coreQueue.enqueue(theNode->getLeftPtr());
		if (theNode->getRightPtr()) coreQueue.enqueue(theNode->getRightPtr());
		visit(theNode->getItem());
	}

}



////////////////////////////////================PRIVATE FUNC===============/////////////////////////////////
////////////////////////////////================PRIVATE FUNC===============/////////////////////////////////
////////////////////////////////================PRIVATE FUNC===============/////////////////////////////////

//==========================================================================================================
//Recursive part of Indented traversal
template<class ItemType>
void BinarySearchTree<ItemType>::_indented(BinaryNode<ItemType>* nodePtr,
                                  int level, void visit(ItemType&)) const
{
	if (nodePtr != 0)
	{
		for (int i = 0;i < level - 1;i++) cout << "       ";
		cout << level << ". " ;
        visit(*nodePtr->getItem()) ;
        cout << endl;
		_indented(nodePtr->getRightPtr(), level + 1, visit);
		_indented(nodePtr->getLeftPtr(), level + 1, visit);
	}
}

//==========================================================================================================
//Recursive part of insert
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_insert(BinaryNode<ItemType>* nodePtr,
                                                          BinaryNode<ItemType>* newNodePtr,
                                                          string getName(ItemType *item))
{
	if (nodePtr == NULL)
        return newNodePtr;
	else {
		if (getName(newNodePtr->getItem()) >= getName(nodePtr->getItem())) {
			nodePtr->setRightPtr(_insert(nodePtr->getRightPtr(), newNodePtr,getName));
		}
		else if (getName(newNodePtr->getItem()) < getName(nodePtr->getItem())) {
			nodePtr->setLeftPtr(_insert(nodePtr->getLeftPtr(), newNodePtr,getName));
		}
		else
            cout << "BST::_insert ERROR : Could not compare item!\n";
	}
	return nodePtr;
}

//==========================================================================================================
//Recursive part of find the Node to delete
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_remove(BinaryNode<ItemType>* nodePtr,
                                                          ItemType target,
                                                          bool & success,
                                                          string getKey(ItemType *item))
{
	if (nodePtr == 0)
		return 0;

    if(getKey(nodePtr->getItem()) == getKey(&target))
    {
        nodePtr = deleteNode(nodePtr);
	    success = true;
        return nodePtr;
    }

	nodePtr->setLeftPtr(_remove( nodePtr->getLeftPtr(),target,success,getKey));

	nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(),target,success,getKey));

	return nodePtr;
}

//==========================================================================================================
//Actually deleting a Node
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::deleteNode
                     (BinaryNode<ItemType>* nodePtr)
{
	if (nodePtr->isLeaf())
	{
		delete nodePtr;
		nodePtr = 0;
		return nodePtr;
	}
	else if (nodePtr->getLeftPtr() == 0)
	{
		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightPtr();
		//delete nodePtr;
		nodePtr = 0;
		return nodeToConnectPtr;
	}
	else if (nodePtr->getRightPtr() == 0)
	{
		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftPtr();
		//delete nodePtr;
		nodePtr = 0;
		return nodeToConnectPtr;
	}
	else
	{
		ItemType *newNodeValue = new ItemType;
		nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), *newNodeValue));
		nodePtr->setItem(newNodeValue);
		return nodePtr;
	}
}

//==========================================================================================================
//Remove the left most node from the BST
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr,
                                                                     ItemType & successor)
{
	if (nodePtr->getLeftPtr() == 0)
	{
		successor = *nodePtr->getItem();
		return deleteNode(nodePtr);
	}
	else
	{
		nodePtr->setLeftPtr(removeLeftmostNode(nodePtr->getLeftPtr(), successor));
		return nodePtr;
	}
}

//==========================================================================================================
//Find the node from the target item. return the entry
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* nodePtr,
                                                            ItemType & target,
                                                           string getName(ItemType *item)) const
{
	BinaryNode<ItemType>* theNode = NULL;

	if (nodePtr==NULL)
        return NULL;
	else {
		if (getName(nodePtr->getItem()) > getName(&target)) {
			theNode = findNode(nodePtr->getLeftPtr(), target,getName);
		}
		else if (getName(nodePtr->getItem()) < getName(&target)) {
			theNode = findNode(nodePtr->getRightPtr(), target,getName);
		}
		else if (getName(nodePtr->getItem()) == getName(&target)) {
			theNode = nodePtr;
		}
		return theNode;
	}
}


#endif
