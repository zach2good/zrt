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

            node(const T& val) :
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

        linkedlist<T>(const T& val) :
            _head(nullptr),
            _tail(nullptr),
            _size(0)
        {
            insert(val);
        }

        ~linkedlist<T>()
        {
            _cursor = _head;
            while (_cursor->next != nullptr)
            {
                auto next = _cursor->next;
                delete _cursor;
                _cursor = next;
            }
        }

        void insert(const T& value)
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

        size_t size() const
        {
            return _size;
        }

        bool empty() const
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