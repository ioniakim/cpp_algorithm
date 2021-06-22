#include "range_sum.hpp"

void
update(int* array, std::size_t pos, int value)
{
    array[pos] = value;
}


int
range_sum(int* array, std::size_t begin, std::size_t end)
{
    int sum = 0;
    while(begin != end){
        sum += array[begin++];
    }

    return sum;
}
