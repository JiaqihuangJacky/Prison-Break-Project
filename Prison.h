#ifndef PRISON
#define PRISON

//V1.1
#include "Criminals.h"
#include "DLinklist.h"
#include "BinarySearchTree.h"
#include "HashTable.h"

struct Prison
{
	HashTable<Prisoner>* id_Base;
	BinarySearchTree<Prisoner>* name_Base;
	BinarySearchTree<Prisoner>* sortedID_Base;
	DLinklist<Prisoner*>* prisoner_Base;
}; 

#endif