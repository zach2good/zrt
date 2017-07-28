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

    ll.insert_tail(1);
    assert(ll.size() == 1);

    // Test Map

    // Test Binary Search Tree

    // Test Sort
	
	return 0;
}