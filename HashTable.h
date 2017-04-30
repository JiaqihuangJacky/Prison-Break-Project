//Powered by Jun Li& JiaQi Huang
//Modified By Niko
//V2.0

#ifndef _HASH_TABLE
#define _HASH_TABLE
#include <iostream>
#include <iomanip>
#include <vector>
#include "DLinklist.h"

using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                               HASH TABLE V2

const int ARRAY_SIZE = 5;// arraysize of each bucket
const int DEFAULT_TABLE_SIZE = 1;//default of tablesize

template <class T>
class HashTable
{
private:

	//private variables:
	struct Bucket // might be a class
	{
		int count;//counter of items in an bucket's array.
		T** bucketArray;// pointer to the pointr to bucketArray
	} *hashArray;

	int table_size;//table size variables

	DLinklist<T*> *extendedList; // extended table -- linked list

	int _count;//total # of objects in the file
	int list_count; // total # of objects in list
	int _collisions;// collision counter
	int _maxSize; // hold the ARRAY_SIZE;
	int _rehashCounter;


	//private member functions:
	int findPos(string key);// hash the index function
	bool isPrime(int n);//check for prime number function
	int findNextPrime(int n);//get the nextprime number function
	void rehash(string getKey(T *item));// rehash function

public:
	HashTable();//constructor
	~HashTable() { destroyTable(); }//deconstructor

									//--------basic hash table function
	bool insertItem(T *newItem, string getKey(T *item));//insertion function
	bool removeItem(string getKey(T *item), T *item);//removing items function
	bool searchByKey(string getKey(T *item), T *item, T &returnedItem);//search function
	int getSize() { return _maxSize; }//get the max size function
	int getCount() { return _count; }//get the total number in the file or table
	int getCollisions() { return _collisions; }//get the number of coliision
	void destroyTable();// destory all the items

						// hash table statisticfunction
	void printHistogram(string getKey(T *item));//print Histogram
	double calcLoadFactor();//calculate the load factor
	double calcTotalLoadFactor();//calculate the total factor
	double calcAverageCollision();//calculate the average collison number
	int calcLongestCollision();// calculate the longest collision in the hash table
	int calcOverFlowArea();// calculate the overflow area's numbers
	void displayStatistic();// display statistic
	void displaySortByKey(void visit(T &)); // display the order

};//end of class

  /////////////////////////Definition of private member functions: ////////////////////////

  //***************************************************************
  // findPos function
  // convert the key to index -- find the position
  //***************************************************************
template <class T>
int HashTable<T>::findPos(string key)
{
	int sum = 0;
	for (int i = 0; i < key.length(); i++)
		sum += (int)key[i] * (int)key[i];
	return  sum % table_size;
}


//***************************************************************
// destroyTable function
// Destroy the table and called by destructor
//***************************************************************
template <class T>
void HashTable<T>::destroyTable()
{
	for (int i = 0; i < table_size; i++)
		delete[]hashArray[i].bucketArray;

	delete[]hashArray;

	if (extendedList != 0)
		delete extendedList;


	//reset all the counter = 0
	_collisions = 0;
	_count = 0;
	list_count = 0;
	_rehashCounter = 0;


	//cout << "collisions: " << _collisions << endl;
	//cout << "count: "<<_count  << endl;
	//cout << "list_count " << list_count << endl;

}

//***************************************************************
// isPrime function
// Decide if the passed int is a prime number and return bool
//***************************************************************
template <class T>
bool HashTable<T>::isPrime(int n)
{
	if (n <= 1)
		return false;
	else if (n <= 3)
		return true;
	else if (n % 2 == 0 || n % 3 == 0)
		return false;

	int i = 5;
	while (i*i <= n)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
		i = i + 6;
	}
	return true;
}

//***************************************************************
// findNextPrime function
// Find the next prime number of the passed integer
//***************************************************************
template <class T>
int HashTable<T>::findNextPrime(int n)
{
	while (!isPrime(n++));
	return n - 1;
}

