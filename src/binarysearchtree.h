#ifndef ZRT_BINARYSEARCHTREE
#define ZRT_BINARYSEARCHTREE

namespace zrt
{
    template <class T>
    class node {
    public:
        T data;
        node* left;
        node* right;
        node* parent;

        node() : left(nullptr), right(nullptr), parent(nullptr) {}
        ~node() {}

        void node(T &value) {
            data = value;
        };

        void operator= (const node<T> &other) {
            data = other.data;
        };

        bool operator< (T &other) {
            return (data < other);
        }
    }

    template <class T>
	class binarysearchtree {
		public:

		private:

	};
} // namespace zrt 

#endif // ZRT_BINARYSEARCHTREE