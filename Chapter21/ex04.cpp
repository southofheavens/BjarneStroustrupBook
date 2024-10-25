/*
    Самостоятельно реализуйте алгоритм count_if(). Протестируйте его.
*/

#include <iostream>
#include <cstdint>
#include <vector>

template<typename InputIterator, typename Pred>
int32_t CountIf(InputIterator first, InputIterator last, Pred pred)
{
    int32_t result = 0;
    for (InputIterator it = first; it != last; ++it)
    {
        if (pred(*it)) {
            result++;
        }
    }
    return result;
}

class PercentageOf
{
private:
    int p;
    
public:
    PercentageOf(int pp) : p{pp} {}
    bool operator()(int x) const { return x % p == 0; }
};

int main()
{
    std::vector<int> arr{1,8,5,4,1,3,2,7,1,5,-7,3,2,4,9,1};
    std::cout << CountIf(arr.begin(),arr.end(),PercentageOf(2)) << '\n';
    std::cout << CountIf(arr.begin(),arr.end(),PercentageOf(3)) << '\n';
    
    return 0;
}
