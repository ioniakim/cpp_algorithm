#include "range_sum.hpp"

#include <iostream>

#include <catch2/catch_all.hpp>


TEST_CASE("test_naive_range_sum", "range_sum")
{
    int data[] = {2, 1, 4, 6, -1, 5, -32, 0, 1};

    update(data, 4, 3); // -1 -> 3
    int res = range_sum(data, 3, 7); // 6 + 3 + 5 + -32

    CHECK(res == -18);
}


TEST_CASE("indexed_tree_prefix_sum", "range_sum")
{
    int data[] = {2, 1, 4, 6, -1, 5, -32, 0, 1};

    IndexedTreeRangeSum range_sum(data);

    CHECK(2 == range_sum.prefix_sum(1));
    CHECK(3 == range_sum.prefix_sum(2));
    CHECK(7 == range_sum.prefix_sum(3));
    CHECK(13 == range_sum.prefix_sum(4));
    CHECK(12 == range_sum.prefix_sum(5));
    CHECK(17 == range_sum.prefix_sum(6));
    CHECK(-15 == range_sum.prefix_sum(7));
    CHECK(-15 == range_sum.prefix_sum(8));
    CHECK(-14 == range_sum.prefix_sum(9));

    range_sum.update(4, 3);

    CHECK(2 == range_sum.prefix_sum(1));
    CHECK(3 == range_sum.prefix_sum(2));
    CHECK(7 == range_sum.prefix_sum(3));
    CHECK(13 == range_sum.prefix_sum(4));
    CHECK(16 == range_sum.prefix_sum(5));
    CHECK(21 == range_sum.prefix_sum(6));
    CHECK(-11 == range_sum.prefix_sum(7));
    CHECK(-11 == range_sum.prefix_sum(8));
    CHECK(-10 == range_sum.prefix_sum(9));
}


TEST_CASE("indexed_tree_range_sum", "range_sum")
{
    int data[] = {2, 1, 4, 6, -1, 5, -32, 0, 1};

    IndexedTreeRangeSum range_sum(data);

    range_sum.update(4, 3); // -1 -> 3

    int res = range_sum.range_sum(3, 7); // 6 + 3 + 5 + -32

    std::cout << "prefix sum of index 0 = " << range_sum.prefix_sum(3) << "\n";
    std::cout << "prefix sum of index 4 = " << range_sum.prefix_sum(7) << "\n";

    CHECK(res == -18);

    CHECK(range_sum.prefix_sum(1) == range_sum.range_sum(0, 1));
}
