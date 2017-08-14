#include "vector.h"
#include "bigint.h"
#include "linkedlist.h"

#include <iostream>
#include <cassert>


int main()
{
    std::cout << "Starting tests..." << std::endl;
    
	// Test Vector
	zrt::vector<int> vec;
    assert(vec.size() == 0);

	vec.push_back(1);
	assert(vec.size() == 1);

    for (auto i = 0; i < 1000; i++)
    {
        vec.push_back(i);
    }

    assert(vec[0] == 1);
    assert(vec[1] == 0);
    assert(vec[2] == 1);
	
    // Test Linked List
    zrt::linkedlist<int> ll;
    assert(ll.empty());

    ll.insert(1);
    assert(ll.size() == 1);

    ll.insert(2);
    assert(ll.size() == 2);

    for (auto i = 0; i < 50; i++)
    {
        ll.insert(i);
    }
    assert(ll.size() == 52);

    assert(ll.at(0) == 1);
    assert(ll.at(1) == 2);
    assert(ll.at(2) == 0);
    assert(ll.at(3) == 1);
    assert(ll.at(4) == 2);
    assert(ll.at(5) == 3);
    assert(ll.at(10) == 8);

    ll.remove(0);
    assert(ll.size() == 51);
    assert(ll.at(0) == 2);

    // Test Map

    // Test Binary Search Tree

    // Test Sort
    
    std::cout << "Tests complete..." << std::endl;
	
	return 0;
}