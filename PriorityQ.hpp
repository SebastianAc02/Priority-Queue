#ifndef PRIORITY_Q_hpp
#define PRIORITY_Q_hpp

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

    void enqueue(const T& item, const int lv) ;
    T dequeue();
    int getSize() const;
    T peek();
private:
    Node<T>* front;
    Node<T>* back;
    int size;
    int lv = 0;
    void clear();
    bool isEmpty();
    Node<T>* lvOne;
    Node<T>* lvTwo;
    Node<T>* lvThree;
    Node<T>* lvFour;
    Node<T>* lvFive;
    Node<T>* lvSix;
    Node<T>* lvSeven;
    Node<T>* lvEight;
    Node<T>* lvNine;
    Node<T>* lvTen;

};


#include "PriorityQ.cpp.h"
#endif


