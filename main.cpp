#include "PriorityQ.hpp"


int main()
{

	// Testing queue with different priority levels

	PriorityQ<int> Test;

	Test.enqueue(3, 2);

	Test.enqueue(5, 3);


	Test.enqueue(8, 8);


	const int test1 = Test.dequeue();


	const int test2 = Test.peek();

	//Output should be test1 : 8

	//Output for test2 should be : 5 

	cout << endl << "Test1: " << test1 << endl;

	cout << endl << "Test2: " << test2 << endl;

}
