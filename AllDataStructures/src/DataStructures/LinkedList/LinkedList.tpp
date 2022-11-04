    template<typename T>
    LinkedList<T>::~LinkedList()
    {
        Node<T>* curr = IterateForward();
        Node<T>* next = IterateForward();
        if (!curr) return;

        while (next)
        {
            delete curr;
            curr = next;
            next = IterateForward();
        }

        delete curr;
        ResetIterator();

    }
    
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
         this->m_Size -= 1;
    }
    template<typename T>
    inline void LinkedList<T>::RemoveTail()
    {
        if (m_Tail == nullptr) return;
        Node<T>* temp = m_Tail;
        m_Tail = m_Tail->m_Previous;
        delete temp;
        this->m_Size -= 1;

    }
    template<typename T>
    inline void LinkedList<T>::RemoveNode(Node<T>* node)
    {
        if (!node) assert(false, "NullNode");

        node->m_Previous->m_Next = node->m_Next;
        node->m_Next->m_Previous = node->m_Previous;
        delete node;
        this->m_Size -= 1;

    }
    template<typename T>
    inline void LinkedList<T>::InsertBehind(Node<T>* node, Node<T>* trgNode)
    {
        if (!node || !trgNode) assert(false, "NullNode");

        node->m_Next = trgNode;
        node->m_Previous = trgNode->m_Previous;

        node->m_Previous->m_Next = node;
        node->m_Next->m_Previous = node;

        this->m_Size += 1;


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
    inline void LinkedList<T>::PrintForward()
    {

        while (IterateForward())
        {
            std::cout << ItrValue() << "\n";
        }
        std::cout << "\n";
        ResetIterator();

    }
    template<typename T>
    inline void LinkedList<T>::PrintBackward()
    {

        while (IterateBackward())
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