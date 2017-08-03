#ifndef ZRT_VECTOR
#define ZRT_VECTOR

#include <cstddef>

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
		
			T* _arr;
            std::size_t _size;
            std::size_t _current_max_size;
			
			void resize();
	};

	template <typename T>
    vector<T>::vector() :
        _arr(new T[4]),
        _current_max_size(4),
        _size(0)
	{
	}
	
	template <typename T>
	vector<T>::~vector() 
	{
		delete[] _arr;
	}
	
	template <typename T>
	void vector<T>::push_back(const T& val) 
	{
		// Resize when needed
        if (_size == _current_max_size - 1)
        {
            _current_max_size <<= 2; // Pow2
            resize();
        }

        _arr[_size] = val;
        _size += 1;
	}

    template <typename T>
    std::size_t vector<T>::size()
    {
        return _size;
    }

    template <typename T>
    bool vector<T>::empty()
    {
        return _size == 0;
    }

    template <typename T>
    T& vector<T>::operator[](unsigned int index)
    {
        return _arr[index];
    }  

    template <typename T>
    void vector<T>::resize()
    {
        T* temp_array = new T[_current_max_size];
        memcpy(temp_array, _arr, _size * sizeof(T));
        delete[] _arr;
        _arr = temp_array;
    }
	
} // namespace zrt 

#endif // ZRT_VECTOR