template<typename T>
	DynamicArray<T>::DynamicArray()
		: m_Size(0), m_Capacity(default_capacity)
	{
		this->m_Data = new T[m_Capacity];
	}


	template<typename T>
	DynamicArray<T>::DynamicArray(size_t cpcty)
		: m_Size(0), m_Capacity(cpcty)
	{
		this->m_Data = new T[m_Capacity];
	}

	template<typename T>
	DynamicArray<T>::DynamicArray(size_t cpcty, T val)
		: m_Size(cpcty), m_Capacity(cpcty)
	{

		this->m_Data = new T[m_Capacity];
		
		for (; 0 < cpcty; --cpcty)
		{
			m_Data[cpcty - 1] = val;
		}
		
	}

	template<typename T>
	DynamicArray<T>::~DynamicArray()
	{
		delete[] m_Data;
	}

	template<typename T>
	void DynamicArray<T>::Push_Back(T val)
	{
		if (m_Capacity < m_Size + 1)
		{
			m_Capacity *= 2;

			T* temp = new T[m_Capacity];
			std::copy(&m_Data[0], &m_Data[m_Size], temp);

			delete[] m_Data;
			m_Data = temp;
			m_Data[m_Size] = val;
			m_Size += 1;
		}
		else
		{
			m_Data[m_Size] = val;
			m_Size += 1;
		}
	}

	template<typename T>
	void DynamicArray<T>::Pop_Back()
	{
		assert(!Empty());
		m_Size--;
	}

	template<typename T>
	bool DynamicArray<T>::Exists(T element)
	{
		return std::find(&m_Data[0], &m_Data[m_Size], element) != &m_Data[m_Size];
	}

	template<typename T>
	bool DynamicArray<T>::Empty()
	{
		return m_Size == 0;
	}

	template<typename T>
	T* DynamicArray<T>::Find(T element)
	{
		T* found = std::find(&m_Data[0], &m_Data[m_Size], element);
		return found != &m_Data[m_Size] ? found : &m_Data[m_Size];
	}

	template<typename T>
	T* DynamicArray<T>::Data()
	{
		return m_Data;
	}

	template<typename T>
	size_t DynamicArray<T>::Size()
	{
		return m_Size;
	}

	template<typename T>
	size_t DynamicArray<T>::Capacity()
	{
		return m_Capacity;
	}

	template<typename T>
	T* DynamicArray<T>::End()
	{
		return &m_Data[m_Size];
	}