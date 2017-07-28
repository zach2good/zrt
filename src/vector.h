#ifndef ZRT_VECTOR
#define ZRT_VECTOR

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
			// empty();
			// max_size();
			
			// usage
			void push_back(const T &);
			
			// access
			// [] operator
			// at()
			
		private:
		
			T* _arr;
            size_t _size;
			
			// resize();
	};

	template <typename T>
    vector<T>::vector() :
        _arr(new T[4]),
        _size(0)
	{
	}
	
	template <typename T>
	vector<T>::~vector() 
	{
		delete[] _arr;
	}
	
	template <typename T>
	void vector<T>::push_back(const T &val) 
	{
		// TODO
        _size += 1;
	}

    template <typename T>
    size_t vector<T>::size()
    {
        return _size;
    }
	
} // namespace zrt 

#endif // ZRT_VECTOR