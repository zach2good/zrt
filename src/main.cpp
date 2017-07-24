#include "vector.h"
#include "bigint.h"

#include <iostream>
#include <cassert>

int main()
{
	// Test Vector
	zrt::vector<int> vec;
	vec.push_back(1);
	//assert(vec.size() == 1);
	
	// Test Bigint
	zrt::bigint biA("10000");
	zrt::bigint biB("250000");
	zrt::bigint biC = biA + biB;
	
	std::cout << biA.toString() << std::endl;
	std::cout << biB.toString() << std::endl;
	std::cout << biC.toString() << std::endl;

    // Test Map

    // Test Binary Search Tree

    // Test Sort
	
	return 0;
}