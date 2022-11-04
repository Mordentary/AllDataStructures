 template<typename T>
    inline void Stack<T>::Push(T value)
    {
        m_InternalDS.Append(value);
    }

    template<typename T>
    inline void Stack<T>::Pop()
    {
        m_InternalDS.RemoveTail();
    }

    template<typename T>
    inline T& Stack<T>::Peek()
    {
        return m_InternalDS.GetTail()->m_Value;
    }

    template<typename T>
    inline bool Stack<T>::Empty()
    {
        return m_InternalDS.Empty();
    }

    template<typename T>
    inline uint32_t Stack<T>::Size()
    {
        return m_InternalDS.Size();
    }
    template<typename T>
    inline void Stack<T>::Print()
    {
        m_InternalDS.PrintBackward();
    }