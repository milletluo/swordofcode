#include "Queue.h"
#include <stdio.h>
#include <stdexcept>

template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template <typename T> void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}

template <typename T> T CQueue<T>::deleteHead()
{
	if(stack2.size() <= 0)
	{
		while(stack1.size() > 0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if(stack2.size() == 0)
	{
		throw std::runtime_error("queue is empty");
	}

	T head = stack2.top();
	stack2.pop();
	return head;
}

void Test(char actual,char excepted)
{
	if(actual == excepted)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(int argc,char* argv[])
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test(head,'a');

	head = queue.deleteHead();
	Test(head,'b');

	queue.appendTail('d');
	head = queue.deleteHead();
	Test(head,'c');
	
	queue.appendTail('e');
	head =queue.deleteHead();
	Test(head,'d');

	head =queue.deleteHead();
	Test(head,'e');

	return 0;

}
