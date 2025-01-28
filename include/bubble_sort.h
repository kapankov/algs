/**
 * @file exchange_sort.h
 * @author Konstantin A. Pankov(explorus@mail.ru)
 *
 * @license Licensed under the MIT License, Version 2.0 (see LICENSE.txt).
 *
 * @brief Bubble Sort Algorithm implementation 
 * 
 * By Edward Harry Friend, 1956 (Kenneth E. Iverson, 1959)
 *
 * @warning Do not use the sorting algorithms below in real code, as they are slow 
 * and are now only used for educational purposes
 * 
 * @note you may need to include <cstddef> for size_t and <algorithm> for std::swap
 *	
 * O(n*n), stable
 *
 * Algorithm (python):
 * n = len(arr)
 * for i in range(n): # [0, n)
 *   swapped = False
 *   for j in range(0, n - i - 1):
 *     if arr[j + 1] < arr[j]:
 *       arr[j], arr[j + 1] = arr[j + 1], arr[j] #swap
 *       swapped = True
 *   if (swapped == False):
 *     break
 */

#pragma once

/**
 * @brief Performs a bubble sort on a range of elements using STL-style iterators
 *
 * This function sorts a range of elements using the bubble sort algorithm.
 * It iterates over the range and compares each element with the next one.
 * If the next element is smaller(greater), it swaps the elements.
 *
 * @tparam It The type of the iterator used to iterate over the range.
 * @tparam C The type of the comparator used to compare elements.
 *
 * @param first An iterator pointing to the first element in the range.
 * @param last An iterator pointing to one past the last element in the range.
 * @param comp A comparator function object that returns true if the first argument is less than the second.
 */
template <typename It, typename C>
void bubble_sort(It first, It last, C comp) noexcept
{
	if ((--last) - first < 1)
       return;
	for (auto i = first, prelast = last - 1; i < last; ++i, --prelast)
	{
		bool swapped = false;
		for (auto j = first; j <= prelast; ++j)
			if (auto nextj = j + 1; comp(*nextj, *j)) // compare
			{
				std::swap(*j, *nextj);
				swapped = true;
			}
		// If no two elements were swapped, then break
		if (!swapped)
			break;
	}
}

/**
 * @brief Performs recursive bubble sorting for a number of items using STL-style iterators
 */
template <typename It, typename C>
void bubble_sort_recursive(It first, It last, C comp) noexcept
{
	if (last - first < 2)
       return;

	bool swapped = false;
	for (auto j = first, prelast = last - 1; j < prelast; ++j)
		if (auto nextj = j + 1; comp(*nextj, *j)) // compare
		{
			std::swap(*j, *nextj);
			swapped = true;
		}
	// If no two elements were swapped, then return
	if (!swapped)
		return;

	bubble_sort_recursive(first, --last, comp);
}

/**
 * @brief Performs a bubble sort on an array of elements in classical form
 *
 * This function sorts an array of elements using the bubble sort algorithm.
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
void bubble_sort(T* arr, const size_t len, C comp) noexcept
{
	if (len < 2)
		return;
	for (size_t i = 0, count = len - 1; i < count; ++i)
	{
		bool swapped = false;
		for (size_t j = 0; j < count - i; ++j)
			if (comp(arr[j + 1], arr[j])) // compare
			{
				std::swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		// If no two elements were swapped, then break
		if (!swapped)
			break;
	}
}