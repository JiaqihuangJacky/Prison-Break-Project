//=========================================
//Queue template
//
//Modified by Chenglin Lu M1.0

//MEMBER FUCNTIONS

//bool enqueue(T input);
//bool dequeue(T &output);
//bool isEmpty() { return cnt == 0; }
//int  getCount() { return cnt; }
//bool peekHead(T &output);
//bool peekTail(T &output);
//void reverse();

//=========================================

#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H
#include <iostream>
using namespace std;


//-----------------------------------------
//Class Queue
//
template <class T>
class Queue
{
private:
	// Structure for the queue nodes
	struct QueueNode
	{
		T value;          // Value in the node
		QueueNode *next = NULL;  // Pointer to next node
	};

	QueueNode *head;    // Pointer to the queue front
	QueueNode *tail;     // Pointer to the queue rear
	int cnt;

public:
	//Constructor
	Queue() { head = tail = NULL; cnt = 0; }

	// Destructor
	~Queue();

	// Stack operations
	bool enqueue(T input);
	bool dequeue(T &output);
	bool isEmpty() { return cnt == 0; }
	int  getCount() { return cnt; }
	bool peekHead(T &output);
	bool peekTail(T &output);
	void reverse();
};

//===================================================================================
//Function definations

//---------------------------
//Destructer
template <class T>
Queue<T>::~Queue()
{
	QueueNode *currNode, *nextNode;

	// Position nodePtr at the top of the stack.
	currNode = head;

	// Traverse the list deleting each node.
	while (currNode) //while (currNode != NULL)
	{
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
}

//---------------------------
//Enqueue
//Push input into tail
template <class T>
bool Queue<T>::enqueue(T input)
{
	//CREATE NEW NODE
	QueueNode *newNode = new QueueNode;

	//If memory full
	if (!newNode) return false;

	//Setup Node
	newNode->value = input;

	// Update links and counter
	if (cnt == 0) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	cnt++;
	return true;
}

//---------------------------
//Dequeue
//Member function dequeue deletes the value at the front
//of the queue, and copies it into the variable
//passed as an argument.

template <class T>
bool Queue<T>::dequeue(T &output)
{
	//MainVars
	QueueNode *pDel = head;

	// empty queue
	if (cnt == 0) return false;

	// delete the value at the front of the queue
	output = head->value;

	if (cnt == 1) {
		head = tail = NULL;
	}else head = head->next;

	cnt--;
	delete pDel;

	return true;
}

//---------------------------
//peekHead
//Return value of head by reference, return 0 if empty queue;

template <class T>
bool Queue<T>::peekHead(T &output)
{
	if (cnt == 0) return false;
	else output = head->value;
	return true;
}


//---------------------------
//peekTail
//Return value of tail by reference, return 0 if empty queue;
template <class T>
bool Queue<T>::peekTail(T &output)
{
	if (cnt == 0) return false;
	else output = tail->value;
	return true;
}


//---------------------------
//reverse()
//wanna get fired by your boss, use this function
template<class T>
void Queue<T>::reverse()
{
	QueueNode *pNext = NULL;
	QueueNode *pPre = NULL;
	QueueNode *pCurr = head;
	tail = head;
	while (pCurr != NULL) {
		pNext = pCurr->next;
		pCurr->next = pPre;
		pPre = pCurr;
		pCurr = pNext;
	}
	head = pPre;
}
#endif