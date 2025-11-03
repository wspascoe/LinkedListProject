#pragma once

#include "LinkedListType.h"

template <class Type>
class orderedLinkedList : public linkedListType<Type>
{
	public:
	bool search(const Type& searchItem) const override;
	void insert(const Type& newItem);
	void insertFirst(const Type& newItem) override;
	void insertLast(const Type& newItem) override;
	void deleteNode(const Type& deleteItem) override;
};