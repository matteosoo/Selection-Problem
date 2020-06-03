Selection-Problem
===
Use "quick sort (QS)" and "prune &amp; search (PS)"  to sort the given n numbers in ascending order and pick out the k-th number from the sorted array

# Time complexity (prospect)

| quick sort (QS) | prune &amp; search (PS) |
| --------------- | ----------------------- |
| $O(n log n)$    | $O(n)$                  |

# How to run?
1. Environments 
    * c++ compile with g++
    * macOS Catalina 10.15.5
    * c++11 standard
2. Compile
    * `$ g++ -std=c++11 -o quick_sort.exe quick_sort.cpp`
    * `$ g++ -std=c++11 -o prune_and_search.exe prune_and_search.cpp`
3. Execution
    * `$ ./quick_sort.exe data/input.txt`
    * `$ ./prune_and_search.exe data/input.txt`


# Experimental results
* Quick sort (QS)

| case\N= | 10000 | 11000 | 12000 | 13000 | 14000 | 15000 | ... | 30000 |
| ------- | ----- | ----- | ----- | ----- | ----- | ----- | --- | ----- |
| case1   |       |       |       |       |       |       |     |       |
| case2   |       |       |       |       |       |       |     |       |
| case3   |       |       |       |       |       |       |     |       |
| Average |       |       |       |       |       |       |     |       |

* Prune and search (PS)

| case\N= | 10000 | 11000 | 12000 | 13000 | 14000 | 15000 | ... | 30000 |
| ------- | ----- | ----- | ----- | ----- | ----- | ----- | --- | ----- |
| case1   |       |       |       |       |       |       |     |       |
| case2   |       |       |       |       |       |       |     |       |
| case3   |       |       |       |       |       |       |     |       |
| Average |       |       |       |       |       |       |     |       |

###### tags: `Algorithm`
