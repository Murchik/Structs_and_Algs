#include "func.hpp"
#include <algorithm>


std::vector<int> readVec()
{
	std::ifstream fin("Vector.txt");
	return std::vector<int>(std::istream_iterator<int>(fin), std::istream_iterator<int>());
	/*std::ifstream fin("Vector.txt");
	int temp;
	if (!fin) { return -1;}
	while (fin >> temp)
	{
		vec.push_back(temp);
	}
	if (vec.empty()) {return -2;}
	else
	{
		return 0;
	}*/

}






//
//void shellSort(std::vector<Record>& array) {
//    int step, i, j;
//    int size = array.size();
//    double compCount = 0;
//    auto start = std::chrono::high_resolution_clock::now();
//
//    // code
//
//    auto end = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> duration = end - start;
//    // std::cout << "After shell sort:" << std::endl;
//    // print(array);
//    std::cout << "Comparisons: " << compCount << std::endl
//        << "Time spend: " << duration.count() << "s" << std::endl
//        << std::endl;
//}