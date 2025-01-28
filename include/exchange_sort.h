/**
 * @file exchange_sort.h
 * @author Konstantin A. Pankov(explorus@mail.ru)
 *
 * @license Licensed under the MIT License, Version 2.0 (see LICENSE.txt).
 *
 * @brief Exchange Sort Algorithm implementation.
 *
 * @warning Do not use the sorting algorithms below in real code, as they are slow 
 * and are now only used for educational purposes
 * 
 * @note you may need to include <cstddef> for size_t and <algorithm> for std::swap
 * 
 * O(n*n), not stable
 * 
 * Algorithm (python):
 * n = len(arr)
 * for i in range(n - 1): # [0, n - 1)
 *   for j in range(i + 1, n): # [i + 1, n)
 *     if arr[j] < arr[i]:
 *       arr[i], arr[j] = arr[j], arr[i] # swap
 */

#pragma once

/**
 * @brief Performs exchange sorting for a number of items using STL-style iterators
 *
 * This function sorts a range of elements using the exchange sort algorithm.
 * It iterates over the range and for each element it iterates over the next elements, comparing them.
 * If the next element is smaller(greater), it swaps the elements.
 * Do not confuse this algorithm with the bubble sort algorithm.
 *
 * @tparam It The type of the iterator used to iterate over the range.
 * @tparam C The type of the comparator used to compare elements.
 *
 * @param first An iterator pointing to the first element in the range.
 * @param last An iterator pointing to the next to last element in the range (not included in the range).
 * @param comp A comparator function object that returns true if the first argument is less than the second.
 */
template <typename It, typename C>
void exchange_sort(It first, It last, C comp) noexcept
{
	if (last - first < 2)
		return;
	for (auto i = first, prelast = last - 1; i < prelast; ++i)
		for (auto j = i + 1; j < last; ++j)
			if (comp(*j, *i)) // compare
				std::swap(*j, *i);
}

/**
 * @brief Performs recursive exchange sorting for a number of items using STL-style iterators
 */
template <typename It, typename C>
void exchange_sort_recursive(It first, It last, C comp) noexcept
{
	if (last - first < 2)
		return;
	for (auto j = first + 1; j < last; ++j)
		if (comp(*j, *first))
			std::swap(*j, *first);
	exchange_sort_recursive(++first, last, comp);
}

/**
 * @brief Performs an exchange sort on an array of elements in classical form
 *
 * This function sorts an array of elements using the exchange sort algorithm.
 * It iterates over the array and compares each element with the next one.
 * If the next element is smaller, it swaps the elements.
 *
 * @tparam T The type of the elements in the array.
 * @tparam C The type of the comparator used to compare elements.
 *
 * @param arr A pointer to the first element in the array.
 * @param len The length of the array.
 * @param comp A comparator function object that returns true if the first argument is less than the second.
 */
template<typename T, typename C>
void exchange_sort(T* arr, const size_t len, C comp) noexcept
{
	if (len < 2)
		return;
	for (size_t i = 0, count = len - 1; i < count; ++i)
		for (size_t j = i + 1; j < len; ++j)
			if (comp(arr[j], arr[i])) // compare
				std::swap(arr[j], arr[i]);
}
