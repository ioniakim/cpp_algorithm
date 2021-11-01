#ifndef GCD_RANGE_SUM_H
#define GCD_RANGE_SUM_H

#include <cstddef>
#include <array>


template<std::size_t CAP>
class GcdRangeSum{
public:
    template<std::size_t SIZE>
    static void init(int (&arr)[SIZE]);

    static int sum(std::size_t start, std::size_t end);

    static void update(std::size_t pos, int value);

private:
    static std::array<int, CAP> storage_;
    static std::array<int, CAP> fx_;
    static int* p_input_;
    static std::size_t input_size_;
};

template<std::size_t CAP>
std::array<int, CAP>
GcdRangeSum<CAP>::storage_;

template <std::size_t CAP>
std::array<int, CAP>
GcdRangeSum<CAP>::fx_;

template<std::size_t CAP>
int*
GcdRangeSum<CAP>::p_input_ = nullptr;

template<std::size_t CAP>
std::size_t
GcdRangeSum<CAP>::input_size_ = 0;


template<std::size_t CAP>
template<std::size_t SIZE>
void
GcdRangeSum<CAP>::init(int (&arr)[SIZE])
{
    p_input_ = arr;
    input_size_ = SIZE;
    for(std::size_t i = 1; i <= SIZE; ++i){
        storage_[i] = 0;
    }

    
}


template<std::size_t CAP>
int
GcdRangeSum<CAP>::sum(std::size_t start, std::size_t end)
{
    return 0;
}


template<std::size_t CAP>
void
GcdRangeSum<CAP>::update(std::size_t pos, int value)
{}

#endif //GCD_RANGE_SUM_H
