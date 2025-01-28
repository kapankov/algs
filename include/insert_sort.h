/**
 * @file insert_sort.h
 * @author Konstantin A. Pankov(explorus@mail.ru)
 *
 * @license Licensed under the MIT License, Version 2.0 (see LICENSE.txt).
 *
 * @brief Insertion Sort Algorithm implementation 
 * 
 * @warning Do not use the sorting algorithms below in real code, as they are slow 
 * and are now only used for educational purposes
 * 
 * @note you may need to include <cstddef> for size_t
 *
 * O(n*n), stable
 * Algorithm (python):
 * n = len(arr)
 * for i in range(1, n): # [1, n)  
 *     t = arr[i]
 *     j = i
 *     while j > 0 and arr[j - 1] > t:
 *         arr[j] = arr[j - 1]
 *         j = j - 1
 *     arr[j] = t
 */

#pragma once

/**
 * @brief Performs an insertion sort on a range of elements using STL-style iterators
 *
 * This function sorts a range of elements using the insertion sort algorithm.
 * It iterates over the range and compares each element with the next one.
 * If the next element is smaller, it swaps the elements.
 *
 * @tparam It The type of the iterator used to iterate over the range.
 * @tparam C The type of the comparator used to compare elements.
 *
 * @param first An iterator pointing to the first element in the range.
 * @param last An iterator pointing to one past the last element in the range.
 * @param comp A comparator function object that returns true if the first argument is less than the second.
 */
template <typename It, typename C>
void insert_sort(It first, It last, C comp) noexcept
{
	if (last - first < 2)
		return;
	for (auto it = first + 1; it < last; ++it)
	{
		auto jt = it;
		auto t = std::move(*it);
		for (; jt != first && comp(t, *(jt - 1)); --jt)
			*jt = std::move(*(jt - 1));
		*jt = std::move(t);
	}
}

/**
 * @brief Performs an insertion sort on an array of elements in classical form
 *
 * This function sorts an array of elements using the insertion sort algorithm.
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
void insert_sort(T* arr, const size_t len, C comp) noexcept
{
	if (len < 2)
		return;
	for (size_t i = 1; i < len; ++i)
	{
		T t = arr[i];
		size_t j = i;
		for (; j && comp(t, arr[j - 1]); --j)
			arr[j] = arr[j - 1];
		arr[j] = t;
	}
}