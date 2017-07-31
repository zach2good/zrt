#ifndef ZRT_LINKEDLIST
#define ZRT_LINKEDLIST

#include <stdexcept>

namespace zrt {

    template <class T>
    class linkedlist {
    private:

        template <class T>
        struct node {
            T data;
            node<T>* next;
            node<T>* prev;

            node(T val) :
                data(val),
                next(nullptr),
                prev(nullptr) {}
        };

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
                auto old_tail = _tail;
                auto new_node = new node<T>(value);

                // Replace
                _tail = new_node;

                // Hook up
                _tail->prev = old_tail;
                old_tail->next = new_node;

            }

            _size += 1;
        }

        T at(int i)
        {
            if (i >= _size)
            {
                throw std::out_of_range("");
            }

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