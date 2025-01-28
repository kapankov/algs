#pragma once

template <typename It, typename T>
It binary_search(const It first, const It last, T value)
{
	auto l = first;
	auto r = last;
	while (l <= r)
	{
		auto m = l + (r - l) / 2;
		if (*m < value)
			l = m + 1;
		else if (*m > value)
			r = m - 1;
		else
			return m;
	}
	return last;
 }

//TODO for Duplicate elements (https://en.wikipedia.org/wiki/Binary_search)

template<typename T>
size_t binary_search_old(const T value, const T* arr, const size_t len) noexcept
{
	size_t l = 0;
	size_t r = len - 1;

	while (l <= r)
	{
		auto m = (l + r) / 2;
		if (arr[m] < value)
			l = m + 1;
		else if (arr[m] > value)
			r = m - 1;
		else
			return m;
	}

	return -1;
}