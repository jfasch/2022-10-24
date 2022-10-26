#include <iostream>
#include <functional>

int main()
{
    std::plus<int> plus;
    int sum = plus(2, 3);
    std::cout << sum << std::endl;

    return 0;
}
