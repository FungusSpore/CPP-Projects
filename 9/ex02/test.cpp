#include <vector>
#include <deque>
#include <iostream>


int main(void)
{
	std::deque<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);

	arr.insert(arr.end(), 0);

	std::cout << "RESULT" << std::endl;
	std::deque<int>::iterator it = arr.begin();
	for (; it != arr.end(); it++)
		std::cout << *it << std::endl;
}
