#ifndef PRIORITY_Q_hpp
#define PRIORITY_Q_hpp
#include <iostream>

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
	  ~Node(){
       if(next != nullptr)
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
	~PriorityQ();

	void enqueue(const T& item, const int lv);
	T dequeue();
	T peek();
private:
	
	bool is_MultilevelQ_empty();
	bool is_levelQ_empty(int lv);

	
	Node<T>* head_MultilevelQ[10];
	Node<T>* tail_MultilevelQ[10];


};




#include "PriorityQ.cpp.h"
#endif


