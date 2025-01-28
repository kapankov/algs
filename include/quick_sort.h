/**
 * @file quick_sort.h
 * @author Konstantin A. Pankov(explorus@mail.ru)
 *
 * @license Licensed under the MIT License, Version 2.0 (see LICENSE.txt).
 *
 * @brief Quick Sort Algorithm implementation with Hoare partitioning
 * 
 * @warning Do not use the sorting algorithms below in real code, as they are slow 
 * and are now only used for educational purposes
 * 
 * @note you may need to include <cstddef> for size_t and <algorithm> for std::swap
 * 
 */
#pragma once

template <typename It, typename C>
It hoare_partition(It left, It right, C comp)
{
    auto pivot = left;
    auto i = left;
    auto j = right - 1;
    while(1)
    {
        while(comp(*i, *pivot))
            ++i;
        while(comp(*pivot, *j))
            --j;
        if(i < j)
            std::swap(*(i++), *(j--));
        else
            return j;
    }

}

/**
 * @brief Performs a quick sort on a range of elements.
 *
 * This function sorts a range of elements using the quick sort algorithm.
 * It recursively partitions the range into two halves, sorts each half, and then merges the sorted halves.
 *
 * @tparam It The type of the iterator used to iterate over the range.
 * @tparam C The type of the comparator used to compare elements.
 *
 * @param first An iterator pointing to the first element in the range.
 * @param last An iterator pointing to one past the last element in the range.
 * @param comp A comparator function object that returns true if the first argument is less than the second.
 */
template <typename It, typename C>
void quick_sort(It first, It last, C comp) noexcept
{
	if (last - first < 2)
		return;

    auto m = hoare_partition(first, last, comp);
    quick_sort(first, m + 1, comp);
    quick_sort(m + 1, last, comp);
}

// classic quick sort implementation
#include <cstddef> // for size_t
#include <utility> // for std::move

template<typename T, typename C>
size_t hoare_partition(T arr[], size_t left, size_t right, C comp)
{
    T pivot = arr[left];
    size_t i = left;
    size_t j = right - 1;
    while(1)
    {
        while(comp(arr[i], pivot))
            ++i;
        while(comp(pivot, arr[j]))
            --j;
        if(i < j)
            std::swap(arr[i++], arr[j--]);
        else
            return j;
    }
}

/**
 * @brief Performs a quick sort on an array of elements.
 *
 * This function sorts an array of elements using the quick sort algorithm.
 * It recursively partitions the array into two halves, sorts each half, and then merges the sorted halves.
 *
 * @tparam T The type of the elements in the array.
 * @tparam C The type of the comparator used to compare elements.
 *
 * @param arr A pointer to the first element in the array.
 * @param left The index of the first element in the range.
 * @param right The index of one past the last element in the range.
 * @param comp A comparator function object that returns true if the first argument is less than the second.
 */
template<typename T, typename C>
void quick_sort(T arr[], size_t left, size_t right, C comp)
{
    if (right - left < 2)
        return;
    auto m = partition(arr, left, right, comp);
    quick_sort(arr, left, m + 1, comp); // the pivot is now included + end
    quick_sort(arr, m + 1, right, comp);
}