cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(algs_test LANGUAGES CXX)

add_executable(${PROJECT_NAME})
# add_library(${PROJECT_NAME} STATIC)
# add_library(${PROJECT_NAME} SHARED)

# CXX_STANDARD support:
# CMAKE 3.1 - 98,11 and 14
# CMAKE 3.8 - 17
# CMAKE 3.12 - 20
# CMAKE 3.20 - 23
# CMAKE 3.25 - 26
set_target_properties(${PROJECT_NAME}
	PROPERTIES
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED YES
		CXX_EXTENSIONS NO
)

target_include_directories(${PROJECT_NAME}
	PRIVATE
		include/
#		second_dir/
)

target_sources(${PROJECT_NAME}
	PRIVATE
		test/main.cpp
		include/linear_search.h
		include/binary_search.h
		include/exchange_sort.h
		include/bubble_sort.h
		include/insert_sort.h
		include/select_sort.h
		include/merge_sort.h
		include/quick_sort.h
		include/lomuto_sort.h
#		test/src.cpp
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		gtest
		gtest_main
		gmock
		gmock_main
)