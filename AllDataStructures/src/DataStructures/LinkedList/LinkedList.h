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
        bool Empty() { return m_Size; }

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

    template<typename T>
    inline void LinkedList<T>::Append(T value)
    {
        m_Size += 1;

        if (m_Head == nullptr)
        {
            m_Head = new Node<T>(value);
            m_Tail = m_Head;
            return;
        }

        m_Tail->m_Next = new Node<T>(value);
        m_Tail->m_Next->m_Previous = m_Tail;
        m_Tail = m_Tail->m_Next;

    }
    template<typename T>
    inline void LinkedList<T>::Prepend(T value)
    {
        this->m_Size += 1;

        if (m_Head == nullptr)
        {
            m_Head = new Node<T>(value);
            m_Tail = m_Head;
            return;
        }

        m_Head->m_Previous = new Node<T>(value);
        m_Head->m_Previous->m_Next = m_Head;
        m_Head = m_Head->m_Previous;
    }
    template<typename T>
    inline void LinkedList<T>::RemoveHead()
    {
         if (m_Head == nullptr) return;
         Node<T>* temp = m_Head;
         m_Head = m_Head->m_Next;
         delete temp;
    }
    template<typename T>
    inline void LinkedList<T>::RemoveTail()
    {
        if (m_Tail == nullptr) return;
        Node<T>* temp = m_Tail;
        m_Tail = m_Tail->m_Previous;
        delete temp;
    }
    template<typename T>
    inline void LinkedList<T>::RemoveNode(Node<T>* node)
    {
        if (!node) assert(false, "NullNode");

        node->m_Previous->m_Next = node->m_Next;
        node->m_Next->m_Previous = node->m_Previous;
        delete node;
    }
    template<typename T>
    inline void LinkedList<T>::InsertBehind(Node<T>* node, Node<T>* trgNode)
    {
        if (!node || !trgNode) assert(false, "NullNode");

        node->m_Next = trgNode;
        node->m_Previous = trgNode->m_Previous;

        node->m_Previous->m_Next = node;
        node->m_Next->m_Previous = node;

    }
    template<typename T>
    inline void LinkedList<T>::RemoveAtIndex(int32_t index)
    {
        int32_t counter = 0;
        Node<T>* itr = IterateForward();
        while (itr && counter < index)
        {
            itr = IterateForward();
            ++counter;
        }
        if (itr) RemoveNode(itr);
        ResetIterator();

    }
    template<typename T>
    inline void LinkedList<T>::InsertAtIndex(Node<T>* node, int32_t index)
    {
        int32_t counter = 0;
        Node<T>* itr = IterateForward();
        while (itr && counter < index)
        {
            itr = IterateForward();
            ++counter;
        }
        if (itr) InsertBehind(node, itr);
        ResetIterator();


    }
    template<typename T>
    inline void LinkedList<T>::Print()
    {

        while (IterateForward())
        {
            std::cout << ItrValue() << "\n";
        }
        std::cout << "\n";
        ResetIterator();

    }
    template<typename T>
    inline Node<T>* LinkedList<T>::IterateForward()
    {
        if (m_Itr == nullptr)
        {
            m_Itr = m_Head;
        }
        else
        {
            m_Itr = m_Itr->m_Next;
        }

        return m_Itr;
    }
    template<typename T>
    inline Node<T>* LinkedList<T>::IterateBackward()
    {
        if (m_Itr == nullptr)
        {
            m_Itr = m_Tail;
        }
        else
        {
            m_Itr = m_Itr->m_Previous;
        }

        return m_Itr;
    }
    template<typename T>
    inline T LinkedList<T>::ItrValue()
    {

        return this->m_Itr->m_Value;

    }
    template<typename T>
    inline void LinkedList<T>::ResetIterator()
    {
        m_Itr = nullptr;
    }


}

