#include <iostream>
#include "ArrayBag.h"

ArrayBag<int>* createBag()
{
	int nums[] = { 13, 82, 21, 10, 11, 24, 99, 16, 12 };
	ArrayBag<int>* bag = new ArrayBag<int>();
	for (int i=0 ; i<9 ; i++)
		bag->add(nums[i]);
	return bag;
}

void segregateAndEmpty(ArrayBag<int>* bag)
{
	// Uncomment when you have added your Bag method implementations
	bag -> segregate();
	int val;
	while (bag -> retrieve(val))
		std::cout << "Retrieved " << val << '\n';

}

int main()
{
	ArrayBag<int>* mainBag = createBag();
	segregateAndEmpty(mainBag);
	delete mainBag;
	return 0;
}
