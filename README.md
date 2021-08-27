# Sorting Algorithms

## Task Descriptions

#### 0-bubble_sort.c
- Bubble Sort Algorithm
	- Swaps two elements of array starting from beginning
	- Multiple passes bringing each number index by index to correct position
	- Not very efficient

#### 1-insertion_sort_list.c
- Insertion Sort Algorithm
	- Swaps elements in doubly-linked list from current position to correct position
	- One pass bringing each number directly to correct position
	- Not very efficient

#### 2-selection_sort.c
- Selection Sort Algorithm
	- Continuously finds lowest element and swaps to beginning
	- Finds number that will be index 0 first
	- Inefficient

#### 3-quick_sort.c
- QuickSort Algorithm
	- Finds element as pivot and partitions array into numbers smaller or larger than element
	- Numbers on left side of pivot are smaller than pivot although not necessarily sorted, etc.
	- Inherently recursive to partition/sort small arrays
	- Efficient - divide and conquer method based

## Big O Files

- Best case time complexity
- Average case time complexity
- Worst case time complexity

## Helper Files

#### sort.h
- Struct to define each node in doubly-linked list

#### print_array.c
- Prints array

#### print_list.c
- Prints doubly-linked list
