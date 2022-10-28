#pragma once
#include <cassert>
#include <algorithm>

namespace DS
{

   template<typename T>
    class DynamicArray
    {
        static constexpr size_t const& default_capacity = 5;

    public:

        //O(1) (omitting a heap allocation time)
                DynamicArray();
       explicit DynamicArray(size_t size);

       //O(n) (omitting a heap allocation time)
       explicit DynamicArray(size_t size, T val);

        ~DynamicArray();


        //O(1) if not overflowing, otherwise O(n)
        void Push_Back(T element);

        //O(1) 
        void Pop_Back();

        //O(n)
        bool Exists(T element);
        bool Empty();
        T* Find(T element);


        //O(1)
        T* End();
        size_t Size();
        size_t Capacity();
        T* Data();

        //Accessing element O(1)
        T& operator [](int i)
        {
            assert(i < m_Size);
            return this->m_Data[i];
        }

    private:
        size_t m_Size;
        size_t m_Capacity;
        T* m_Data;

    };

#include"DynamicArray.tpp"

}