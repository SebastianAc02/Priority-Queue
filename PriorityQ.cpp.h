#include "PriorityQ.hpp"


template<typename T>
PriorityQ<T>::PriorityQ()
{
	head_lvOne = head_lvTwo = head_lvThree = head_lvFour = head_lvFive = head_lvSix = head_lvSeven = head_lvEight = head_lvNine = head_lvTen = nullptr;
	tail_lvOne = tail_lvTwo = tail_lvThree = tail_lvFour = tail_lvFive = tail_lvSix = tail_lvSeven = tail_lvEight = tail_lvNine = tail_lvTen = nullptr;

	//Highest priority is level 10
	head_MultilevelQ[9] = head_lvOne;
	head_MultilevelQ[8] = head_lvTwo;
	head_MultilevelQ[7] = head_lvThree;
	head_MultilevelQ[6] = head_lvFour;
	head_MultilevelQ[5] = head_lvFive;
	head_MultilevelQ[4] = head_lvSix;
	head_MultilevelQ[3] = head_lvSeven;
	head_MultilevelQ[2] = head_lvEight;
	head_MultilevelQ[1] = head_lvNine;
	head_MultilevelQ[0] = head_lvTen;


	tail_MultilevelQ[9] = tail_lvOne;
	tail_MultilevelQ[8] = tail_lvTwo;
	tail_MultilevelQ[7] = tail_lvThree;
	tail_MultilevelQ[6] = tail_lvFour;
	tail_MultilevelQ[5] = tail_lvFive;
	tail_MultilevelQ[4] = tail_lvSix;
	tail_MultilevelQ[3] = tail_lvSeven;
	tail_MultilevelQ[2] = tail_lvEight;
	tail_MultilevelQ[1] = tail_lvNine;
	tail_MultilevelQ[0] = tail_lvTen;

}


template<typename T>
PriorityQ<T>::~PriorityQ()
{
	    
    for ( int i = 0 ; i< 10 ; i++)
    {
       delete head_MultilevelQ[i];
        delete  tail_MultilevelQ[i];

    }
    
    
    head_lvOne = head_lvTwo = head_lvThree = head_lvFour = head_lvFive = head_lvSix = head_lvSeven = head_lvEight = head_lvNine = head_lvTen = nullptr;
    tail_lvOne = tail_lvTwo = tail_lvThree = tail_lvFour = tail_lvFive = tail_lvSix = tail_lvSeven = tail_lvEight = tail_lvNine = tail_lvTen = nullptr;



}

template<typename T>
void PriorityQ<T>::enqueue(const T& element, const int lv)
{
	if (lv < 1 || lv > 10)
		throw out_of_range("Priority lv must be between [1, 10]");

	if (head_MultilevelQ[lv - 1] == nullptr)
		head_MultilevelQ[lv - 1] = new Node<T>(element);
	else {
		tail_MultilevelQ[lv - 1]->next = new Node<T>(element);
		tail_MultilevelQ[lv - 1] = tail_MultilevelQ[lv - 1]->next;
	}


}
template <typename T>
T PriorityQ<T>::dequeue() {
	if (is_MultilevelQ_empty()) {
		throw runtime_error("Queue is empty");
	}

	//check from the highest priority lv
	for (unsigned int i = 9; ; i--) //condition of for-loop is left intentionally
	{
		if (head_MultilevelQ[i] != nullptr) // if(MultilevelQ is NOT empty - as checked above). This if condition must be met
		{
			Node<T>* temp_head_lv = head_MultilevelQ[i];
			head_MultilevelQ[i] = head_MultilevelQ[i]->next;

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
bool PriorityQ<T>::is_levelQ_empty(int lv) {
	if (lv < 1 || lv > 10)
		throw out_of_range("Priority lv must be between [1, 10]");

	Node<T>* temp_head_lv = head_MultilevelQ[lv - 1];
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
	for (unsigned int i = 9; ; i--) //condition of for-loop is left intentionally
	{
		if (head_MultilevelQ[i] != nullptr) // if(MultilevelQ is NOT empty - as checked above). This if condition must be met
		{
			return head_MultilevelQ[i]->element;
		}
	}


}

