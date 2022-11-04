#include"AllHeaders.h"
#include "Demo.h"
#include"iostream"

int main() 
{
	DynamicArrayTest();

	DoublyLinkedListTest();

	QueueTest();

	StackTest();
	




}
void StackTest()
{
	DS::Stack<int> stk{};


	std::cout << "IsEmpty: " << stk.Empty() << "\n\n";

	stk.Push(3);
	stk.Push(123);
	stk.Push(354);
	stk.Push(15);
	stk.Push(75);

	stk.Print();

	stk.Pop();
	stk.Pop();
	stk.Pop();

	stk.Print();

	std::cout << "Peek: " << stk.Peek() << "\n";
	stk.Pop();

	std::cout << "PeekAfterDelete: " << stk.Peek() << "\n\n";

	stk.Print();
	stk.Pop();

	stk.Push(68);
	std::cout << "PeekAfterPush: " << stk.Peek() << "\n";
	stk.Push(31);
	std::cout << "PeekAfterPush: " << stk.Peek() << "\n\n";

	std::cout << "Size: " << stk.Size() << "\n\n";

	stk.Print();

	stk.Pop();
	stk.Pop();
	stk.Push(70);
	stk.Push(15);
	stk.Push(12489);

	stk.Print();

	std::cout << "StackSize: " << stk.Size() << "\n\n";

}

void QueueTest()
{
	DS::Queue<int> qq{};


	std::cout << "IsEmpty: " << qq.Empty() << "\n\n";

	qq.Enqueue(3);
	qq.Enqueue(123);
	qq.Enqueue(354);
	qq.Enqueue(15);
	qq.Enqueue(75);

	qq.Print();


	qq.Dequeue();
	qq.Dequeue();
	qq.Dequeue();

	qq.Print();


	std::cout << "ValueFront: " << qq.Front()<< "\n";
	std::cout << "ValueBack: " << qq.Back() << "\n\n";

	qq.Dequeue();
	qq.Print();

	std::cout << "ValueFront: " << qq.Front() << "\n";
	std::cout << "ValueBack: " << qq.Back() << "\n\n";

	std::cout << "QueueSize: " << qq.Size() << "\n\n";


	qq.Enqueue(5);
	qq.Dequeue();
	qq.Enqueue(19);
	qq.Enqueue(31);
	qq.Enqueue(699);

	qq.Print();

	std::cout << "QueueSize: " << qq.Size() << "\n\n";

}

void DoublyLinkedListTest()
{
	DS::LinkedList<int> ll;
	ll.Append(1);
	ll.Append(2);
	ll.Append(3);
	ll.Append(4);

	ll.PrintForward();

	ll.Prepend(2);
	ll.RemoveAtIndex(2);

	ll.PrintBackward();

	ll.RemoveHead();
	ll.RemoveTail();

	ll.Prepend(5);
	ll.Append(5);

	ll.PrintForward();

	ll.RemoveAtIndex(1);
	ll.RemoveAtIndex(1);
	ll.InsertAtIndex(new DS::Node<int>(10), 1);
	ll.InsertAtIndex(new DS::Node<int>(3), 2);

	ll.RemoveTail();
	ll.Append(-400);
	ll.Prepend(2);

	ll.PrintForward();
}

void DynamicArrayTest()
{
	DS::DynamicArray<int> arr(3,1);

	for (size_t i = 0; i < arr.Size(); i++)
	{
		std::cout << arr[i];
	}
	std::cout << "\n" << arr.Size() << arr.Capacity();
	arr.Push_Back(5);
	std::cout << "\n" << arr.Size() << arr.Capacity() << "\n";

	for (size_t i = 0; i < arr.Size(); i++)
	{
		std::cout << arr[i];
	}
	std::cout << "\n";
	arr.Pop_Back();

	for (size_t i = 0; i < arr.Size(); i++)
	{
		std::cout << arr[i];
	}

	std::cout << "\n" << arr.Size() << arr.Capacity() << "\n";;

	std::cout << arr.Exists(5) << "\n";
	arr.Push_Back(5);
	std::cout << arr.Exists(5) << "\n";

	auto* ptrTo = arr.Find(4);
	if (arr.Find(5) != arr.End()) 
	{
		std::cout << "Found it at adress: " << ptrTo;
	}
	else 
	{
		std::cout << "Value doesnt exist..." << "PostEnd adress of the array is: " << ptrTo;
	}

}
