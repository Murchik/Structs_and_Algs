#include "func.hpp"


int readVec(std::vector<int> &vec)
{
	std::ifstream fin("Vector.txt");
	int temp;
	while (fin >> temp)
	{
		vec.push_back(temp);
	}
	return 0;

}

//void print(std::vector<Record>& array) {
//    int N = array.size();
//    for (int i = 0; i < N; ++i) {
//        printf(" A[%2d] = %3d\n", i, array[i].key);
//    }
//}
//
//void shakeSort(std::vector<Record>& array) {
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