#pragma once
#include"../LinkedList/LinkedList.h"


namespace DS
{
    template <typename T>
    class Stack
    {

    public:
        Stack() = default;
        ~Stack() = default;

        //O(1)
        void Pop();
        void Push(T value);

        T& Peek();

        uint32_t Size();
        bool Empty();

        //O(n)
        void Print();

    private:
        LinkedList<T> m_InternalDS;
    };

#include"Stack.tpp"

}