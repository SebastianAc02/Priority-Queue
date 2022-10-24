#include "PriorityQ.hpp"


template<typename T>
PriorityQ<T>::PriorityQ()
{
    head_lvOne = head_lvTwo = head_lvThree = head_lvFour = head_lvSix = head_lvSeven = head_lvEight = head_lvNine = head_lvTen = nullptr;
    tail_lvOne = tail_lvTwo = tail_lvThree = tail_lvFour = tail_lvSix = tail_lvSeven = tail_lvEight = tail_lvNine = tail_lvTen = nullptr;
    
    head_MultilevelQ[0] = head_lvOne;
    head_MultilevelQ[1] = head_lvTwo;
    head_MultilevelQ[2] = head_lvThree;
    head_MultilevelQ[3] = head_lvFour;
    head_MultilevelQ[4] = head_lvFive;
    head_MultilevelQ[5] = head_lvSix;
    head_MultilevelQ[6] = head_lvSeven;
    head_MultilevelQ[7] = head_lvEight;
    head_MultilevelQ[8] = head_lvNine;
    head_MultilevelQ[9] = head_lvTen;
    
  
    tail_MultilevelQ[0] = tail_lvOne;
    tail_MultilevelQ[1] = tail_lvTwo;
    tail_MultilevelQ[2] = tail_lvThree;
    tail_MultilevelQ[3] = tail_lvFour;
    tail_MultilevelQ[4] = tail_lvFive;
    tail_MultilevelQ[5] = tail_lvSix;
    tail_MultilevelQ[6] = tail_lvSeven;
    tail_MultilevelQ[7] = tail_lvEight;
    tail_MultilevelQ[8] = tail_lvNine;
    tail_MultilevelQ[9] = tail_lvTen;
    
}


template<typename T>
PriorityQ<T>::~PriorityQ()
{
  
}

template<typename T>
void PriorityQ<T>::enqueue(const T& element, const int lv)
{
    if (lv < 1 || lv > 10)
        throw out_of_range("Priority lv must be between [1, 10]");

    //access priority lv by lv-arg
    Node<T>* temp_head_lv = head_MultilevelQ[lv - 1];
    Node<T>* temp_tail_lv = tail_MultilevelQ[lv - 1];

    if (temp_head_lv == nullptr)
        temp_head_lv = temp_tail_lv = new Node<T>(element);
    else
    {
        temp_tail_lv->next = new Node<T>(element);
        temp_tail_lv = temp_tail_lv->next;
    }
    //new
    //Node<T>* temp_head_lv = new Node<T>(element);


}
template <typename T>
T PriorityQ<T>::dequeue() {
    if (is_MultilevelQ_empty()) {
        throw runtime_error("Queue is empty");
    }

    //check from the highest priority lv
    for (unsigned int i = 0; ; i++) //condition of for-loop is left intentionally
    {
        if (head_MultilevelQ[i] != nullptr) // if(MultilevelQ is NOT empty - as checked above). This if condition must be met
        {
            Node<T>* temp_head_lv = head_MultilevelQ[i];
            temp_head_lv = temp_head_lv->next;

            T dequeued_element = temp_head_lv->element;
            delete temp_head_lv;
            temp_head_lv = nullptr;

            return dequeued_element;
        }
    }
}

template <typename T>
bool PriorityQ<T>::is_MultilevelQ_empty() {
    //check through every level if each Q is empty (empty == nulltr)
    for (unsigned int i = 0; head_MultilevelQ[i] != nullptr; i++)
        return true;
    //else
    return false;
}

template <typename T>
bool PriorityQ<T>::is_levelQ_empty(int lv){
    if (lv < 1 || lv > 10)
        throw out_of_range("Priority lv must be between [1, 10]");

    Node<T>* temp_head_lv = head_MultilevelQ[lv-1];
    if (temp_head_lv == nullptr)
        return true;
    else
        return false;
}



template <typename T>
T PriorityQ<T>::peek() {

    if (is_MultilevelQ_empty()) {
        throw runtime_error("Queue is empty");
    }
 
    //check from the highest priority lv
    for (unsigned int i = 0; ; i++) //condition of for-loop is left intentionally
    {
        if (head_MultilevelQ[i] != nullptr) // if(MultilevelQ is NOT empty - as checked above). This if condition must be met
        {
           return head_MultilevelQ[i]->element;
        }
    }
  

}


//#include "PriorityQ.hpp"
//#include <iostream>
//
//using namespace std;
//
//template<typename T>
//PriorityQ<T>::PriorityQ()
//{
//    front = back = nullptr;
//    lvOne = lvTwo = lvThree = lvFour = lvSix = lvSeven = lvEight = lvNine = lvTen = nullptr;
//    size = 0;
//}
//
//
//template<typename T>
//PriorityQ<T>::~PriorityQ()
//{
//    clear();
//}
//
//template<typename T>
//void PriorityQ<T>::enqueue(const T& element, const int lv)
//{
//    if(front == nullptr)
//        front = back = new Node<T>(element);
//    else
//    {
//        back->next = new Node<T>(element);
//        back = back->next;
//    }
//    size++;
//}
//template <typename T>
//T PriorityQ<T>::dequeue() {
//    if (isEmpty()) {
//        throw runtime_error("Queue is empty");
//    }
//    else {
//        Node<T>* temp = front;
//        front = front->next;
//        if (front == nullptr) { //if front get assigned to nullptr after doing front = front->next
//            back = nullptr;
//        }
//
//        T element = temp->element;
//        delete temp;
//        temp = nullptr;
//        size--;
//        return element;
//    }
//}
//template <typename T>
//bool PriorityQ<T>::isEmpty() {
//    if (front == nullptr && back == nullptr )
//        return true;
//    else
//        return false;
//
//}
//
//
//template <typename  T>
//void PriorityQ<T>::clear(){
//    
//    delete front ;
//    
//}
//
//template <typename T>
//T PriorityQ<T>::peek(){
//    
//    // if this is not empty
//    if(front != nullptr)
//        return front -> element ;
//    else
//        return 0;
// 
//
//}
//
