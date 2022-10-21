#include"AllHeaders.h"
#include "Demo.h"
#include"iostream"


int main() 
{
	DynamicArrayTest();

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
