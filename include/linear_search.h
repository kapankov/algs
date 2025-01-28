#pragma once

template <typename It, typename T>
It linear_search(const It first, const It last, T value)
{
	for (auto it = first;it != last;++it)
		if (*it == value)
			return it;
	return last;
}

template<typename T>
size_t linear_search_old(const T* arr, const size_t len, const T value) noexcept
{
	for (size_t i = 0; i < len; ++i)
		if (*arr++ == value)
			return i;
	return -1;
}