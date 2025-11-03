#include "LinkedListType.h"
#include <iostream>
using namespace std;

//Linked List Iterator Implementation
template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
	current = nullptr;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type>* ptr)
{
	current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
	return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
	current = current->link;
	return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
	return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
	return (current != right.current);
}
//End of Linked List Iterator Implementation

template<class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
	DestroyList(); //if the list is nonempty, make it empty
	if (otherList.firstNode == nullptr) //otherList is empty
	{
		firstNode = nullptr;
		lastNode = nullptr;
		count = 0;
	}
	else
	{
		nodeType<Type>* current; //pointer to traverse the otherList
		current = otherList.firstNode; //set current to point to the first node of otherList
		count = otherList.count;
		//copy the first node
		nodeType<Type>* newNode; //pointer to create a node
		newNode = new nodeType<Type>; //create the node
		newNode->info = current->info; //copy the info
		newNode->link = nullptr; //set the link field of the node to nullptr
		firstNode = newNode; //make first point to the first node
		lastNode = newNode; //make last point to the last node
		current = current->link; //advance current to the next node
		//copy the remaining nodes
		while (current != nullptr)
		{
			newNode = new nodeType<Type>; //create a node
			newNode->info = current->info; //copy the info
			newNode->link = nullptr; //set the link of the new node to nullptr
			lastNode->link = newNode; //attach newNode after last
			lastNode = newNode; //make last point to the actual last node
			current = current->link; //advance current to the next node
		}
	}
}

//Linked List Type Implementation
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
	if (this != &otherList) //avoid self-copy
	{
		copyList(otherList);
	}
	return *this;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
	DestroyList();
}

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return (firstNode == nullptr);
}

template <class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type>* current; //pointer to traverse the list
	current = firstNode; //set current to point to the first node
	while (current != nullptr) //while more nodes to print
	{
		cout << current->info << " ";
		current = current->link;
	}
}

template <class Type>
int linkedListType<Type>::length() const
{
	return count;
}

template <class Type>
void linkedListType<Type>::DestroyList()
{
	nodeType<Type>* temp; //pointer to deallocate the memory
	while (firstNode != nullptr) //while there are nodes in the list
	{
		temp = firstNode; //set temp to point to the current node
		firstNode = firstNode->link; //advance first to the next node
		delete temp; //deallocate the memory occupied by temp
	}
	lastNode = nullptr; //initialize last to nullptr
	count = 0;
}

template <class Type>
Type linkedListType<Type>::front() const
{
	assert(firstNode != nullptr); //list is not empty
	return firstNode->info; //return the info of the first node
}

template <class Type>
Type linkedListType<Type>::back() const
{
	assert(lastNode != nullptr); //list is not empty
	return lastNode->info; //return the info of the last node
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
	linkedListIterator<Type> temp(firstNode);
	return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
	linkedListIterator<Type> temp(nullptr);
	return temp;
}

template <class Type>
linkedListType<Type>::linkedListType()
{
	firstNode = nullptr;
	lastNode = nullptr;
	count = 0;
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
	firstNode = nullptr;
	lastNode = nullptr;
	count = 0;
	copyList(otherList);
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
	DestroyList();
}
//End of Linked List Type Implementation