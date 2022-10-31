#ifndef PRIORITY_Q_hpp
#define PRIORITY_Q_hpp
#include <iostream>

const int MAX_NUM_OF_LEVEL = 10;
using namespace std;

template <typename T>
class Node
{
public:
	T element;
	Node<T>* next;

	Node() {
		next = nullptr;
	}

	Node(const T& element)
	{
		this->element = element;
		next = nullptr;
	}

	~Node()
	{
		if (next != nullptr)
		{
			delete next;
			next = nullptr;
		}
	}

};



template <typename T>
class PriorityQ
{
public:
	PriorityQ();
	virtual ~PriorityQ();
	PriorityQ(const PriorityQ<T>& anotherQ);
	PriorityQ(PriorityQ<T>&& anotherQ);


	void enqueue(const T& item, const int lv);
	T dequeue();
	T peek();

	PriorityQ<T>& operator= (const PriorityQ<T>& anotherQ);
	PriorityQ<T>& operator= (PriorityQ<T>&& anotherQ);

	static Node<T>* copy(Node<T>* head, Node<T>* tail);
	void clear();


	/* to_be_implemented
	* operator= & move operator=
	* Copy & Move constructors
	*/

private:

	bool is_MultilevelQ_empty();
	bool is_levelQ_empty(int lv);

	Node<T>* head_MultilevelQ[MAX_NUM_OF_LEVEL];
	Node<T>* tail_MultilevelQ[MAX_NUM_OF_LEVEL];
};

#include "PriorityQ.cpp.h"
#endif


