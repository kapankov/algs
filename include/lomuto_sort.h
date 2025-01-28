/**
 * @file quick_sort.h
 * @author Konstantin A. Pankov(explorus@mail.ru)
 *
 * @license Licensed under the MIT License, Version 2.0 (see LICENSE.txt).
 *
 * @brief Quick Sort Algorithm implementation with Lomuto partitioning
 * 
 * @warning Do not use the sorting algorithms below in real code, as they are slow 
 * and are now only used for educational purposes
 * 
 * @note you may need to include <cstddef> for size_t and <algorithm> for std::swap
 * 
 */
#pragma once

template<typename It, typename C>
It lomuto_partition(It left, It right, C comp)
{
    auto pivot = *(right - 1);
    auto m = left;
    for(auto i = left; i < (right - 1); ++i)
    {
        if(!comp(*i, pivot))
            continue;
        std::swap(*i, *(m++));
    }
    std::swap(*(right - 1), *m);
    return m;
}

template <typename It, typename C>
void lomuto_sort(It first, It last, C comp) noexcept
{
	if (last - first < 2)
		return;

    auto m = lomuto_partition(first, last, comp);
    lomuto_sort(first, m, comp);
    lomuto_sort(m + 1, last, comp);
}

// classic quick sort implementation with lomuto partitioning
#include <cstddef> // for size_t
#include <utility> // for std::move

// Nico Lomuto partition scheme
template<typename T, typename C>
size_t lomuto_partition(T arr[], size_t left, size_t right, C comp)
{
    T pivot = arr[right - 1];
    size_t m = left;
    for(size_t i = left; i < right; ++i)
    {
        if(!comp(arr[i], pivot))
            continue;
        std::swap(arr[i], arr[m++]);
    }
    std::swap(arr[right - 1], arr[m]);
    return m;
}

template<typename T, typename C>
void lomuto_sort(T arr[], size_t left, size_t right, C comp)
{
    if (right - left < 2)
        return;
    auto m = lomuto_partition(arr, left, right, comp);
    lomuto_sort(arr, left, m, comp);
    lomuto_sort(arr, m + 1, right, comp);
}
