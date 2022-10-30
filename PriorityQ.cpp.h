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
PriorityQ<T>::PriorityQ(const PriorityQ<T>& anotherQ)
{
	for (int i = 0; i < MAX_NUM_OF_LEVEL; i++)
	{
		head_MultilevelQ[i] = copy(anotherQ.head_MultilevelQ[i], anotherQ.tail_MultilevelQ[i]);
	}
}


template <typename T>
PriorityQ<T>::PriorityQ(PriorityQ<T>&& anotherQ)
{
	for (int i = 0; i < MAX_NUM_OF_LEVEL; i++)
	{
		head_MultilevelQ[i] = anotherQ.head_MultilevelQ[i];
		tail_MultilevelQ[i] = anotherQ.tail_MultilevelQ[i];
	}
}


template<typename T>
PriorityQ<T>::~PriorityQ()
{
	clear();
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
	for (unsigned int i = MAX_NUM_OF_LEVEL - 1; ; i--) //condition of for-loop is left intentionally
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
T PriorityQ<T>::peek() const {

	if (is_MultilevelQ_empty())
		throw runtime_error("Queue is empty");

	//check from the highest priority lv
	for (unsigned int i = 9; ; i--) //condition of for-loop is left intentionally
	{
		if (head_MultilevelQ[i] != nullptr) // if(MultilevelQ is NOT empty - as checked above). This if condition must be met
		{
			return head_MultilevelQ[i]->element;
		}
	}
}


template <typename T>
PriorityQ<T>& PriorityQ<T>::operator= (const PriorityQ<T>& anotherQ)
{
	clear();
	if (this != &anotherQ)
	{
		for (unsigned int i = 0; i < MAX_NUM_OF_LEVEL; i++)
			head_MultilevelQ[i] = copy(anotherQ.head_MultilevelQ[i], anotherQ.tail_MultilevelQ[i]);

	}
	return *this;
}

template <typename T>
PriorityQ<T>& PriorityQ<T>::operator= (const PriorityQ<T>&& anotherQ)
{
	clear();
	for (unsigned int i = 0; i < MAX_NUM_OF_LEVEL; i++)
	{
		head_MultilevelQ[i] = anotherQ.head_MultilevelQ[i];
		tail_MultilevelQ[i] = anotherQ.tail_MultilevelQ[i];

		anotherQ.head_MultilevelQ[i] = anotherQ.tail_Multilevel[i] = nullptr;
	}
	return *this;

}

template <typename T>
static Node<T> copy(Node<T>* head, Node<T>*& tail)
{
	// if (queue is empty)
	if (head == nullptr)
	{
		tail = nullptr;
		return nullptr;
	}

	Node<T>* temp_newNode = new Node<T>(head->element);

	// if (queue has exactly one element)
	if (head->next == nullptr)
	{
		tail = temp_newNode;
		return temp_newNode;
	}

	temp_newNode->next = copy(head->next, tail);
	return temp_newNode;
}

template <typename T>
void PriorityQ<T>::clear()
{
	for (int i = 0; i < MAX_NUM_OF_LEVEL; i++)
	{
		Node<T>* temp_head = head_MultilevelQ[i];
		while (head_MultilevelQ[i] != nullptr)
		{
			Node<T>* temp = temp_head->next;
			delete temp_head;
			temp_head = temp;

			tail_MultilevelQ[i] = nullptr;
		}
	}
}
