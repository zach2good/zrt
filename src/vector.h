#ifndef ZRT_VECTOR
#define ZRT_VECTOR

#include <cstddef>
#include <cstring> // memcpy

namespace zrt
{
	template <typename T>
	class vector 
	{
		public:
		
			// typedefs
			
			// constructor / destructor / cop
            vector();
			virtual ~vector();
			
			// iterators
			// begin();
			// cbegin();
			// end();
			// cend();
			
			// capacity
			size_t size();
			// capacity();
			bool empty();
			// max_size();
			
			// usage
			void push_back(const T &);
			
			// access
            T& operator[](unsigned int index);
			// at()
			
		private:
		
            std::size_t m_size;
            std::size_t m_current_max_size;
            T* m_arr;

			void resize();
	};

	template <typename T>
    vector<T>::vector() :
        m_size(0),
        m_current_max_size(4),    
        m_arr(new T[m_current_max_size])
	{
	}
	
	template <typename T>
	vector<T>::~vector() 
	{
		delete[] m_arr;
	}
	
	template <typename T>
	void vector<T>::push_back(const T& val) 
	{
		// Resize when needed
        if (m_size == m_current_max_size - 1)
        {
            m_current_max_size <<= 2; // Pow2
            resize();
        }

        m_arr[m_size] = val;
        m_size += 1;
	}

    template <typename T>
    std::size_t vector<T>::size()
    {
        return m_size;
    }

    template <typename T>
    bool vector<T>::empty()
    {
        return m_size == 0;
    }

    template <typename T>
    T& vector<T>::operator[](unsigned int index)
    {
        return m_arr[index];
    }  

    template <typename T>
    void vector<T>::resize()
    {
        T* temp_array = new T[m_current_max_size];
        std::memcpy(temp_array, m_arr, m_size * sizeof(T));
        delete[] m_arr;
        m_arr = temp_array;
    }
	
} // namespace zrt 

#endif // ZRT_VECTOR