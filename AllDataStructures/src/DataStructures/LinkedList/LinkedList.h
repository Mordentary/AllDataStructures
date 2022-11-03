#pragma once
#include <cassert>
#include <algorithm>


namespace DS
{


    template <typename T>
    class Node
    {
    public:

        Node(T value)
            : m_Value(value)
        {
        }

        Node(T value, Node* next, Node* previous)
            : m_Value(value), m_Next(next), m_Previous(previous)
        {
        }
 
        T m_Value = default;
        Node* m_Next = nullptr;
        Node* m_Previous = nullptr;
    };


    template <typename T>
    class LinkedList
    {
    public:
        LinkedList()
            : m_Size(0)
        {
        }
        //O(1)
        void Append(T value);
        void Prepend(T value);
        void RemoveHead();
        void RemoveTail();
        void RemoveNode(Node<T>* node);
        void InsertBehind(Node<T>* InsertableNode, Node<T>* targetNode);



        Node<T>* GetHead() { return m_Head; }
        Node<T>* GetTail() { return m_Tail; }

        int32_t Size() { return m_Size; }
        bool Empty() { return !static_cast<bool>(m_Size); }

        //O(n)
        void RemoveAtIndex(int32_t index);
        void InsertAtIndex(Node<T>* node, int32_t index);
        void Print();

        //O(1)
        Node<T>* IterateForward();
        Node<T>* IterateBackward();

        T ItrValue();
        void ResetIterator();

    private:
        Node<T>* m_Head = nullptr;
        Node<T>* m_Tail = nullptr;
        Node<T>* m_Itr = nullptr;
        int32_t m_Size = 0;
    };

#include"LinkedList.tpp"  

}

