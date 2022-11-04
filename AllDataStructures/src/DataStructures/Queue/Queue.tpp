    template<typename T>
    inline void Queue<T>::Enqueue(T value)
    {
        m_InternalDS.Append(value);
    }

    template<typename T>
    inline void Queue<T>::Dequeue()
    {
        m_InternalDS.RemoveHead();
    }

    template<typename T>
    inline bool Queue<T>::Empty()
    {
        return m_InternalDS.Empty();
    }

    template<typename T>
    inline uint32_t Queue<T>::Size()
    {
        return m_InternalDS.Size();
    }

    template<typename T>
    inline T& Queue<T>::Front()
    {
        return m_InternalDS.GetHead()->m_Value;
    }

    template<typename T>
    inline T& Queue<T>::Back()
    {
        return m_InternalDS.GetTail()->m_Value;
    }

    template<typename T>
    inline void Queue<T>::Print()
    {
       m_InternalDS.PrintForward();
    }