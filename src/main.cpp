#include "vector.h"
#include "bigint.h"
#include "linkedlist.h"

#include <iostream>
#include <cassert>

int main()
{
	// Test Vector
	zrt::vector<int> vec;
    assert(vec.size() == 0);

	vec.push_back(1);
	assert(vec.size() == 1);
	
	// Test Bigint
	zrt::bigint biA("10000");
	zrt::bigint biB("250000");
	zrt::bigint biC = biA + biB;
	
    assert(biA.toString() == std::string("10000"));
    assert(biB.toString() == std::string("250000"));
    //assert(biC.toString() == std::string("260000"));

    // Test Linked List
    zrt::linkedlist<int> ll;
    assert(ll.empty());

    ll.insert(1);
    assert(ll.size() == 1);

    ll.insert(2);
    assert(ll.size() == 2);

    for (size_t i = 0; i < 100; i++)
    {
        ll.insert(i);
    }
    assert(ll.size() == 102);

    assert(ll.at(0) == 1);
    assert(ll.at(1) == 2);
    assert(ll.at(2) == 0);
    assert(ll.at(3) == 1);
    assert(ll.at(4) == 2);
    assert(ll.at(5) == 3);
    assert(ll.at(10) == 8);

    ll.remove(0);
    assert(ll.size() == 101);
    assert(ll.at(0) == 2);

    // Test Map

    // Test Binary Search Tree

    // Test Sort
	
	return 0;
}