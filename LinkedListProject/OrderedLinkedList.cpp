
#include "OrderedLinkedList.h"

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
	nodeType<Type>* current; //pointer to traverse the list
	bool found = false;

	current = first; 
	while (current != nullptr && !found) //while more nodes to search and item not found
	{
		if (current->info = searchItem) //searchItem is found
			found = true;
		else
			current = current->link; //advance to the next node
	}

	if(found)
	{
		found = (current->info == searchItem);
	}
	return found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
	nodeType<Type>* current; //pointer to traverse the list
	nodeType<Type>* trailCurrent; //pointer just before current
	nodeType<Type>* newNode; //pointer to create a node
	bool found;
	newNode = new nodeType<Type>; //create the node
	newNode->info = newItem; //store the new item in the node
	if (first == nullptr) //list is empty
	{
		first = newNode;
		newNode->link = nullptr;
		last = newNode;
		this->count++;
	}
	else
	{
		current = first;
		found = false;
		while (current != nullptr && !found) //search the list
		{
			if (current->info >= newItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		}
		if (current == first) //insert at the beginning
		{
			newNode->link = first;
			first = newNode;
			this->count++;
		}
		else //insert somewhere after the first node
		{
			trailCurrent->link = newNode;
			newNode->link = current;
			if (current == nullptr) //insert at the end
				last = newNode;
			this->count++;
		}
	}
}

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
	insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type>* current; //pointer to traverse the list
	nodeType<Type>* trailCurrent; //pointer just before current
	bool found;
	if (first == nullptr) //list is empty
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		current = first;
		found = false;
		while (current != nullptr && !found) //search the list
		{
			if (current->info >= deleteItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		}
		if (current == nullptr) //reached the end of the list
			cout << "The item to be deleted is not in the list." << endl;
		else if (current->info == deleteItem) //item is found
		{
			if (current == first) //node to be deleted is the first node
			{
				first = first->link;
				if (first == nullptr) //list has only one node
					last = nullptr;
				delete current;
			}
			else //node to be deleted is not the first node
			{
				trailCurrent->link = current->link;
				if (current == last) //node to be deleted is the last node
					last = trailCurrent;
				delete current;
			}
			this->count--;
		}
		else //item is not found
			cout << "The item to be deleted is not in the list." << endl;
	}
}
