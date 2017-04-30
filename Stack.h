//=========================================
//Stack template
//
//Modified by Chenglin Lu M1.0

//MEMBER FUCNTIONS

//bool push(T input)        
//bool pop(T &output)
//bool peek(T &output)
//void reverse()
//bool isEmpty()
//int getCount()

//=========================================


#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H
#include <iostream>
using namespace std;

//-----------------------------------------
//Class Stack
//
template <class T>
class Stack
{
private:
	// Structure for the stack nodes
	struct StackNode
	{
		T value;          // Value in the node
		StackNode *next = NULL;  // Pointer to next node
	};

	StackNode *head;     // Pointer to the stack top
	int cnt;

public:
	//Constructor
	Stack() { head = NULL; cnt = 0; }

	// Destructor
	~Stack();

	// Stack operations
	bool push(T input);
	bool pop(T &output);
	bool peek(T &output);
	void reverse();
	bool isEmpty() { return cnt == 0; }
	int getCount() { return cnt; }
};




//===================================================================================
//Function definations

//---------------------------
//Destructer

template <class T>
Stack<T>::~Stack()
{
	StackNode *currNode, *nextNode;
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
//Push
//Member function push pushes the argument onto stack

template <class T>
bool Stack<T>::push(T input)
{
	//A brand new node
	StackNode *newNode = new StackNode;

	//If memory full
	if (!newNode) return false;

	//Setup Node
	newNode->value = input;

	// Update links and counter
	newNode->next = head;
	head = newNode;
	cnt++;
	return true;
}

//---------------------------
//Pop
//Member function pop pops the value at the top
//of the stack off, and copies it into the variable
//passed as an argument.

template <class T>
bool Stack<T>::pop(T &output)
{
	//Vars
	StackNode *ptr;

	//If empty stack or program is being hacked, say no.
	if (cnt <= 0) return false;

	// pop value off top of stack
	output = head->value;
	ptr = head->next;
	delete head;
	head = ptr;
	cnt--;
	return true;
}

//---------------------------
//Peek
//Return the value of head by reference secretly
//If no elements at all, return false, or something s going on, like being hacked.

template<class T>
bool Stack<T>::peek(T &output) 
{
	if (cnt <= 0) return false;
	else output = head->value;
	return true;
}

/*------------------
Reverse
Reverse the whole list.
*/
template<class T>
void Stack<T>::reverse() {

	StackNode* pNext = NULL;
	StackNode* pPre = NULL;
	StackNode* pCurr = head;
	while (pCurr != NULL) {
		pNext = pCurr->next;
		pCurr->next = pPre;
		pPre = pCurr;
		pCurr = pNext;
	}
	head = pPre;
}
#endif