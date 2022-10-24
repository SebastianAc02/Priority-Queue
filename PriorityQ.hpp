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

	Node<T>* head_lvOne, * head_lvTwo, * head_lvThree, * head_lvFour, * head_lvFive, * head_lvSix, * head_lvSeven, * head_lvEight, * head_lvNine, * head_lvTen;
	Node<T>* tail_lvOne, * tail_lvTwo, * tail_lvThree, * tail_lvFour, * tail_lvFive, * tail_lvSix, * tail_lvSeven, * tail_lvEight, * tail_lvNine, * tail_lvTen;

    //Node<T>* head_MultilevelQ = [*head_lvOne, *head_lvTwo, *head_lvThree, *head_lvFour, *head_lvFive, *head_lvSix, *head_lvSeven, *head_lvEight, *head_lvNine, *head_lvTen];
    //Node<T>* tail_MultilevelQ = [*tail_lvOne, *tail_lvTwo, *tail_lvThree, *tail_lvFour, *tail_lvFive, *tail_lvSix, *tail_lvSeven, *tail_lvEight, *tail_lvNine, *tail_lvTen];

	Node<T>* head_MultilevelQ[10];
	Node<T>* tail_MultilevelQ[10];


};




#include "PriorityQ.cpp.h"
#endif

//#ifndef PRIORITY_Q_hpp
//#define PRIORITY_Q_hpp
//
//template <typename T>
//class Node
//{
//public:
//    T element;
//    Node<T>* next;
//
//    Node() {
//        next = nullptr;
//    }
//
//    Node(const T& element)
//    {
//        this->element = element;
//        next = nullptr;
//    }
//};
//
//template <typename T>
//class PriorityQ
//{
//public:
//    PriorityQ();
//    ~PriorityQ();
//
//    void enqueue(const T& item, const int lv) ;
//    T dequeue();
//    int getSize() const;
//    T peek();
//private:
//    Node<T>* front;
//    Node<T>* back;
//    int size;
//    int lv = 0;
//    void clear();
//    bool isEmpty();
//    Node<T>* lvOne;
//    Node<T>* lvTwo;
//    Node<T>* lvThree;
//    Node<T>* lvFour;
//    Node<T>* lvFive;
//    Node<T>* lvSix;
//    Node<T>* lvSeven;
//    Node<T>* lvEight;
//    Node<T>* lvNine;
//    Node<T>* lvTen;
//
//};
//
//
//#include "PriorityQ.cpp.h"
//#endif


