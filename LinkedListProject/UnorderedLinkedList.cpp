#include <iostream>
#include "UnorderedLinkedList.h"

using namespace std;

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
	nodeType<Type>* current; //pointer to traverse the list
	bool found = false;
	current = this->first; //set current to point to the first node
	while (current != nullptr && !found) //while more nodes to search and item not found
	{
		if (current->info == searchItem) //searchItem is found
			found = true;
		else
			current = current->link; //advance to the next node
	}
	return found;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type>* newNode; //pointer to create the new node
	newNode = new nodeType<Type>; //create the new node
	newNode->info = newItem; //store the new item in the node
	newNode->link = this->first; //insert newNode before first
	this->first = newNode; //make first point to the actual first node
	this->count++; //increment count
	if (this->last == nullptr) //if the list was empty, make last point to the new node
		this->last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	nodeType<Type>* newNode; //pointer to create the new node
	newNode = new nodeType<Type>; //create the new node
	newNode->info = newItem; //store the new item in the node
	newNode->link = nullptr; //set the link field of newNode to nullptr
	if (this->first == nullptr) //if the list is empty, make first and last point to the new node
	{
		this->first = newNode;
		this->last = newNode;
		this->count++; //increment count
	}
	else //the list is not empty
	{
		this->last->link = newNode; //insert newNode after last
		this->last = newNode; //make last point to the actual last node
		this->count++; //increment count
	}
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type>* current; //pointer to traverse the list
	nodeType<Type>* trailCurrent; //pointer just before current
	bool found;
	if (this->first == nullptr) //list is empty
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		if (this->first->info == deleteItem) //the item to be deleted is the first item
		{
			current = this->first;
			this->first = this->first->link;
			this->count--;
			if (this->first == nullptr) //list has only one node
				this->last = nullptr;
			delete current;
		}
		else //the item to be deleted is not the first item
		{
			found = false;
			trailCurrent = this->first; //set trailCurrent to point to the first node
			current = this->first->link; //set current to point to the second node
			while (current != nullptr && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}
			if (found) //the item to be deleted is found
			{
				trailCurrent->link = current->link;
				this->count--;
				if (this->last == current) //the last node is to be deleted
					this->last = trailCurrent; //update the value of last
				delete current; //delete the node from the list
			}
			else
				cout << "The item to be deleted is not in the list." << endl;
		}
	}
}