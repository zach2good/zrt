#ifndef ZRT_BIGINT
#define ZRT_BIGINT

#include <string>

namespace zrt
{
	class bigint {
		public:

			bigint(const char* input)
			{
				m_strInternal = std::string(input);
			}
			
			bigint(std::string input)
			{
				m_strInternal = input;
			}
			
			template<typename T>
			bigint(const T& obj) 
			{ 
				m_strInternal = std::to_string(obj); 
			}
			
			~bigint()
			{
				
			}
			
			// Operators
			inline bigint operator+(const bigint& other)
			{
				int length = (this->m_strInternal.length() > other.m_strInternal.length()) ? 
					this->m_strInternal.length() : other.m_strInternal.length();
				
				int carry = 0;
				for (int i = 0; i < length; ++i)
				{
					if ( this->m_strInternal[i] && other.m_strInternal[i] )
					{
						// Add and remember carry;
					}
					else if ( this->m_strInternal[i] ) 
					{
						// No Carry
					}
					else if ( other.m_strInternal[i] ) 
					{
						// No Carry
					}
				}
			}
			
			std::string toString()
			{
				return m_strInternal;
			}
		
		private:
			std::string m_strInternal;	
	};
} // namespace zrt 

#endif // ZRT_BIGINT