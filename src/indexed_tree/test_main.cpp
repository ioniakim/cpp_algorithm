#include "range_sum.hpp"


#include <catch2/catch_all.hpp>


TEST_CASE("test_naive_range_sum", "range_sum")
{
    int data[] = {2, 1, 4, 6, -1, 5, -32, 0, 1};

    update(data, 4, 3); // -1 -> 3
    int res = range_sum(data, 3, 7); // 6 + 3 + 5 + -32

    CHECK(res == -18);
}


TEST_CASE("test_indexed_tree_range_sum", "range_sum")
{
    int data[] = {0, 2, 1, 4, 6, -1, 5, -32, 0, 1};

    IndexedTreeRangeSum<1000>::init(data);

    IndexedTreeRangeSum<1000>::update(5, 3); // -1 -> 3

    int res = IndexedTreeRangeSum<1000>::range_sum(4, 7); // 6 + 3 + 5 + -32

    CHECK(res == -18);
}
