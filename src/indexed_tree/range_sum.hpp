#ifndef RANGE_SUM
#define RANGE_SUM

#include <cstddef>

void
update(int* array, std::size_t pos, int value);


int
range_sum(int* array, std::size_t first, std::size_t last);


template <std::size_t Max>
class IndexedTreeRangeSum{
public:
    template <std::size_t DataSize>
    void init(int (&data)[DataSize]);

    static void update(std::size_t pos, int value);

    static int range_sum(std::size_t first, std::size_t last);

private:
    static int indexed_tree[Max];
    static std::size_t data_size;
    static std::size_t indexed_tree_size;
};


template <std::size_t Max>
template <std::size_t DataSize>
void
IndexedTreeRangeSum<Max>::init(int (&data)[DataSize])
{
    data_size = DataSize;
    indexed_tree_size = 2 * data_size + 1;
    for(std::size_t i = 1; i < data_size; ++i){
        update(i, data[i]);
    }
}


template <std::size_t Max>
void
IndexedTreeRangeSum<Max>::update(std::size_t pos, int value)
{
}


template <std::size_t Max>
int
IndexedTreeRangeSum<Max>::range_sum(std::size_t first, std::size_t last)
{
    return 0;
}

#endif // RANGE_SUM
