#pragma once


template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type>* link;
};

template <class Type>
class linkedListIterator
{
private:
	nodeType<Type>* current; //pointer to point to the current node in the linked list

public:
	linkedListIterator();
	linkedListIterator(nodeType<Type>* ptr);
	Type operator*();
	linkedListIterator<Type> operator++();
	bool operator==(const linkedListIterator<Type>& right) const;
	bool operator!=(const linkedListIterator<Type>& right) const;
};

template <class Type>
class linkedListType
{
private:
	void copyList(const linkedListType<Type>& otherList);
protected:
	int count; //variable to store the number of nodes in the list
	nodeType<Type>* first; //pointer to the first node of the list
	nodeType<Type>* last; //pointer to the last node of the list

public:
	const linkedListType<Type>& operator=(const linkedListType<Type>&);
	void initializeList();
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void DestroyList();
	Type front() const;
	Type back() const;
	virtual bool search(const Type& searchItem) const = 0;
	virtual void insertFirst(const Type& newItem) = 0;
	virtual void insertLast(const Type& newItem) = 0;
	virtual void deleteNode(const Type& deleteItem) = 0;
	linkedListIterator<Type> begin();
	linkedListIterator<Type> end();
	linkedListType();
	linkedListType(const linkedListType<Type>& otherList);
	~linkedListType();
};