//***************************************************************
// rehash function
// rehash the table using a table size greater twice of old size
//***************************************************************
template <class T>
void HashTable<T>::rehash(string getKey(T *item))
{
	// Keep old table address and data
	_rehashCounter++;
	int oldSize = table_size;
	Bucket *oldHashArray = hashArray;
	DLinklist<T*> *oldList = extendedList;

	table_size = findNextPrime(oldSize * 2);
	_count = 0;
	_collisions = 0;

	//Allocate new table
	hashArray = new Bucket[table_size];
	for (int i = 0; i < table_size; i++)
		hashArray[i].bucketArray = new T*[ARRAY_SIZE];

	for (int i = 0; i < table_size; i++)
	{
		hashArray[i].count = 0;
		for (int j = 0; j < ARRAY_SIZE; j++)
			hashArray[i].bucketArray[j] = 0;
	}

	extendedList = new DLinklist<T*>;

	//insert data from old table to new table
	for (int i = 0; i < oldSize; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			if (oldHashArray[i].bucketArray[j] != 0)
				insertItem(oldHashArray[i].bucketArray[j], getKey);
		}
	}

    //insert data from old list to new list
	for (int i = 1;i <= oldList->getCount();i++) {
		T* tempPtr;
		oldList->get(i, tempPtr);
		extendedList->add(tempPtr);
	}

	//delete old table
	for (int i = 0; i < oldSize; i++)
		delete[]oldHashArray[i].bucketArray;

	delete[]oldHashArray;

	if (oldList != 0)
		delete oldList;
}

/////////////////////////public functions////////////////////////

//***************************************************************
// Constructor
//  - Set all the counters to 0
//  - Set all the pointers to 0
//***************************************************************
template <class T>
HashTable<T>::HashTable()
{
	table_size = DEFAULT_TABLE_SIZE;//initilize the table size

	hashArray = new Bucket[table_size];

	for (int i = 0; i<table_size; i++)
		hashArray[i].bucketArray = new T*[ARRAY_SIZE];

	for (int i = 0; i < table_size; i++)
	{
		hashArray[i].count = 0;
		for (int j = 0; j < ARRAY_SIZE; j++)
			hashArray[i].bucketArray[j] = 0;
	}

	extendedList = new DLinklist<T*>;//create an new list for overflow area


										  //initialize the private variables

	_collisions = 0;
	_maxSize = ARRAY_SIZE;
	_count = 0;
	list_count = 0;
	_rehashCounter = 0;
}

//***************************************************************
// insertItem function
// insert an item to the function
//***************************************************************
template <class T>
bool HashTable<T>::insertItem(T *newItem, string getKey(T *item))
{
	int index = findPos(getKey(newItem));// hash an index

										 //cout  << "Pig: "<< getKey(newItem) << endl;						 //go over the hash array in index
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		// if bucketArray is empty
		if (hashArray[index].bucketArray[i] == NULL)
		{
			hashArray[index].bucketArray[i] = newItem;//assgin an newItem

			//cout << "I insert " << getKey(newItem) << " in bucket " << index << endl;

			hashArray[index].count++;//increment the counter
			_count++;

			if (hashArray[index].count > 1)
				_collisions++;

			if (calcLoadFactor() > 0.75)
			{
				rehash(getKey);
			}

			return true;
		}
	}

	extendedList->add(newItem);
	//cout << "I insert " << getKey(newItem) << " in LIST " << endl;
	hashArray[index].count++;
	_count++;
	_collisions++;
	list_count++;
	return true;

}

//***************************************************************
// removeItem function
// Delete an Item by key from the Hash Table.
// Return true if the operation is successful.
//***************************************************************
template <class T>
bool HashTable<T>::removeItem(string getKey(T *item), T *item)
{
	int index = findPos(getKey(item));

	if (hashArray[index].count == 0)
		return false;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (hashArray[index].bucketArray[i] != 0)
		{
			if (getKey(hashArray[index].bucketArray[i]) == getKey(item))
			{
				hashArray[index].bucketArray[i] = NULL; // delete
				hashArray[index].count--; //decrement counter

				_count--;
				if (hashArray[index].count > 1)
					_collisions--;

				cout << "\n- " << getKey(item) << " removed!" << endl;

				return true;
			}
		}
	}

	if (extendedList->getCount() != 0)
	{
		for (int i = 1;i <= extendedList->getCount();i++) {
			T* tempPtr;
			extendedList->get(i, tempPtr);
			if (getKey(tempPtr) == getKey(item)) {
				extendedList->remove(i);
				hashArray[index].count--;
				_count--;
				_collisions--;
				list_count--;
				cout << getKey(item) << "removed!!" << endl;
				return true;
			}
		}
	}
	return false;
}

//***************************************************************
// searchByKey function
// Search an item by key and return it as reference parameter
// Return true if the operation is successful.
//***************************************************************
template <class T>
bool HashTable<T>::searchByKey(string getKey(T *item), T *item, T &returnedItem)
{
	int index = findPos(getKey(item));//position found

									  //cout << "Index :" << index;

	if (hashArray[index].count == 0)
		return false;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (hashArray[index].bucketArray[i] != 0)
		{
			if (getKey(hashArray[index].bucketArray[i]) == getKey(item))
			{
				returnedItem = *(hashArray[index].bucketArray[i]);
				//cout << returnedItem << endl;
				return true;
			}
		}
	}

	if (extendedList->getCount() != 0)
	{
		for (int i = 1;i <= extendedList->getCount();i++) {
			T* tempPtr;
			extendedList->get(i, tempPtr);
			if (getKey(tempPtr) == getKey(item)) {
				returnedItem = *tempPtr;
				return true;
			}
		}
	}

	//cout << getKey(item) << " Not found!" << endl;
	return false;
}


