#ifndef ZRT_LINKEDLIST
#define ZRT_LINKEDLIST

#include <stdexcept>
#include <string>

namespace zrt {

    template <typename T>
    class linkedlist {
    private:

        template <typename D>
        struct node {
            T data;
            node<T>* next;
            node<T>* prev;

            node(const D& val) :
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

        T at(unsigned int i)
        {
            if (i >= _size)
            {
                throw std::out_of_range("");
            }

            _cursor = _head;
            unsigned int counter = 0;
            while (_cursor->next != nullptr)
            {
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

            throw std::range_error("");
        }

        void remove(unsigned int i)
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

        // Broken!
        // https://stackoverflow.com/questions/21860674/implementing-begin-and-end-for-doubly-linked-list
        T begin()
        {
            return _head->data;
        }

        std::size_t size() const
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

        std::size_t _size;
    };

} // namespace zrt 

#endif // ZRT_LINKEDLIST