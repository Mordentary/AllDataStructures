#pragma once
#include"../LinkedList/LinkedList.h"

namespace DS
{
    template <typename T>
    class Queue
    {

    public:
        Queue() = default;
        //O(1)
        void Enqueue(T value);
        void Dequeue();

        T& Back();
        T& Front();

        uint32_t Size();
        bool Empty();

        //O(n)
        void Print();

    private:
        LinkedList<T> m_InternalDS;
    };

#include"Queue.tpp"


}