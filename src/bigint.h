#ifndef ZRT_BIGINT
#define ZRT_BIGINT

#include <string>

#define MAX_BIGINT_SIZE 100

namespace zrt
{
	class bigint {
		public:

            bigint(const char* input)
			{
				m_strInternal = std::string(input);
			}
			
            explicit bigint(std::string input)
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
			bigint operator+(const bigint& other)
			{
				size_t length = (this->m_strInternal.length() > other.m_strInternal.length()) ? 
					this->m_strInternal.length() + 1 : other.m_strInternal.length() + 1;

                unsigned int result[MAX_BIGINT_SIZE] = {0};
				
               unsigned int carry = 0;
				for (size_t i = 0; i < length; ++i)
				{
                    if (i == length - 1)
                    {
                        result[i] = carry;
                        break;
                    }

                    unsigned int a = std::stoi(std::to_string(this->m_strInternal[i] - '0'));
                    unsigned int b = std::stoi(std::to_string(other.m_strInternal[i] - '0'));

                    unsigned int c = a + b + carry;
                    carry = 0;
                    if (c > 9)
                    {
                        carry = 1;
                        c -= 10;
                    }
                    result[i] = c;
				}
                
                return arrayToBigInt(result, MAX_BIGINT_SIZE);
			}

            bigint arrayToBigInt(unsigned int* array, size_t size)
            {
                std::string result;
                for (int i = 0; i < size; ++i)
                {
                    unsigned int number = array[i];
                    std::string digit = std::to_string(number);
                    result.append(digit);
                }

                return bigint(result);
            }
			
			std::string toString() const
			{
				return m_strInternal;
			}
		
		private:
			std::string m_strInternal;	
	};
} // namespace zrt 

#endif // ZRT_BIGINT