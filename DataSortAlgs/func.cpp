#include "func.hpp"

std::vector<int> readVec()
{
	std::ifstream fin("Vector.txt");
	return std::vector<int>(std::istream_iterator<int>(fin), std::istream_iterator<int>());
}
