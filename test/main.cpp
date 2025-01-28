#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "linear_search.h"
#include "binary_search.h"
#include "exchange_sort.h"
#include "bubble_sort.h"
#include "insert_sort.h"
#include "select_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "lomuto_sort.h"

#define SIZEOF(x) (sizeof(x) / sizeof(decltype(x[0])))
#define END(x) (x + SIZEOF(x))
#define LAST(x) (END(x) - 1)

TEST(Search, Linear)
{
	int arr[] = {5, 3, 7, 1, 3, 8, 4, 6, 9, 2, 0};

	auto arr_end = END(arr);
	auto arr_it = linear_search(arr, arr_end, 8);
	
	ASSERT_NE(arr_it, arr_end);
	ASSERT_EQ(arr_it - arr, 5);

	arr_it = linear_search(arr, arr_end, 'X');
	
	ASSERT_EQ(arr_it, arr_end);

}

TEST(Search, Binary)
{
	char str[] = "abcdefghijklmnopqrstuvwxyz";

	auto str_end = END(str);
	auto str_it = binary_search(str, str_end, 's');

	ASSERT_NE(str_it, str_end);
	ASSERT_EQ(str_it - str, 18);

	str_it = binary_search(str, str_end, '#');

	ASSERT_EQ(str_it, str_end);
}

