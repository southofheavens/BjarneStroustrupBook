/*
    Самостоятельно реализуйте алгоритм count(). Протестируйте его.
*/

#include <iostream>
#include <cstdint>
#include <vector>

template<typename InputIterator, typename Type>
int32_t Count(InputIterator first, InputIterator last, const Type& elem)
{
    int32_t result = 0;
    for (InputIterator it = first; it != last; ++it)
    {
        if (*it == elem)
        {
            result++;
        }
    }
    return result;
}

int main()
{
    std::vector<int> arr{1,8,5,4,1,3,2,7,1,5,-7,3,2,4,9,1};
    std::cout << Count(arr.begin(),arr.end(),1) << '\n';
    
    std::vector<double> arr2{5.5,12.3,7,8,5.5,14,-5,-5.5,5.5,21,7.31};
    std::cout << Count(arr2.begin(),arr2.end(),5.5) << '\n';
    return 0;
}
