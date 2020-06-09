Selection-Problem
===
Use "quick sort (QS)" and "prune &amp; search (PS)"  to sort the given n numbers in ascending order and pick out the k-th number from the sorted array

# Time complexity (prospect)

| quick sort (QS) | prune &amp; search (PS) |
| --------------- | ----------------------- |
| O(n log n)      | O(n)                    |

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
4. Data generation (optional)
    * `$ python data_generation.py`
    * Input size (i) is  10000 to 30000 in steps 1000
    * Random list(unsorted data) is integers with range [1,20000]

# Input / Output
* Preview input.txt
```cpp
// with n numbers and locate the k-th element
10000 4159
// unsorted data below
8783 16199 7648 14201 12254 3732 13701 840 8477 5175 9408 7595 9652 19317 3908  ...
```

* Preview QS.txt
```cpp
8350 // the number of k-th element
0.002023 // the program execution time
```

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

# References
1. quick sort: https://www.geeksforgeeks.org/quickselect-algorithm/
2. prune and search: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/
3. https://www.ptt.cc/bbs/Grad-ProbAsk/M.1255803641.A.D78.html

###### tags: `Algorithm`
