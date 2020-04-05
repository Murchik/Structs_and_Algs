#include <iostream>
#include <vector>
#include <iterator>
#include<fstream>
#include <algorithm>

std::vector<int> readVec();

template <class Arr>
void printVec(const Arr& input)
{
	std::copy(input.begin(),
		input.end(),
		std::ostream_iterator<Arr::value_type>(std::cout, " "));
}



template <class Arr>
void shakeSort(Arr input)
{
	int start = 0;
	int end = input.size() - 1;
	bool swapped = true;
	while (swapped)
	{
		swapped = false;


		for (int i = start; i < end; ++i)
		{
			if (input[i] > input[i + 1])
			{
				std::swap(input[i], input[i + 1]);
				swapped = true;
			}
		}
		if (!swapped) { break; }

		swapped = false;
		--end;

		for (int i = end - 1; i >= start; --i)
		{
			if (input[i] > input[i + 1])
			{
				std::swap(input[i], input[i + 1]);
				swapped = true;
			}
		}

		++start;
	}
	std::cout << std::endl << "Sorted array: " << std::endl;
	printVec(input);
}