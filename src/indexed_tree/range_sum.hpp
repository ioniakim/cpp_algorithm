#ifndef RANGE_SUM
#define RANGE_SUM

#include <cstddef>
#include <vector>
#include <cstdint>


void
update(int* array, std::size_t pos, int value);


int
range_sum(int* array, std::size_t first, std::size_t last);


class IndexedTreeRangeSum{
public:
    template <std::size_t DataSize>
    IndexedTreeRangeSum(std::int32_t (&data)[DataSize]);

    void update(std::int32_t pos, std::int32_t value);

    std::int32_t range_sum(std::int32_t first, std::int32_t last);

    std::int32_t prefix_sum(std::int32_t pos);
private:

    void update_indexed_tree(std::int32_t pos, std::int32_t value);

private:
    const std::size_t data_size_;
    std::vector<std::int32_t> indexed_tree_;
    std::int32_t* p_origin_data;
};


template <std::size_t DataSize>
IndexedTreeRangeSum::IndexedTreeRangeSum(std::int32_t (&data)[DataSize])
: data_size_(DataSize)
, indexed_tree_(DataSize + 1, 0)
, p_origin_data(data)
{
    for(std::size_t i = 0; i < DataSize; ++i){
        update_indexed_tree(i, data[i]);
    }
}


#endif // RANGE_SUM
