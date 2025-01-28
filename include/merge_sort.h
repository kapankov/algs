/**
 * @file merge_sort.h
 * @author Konstantin A. Pankov(explorus@mail.ru)
 *
 * @license Licensed under the MIT License, Version 2.0 (see LICENSE.txt).
 *
 * @brief Merge Sort Algorithm implementation 
 * 
 * @warning Do not use the sorting algorithms below in real code, as they are slow 
 * and are now only used for educational purposes
 * 
 * @note you may need to include <cstddef> for size_t, <algorithm> for std::inplace_merge
 * and <memory> for std::make_unique
 * 
 */
#pragma once

template <typename It, typename C>
void merge(It left, It mid, It right, C comp)
{
    using T = std::remove_reference_t<decltype(*left)>;

    auto n1 = mid - left + 1;
    auto n2 = right - mid - 1;

    auto left_arr = std::make_unique<T[]>(n1);
    auto right_arr = std::make_unique<T[]>(n2);

    for (size_t i = 0; i < n1; ++i)
        left_arr[i] = *(left + i);
    for (size_t j = 0; j < n2; ++j)
        right_arr[j] = *(mid + j + 1);

    size_t i = 0;
    size_t j = 0;
    while (i < n1 && j < n2)
    {
        if (comp(right_arr[j], left_arr[i]))
            *(left++) = right_arr[j++];
        else
            *(left++) = left_arr[i++];
    }

    while (i < n1)
        *(left++) = left_arr[i++];

    while (j < n2)
        *(left++) = right_arr[j++];
}

template <typename It, typename C>
void merge_sort(It first, It last, C comp)
{
	if (last - first < 2)
		return;
   auto middle = first + (last - 1 - first) / 2;
   merge_sort(first, middle + 1, comp);
   merge_sort(middle + 1, last, comp);
   merge(first, middle, last, comp);
}


#include <iterator>

/**
 * @brief Performs a merge sort on a range of elements using std::inplace_merge.
 *
 * This function sorts a range of elements using the merge sort algorithm.
 * It recursively divides the range into two halves, sorts each half, and then merges the sorted halves.
 *
 * @tparam It The type of the iterator used to iterate over the range.
 * @tparam C The type of the comparator used to compare elements.
 *
 * @param first An iterator pointing to the first element in the range.
 * @param last An iterator pointing to one past the last element in the range.
 * @param comp A comparator function object that returns true if the first argument is less than the second.
 */
template <typename It, typename C>
void merge_sort_stl(It first, It last, C comp)
{
	if (last - first < 2)
		return;
   auto middle = first + (last - first) / 2;
   merge_sort(first, middle, comp);
   merge_sort(middle, last, comp);
   std::inplace_merge(first, middle, last, comp);
}

