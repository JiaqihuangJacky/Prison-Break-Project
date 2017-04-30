//=========================================
//DLinklist template
//
//Created By Chenglin Lu V1.1

//MEMBER FUCNTIONS

//void add(T inputObject);
//void destoryAll();
//int getCount() { return cnt; }
//int get(int index, T &output);
//int remove(int index);
//bool compRemove(T obj, string getKey(T&))

//=========================================
#ifndef DOUBLYLINKLIST
#define DOUBLYLINKLIST

#include <string>
using namespace std;
//-----------------------------------------
//CLASS LISTNODE
template<typename T>
class ListNode
{
private:
	T object;
	ListNode* next;
	ListNode* last;

public:

	//STRUCTORS
	ListNode();

	//GETTERS
	T getObject();
	ListNode* getNext();
	ListNode* getLast();

	//SETTERS
	void setObject(T inputObject);
	void setNext(ListNode* inputAddress);
	void setLast(ListNode* inputAddress);
};

//-----------------------------------------
//CLASS DLinklist
template<typename T>
class DLinklist
{
private:
	ListNode<T>* head;
	int cnt;

public:
	//STRUCTORS
	DLinklist();
	~DLinklist();

	//SETTERS
	void add(T inputObject);
	int remove(int index);
	bool compRemove(T obj, string getKey(T));
	void destoryAll();

	//GETTERS
	int getCount() { return cnt; }
	int get(int index, T &output);
};

//===================================================================================
//ListNode member functions definations


//-------------------------
//CONSTRUCTOR
template<typename T>
ListNode<T>::ListNode()
{
	next = last = NULL;
}


//-------------------------
//getObject 
//returns the object
template<typename T>
T ListNode<T>::getObject()
{
	return object;
}


//-------------------------
//getLast
//returns the address of last
template<typename T>
ListNode<T>* ListNode<T>::getLast()
{
	return last;
}

//-------------------------
//getNext
//returns the address of next
template<typename T>
ListNode<T>* ListNode<T>::getNext()
{
	return next;
}

//-------------------------
//setObject
//take one parameter to set the obj
template<typename T>
void ListNode<T>::setObject(T inputObject)
{
	object = inputObject;
}


//-------------------------
//setNext
template<typename T>
void ListNode<T>::setNext(ListNode* inputAddress)
{
	next = inputAddress;
}

//-------------------------
//setLast
template<typename T>
void ListNode<T>::setLast(ListNode* inputAddress)
{
	last = inputAddress;
}

//===================================================================================
//DLinklist member functions definations

//-------------------------
//CONSTRUCTOR
template<typename T>
DLinklist<T>::DLinklist()
{
	head = new ListNode<T>;
	head->setLast(head);
	head->setNext(head);
	cnt = 0;
}

//-------------------------
//DESTURCTOR
template<typename T>
DLinklist<T>::~DLinklist()
{
	ListNode<T> *ptr, *ptr2;
	ptr = head->getNext();
	while (ptr != head) {
		ptr2 = ptr->getNext();
		delete ptr;
		ptr = ptr2;
	}
}

//-------------------------
//ADD
//This functions add a Node in the end
template<typename T>
void DLinklist<T>::add(T inputObject)
{
	//SET UP NODE
	ListNode<T>* newNode = new  ListNode<T>;
	newNode->setObject(inputObject);

	//INSERTION
	newNode->setNext(head);
	newNode->setLast(head->getLast());
	head->getLast()->setNext(newNode);
	head->setLast(newNode);
	cnt++;
}
template<typename T>
bool DLinklist<T>::compRemove(T obj, string getKey(T))
{
	ListNode<T>* NodePtr = head;
	if (cnt <= 0) return false;
	do {
		NodePtr = NodePtr->getNext();
		if (getKey(NodePtr->getObject()) == getKey(obj)) {

			//OVER CONNECT
			NodePtr->getLast()->setNext(NodePtr->getNext());
			NodePtr->getNext()->setLast(NodePtr->getLast());

			//REMOVE NODE
			delete NodePtr;
			cnt--;
			return true;
		}
	} while (NodePtr->getNext() != head);
	return false;
}
//-------------------------
//REMOVE
//This function removes content by index num
//Returns -1 if empty list
//Return 0 if out of range
//Return 1 if success
template<typename T>
int DLinklist<T>::remove(int index)
{
	//RANGE TEST
	if (index > cnt || index <= 0) {
		return 0;
	}
	//LIST TEST
	else if (cnt <= 0) {
		return -1;
	}
	//TEMINATION
	else {

		//SET PTR
		ListNode<T>* NodePtr = head;
		for (int i = 0; i < index; i++) {
			NodePtr = NodePtr->getNext();
		}

		//OVER CONNECT
		NodePtr->getLast()->setNext(NodePtr->getNext());
		NodePtr->getNext()->setLast(NodePtr->getLast());

		//REMOVE NODE
		delete NodePtr;
		cnt--;
		return 1;
	}
}

//-------------------------
//DestoryAll
//This functions eliminates all Nodes
template<typename T>
void DLinklist<T>::destoryAll()
{
	//PTRS
	ListNode<T>* Ptr = head->getNext();
	ListNode<T>* Ptr2;

	//Traverse and delete
	while (Ptr != head) {
		Ptr2 = Ptr->getNext();
		delete Ptr;
		Ptr = Ptr2;
	}

	//Reinitialize
	head->setLast(head);
	head->setNext(head);
	cnt = 0;
}

//-------------------------
//get
//This functions return the Nth element in the List by reference
//Returns -1 if empty list
//Return 0 if out of range
//Return 1 if success
template<typename T>
int DLinklist<T>::get(int index, T &output)
{
	//RANGE TEST
	if (index > cnt || index <= 0) {
		return 0;
	}
	//LIST TEST
	else if (cnt <= 0) {
		return -1;
	}
	//FIND VALUE
	else {

		//SET PTR
		ListNode<T>* NodePtr = head;
		for (int i = 0; i < index; i++) {
			NodePtr = NodePtr->getNext();
		}

		//RETURN VALUE
		output = NodePtr->getObject();
		return 1;
	}
}
#endif