#include "PriorityQ.hpp"
#include <iostream>

using namespace std;

template<typename T>
PriorityQ<T>::PriorityQ()
{
    front = back = nullptr;
    lvOne = lvTwo = lvThree = lvFour = lvSix = lvSeven = lvEight = lvNine = lvTen = nullptr;
    size = 0;
}


template<typename T>
PriorityQ<T>::~PriorityQ()
{
    clear();
}

template<typename T>
void PriorityQ<T>::enqueue(const T& element, const int lv)
{
    if(front == nullptr)
        front = back = new Node<T>(element);
    else
    {
        back->next = new Node<T>(element);
        back = back->next;
    }
    size++;
}
template <typename T>
T PriorityQ<T>::dequeue() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty");
    }
    else {
        Node<T>* temp = front;
        front = front->next;

        T element = temp->element;
        delete temp;
        temp = nullptr;
        size--;
        return element;
    }
}
template <typename T>
bool PriorityQ<T>::isEmpty() {
    if (front == nullptr && back == nullptr )
        return true;
    else
        return false;

}


template <typename  T>
void PriorityQ<T>::clear(){
    
    delete front ;
    
}

template <typename T>
T PriorityQ<T>::peek(){
    
    // if this is not empty
    if(front != nullptr)
        return front -> element ;
    else
        return 0;
 

}

