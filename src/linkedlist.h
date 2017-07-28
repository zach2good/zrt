#ifndef ZRT_LINKEDLIST
#define ZRT_LINKEDLIST

namespace zrt
{
    template <class T>
    class linkedlist {
    private:
    
        struct node {
            T data;
            node* next;
        };

    public:
        
        linkedlist() : 
            _head(nullptr), 
            _tail(nullptr), 
            _size(0) { }
        
        virtual ~linkedlist() 
        {
            // delete everything
        }

        void insert_head(T value)
        {
            _size += 1;
        }

        void insert_tail(T value)
        {
            _size += 1;
        }

        size_t size()
        {
            return _size;
        }

        bool empty()
        {
            return _size == 0;
        }

    private:
        
        node* _head;
        node* _tail;

        size_t _size;
    };

} // namespace zrt 

#endif // ZRT_LINKEDLIST