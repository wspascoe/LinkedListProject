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
	return (first == nullptr);
}

template <class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type>* current; //pointer to traverse the list
	current = first; //set current to point to the first node
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
	while (first != nullptr) //while there are nodes in the list
	{
		temp = first; //set temp to point to the current node
		first = first->link; //advance first to the next node
		delete temp; //deallocate the memory occupied by temp
	}
	last = nullptr; //initialize last to nullptr
	count = 0;
}

template <class Type>
Type linkedListType<Type>::front() const
{
	assert(first != nullptr); //list is not empty
	return first->info; //return the info of the first node
}

template <class Type>
Type linkedListType<Type>::back() const
{
	assert(last != nullptr); //list is not empty
	return last->info; //return the info of the last node
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
	linkedListIterator<Type> temp(first);
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
	first = nullptr;
	last = nullptr;
	count = 0;
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
	first = nullptr;
	last = nullptr;
	count = 0;
	copyList(otherList);
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
	DestroyList();
}
//End of Linked List Type Implementation