#include "PriorityQ.hpp"


template<typename T>
PriorityQ<T>::PriorityQ()
{
	for (int i = 0; i < 10; i++)
	{
		head_MultilevelQ[i] = nullptr;
		tail_MultilevelQ[i] = nullptr;
	}
}


template<typename T>
PriorityQ<T>::~PriorityQ()
{
	for (int i = 0; i < 10; i++)
	{
		delete head_MultilevelQ[i] = nullptr;
		delete tail_MultilevelQ[i] = nullptr;
	}
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

