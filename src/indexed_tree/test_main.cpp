#define CATCH_CONFIG_MAIN

#include "range_sum.hpp"

#include <iostream>

#include <catch2/catch.hpp>

// Compile test
// g++ -std=c++17 -Wall -I ~/.local/include -o test.out *.cpp

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

    IndexedTreeRangeSum rangeSum(data);

    rangeSum.update(5, 3); // -1 -> 3

    int res = rangeSum.range_sum(4, 7); // 6 + 3 + 5 + -32

    std::cout << "prefix sum of index 0 = " << rangeSum.prefix_sum(0) << "\n";
    std::cout << "prefix sum of index 4 = " << rangeSum.prefix_sum(4) << "\n";

    CHECK(res == -18);
}
