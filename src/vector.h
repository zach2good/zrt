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
			~vector();
			
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
		
			T* arr;
            size_t count;
			
			// resize();
	};

	template <typename T>
	vector<T>::vector() 
	{
		arr = new T[4];
	}
	
	template <typename T>
	vector<T>::~vector() 
	{
		delete[] arr;
	}
	
	template <typename T>
	void vector<T>::push_back(const T &val) 
	{
		// TODO
        count++;
	}

    template <typename T>
    size_t vector<T>::size()
    {
        return count;
    }
	
} // namespace zrt 

#endif // ZRT_VECTOR