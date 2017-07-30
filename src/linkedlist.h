#ifndef ZRT_LINKEDLIST
#define ZRT_LINKEDLIST

namespace zrt {
template <class T>
struct node {
    T data;
    node<T>* next;

    node(T val) :
        data(val),
        next(nullptr) {}

    node(T val, node<T>* ptr) :
        data(val),
        next(ptr) {}
};

    template <class T>
    class linkedlist {

        

    public:

        linkedlist<T>() :
            _head(nullptr),
            _tail(nullptr),
            _size(0)
        {
            // ===
        }

        linkedlist<T>(T val) :
            _head(nullptr),
            _tail(nullptr),
            _size(0)
        {

        }

        void insert(T value)
        {
            // List is empty
            if (_head == nullptr)
            {
                _head = new node<T>(value);
                _tail = _head;
            }
            // Otherwise...
            else
            {
                auto new_node = new node<T>(value);
                _tail->next = new_node;
                _tail = new_node;
            }

            _size += 1;
        }

        T at(int i)
        {
            _cursor = _head;
            int counter = 0;
            while (_cursor->next != nullptr)
            {
                T data = _cursor->data;
                if (counter == i)
                {
                    return _cursor->data;
                }
                else
                {
                    _cursor = _cursor->next;
                    counter += 1;
                }    
            }

            // Throw exception?
            return NULL;
        }

        void remove(int i)
        {
            if (i == 0) // Head
            {
                auto temp = _head->next;
                delete _head;
                _head = temp;
                _size -= 1;
            }
            else
            {
                // TODO
            }
        }

        size_t size()
        {
            return _size;
        }

        bool empty()
        {
            return (_size == 0);
        }

    private:
        node<T>* _head;
        node<T>* _tail;
        node<T>* _cursor;

        size_t _size;
    };

} // namespace zrt 

#endif // ZRT_LINKEDLIST