TEST(Sort, Exchange)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	exchange_sort(str, LAST(str),
		[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");

	exchange_sort(str, LAST(str), 
		[](const char& a, const char& b){ return a > b; });

	ASSERT_STREQ(str, "zyxwvutsrqponmlkjihgfedcba");

	int arr[] = { 9, 3, 7, 4, 1, 8, 0, 6, 2, 5 };

	exchange_sort(arr, END(arr), 
		[](const int& a, const int& b){ return a < b; });

	ASSERT_THAT(arr, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));

	char x = 'x';
	exchange_sort(&x, &x + 1, 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(x, 'x');

	std::string s{"runme"};

	exchange_sort(s.begin(), s.end(), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(s, "emnru");

	exchange_sort(s.rbegin(), s.rend(), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(s, "urnme");
}

TEST(Sort, ExchangeRecursive)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	exchange_sort_recursive(str, LAST(str),
		[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");

	exchange_sort_recursive(str, LAST(str), 
		[](const char& a, const char& b){ return a > b; });

	ASSERT_STREQ(str, "zyxwvutsrqponmlkjihgfedcba");

	int arr[] = { 9, 3, 7, 4, 1, 8, 0, 6, 2, 5 };

	exchange_sort_recursive(arr, END(arr), 
		[](const int& a, const int& b){ return a < b; });

	ASSERT_THAT(arr, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));

	char x = 'x';
	exchange_sort_recursive(&x, &x + 1, 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(x, 'x');

	std::string s{"runme"};

	exchange_sort_recursive(s.begin(), s.end(), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(s, "emnru");

	exchange_sort_recursive(s.rbegin(), s.rend(), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(s, "urnme");
}

TEST(Sort, ExchangeClassic)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	exchange_sort(str, strlen(str),
		[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");

	exchange_sort(str, strlen(str), 
		[](const char& a, const char& b){ return a > b; });

	ASSERT_STREQ(str, "zyxwvutsrqponmlkjihgfedcba");

	int arr[] = { 9, 3, 7, 4, 1, 8, 0, 6, 2, 5 };

	exchange_sort(arr, SIZEOF(arr), 
		[](const int& a, const int& b){ return a < b; });

	ASSERT_THAT(arr, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));

	char x = 'x';
	exchange_sort(&x, 1, 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(x, 'x');

	std::string s{"runme"};

	exchange_sort(s.data(), s.length(), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(s, "emnru");
}

TEST(Sort, Bubble)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	bubble_sort(str, LAST(str), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");

	bubble_sort(str, LAST(str), 
		[](const char& a, const char& b){ return a > b; });

	ASSERT_STREQ(str, "zyxwvutsrqponmlkjihgfedcba");

	std::string s{ "ceiqnzauslygkpvdrmthwjboxf" };

	bubble_sort(s.begin(), s.end(), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(s, "abcdefghijklmnopqrstuvwxyz");

	int arr[] = { 9, 3, 7, 4, 1, 8, 0, 6, 2, 5 };

	bubble_sort(arr, END(arr), 
		[](const int& a, const int& b){ return a < b; });

	ASSERT_THAT(arr, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
}

TEST(Sort, BubbleRecursive)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	bubble_sort_recursive(str, LAST(str), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");

	bubble_sort_recursive(str, LAST(str), 
		[](const char& a, const char& b){ return a > b; });

	ASSERT_STREQ(str, "zyxwvutsrqponmlkjihgfedcba");

	std::string s{ "ceiqnzauslygkpvdrmthwjboxf" };

	bubble_sort_recursive(s.begin(), s.end(), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(s, "abcdefghijklmnopqrstuvwxyz");

}

TEST(Sort, BubbleClassic)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	bubble_sort(str, strlen(str), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");

	bubble_sort(str, strlen(str), 
		[](const char& a, const char& b){ return a > b; });

	ASSERT_STREQ(str, "zyxwvutsrqponmlkjihgfedcba");

	std::string s{ "ceiqnzauslygkpvdrmthwjboxf" };

	bubble_sort(s.data(), s.length(), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(s, "abcdefghijklmnopqrstuvwxyz");

	int arr[] = { 9, 3, 7, 4, 1, 8, 0, 6, 2, 5 };

	bubble_sort(arr, SIZEOF(arr), 
		[](const int& a, const int& b){ return a < b; });

	ASSERT_THAT(arr, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
}

TEST(Sort, Insert)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	insert_sort(str, LAST(str), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");

	insert_sort(str, LAST(str), 
		[](const char& a, const char& b){ return a > b; });

	ASSERT_STREQ(str, "zyxwvutsrqponmlkjihgfedcba");

	int arr[] = { 9, 3, 7, 4, 1, 8, 0, 6, 2, 5 };

	insert_sort(arr, END(arr), 
		[](const int& a, const int& b){ return a < b; });

	ASSERT_THAT(arr, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
}

TEST(Sort, InsertClassic)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	insert_sort(str, strlen(str),
		[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");

	insert_sort(str, strlen(str), 
		[](const char& a, const char& b){ return a > b; });

	ASSERT_STREQ(str, "zyxwvutsrqponmlkjihgfedcba");

	int arr[] = { 9, 3, 7, 4, 1, 8, 0, 6, 2, 5 };

	insert_sort(arr, SIZEOF(arr), 
		[](const int& a, const int& b){ return a < b; });

	ASSERT_THAT(arr, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));

	char x = 'x';
	insert_sort(&x, 1, 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(x, 'x');

	std::string s{"runme"};

	insert_sort(s.data(), s.length(), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(s, "emnru");
}

TEST(Sort, Select)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	select_sort(str, LAST(str), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");

	int arr[] = { 9, 3, 7, 4, 1, 8, 0, 6, 2, 5 };

	select_sort(arr, END(arr), 
		[](const int& a, const int& b){ return a < b; });

	ASSERT_THAT(arr, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
}

TEST(Sort, SelectRecursive)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	select_sort_recursive(str, LAST(str), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");
}

TEST(Sort, SelectClassic)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	select_sort(str, strlen(str),
		[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");

	select_sort(str, strlen(str), 
		[](const char& a, const char& b){ return a > b; });

	ASSERT_STREQ(str, "zyxwvutsrqponmlkjihgfedcba");

	int arr[] = { 9, 3, 7, 4, 1, 8, 0, 6, 2, 5 };

	select_sort(arr, SIZEOF(arr), 
		[](const int& a, const int& b){ return a < b; });

	ASSERT_THAT(arr, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));

	char x = 'x';
	select_sort(&x, 1, 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(x, 'x');

	std::string s{"runme"};

	select_sort(s.data(), s.length(), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_EQ(s, "emnru");
}

TEST(Sort, Merge)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	merge_sort(str, LAST(str), 
	 	[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");

	int arr[] = { 9, 3, 7, 4, 1, 8, 0, 6, 2, 5 };

	merge_sort(arr, END(arr), 
		[](const int& a, const int& b){ return a < b; });

	ASSERT_THAT(arr, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
}

TEST(Sort, HoareQuick)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	quick_sort(str, LAST(str), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");

	int arr[] = { 9, 3, 7, 4, 1, 8, 0, 6, 2, 5 };

	quick_sort(arr, END(arr), 
		[](const int& a, const int& b){ return a < b; });

	ASSERT_THAT(arr, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
}

TEST(Sort, LomutoQuick)
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";

	lomuto_sort(str, LAST(str), 
		[](const char& a, const char& b){ return a < b; });

	ASSERT_STREQ(str, "abcdefghijklmnopqrstuvwxyz");

	int arr[] = { 9, 3, 7, 4, 1, 8, 0, 6, 2, 5 };

	lomuto_sort(arr, END(arr), 
		[](const int& a, const int& b){ return a < b; });

	ASSERT_THAT(arr, testing::ElementsAre(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
}

/*int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);

	return RUN_ALL_TESTS();
}*/