/////////////////////////Statistic functions////////////////////////

//***************************************************************
// printHistogram function
// Print table in format.
//***************************************************************
template <class T>
void HashTable<T>::printHistogram(string getKey(T *item))
{
	cout << "\n\n--------------------------------Hash Table"
		<< "----------------------------------\n\n";

	for (int i = 0; i < table_size; i++)
	{
		cout << setw(5) << i + 1 << ":  ";
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			if (hashArray[i].bucketArray[j] == NULL)
				cout << "  " << "  " << " ";
			else
				cout << "  " << getKey(hashArray[i].bucketArray[j]) << " ";
			//cout << " " << "X" << " ";
		}
		cout << "" << hashArray[i].count;

		if (hashArray[i].count == 0)
			cout << "                ";
		else if (hashArray[i].count == 1)
			cout << "  No collision  ";
		else
			cout << "  Collision:" << hashArray[i].count - 1 << "  ";

		if (hashArray[i].count == 0)
			cout << " Empty Bucket";
		else if (hashArray[i].count > 4)
			cout << "  Full Bucket";
		cout << endl;
	}
	cout << "----------------------------------------------------------"
		<< "------------------" << endl;
}

//***************************************************************
// calcLoadFactor function
// Calculate load factor.
//***************************************************************
template<class T>
double HashTable<T>::calcLoadFactor()
{

	return 1.0 * (_count - _collisions) / table_size;//_maxsize is arraysize = 5

}

//***************************************************************
// calcTotalLoadFactor function
// Calculate load factor.
//***************************************************************
template<class T>
double HashTable<T>::calcTotalLoadFactor()
{
	return (1.0 * (_count - list_count)) / (table_size * ARRAY_SIZE);
}


//***************************************************************
// calMostRepeatIndex function
// Calculate the most repeated index
//***************************************************************
template <class T>
int HashTable<T>::calcLongestCollision()
{
	int length;
	int hiLength = 0;

	for (int i = 0; i < table_size; i++)
	{

		if (hashArray[i].count != 0)
		{
			length = hashArray[i].count;
			if (length > hiLength)
				hiLength = length;
		}//end if
	}//end for
	return hiLength - 1;
}

//***************************************************************
// calcAverageCollision function
// Calculate the average the occupy of index
//***************************************************************
template <class T>
double HashTable<T>::calcAverageCollision()
{
	int sum = 0;

	for (int i = 0; i < table_size; ++i)
	{
		//cout << hashArray[i].count << endl;
		if (hashArray[i].count != 0)
			sum += (hashArray[i].count - 1); // exclude the first element
	}
	return 1.0 * sum / table_size;
}



//***************************************************************
// calcTotalLoadFactor function
// Calculate load factor.
//***************************************************************
template<class T>
int HashTable<T>::calcOverFlowArea()
{
	return list_count;
}


//***************************************************************
// displayStatistic function
// display all the Statistic in hash table .
//***************************************************************
template<class T>
void HashTable<T>::displayStatistic()
{
	cout << "\n\n--------------------Displaying Statistic in Hash Table"
		<< "----------------------\n";

	cout << "\nTotal items: " << _count << endl
		<< "Total Collisions: " << _collisions << endl;

	cout << "Load Factor: "
		<< setprecision(2) << fixed << calcLoadFactor() * 100 << "%" << endl
		<< "Total Load Factor: "
		<< calcTotalLoadFactor() * 100 << "%" << endl;

	cout << "The average collision: " << calcAverageCollision() << endl;
	cout << "The longest collision: " << calcLongestCollision() << endl;
	cout << "The overFlowArea: " << calcOverFlowArea() << endl;
	cout << "The rehash counter: : " << _rehashCounter << endl;
	if (_rehashCounter>0) cout << "Current Table size : " << table_size << endl;
	cout << "------------------------------------------------------"
		<< "----------------------" << endl;
	cout << "\n" << endl;

}

//


template <class T>
void HashTable<T>::displaySortByKey( void visit(T&))
{

	for (int i = 0; i < table_size; i++)
	{

		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			if (hashArray[i].bucketArray[j] != NULL)
				visit( *hashArray[i].bucketArray[j]);
		}

	}

	if (extendedList->getCount() != 0)
	{
		for (int i = 1;i <= extendedList->getCount();i++) {
			T* tempPtr;
			extendedList->get(i, tempPtr);
			visit(*tempPtr);
		}
	}
}
#endif
