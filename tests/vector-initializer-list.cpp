#include <vector>
#include <iostream>


int main()
{
    const std::vector<int> array{3,2};

    for (auto elem: array)
        std::cout << elem << std::endl;

    return 0;
}
