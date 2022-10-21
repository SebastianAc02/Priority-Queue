#ifndef PRIORITY_Q;
#define PRIORITY_Q;

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

private:
	Node<T>* front;
	Node<T>* back;
	int size;
	int lv = 0;
	void clear();
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
#endif;



// Why are we using too many pointers, this is for the multilevel queueu??

// So for the multilevel part you want like all items of all queues of level one and then go to the next level?

// I thought we have like a queue itself with a priority lets say 1 and then anothe queue with another priority lets say 2 

// and the order should be first the 2 level queue then the one  with lvl 1 agnostic to what levels they have inside 

// 