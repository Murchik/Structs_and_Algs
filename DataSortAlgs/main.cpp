#include "func.hpp"


int main() 

{
    
    std::vector<int> vec(readVec());
    

    printVec(vec);

    
    shakeSort(vec);
    /*shake(array);
    shellSort(array);*/

    return 0;
}
