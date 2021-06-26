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

void IndexedTreeRangeSum::update(int pos, int value)
{
    pos += 1;
    for (; pos < std::size(indexed_tree_); pos += pos & (-pos))
    {
        indexed_tree_[pos] += value;
    }
}

std::int32_t
IndexedTreeRangeSum::range_sum(int first, int last)
{
    return prefix_sum(last) - prefix_sum(first);
}

std::int32_t
IndexedTreeRangeSum::prefix_sum(std::int32_t pos)
{
    std::int32_t sum = 0;
    for (; pos >= 1; pos -= pos & (-pos))
    {
        sum += indexed_tree_[pos];
    }
    return sum;
}
